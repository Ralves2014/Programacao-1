#include <stdio.h>
int main() {
    FILE *f = fopen("new.txt", "r");
    int c = getc(f);
    while (c != EOF) {
        putchar(c);
        c = getc(f);
    }
    if (feof(f))
        printf("Reached the end of file.\n");
    else
        printf("Failure.\n");
    fclose(f);
    return 0;
}