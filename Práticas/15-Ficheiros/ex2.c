#include <stdio.h>

struct aluno
{
    char nome[20];
    long int num;
    long int nota;
};


int conta_alunos(FILE *f){

    int count=0, count_spaces=0;
    int c=getc(f);

    while (c!=EOF)
    {
        if (c==' ')
            count_spaces+=1;
        if (count_spaces==2){
            count+=1;
            count_spaces=0;
        }
        c=getc(f);
    }

    fclose(f);

    return count;
}

void processa_notas(FILE *f, struct aluno a[], int sz){

    f=fopen("notas.txt","r");

    for(int i = 0; i < sz; i++){
        fscanf(f , "%s %ld %ld", a[i].nome, &a[i].num, &a[i].nota);
        printf("%dº: %s %ld %ld\n",i+1, a[i].nome, a[i].num, a[i].nota);
    }

    fclose(f);
    
}

int maior_nota(int nota[],int sz){
    int maior=nota[0];
    int ind=0;

    for (int i = 1; i < sz; i++)
    {
        if (nota[i]>maior)
        {
            maior=nota[i];
            ind=i;

        }
        
    }

    return ind;
    
}

int main(){
    FILE *f;
    char filename[20];
    int func, maior_n;
    

    printf("Indique o nome do ficheiro: ");
    scanf("%s",filename);

    f=fopen(filename,"r");
    if (f==NULL)
        printf("Ficherio nao existe\n");
    
    func=conta_alunos(f);
    printf("Existem %d alunos\n", func);
    struct aluno a[func];
    
    processa_notas(f,a,func);

    int tabela[func];

    for (int i = 0; i < func; i++)
        tabela[i]=a[i].nota;
    
    maior_n=maior_nota(tabela,func);

    printf("A maior nota é do aluno %s, indice: %d\n", a[maior_n].nome, maior_n);
    
    return 0;
    
    
}