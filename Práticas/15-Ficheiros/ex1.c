#include <stdio.h>

int main(){
    
    FILE *f, *f2;

    f=fopen("original.txt","r");
    f2=fopen("copy.txt","w");

    int c=getc(f);
    printf("%d\n",c);
    while (c!=EOF)
    {
        putc(c,f2);
        c=getc(f);
    }
    
    fclose(f);
    fclose(f2);
    
    if (feof(f))
        printf("Reached the end of file.\n");
    else
        printf("\n Failure.");
    
    return 0;
    

}