#ifndef othello_func_h
#define othello_func_h

// As peças brancas(o) são identificadas no tabuleiro com o número 0;
// As peças pretas(x) são identificadas no tabuleiro com o número 1;
// Nenhumas das anteriores é identificado com número -1;

#define max_lines 8
#define max_col 8

// Estrutura que guarda as respetivas cores atribuídas ao jogador e ao computador
struct color
{
    int color_jogador;
    int color_CPU;
};

// Estrutura que guarda os valores das variáveis de uma jogada na horizontal
struct valoresH
{
    int value_f;
    int value_l;
    int value_r; 
    int col_left;
    int col_right;
};

// Estrutura que guarda os valores das variáveis de uma jogada na vertical
struct valoresV
{
    int value_f;
    int value_d;
    int value_u;
    int line_down;
    int line_up;

};

// Estrutura que guarda os valores das variáveis de uma jogada na diagonal
struct valoresD
{
    int value_f;
    int value_d_p;
    int value_u_p;
    int value_d_s;
    int value_u_s;
    int diagonal_down_line;
    int diagonal_down_col;
    int diagonal_down_line2;
    int diagonal_down_col2;
    int diagonal_up_line;
    int diagonal_up_col;
    int diagonal_up_line2;
    int diagonal_up_col2;

};

// Estrutura que guarda todas as jogadas possíveis de uma determinada cor
struct jogadaP
{
    int line;
    char col;
    int num_jogadas;
};

// Estrutura que guarda a linha e a coluna da melhor jogada a ser realizada pelo computador
struct best
{
    int line;
    char col;
};

// Estrutura que guarda a linha e a coluna de todas as jogadas de um ficheiro
struct jogadasFile
{
    int line;
    char col;
    int num_jogadas;
};




/*
######################################################
# init_board - Esta função inicializa o tabuleiro (parâmetro board) com as peças brancas e pretas iniciais.
#
# Argumentos:
# board - tabuleiro atual, inteiro 
# lines - posição da linha no tabuleiro, inteiro
# coluns - posição da coluna no tabuleiro, inteiro
# max_lines - número máximo de linhas que um tabuleiro pode ter, inteiro
# max_col - número máximo de colunas que um tabuleiro pode ter, inteiro
######################################################
*/
void init_board(int board[][8]);

/*
######################################################
# print_board - Esta função mostra o tabuleiro (parâmetro board) atual no standard output (ecrã).
#
# Argumentos:
# board - tabuleiro atual, inteiro 
# letra - código ASCII da letra que representa uma determinada coluna no tabuleiro
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro 
# nline - número da linha 
######################################################
*/
void print_board(int board[][8]);

/*
######################################################
# clean_last_game - Esta função retira as jogadas efetuadas no jogo anterior para podermos possuir só neste ficheiro as jogadas do novo jogo
# Argumentos:
# f - ficheiro que está associado à estrutura FILE, FILE
######################################################
*/
void clean_last_game();

/*
######################################################
# safe_file - Esta funcao escreve no ficheiro "jogadas.txt" todas as jogadas/coordenadas efetuadas (parâmetro l e c) 
#
# Argumentos:
# board - tabuleiro atual, inteiro 
# l - linha da jogada introduzida no terminal, inteiro
# c - coluna da jogada introduzida no terminal, char
# f - ficheiro que está associado à estrutura FILE, FILE
######################################################
*/
void safe_file(int l, char c);

/*
######################################################
# zero_jogodasP - Esta função escreve no ficheiro uma linha em branco no caso de não haver jogadas possíveis para o jogador ou para o computador quando era a sua vez de jogar
#
# Argumentos:
# f - ficheiro que está associado à estrutura FILE, FILE
######################################################
*/
void zero_jogadasP();

/*
######################################################
# jogadaH - Esta função averigua se existe condições para se efetuar uma jogada na horizontal para a peça com a cor que está a ser jogada (parâmetro color).
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# c - posição da coluna no tabuleiro, inteiro
# col_right - guarda a posição da coluna no tabuleiro da peça que se encontra o mais próximo à direita da jogada introduzida no terminal, inteiro
# col_left - guarda a posição da coluna no tabuleiro da peça que se encontra o mais próximo à esquerda da jogada introduzida no terminal, inteiro
# valuer_r - indica se é possível flankear somente à esquerda da jogada introduzida no terminal, inteiro
# valuer_l - indica se é possível flankear somente à direita da jogada introduzida no terminal, inteiro
# value_f - indica se a jogada é valida à esquerda ou à direita, isto é, se existe condições para aceitar a jogada, inteiro
# exist_right - verifica se existe uma peça da mesma cor à direita da jogada introduzida no terminal, inteiro
# exist_left - verifica se existe uma peça da mesma cor à esquerda da jogada introduzida no terminal, inteiro 
#
# Valor de retorno:
# dados da jogada na horizontal, struct
######################################################
*/
struct valoresH jogadaH(int board[][8], int line, char col, int color);

