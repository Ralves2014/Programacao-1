#include <stdio.h>

int main(){

	char locale1[100], locale2[100], line[100];

	printf("\nDir do ficheiro origem: ");
	scanf("%s", locale1);
	printf("\nDir do ficheiro cópia: ");
	scanf("%s", locale2);

	FILE *myf;
	myf = fopen(locale1, "r");

	FILE *myf2;
	myf2 = fopen(locale2, "w+");

	while(1){
		if(fgets(line, 100, myf) == NULL){
			break;
		}
		else{
			fprintf(myf2, "%s", line);
		}
	}

	fclose(myf);
	fclose(myf2);

	return 0;

}