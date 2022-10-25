#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "othello_func.h"


void init_board(int board[][8]){

    for (int lines = 0; lines < max_lines; lines++)
    {
        for (int coluns = 0; coluns < max_col; coluns++)
        {
            if (lines == 3 && coluns == 3 || lines == 4 && coluns == 4)     // posiçẽs iniciais das peças brancas
                board[lines][coluns]=0;
            else if (lines == 4 && coluns == 3 || lines == 3 && coluns == 4)    // posiçẽs iniciais das peças pretas 
                board[lines][coluns]=1;
            else
                board[lines][coluns]=-1;
        }
        
    }

}

void print_board(int board[][8]){

    printf(" ");
    for (int letra = 65; letra < 73; letra++)       // 65 é o código ASCII de A, 72 é o código ASCII de H
        printf(" %c",(char) letra);         // nº da coluna em código ASCII
        
    printf("\n");

    for (int nline = 1; nline < 9; nline++){
        printf("%d",nline);           // nº da linha

        int l=nline-1;              // nº da linha na board
        for (int c = 0; c < max_col; c++)
        {
            if (board[l][c]== 0)          // se for peça branca
                printf(" o");
            else if (board[l][c]==1)   // se for peça preta 
                printf(" x");
            else if(board[l][c]==-1)
                printf(" .");       // nenhuma das anteriores
            
        }
        printf("\n");
    }
    
}

void clean_last_game(){

    FILE *f;
    f = fopen("jogadas.txt","w+");       
    
    fprintf(f,"Jogadas efetuadas:\n");            
      
    fclose(f);
}

void safe_file(int l, char c){

    FILE *f;
    f = fopen("jogadas.txt","a");       // modo de acesso "acrescentar"
    
    fprintf(f,"%d%c\n",l,c);            // escreve numa linha do ficherio a jogada introduzida no terminal
      
    fclose(f);

}

void zero_jogadasP(){

    FILE *f;
    f = fopen("jogadas.txt","a");   // modo de acesso "acrescentar"

    fprintf(f," \n");  

    fclose(f);
}

struct valoresH jogadaH(int board[][8], int line, char col, int color){

    struct valoresH v;
    int value_r=2, value_l=2, value_f=0, exist_right=0, exist_left=0;       
    int col_right=0;       // peça que se encontra o mais próximo à direita da jogada introduzida no terminal
    int col_left=0;        // peça que se encontra o mais próximo à esquerda da jogada introduzida no terminal

    //
    // Testamos se existe uma peça na mesma linha com a mesma cor à direita e à esquerda da jogada introduzida no terminal
    //

    int c =(int) col - 65 + 1;

    while (c<max_col && exist_right==0)
    {
        if(board[line-1][c]== color){
            col_right=c;
            exist_right=1;                  
        }
        c++;
    }

    c =(int) col - 65 - 1;

    while (c >= 0 && exist_left == 0)
    {
        if(board[line-1][c]== color){
            col_left=c;
            exist_left=1;                   
        }
        c--;
    }
    

    //printf("exist_right: %d\n",exist_right);              // testes
    //printf("exist_left: %d\n",exist_left);                // testes

    //
    // Depois de averiguarmos a existência de uma peça, avaliamos se a jogada na horizontal respeita as regras do jogo
    //

    if (exist_right==0)
        value_r=0;
    if (exist_left==0)
        value_l=0;
    
    
    if (exist_right==1)
    {   
        int c=(int) col - 65 + 1;
        while (c < col_right && value_r != 0)
        {
            if (board[line-1][c] != color && board[line-1][c] != -1)
                value_r=1;        // averiguamos se a jogada respeita as regras do jogo
            else    
                value_r=0;
            c++;
        } 
    }
    if (exist_left==1)
    {
        int c=(int) col - 65 - 1;
        while (c > col_left && value_l != 0)
        {
            if (board[line-1][c] != color && board[line-1][c] != -1)
                value_l=1;
            else
                value_l=0;
            c--;
        }
    }

    //printf("value_r: %d\n", value_r);         // testes
    //printf("value_l: %d\n", value_l);         // testes

    
    if (value_l == 1 || value_r == 1)
        value_f=1;

    
    v.value_f=value_f;
    v.value_l=value_l;
    v.value_r=value_r;
    v.col_left=col_left;
    v.col_right=col_right;
    