/*
######################################################
# play_horizontal - Esta função coloca a peça da cor que está a ser jogada (parâmetro color) no tabuleiro e flanqueia horizontalmente todas peças possíveis.
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# c - posição da coluna no tabuleiro, inteiro
# v - dados/valores da jogada na horizontal, struct
######################################################
*/
void play_horizontal(int board[][8], int line, char col, int color, struct valoresH v);

/*
######################################################
# jogadaV - Esta função averigua se existe condições para se efetuar uma jogada na vertical para a peça com a cor que está a ser jogada (parâmetro color).
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# l - posição da linha no tabuleiro, inteiro
# exist_down - verifica se existe uma peça da mesma cor abaixo da jogada introduzida no terminal, inteiro
# exist_up - verifica se existe uma peça da mesma cor acima da jogada introduzida no terminal, inteiro
# line_down - guarda a posição da linha no tabuleiro da peça que se encontra o mais próximo abaixo da jogada introduzida no terminal, inteiro
# line_up - guarda a posição da linha no tabuleiro da peça que se encontra o mais próximo acima da jogada introduzida no terminal, inteiro
# value_d - indica se é possível flankear somente abaixo da jogada introduzida no terminal, inteiro
# value_u - indica se é possível flankear somente acima da jogada introduzida no terminal, inteiro
# value_f - indica se a jogada é válida acima ou abaixo, isto é, se existe condições para aceitar a jogada, inteiro
#
# Valor de retorno:
# dados da jogada na vertical, struct
######################################################
*/
struct valoresV jogadaV(int board[][8], int line, char col, int color);

/*
######################################################
# play_vertical - Esta função coloca a peça da cor que está a ser jogada (parâmetro color) no tabuleiro e flanqueia verticalmente todas peças possíveis.
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# v - dados/valores da jogada na vertical, struct
# l - posição da linha no tabuleiro, inteiro
######################################################
*/
void play_vertical(int board[][8], int line, char col, int color, struct valoresV v);

/*
######################################################
# jogadaD - Esta função averigua se existe condições para se efetuar uma jogada na diagonal para a peça com a cor que está a ser jogada (parâmetro color).
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro
# exist_down_p - verifica se existe uma peça da mesma cor nesta direção "/" abaixo da jogada introduzida no terminal, inteiro
# exist_up_p - verifica se existe uma peça da mesma cor nesta direção "/" acima da jogada introduzida no terminal, inteiro
# diagonal_down_line - guarda a posição da linha no tabuleiro da peça que se encontra o mais próximo abaixo da jogada introduzida no terminal nesta direção "/", inteiro
# diagonal_down_col - guarda a posição da coluna no tabuleiro da peça que se encontra o mais próximo abaixo da jogada introduzida no terminal nesta direção "/", inteiro
# diagonal_up_line - guarda a posição da linha no tabuleiro da peça que se encontra o mais próximo acima da jogada introduzida no terminal nesta direção "/", inteiro
# diagonal_up_col - guarda a posição da coluna no tabuleiro da peça que se encontra o mais próximo acima da jogada introduzida no terminal nesta direção "/", inteiro
# value_d_p - indica se é possível flankear somente abaixo da jogada introduzida no terminal nesta direção "/", inteiro
# value_u_p - indica se é possível flankear somente acima da jogada introduzida no terminal nesta direção "/", inteiro
# exist_down_s - verifica se existe uma peça da mesma cor nesta direção "\" abaixo da jogada introduzida no terminal, inteiro
# exist_up_s - verifica se existe uma peça da mesma cor nesta direção "\" acima da jogada introduzida no terminal, inteiro
# diagonal_down_line2 - guarda a posição da linha no tabuleiro da peça que se encontra o mais próximo abaixo da jogada introduzida no terminal nesta direção "\", inteiro
# diagonal_down_col2 - guarda a posição da coluna no tabuleiro da peça que se encontra o mais próximo abaixo da jogada introduzida no terminal nesta direção "\", inteiro
# diagonal_up_line2 - guarda a posição da linha no tabuleiro da peça que se encontra o mais próximo acima da jogada introduzida no terminal nesta direção "\", inteiro
# diagonal_up_col2 - guarda a posição da coluna no tabuleiro da peça que se encontra o mais próximo acima da jogada introduzida no terminal nesta direção "\", inteiro
# value_d_s - indica se é possível flankear somente abaixo da jogada introduzida no terminal nesta direção "\", inteiro
# value_u_s - indica se é possível flankear somente acima da jogada introduzida no terminal nesta direção "\", inteiro
# value_f - indica se a jogada é válida acima ou abaixo nesta direção "/" ou "\", isto é, se existe condições para aceitar a jogada, inteiro
#
# Valor de retorno:
# dados da jogada na diagonal, struct
######################################################
*/
struct valoresD jogadaD(int board[][8], int line, char col, int color);

