#include <stdio.h>

struct aluno{
    char nome[100];
    long int number;
    long int nota;
};

int conta_alunos(FILE *myf){
    char line[100];
    int counter = 0;

    while(1){
        if(fgets(line, 100, myf) == NULL){
            break;
        }
        else if(line[0] != '\n'){
            counter += 1;
        }
    }

    return counter;
}

void escreve(struct aluno base[], struct aluno best, int sz, char locale[]){
	FILE *myf2;
	myf2 = fopen(locale, "w+");

	fprintf(myf2, "#Prova de %3d alunos\n", sz);
	fprintf(myf2, "#A melhor nota foi: %s %ld %ld\n",best.nome, best.number, best.nota);

	for(int i = 0; i<sz; i++){
		fprintf(myf2, "%ld = %ld\n", base[i].number, base[i].nota);
	}

	fclose(myf2);
}

struct aluno maior_nota(struct aluno base[], int sz){
	int position;
	int max = 0;

	for(int i = 0; i < sz; i++){
		if(base[i].nota > max){
			max = base[i].nota;
			position = i;
		}
	}
	printf("\nMelhor aluno: %s\n", base[position].nome);


	return base[position];
}

void processa_notas(FILE *myf, int sz){
    struct aluno base[sz];
    char locale[100];

    for(int i = 0; i < sz; i++){
        fscanf(myf , "%s %ld %ld", base[i].nome, &base[i].number, &base[i].nota);
        printf("%dº: %s %ld %ld\n",i, base[i].nome, base[i].number, base[i].nota);
    }

    struct aluno d = maior_nota(base, sz);

    printf("Escreva a localização das notas: ");
    scanf("%s", &locale);

    escreve(base, d, sz, locale);
}

int main(){
    int sz;

    FILE *myf;

    myf = fopen("/Users/joao/Desktop/notas.txt", "r");
    
    sz = conta_alunos(myf);
    
    printf("%d\n", sz);
    
    fclose(myf);
    
    FILE *myf2;

    myf2 = fopen("/Users/joao/Desktop/notas.txt", "r");

    struct aluno base[sz];
    processa_notas(myf2, sz);
    fclose(myf2);
    
    return 0;


}

