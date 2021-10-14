#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    int prime_number[168];
    int i,j,h,count,n,k,flag,carry;
    srand(time(NULL));
    count=0;
    for (j = 2; j < 1000; j++) {
	    flag=0;
	    carry=j;
	    for (i = 2; i <= carry/2; ++i) {
		 if (j%i == 0) {
			 flag=1;
	   	 break;
		 }
    	 }
   
   
	    if (flag == 0){
	        prime_number[count]=carry;
	        count=count+1; 
    	}
    }    
   
    printf("Numeros primos:\n ");
    for (h=1; h<21; h++){
    	printf("%d  ", prime_number[rand() % 168]);
	if (h==10){
		printf(" \n");
	}
    }

    printf(" \n");
        
}