    //printf("v.col_left: %d\n", v.col_left);       // testes
    //printf("v.value_l: %d\n", v.value_l);         // testes

    
    return v;
    
}

void play_horizontal(int board[][8], int line, char col, int color, struct valoresH v){

    if (v.value_r == 1)
    {
        for (int c = (int) col-65; c < v.col_right; c++)
            board[line-1][c]=color;
    }
    if (v.value_l == 1)
    {
        for (int c = (int) col-65; c > v.col_left; c--)
            board[line-1][c]=color;
    }
}

struct valoresV jogadaV(int board[][8], int line, char col, int color){

    struct valoresV v;

    int exist_down=0, exist_up=0, value_d=2, value_u=2, value_f=0;
    int line_down= 0;       // peça que se encontra o mais próximo a baixo das coordenadas inseridas
    int line_up= 0;         // peça que se encontra o mais próximo a cima das coordenadas inseridas

    //
    // Testamos se existe uma peça na mesma linha com a mesma cor acima e abaixo
    //

    int l = line;      

    while (l<max_lines && exist_down==0)
    {
        if (board[l][(int) col - 65] == color){
            exist_down=1;       
            line_down=l;
        }
        l++;
    }

    l = line - 2;

    while (l >= 0 && exist_up==0)
    {
        if (board[l][(int) col - 65] == color){
            exist_up=1;     
            line_up=l;
        }
        l--;
    }
    
    
    //printf("exist_down: %d\n",exist_down);        // testes
    //printf("exist_up: %d\n",exist_up);            // testes 

    if(exist_down==0)
        value_d=0;
    if (exist_up==0)
        value_u=0;
    
    
    //
    // Depois de averiguarmos a existência de uma peça, avaliamos se a jogada na vertical respeita as regras do jogo
    //

    if (exist_down == 1)
    {
        int l = line;           
        while (l < line_down && value_d != 0)
        {
            if (board[l][(int) col - 65] != color && board[l][(int) col - 65] != -1)
                value_d=1;
            else
                value_d=0;
            l++;
        }
    }

    if (exist_up == 1)
    {
        int l = line - 2;               
        while (l > line_up && value_u != 0)
        {
            if (board[l][(int) col - 65] != color && board[l][(int) col - 65] != -1)
                value_u=1;
            else
                value_u=0;
            l--;
        }
    }

    //printf("Value_d: %d\n",value_d);          // testes
    //printf("Value_u: %d\n",value_u);          // testes

    
    if (value_u == 1 || value_d == 1)
        value_f=1;
    

    v.value_f=value_f;
    v.value_d=value_d;
    v.value_u=value_u;
    v.line_down=line_down;
    v.line_up=line_up;

    //printf("v.line_down: %d\n", v.line_down);     // testes 
    //printf("v.value_d: %d\n", v.value_d);         // testes

    return v;
    
}

void play_vertical(int board[][8], int line, char col, int color, struct valoresV v){

    if (v.value_d==1)
    {
        for (int l = line-1; l < v.line_down; l++)
            board[l][(int) col-65]=color;
    }
    
    if (v.value_u==1)
    {
        for (int l = line-1; l > v.line_up; l--)
            board[l][(int) col-65]=color;
    }
    
}

struct valoresD jogadaD(int board[][8], int line, char col, int color){

    struct valoresD d;
    int  value_f=0;

    int exist_down_p=0, exist_up_p=0, l=line, c=(int) col - 65 +1, value_d_p=2, value_u_p=2;
    int diagonal_down_line = 0;         // guarda a linha da peça que esta mais próxima a baixo das coordenadas inseridas
    int diagonal_down_col = 0;          // guarda a coluna da peça que esta mais próxima a baixo das coordenadas inseridas
    int diagonal_up_line = 0;           // guarda a linha da peça que esta mais próxima acima das coordenadas inseridas
    int diagonal_up_col = 0;            // guarda a coluna da peça que esta mais próxima acima das coordenadas inseridas


    int exist_down_s=0, exist_up_s=0, value_d_s=2, value_u_s=2;
    int diagonal_down_line2 = 0;        // guarda a linha da peça que esta mais próxima a baixo das coordenadas inseridas
    int diagonal_down_col2 = 0;         // guarda a coluna da peça que esta mais próxima a baixo das coordenadas inseridas
    int diagonal_up_line2 = 0;          // guarda a linha da peça que esta mais próxima acima das coordenadas inseridas
    int diagonal_up_col2 = 0;           // guarda a coluna da peça que esta mais próxima acima das coordenadas inseridas