/*
######################################################
# play_diagonal - Esta função coloca a peça da cor que está a ser jogada (parâmetro color) no tabuleiro e flanqueia na diagonal todas peças possíveis.
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# v - dados/valores da jogada na diagonal, struct
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro
######################################################
*/
void play_diagonal(int board[][8], int line, char col, int color, struct valoresD v);

/*
######################################################
# play - Esta função coloca uma peça de cor (parâmetro color) na posição (line, col) e vira as peças do adversário de acordo com as regras indicadas na descrição do jogo...
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# h - estrutura que guarda todos os valores da jogada realizada na horizontal, struct
# v - estrutura que guarda todos os valores da jogada realizada na vertical, struct
# d - estrutura que guarda todos os valores da jogada realizada na diagonal, struct
# play - guarda o valor da veracidade da jogada introduzida no terminal, inteiro
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro
#
# Valor de retorno:
# veracidade da jogada introduzida no terminal, inteiro
######################################################
*/
int play(int board[][8], int line, char col, int color);

/*
######################################################
# score- Esta função mostra o resultado do jogo quando o mesmo acaba
# 
# Argumentos:
# board - tabuleiro, inteiro
# color - estrutura que guarda a cor do jogador e do computador, struct
# player - número de peças que o jogador possui no tabuleiro, inteiro
# cpu - número de peças que o computador possui no tabuleiro, inteiro
# black - número de peças pretas no tabuleiro, inteiro
# white - número de peças brancas no tabuleiro, inteiro
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro
######################################################
*/
void score(int board[][8],struct color color);

/*
######################################################
# player_color - Esta função atribui a cor ao jogador aleatoriamente
#
# Argumentos:
# c - estrutura que guarda as cores atribuidas ao jogador e ao computador, struct
# num - número gerado aleatoriamente, inteiro
#
# Valor de retorno:
# atribuição das cores para o jogador e para o computador, struct
######################################################
*/
struct color player_color();

/*
######################################################
# your_color - Esta função imprime a cor atribuída aleatoriamente ao jogador
#
# Argumentos:
# c - estrutura que guarda as cores atribuidas ao jogador e ao computador, struct
######################################################
*/
void your_color(struct color c);

/*
######################################################
# board_clone - Esta função vai copiar o tabuleiro principal antes de se efetuar uma jogada aceite, para um tabuleiro secundário
#
# Argumentos:
# b_p - tabuleiro principal, inteiro
# b_s - tabuleiro secundário, inteiro
######################################################
*/
void board_clone(int b_p[][8], int b_s[][8]);

/*
######################################################
# flanked- Esta função conta o número de peças viradas ao jogar numa certa linha e coluna
#
# Argumentos:
# board - tabuleiro, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro
# count - número de peças que foram viradas, inteiro
#
# Valor de retorno:
# número de peças que foram viradas, inteiro
######################################################
*/
int flanked(int board[][8], int board_s[][8], int line, char col, int color);

/*
######################################################
# count_flips_dir - Esta função conta quantas peças serão viradas, numa certa linha e coluna, e numa certa numa direção que é definida por delta_line e delta_col
#
# Argumentos:
# board_p - tabuleiro depois de se efetuar a jogada introduzida no terminal, inteiro
# board_s - tabuleiro antes de se eftuar a jogada introduzida no terminal, inteiro
# line - linha da jogada introduzida no terminal, inteiro
# col - coluna da jogada introduzida no terminal, char
# color - cor da peça que está a ser jogada, inteiro
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro
# count_f - número de peças que foram viradas, inteiro
#
# Valor de retorno:
# número de peças que foram viradas numa dada direção, inteiro
######################################################
*/
int count_flips_dir(int board_p[][8], int board_s[][8], int line, char col, int delta_line, int delta_col, int color);

/*
######################################################
# cor_a_jogar - Esta função indica a cor que vai jogar
#
# Argumentos:
# count - indica a cor que vai jogar, inteiro
#
# Valor de retorno:
# cor que vai jogar, inteiro
######################################################
*/
int cor_a_jogar(int count);

/*
######################################################
# jogadas_possiveis - Esta função retorna todas as jogadas possíveis num dado momento de jogo para uma certa cor (parâmetro color)
#
# Argumentos:
# board - tabuleiro, inteiro
# color - cor da peça que está a ser jogada, inteiro
# l - posição da linha no tabuleiro, inteiro
# c - posição da coluna no tabuleiro, inteiro
# h - estrutura que guarda todos os valores da jogada realizada na horizontal, struct
# v - estrutura que guarda todos os valores da jogada realizada na vertical, struct
# d - estrutura que guarda todos os valores da jogada realizada na diagonal, struct
# jp - estrutura que guarda a linha e a coluna de cada jogada possível, struct
# i - índice de cada jogada possível na estrutura jp, inteiro
#
# Valor de retorno:
# a linha e coluna de todas as jogadas possíveis, struct
######################################################
*/
struct jogadaP *jogadas_possiveis(int board[][8], int color);

