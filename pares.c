#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    int prime_number[168];
    int h,carry;
    int i=0;
    srand(time(NULL));
   

    printf("Numeros pares:\n ");
    for (h=1; h<21;){
  	carry= rand() % 1000;  	
	if (carry % 2 == 0){
		printf("%d ",carry);
		h++;
	}
    	if (h==11 & i==0 )
	{
	printf(" \n");
	i=1;
	}
    }

    printf(" \n");


}