    //
    // Testamos se existe uma peça nesta direção "/" com a mesma cor acima e abaixo
    //

    while (l < max_lines && c < max_col && exist_down_p==0)
    {
        if (board[l][c] == color )
        {
            exist_down_p=1;
            diagonal_down_line=l;
            diagonal_down_col=c;
        }
        l++;
        c++;    
    }

    l=line-2;
    c=(int) col -65-1;

    while (l>=0 && c>=0 && exist_up_p==0)
    {
        if (board[l][c] == color )
        {
            exist_up_p=1;
            diagonal_up_line=l;
            diagonal_up_col=c;
        }
        l--;
        c--;
    }

    //
    // Testamos se existe uma peça nesta direção "\" com a mesma cor acima e abaixo
    //

    l=line;
    c=(int) col - 65 -1; 
    
    while (l<max_lines && c>=0 && exist_down_s==0)
    {
        if (board[l][c]==color)
        {
            exist_down_s=1;
            diagonal_down_line2=l;
            diagonal_down_col2=c;  
        }
        l++;
        c--;  
    }

    l=line - 2;
    c=(int) col - 65 +1;

    while (l>=0 && c<max_col && exist_up_s==0)
    {
        if (board[l][c]==color)
        {
            exist_up_s=1;
            diagonal_up_line2=l;
            diagonal_up_col2=c; 
        }
        l--;
        c++;
    }
    

    //printf("exist_down_p: %d\n",exist_down_p);        // testes
    //printf("exist_up_p: %d\n",exist_up_p);            // testes
    //printf("exist_down_s: %d\n",exist_down_s);        // testes 
    //printf("exist_up_s: %d\n",exist_up_s);            // testes 

    //
    // Depois de averiguarmos a existência de uma peça, avaliamos se a jogada nesta direção "/" ou nesta "\" respeita as regras do jogo
    //

    if (exist_down_p==1)
    {
        int l = line;     
        int c = (int) col - 65 + 1;
        while (l<diagonal_down_line && c<diagonal_down_col && value_d_p!=0)
        {
            if (board[l][c] != color && board[l][c] != -1)
                value_d_p=1;
            else
                value_d_p=0;
            l++;
            c++;
        } 
    }

    
    if (exist_up_p==1)
    {
        int l = line-2;
        int c = (int) col - 65 - 1;

        while (l>diagonal_up_line && c>diagonal_up_col && value_u_p!=0)
        {
            if (board[l][c] != color && board[l][c] != -1)
                value_u_p=1;
            else
                value_u_p=0;
            l--;
            c--;
        }
        
    }
    
    
    if (exist_down_s==1)
    {
        int l = line;
        int c = (int) col - 65 - 1;

        while (l<diagonal_down_line2 && c>diagonal_down_col2 && value_d_s!=0)
        {
            if (board[l][c] != color && board[l][c] != -1)
                value_d_s=1;
            else
                value_d_s=0;
            l++;
            c--;
        }
        

    }


    if (exist_up_s==1)
    {
        int l = line-2;
        int c = (int) col - 65+1;

        while (l>diagonal_up_line2 && c<diagonal_up_col2 && value_u_s!=0)
        {
            if (board[l][c] != color && board[l][c] != -1)
                value_u_s=1;
            else
                value_u_s=0;
            l--;
            c++;
        }
        
    }

    
    //printf("diagonal_down_line2: %d\n",diagonal_down_line2);      // testes
    //printf("diagonal_down_col2: %d\n",diagonal_down_col2);        // testes
    //printf("diagonal_up_line2: %d\n",diagonal_up_line2);          // testes
    //printf("diagonal_up_col2: %d\n",diagonal_up_col2);            // testes
    

    if (value_d_p==1 || value_u_p==1 || value_d_s==1 || value_u_s==1)
        value_f=1;
    
    d.value_f=value_f;
    d.value_d_p=value_d_p;
    d.value_u_p=value_u_p;
    d.value_d_s=value_d_s;
    d.value_u_s=value_u_s;
    d.diagonal_down_line=diagonal_down_line;
    d.diagonal_down_col=diagonal_down_col;
    d.diagonal_down_line2=diagonal_down_line2;
    d.diagonal_down_col2=diagonal_down_col2;
    d.diagonal_up_line=diagonal_up_line;
    d.diagonal_up_col=diagonal_up_col;
    d.diagonal_up_line2=diagonal_up_line2;
    d.diagonal_up_col2=diagonal_up_col2;