/*
######################################################
# imprime_jp - Esta função mostra no terminal todas as jogadas possíveis de uma determinada cor (função que serviu para testar)
#
# Argumentos:
# j - estrutura que guarda a linha e a coluna de cada jogada possível, struct
# color - cor da peça que está a ser jogada, inteiro
######################################################
*/
void imprime_jp(struct jogadaP j[],int color);

/*
######################################################
# best_play - Esta função vai indicar qual é a melhor jogada a ser efetuada naquele momento do jogo
#
# Argumentos:
# board - tabuleiro, inteiro
# j - estrutura que guarda a linha e a coluna de cada jogada possível, struct
# color - cor da peça que está a ser jogada, inteiro
# bp - estrutura que guarda a linha e a coluna da melhor jogada, struct
# flanked_max - número máximo de peças viradas, inteiro
# i - índice de cada jogada possível na estrutura jp, inteiro
# board_clone_p - réplica do tabuleiro principal depois de se efetuar a jogada introduzida no terminal, inteiro
# board_clone_s - réplica do tabuleiro secundário antes de se efetuar a jogada introduzida no terminal, inteiro
# corners - estrutura que guarda a linha e a coluna da melhor jogada possível num canto, struct
# exists_corner - variável que indica se existe uma jogada possível num canto do tabuleiro, inteiro
# p - índice de cada jogada possível na estrutura corners, struct
# center - estrutura que guarda a linha e a coluna da melhor jogada no centro do tabuleiro "quadrado imaginário", struct
# exixts_center - variável que indica se existe uma jogada possível num "quadrado imaginário" no centro do tabuleiro (uma aresta do quadrado - 3C à 3F), inteiro
# d - índice de cada jogada possível na estrutura center, struct
#
# Valor de retorno:
# a linha e coluna da jogada que vira mais peças, struct
######################################################
*/
struct best best_play(int board[][8],struct jogadaP j[],int color);

/*
######################################################
# play_CPU - Esta função indica e efetua a jogada escolhida pelo computador no tabuleiro
#
# Argumentos:
# board - tabuleiro, inteiro
# bp - estrutura que guarda a linha e a coluna da melhor jogada (a que vira mais peças), struct
# color - cor da peça que está a ser jogada, inteiro
# play_cpu - efetua a jogada no tabuleiro, inteiro
######################################################
*/
void play_CPU(int board[][8], struct best bp, int color);

/*
######################################################
# end_game - Esta função indica quando o jogo está terminado
#
# Argumentos:
# board - tabuleiro, inteiro
# end - variável que indica o fim do jogo, inteiro
# jP_b - estrutura que guarda as jogadas possíveis para as peças brancas, struct
# jP_p - estrutura que guarda as jogadas possíveis para as peças pretas, struct
#
# Valor de retorno:
# o fim ou não do jogo, inteiro
######################################################
*/
int end_game(int board[][8]);

/*
######################################################
# char2int - Esta função converte um caractere para o seu respetivo inteiro
#
# Argumentos:
# letter - caracter(número) que representa a linha da jogada, char
# conversao - caracter(número) convertido para inteiro, inteiro
#
# Valor de retorno:
# número da linha, inteiro
######################################################
*/
int char2int(char letter);

/*
######################################################
# game_inFile - Esta função retira a informação de todas as jogadas que estão presentes no ficheiro
#
# Argumentos:
# filename - nome do ficheiro onde estão as jogadas, const char
# num_j - número de jogadas, inteiro
# i - indíce da jogada na estrutura, inteiro
# end_of_file - variável que indica o fim do ficheiro, inteiro
# ascii_0 - código ASCII do caracter da posição 0 da string linha, char
# ascii_1 - código ASCII do caracter da posição 1 da string linha, char
# jogadasF - estrutura que guarda as jogadas do ficheiro, struct
# f - ficheiro que está associado à estrutura FILE, FILE
######################################################
*/
struct jogadasFile *game_inFile(const char *filename);

/*
######################################################
# imprime - Esta função mostra no terminal todas as jogadas que foram passadas na leitura de um ficheiro (função que serviu para testar)
#
# Argumentos:
# jogadasF - estrutura que guarda as jogadas do ficheiro, struct
# i - indíce da jogada na estrutura, inteiro
#
# Valor de retorno:
# informação (linha e coluna) de todas as jogadas que foram passadas na leitura de um ficheiro, struct
######################################################
*/
void imprime(struct jogadasFile jf[]);

#endif