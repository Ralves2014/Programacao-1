#include<stdio.h>

int numalg(int n){
	int a=0;
	if(n/10==0){
    	return 1;
    }else{
    	a++;
    	return a+numalg(n/10);
    }
}

int main(){

    int f;
    f=numalg(1);

    printf("%d\n", f);
    return 0;

}