    return d;
    
}

void play_diagonal(int board[][8], int line, char col, int color, struct valoresD v){

    if (v.value_d_p==1)
    {
        int l = line-1;
        int c = (int) col -65;

        while (l < v.diagonal_down_line && c < v.diagonal_down_col){
            board[l][c]=color;
            l++;
            c++; 
        }
    }
    
    
    if (v.value_u_p==1)
    {
        int l = line-1;
        int c = (int) col -65;

        while (l>v.diagonal_up_line && c>v.diagonal_up_col){
            board[l][c]=color;
            l--;
            c--;
        }
    }

    if (v.value_d_s==1) 
    {
        int l = line-1;
        int c = (int) col - 65;
        while (l<v.diagonal_down_line2 && c>v.diagonal_down_col2)
        {
            board[l][c]=color;
            l++;
            c--;
        }
        
    }
    
    
    if (v.value_u_s==1)
    {
        int l = line-1;
        int c = (int) col - 65;
        while (l>v.diagonal_up_line2 && c<v.diagonal_up_col2)
        {
            
            board[l][c]=color;
            l--;
            c++;
        }
    
    }
    
}

int play(int board[][8], int line, char col, int color){

    int play=0, l, c;

    l=line-1;
    c=(int) col - 65;

    if (board[l][c]==-1)
    {
        struct valoresH h = jogadaH(board, line, col, color);
        struct valoresV v = jogadaV(board, line, col, color);
        struct valoresD d = jogadaD(board, line, col, color);

        if (h.value_f){
            play=1;
            play_horizontal(board,line,col,color,h);
        }

        if(v.value_f){
            play=1;
            play_vertical(board,line,col,color,v);
        }

        if (d.value_f){
            play=1;
            play_diagonal(board,line,col,color,d);
        }
    }
    
    return play;
    
}

void score(int board[][8],struct color color){

    int player=0, cpu=0, black, white;

    for(int l=0;l<max_lines;l++){
        for(int c=0;c<max_col;c++){
            if(board[l][c]==color.color_jogador)
                player++;
            else if(board[l][c]==color.color_CPU)
                cpu++;
        }
    }

    if (color.color_jogador)
    {
        black=player;
        white=cpu;
    }
    else
    {
        black=cpu;
        white=player;
    }
    

    printf("\n");
    printf("Game Over!\n");
    printf("Black: %d discs, White: %d discs\n",black,white);
    //printf("player: %d discs , CPU: %d discs\n",player,cpu);      // testes 

    if(player>cpu)
        printf("You win!\n");
    else if (player==cpu)
        printf("It's a draw!\n");
    else
        printf("You lose!\n");
      
}

struct color player_color(){

    struct color c;

    int num;

    srand(time(NULL));
    num=rand()%2;
    //printf("%d\n", num);

    c.color_jogador=num;

    if(c.color_jogador)
        c.color_CPU=0;
    else 
        c.color_CPU=1;

    return c;

}

void your_color(struct color c){
    
    if (c.color_jogador)
        printf("Your discs are Black.\n");
    else
        printf("Your discs are White.\n");      
    
}

void board_clone(int b_p[][8], int b_s[][8]){

    for (int i = 0; i < max_lines; i++)
    {
        for (int z = 0; z < max_col; z++)
            b_s[i][z]=b_p[i][z];
    }
    
}

int flanked(int board[][8], int board_s[][8], int line, char col, int color){

    int count=0;

    //printf("line: %d col: %c\n",line,col);                    // testes
    //printf("line-1: %d col: %d\n",line-1,(int) col - 65);     // testes

    for (int l = 0; l < max_lines; l++)
    {
        for (int c = 0; c < max_col; c++)
        {
            if (board[l][c]!=board_s[l][c])         
                count+=1;
                
            if (l==line-1 && c==(int) col - 65 && count!=0)
                count-=1;
            
        }
    }

    return count;     
}

