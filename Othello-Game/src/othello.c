#include "othello_func.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, const char * argv[]){

    if (argc>1)
    {
        struct color cor;
        int b[8][8];
        int end, play_game, count_cor=1, indice=0, jogadaInvalida;

        struct jogadasFile *jogadasFicheiro=malloc(sizeof(struct jogadasFile)*100);

        jogadasFicheiro=game_inFile(argv[1]);                                    
        //printf("Numero de jogadas no file: %d\n", jogadasFicheiro->num_jogadas);        // testes
        //imprime(jogadasFicheiro);                                                       // testes
        //printf("\n");                                                                   //
        
    
        // Inicio do jogo a partir de um ficheiro

        printf("Othello Game\n");

        init_board(b);
        printf("\n");
        cor=player_color();
        your_color(cor);
        printf("\n");

        print_board(b);
        

        while (count_cor<=jogadasFicheiro->num_jogadas)
        {
            int b_copy[8][8];
            int color, flank;
            
            color=cor_a_jogar(count_cor);

            //printf("\n");                                   //
            //printf("Cor a jogar (color): %d\n",color);      //teste
            //printf("\n");                                   //

            board_clone(b,b_copy);

            // CPU/player 

            if (color==cor.color_jogador)
            {
                printf("\n");
                printf("Choose your move. For instance: 5F\n");
                printf("%d%c\n",jogadasFicheiro[indice].line,jogadasFicheiro[indice].col);

                play_game=play(b,jogadasFicheiro[indice].line,jogadasFicheiro[indice].col,cor.color_jogador); 

                if (!play_game)
                {
                    jogadaInvalida=indice+1;
                    count_cor=jogadasFicheiro->num_jogadas+2;
                }
                

                flank=flanked(b,b_copy,jogadasFicheiro[indice].line,jogadasFicheiro[indice].col,color);         // 
                printf("Número de peças flanqueadas: %d",flank);                                                // teste
                printf("\n");                                                                                   //

            }
            else if (color==cor.color_CPU)
            {
                printf("\n");
                printf("My move: %d%c",jogadasFicheiro[indice].line,jogadasFicheiro[indice].col);
                printf("\n");

                play_game=play(b,jogadasFicheiro[indice].line,jogadasFicheiro[indice].col,cor.color_CPU); 

                if (!play_game)
                {
                    jogadaInvalida=indice+1;
                    count_cor=jogadasFicheiro->num_jogadas+2;
                }

                flank=flanked(b,b_copy,jogadasFicheiro[indice].line,jogadasFicheiro[indice].col,color);         // 
                printf("Número de peças flanqueadas: %d",flank);                                                // teste
                printf("\n");                                                                                   //
            }

            printf("\n");
            print_board(b);
            count_cor++;
            indice++;
        }

        printf("\n");

        //printf("count_cor: %d\n",count_cor);                                // testes

        if (count_cor>jogadasFicheiro->num_jogadas+1){
            printf("A %dº jogada do ficheiro %s não respeita as regras do jogo, modifique o documento.\n",jogadaInvalida,argv[1]);
            printf("\n");
        }
        else
            score(b,cor);
        
    }
    else
    {
        struct color cor;
        int b[8][8];
        int end, play_game, count_cor=1;
        
        // Variáveis que guardam a informação acerca da jogada introduzida no terminal pelo utilizador
        int linha, coluna;
        char jogada[3];

        // Inicio do jogo interativo

        clean_last_game();

        printf("Othello Game\n");

        init_board(b);
        end=end_game(b);          
        printf("\n");
        cor=player_color();
        your_color(cor);
        printf("\n");

        print_board(b);

        while (!end)
        {   
            struct jogadaP *jogadasPossiveis=malloc(sizeof(struct jogadaP)*20);
            struct best best;
            int b_copy[8][8];
            int color, flank;

            color=cor_a_jogar(count_cor);
            
            jogadasPossiveis=jogadas_possiveis(b,color);            
            
            //printf("\n");                                   //
            //printf("Cor a jogar (color): %d\n",color);      // testes
            //printf("\n");                                   //

            board_clone(b,b_copy);
            
            // CPU/player 
            
            if (color==cor.color_jogador && jogadasPossiveis->num_jogadas>0)
            {
                //imprime_jp(jogadasPossiveis,color);                   // testes
                //best=best_play(b,jogadasPossiveis,color);               // testes
                printf("\n");
                printf("Choose your move. For instance: 5F\n");
                scanf("%s", jogada);
                linha=char2int(jogada[0]);
                coluna=jogada[1];

                play_game=play(b,linha,coluna,cor.color_jogador);            

                while (play_game==0)
                {   
                    flank=flanked(b,b_copy,linha,coluna,color);         // 
                    printf("Número de peças flanqueadas: %d",flank);    // teste
                    printf("\n");                                       //
                    printf("Invalid move!");
                    printf("Choose your move. For instance: 5F\n");
                    scanf("%s", jogada);
                    linha=char2int(jogada[0]);
                    coluna=jogada[1];
                    
                    play_game=play(b,linha,coluna,cor.color_jogador);            
                }

                flank=flanked(b,b_copy,linha,coluna,color);         // 
                printf("Número de peças flanqueadas: %d",flank);    // testes
                printf("\n");                                       //

                safe_file(linha,coluna);                            // guarda a jogada no ficheiro
            }
            else if (color==cor.color_jogador && !jogadasPossiveis->num_jogadas)
            {
                struct jogadaP *jogadasPossiveis=malloc(sizeof(struct jogadaP)*20);
                struct best best;
                
                zero_jogadasP();
                printf("\n");
                printf("Não há jogadas possíveis para o jogador poder jogar, por isso passa-se a vez para o CPU\n");
                printf("\n");

                jogadasPossiveis=jogadas_possiveis(b,cor.color_CPU);        
                //imprime_jp(jogadasPossiveis,cor.color_CPU);               //teste
                best=best_play(b,jogadasPossiveis,cor.color_CPU);           // indica a melhor jogada para o CPU 
                play_CPU(b,best,cor.color_CPU);

                flank=flanked(b,b_copy,best.line,best.col,color);   //
                printf("Número de peças flanqueadas: %d",flank);    // teste
                printf("\n");                                       //

                safe_file(best.line,best.col);                      // guarda a jogada no ficheiro

                count_cor-=1;

            }
            else if (color==cor.color_CPU && jogadasPossiveis->num_jogadas>0)
            {
                //jogadasPossiveis=jogadas_possiveis(b,cor.color_CPU);            // 
                //imprime_jp(jogadasPossiveis,cor.color_CPU);                     // teste 

                printf("\n");
                best=best_play(b,jogadasPossiveis,cor.color_CPU);                 // indica a melhor jogada para o CPU
                play_CPU(b,best,cor.color_CPU);

                flank=flanked(b,b_copy,best.line,best.col,color);   //
                printf("Número de peças flanqueadas: %d",flank);    // teste
                printf("\n");                                       // 

                safe_file(best.line,best.col);                      // guarda a jogada no ficheiro

            }
            else if (color==cor.color_CPU && !jogadasPossiveis->num_jogadas)
            {
                struct jogadaP *jogadasPossiveis=malloc(sizeof(struct jogadaP)*20);
                struct best best;

                zero_jogadasP();
                printf("\n");
                printf("Não há jogadas possíveis para o CPU poder jogar, por isso passa-se a vez para o jogador.\n");
                printf("\n");

                jogadasPossiveis=jogadas_possiveis(b,cor.color_jogador); 
                //imprime_jp(jogadasPossiveis,cor.color_jogador);                 // testes
                //best=best_play(b,jogadasPossiveis,cor.color_jogador);             // testes

                printf("Choose your move. For instance: 5F\n");
                scanf("%s", jogada);
                linha=char2int(jogada[0]);
                coluna=jogada[1];

                play_game=play(b,linha,coluna,cor.color_jogador);            

                while (play_game==0)
                {   
                    flank=flanked(b,b_copy,linha,coluna,color);         // 
                    printf("Número de peças flanqueadas: %d",flank);    // teste
                    printf("\n");                                       //
                    printf("Invalid move!");
                    printf("Choose your move. For instance: 5F\n");
                    scanf("%s", jogada);
                    //l=jogada[0]-48;
                    linha=char2int(jogada[0]);
                    coluna=jogada[1];
                    
                    play_game=play(b,linha,coluna,cor.color_jogador);            
                }

                flank=flanked(b,b_copy,linha,coluna,color);         //
                printf("Número de peças flanqueadas: %d",flank);    // teste
                printf("\n");                                       //

                safe_file(linha,coluna);                            // guarda a jogada no ficheiro

                count_cor-=1;
            }
            
            printf("\n");
            print_board(b);
            count_cor++;
            end=end_game(b); 

        }

        score(b,cor);
    }
    

    return 0;
}