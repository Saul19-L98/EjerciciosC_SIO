#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mqueue.h>
#include <time.h>

mqd_t pipe1;

int main (){

    char prime_number[100];
	char destination[100];
	char prime_numbers[150]="Numeros Primos: \n";

    int all_prime[168];
    int i,j,h,count,flag;
    srand(time(NULL));
    count=0;

    for (j = 2; j < 1000; j++) {
	    flag=0;
	    for (i = 2; i <= j/2; ++i) {

		    if (j%i == 0) {flag=1; }
    	 }
   
	    if (flag == 0){
	        all_prime[count]=j;
	        count=count+1; 
    	}
    }    

    for (h=1; h<21; h++){

        sprintf(prime_number, "%d ", all_prime[rand() % 168]);
		strcat(destination, prime_number);
        
	    if (h==10){
		    strcat(destination, "\n");
	    }
    }

    strcat(prime_numbers, destination);
	strcat(prime_numbers, "\n\n");
    printf("%s", prime_numbers);

	pipe1 = mq_open("/cola",O_WRONLY | O_CREAT, 0664, NULL);
    mq_send(pipe1, prime_numbers, strlen(prime_numbers) + 1,0);
	mq_close(pipe1);
    return 0;
        
}