int count_flips_dir(int board_p[][8], int board_s[][8], int line, char col, int delta_line, int delta_col, int color){

    int count_f=0;

    if (delta_line && delta_col)
    {
        int l = line;
        int c = (int) col - 65 + 1;
        
        while (l<max_lines && c<max_col)
        {
            if (board_p[l][c]!=board_s[l][c])
                count_f+=1;
            l++;
            c++;
            
        }
        
    }
    else if (!delta_line && !delta_col)
    {
        int l = line-2;
        int c = (int) col - 65 - 1;

        while (l>=0 && c>=0)
        {
            if (board_p[l][c]!=board_s[l][c])
                count_f+=1;
            l--;
            c--;
        }
        
    }
    else if (!delta_line && delta_col)
    {
        int l = line-2;
        int c = (int) col - 65 + 1;

        while (l>=0 && c<max_col)
        {
            if (board_p[l][c]!=board_s[l][c])
                count_f+=1;
            l--;
            c++;
        }

    }
    else if (delta_line && !delta_col)
    {
        int l = line;
        int c = (int) col - 65 - 1;

        while (l<max_lines && c>=0)
        {
            if (board_p[l][c]!=board_s[l][c])
                count_f+=1;
            l++;
            c--;
        }
    }
    
    return count_f;
    
}

int cor_a_jogar(int count){

    if (count%2==0)
        return 0;
    else
        return 1;
    
}

struct jogadaP *jogadas_possiveis(int board[][8], int color){

    int i=0;
    struct valoresH h;
    struct valoresV v;
    struct valoresD d;
    struct jogadaP *jP=malloc(sizeof(struct jogadaP)*20);

    for (int l = 0; l < max_lines; l++)
    {
        for (int c = 0; c < max_col; c++)
        {
            h=jogadaH(board,l+1,(char) c + 65, color);
            v=jogadaV(board,l+1,(char) c + 65, color);
            d=jogadaD(board,l+1,(char) c + 65, color);
            if (board[l][c]==-1 && (h.value_f || v.value_f || d.value_f))
            {
                jP[i].line=l+1;
                jP[i].col=(char) c + 65;
                //printf("i: %d posiçao: %d%c\n",i,jP[i].line,jP[i].col);                               // testes
                //printf("i: %d h.value_f: %d posiçao: %d%c\n",i,h.value_f,jP[i].line,jP[i].col);       // testes      
                //printf("i: %d v.value_f: %d posiçao: %d%c\n",i,v.value_f,jP[i].line,jP[i].col);       // testes            
                //printf("i: %d d.value_f: %d posiçao: %d%c\n",i,d.value_f,jP[i].line,jP[i].col);       // testes         
                i+=1;
            }
        }
    }

    jP->num_jogadas=i;
    
    return jP;
    
}

void imprime_jp(struct jogadaP j[],int color){

    for (int i = 0; i < j->num_jogadas; i++)
        printf("i: %d posiçao: %d%c\n",i,j[i].line,j[i].col);
    
}

struct best best_play(int board[][8],struct jogadaP j[],int color){

    struct best bp;
    int flanked_max=0, exists_corner=0, p=0, exists_center=0, ascii, d=0;

    struct jogadaP *center=malloc(sizeof(struct jogadaP)*20);
    struct jogadaP *corners=malloc(sizeof(struct jogadaP)*20);

    //imprime_jp(j,color);                      // testes

    for (int i = 0; i < j->num_jogadas; i++)
    {
        ascii=(int) j[i].col;
        if (j[i].line>=3 && j[i].line<=6 && ascii>=67 && ascii<= 70)              // ASCII de C       ASCII de F
        {
            center[d].line=j[i].line;
            center[d].col=j[i].col;
            d+=1;
            exists_center=1;
        }
        
    }

    center->num_jogadas=d;

    if (exists_center)
    {
        for (int d = 0; d < center->num_jogadas; d++)
        {
            int board_clone_p[8][8];
            int board_clone_s[8][8];
            int func=0;

            board_clone(board,board_clone_p);   // testes
            board_clone(board,board_clone_s);   // testes

            //printf("Board clone: \n");        //
            //print_board(board_clone_p);       // testes
            //printf("\n");                     //

            play(board_clone_p,center[d].line,center[d].col,color);

            //printf("Board clone depois da jogada: \n");       //
            //print_board(board_clone_p);                       // testes
            //printf("\n");                                     //

            func=flanked(board_clone_p,board_clone_s,center[d].line,center[d].col,color);     

            //printf("func (%d%c): %d\n",center[d].line,center[d].col,func);        // testes

            if (func>flanked_max)           
            {
                flanked_max=func;
                bp.line=center[d].line;
                bp.col=center[d].col;
            }
        }
        
    }
    else
    {
        for (int i = 0; i < j->num_jogadas; i++)
        {
            if ((j[i].line==1 && j[i].col=='A') || (j[i].line==8 && j[i].col=='A') || (j[i].line==1 && j[i].col=='H') || (j[i].line==8 && j[i].col=='H'))                 
            {
                corners[p].line=j[i].line;
                corners[p].col=j[i].col;
                p+=1;
                exists_corner=1;
            }
        }

        corners->num_jogadas=p;

        if (exists_corner)
        {
            for (int p = 0; p < corners->num_jogadas; p++)
            {
                int board_clone_p[8][8];
                int board_clone_s[8][8];
                int func=0;

                board_clone(board,board_clone_p);   // testes
                board_clone(board,board_clone_s);   // testes

                //printf("Board clone: \n");        //
                //print_board(board_clone_p);       // testes
                //printf("\n");                     //

                play(board_clone_p,corners[p].line,corners[p].col,color);

                //printf("Board clone depois da jogada: \n");       //
                //print_board(board_clone_p);                       // testes
                //printf("\n");                                     //

                func=flanked(board_clone_p,board_clone_s,corners[p].line,corners[p].col,color);     

                //printf("func (%d%c): %d\n",corners[p].line,corners[p].col,func);        // testes

                if (func>flanked_max)           
                {
                    flanked_max=func;
                    bp.line=corners[p].line;
                    bp.col=corners[p].col;
                }
            }
        }
        else
        {
            for (int i = 0; i < j->num_jogadas; i++)
            {
                int board_clone_p[8][8];
                int board_clone_s[8][8];
                int func=0;
            
                board_clone(board,board_clone_p);   // testes
                board_clone(board,board_clone_s);   // testes

                //printf("Board clone: \n");        //
                //print_board(board_clone_p);       // testes
                //printf("\n");                     //

                play(board_clone_p,j[i].line,j[i].col,color);

                //printf("Board clone depois da jogada: \n");       //
                //print_board(board_clone_p);                       // testes
                //printf("\n");                                     //

                func=flanked(board_clone_p,board_clone_s,j[i].line,j[i].col,color);     

                //printf("func (%d%c): %d\n",j[i].line,j[i].col,func);        // testes

                if (func>flanked_max)           
                {
                    flanked_max=func;
                    bp.line=j[i].line;
                    bp.col=j[i].col;
                }
            }  
        }
    }
    
    
    //printf("best jogada: %d%c\n",bp.line,bp.col);

    return bp;
}

void play_CPU(int board[][8], struct best bp, int color){

    int play_cpu;

    play_cpu=play(board,bp.line,bp.col,color);

    printf("My move: %d%c",bp.line,bp.col);
    printf("\n");

}

int end_game(int board[][8]){

   int end=0;

   struct jogadaP *jP_b=jogadas_possiveis(board,0);
   struct jogadaP *jP_p=jogadas_possiveis(board,1);

   if (!jP_b->num_jogadas && !jP_p->num_jogadas)
       end=1;
   
   return end;
}

int char2int(char letter){
    int conversao;

    conversao=(int) letter - 48;

    return conversao;
}

struct jogadasFile *game_inFile(const char *filename){

    struct jogadasFile *jogadasF=malloc(sizeof(struct jogadasFile)*100);
    int num_j=0, i=0, end_of_file=0;
    char linha[10];
    FILE *f;

    f=fopen(filename,"r");

    while (!end_of_file){
        if (fgets(linha,3,f)==NULL)
            end_of_file=1;

        else if (linha[0]!='\n'){
            char ascii_0 = linha[0];
            char ascii_1 = linha[1];
            if (ascii_0>=49 && ascii_0<=56 && ascii_1>=65 && ascii_1<=72)                  // ASCII de 0 e de 8  ASCII de A e de H  
            {
                jogadasF[i].line=char2int(linha[0]);
                jogadasF[i].col=linha[1];
                i+=1;
                num_j+=1;
            }
        }

    }
    
    fclose(f);

    jogadasF->num_jogadas=num_j;

    return jogadasF;

}

void imprime(struct jogadasFile jf[]){
    for (int i = 0; i < jf->num_jogadas; i++)
        printf("jogada nº%d: %d%c\n",i+1,jf[i].line,jf[i].col);
    
}