#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>


mqd_t pipe1;


int main(void){

    int h,carry,fd;
	char odd_number[100];
    int i=0;
	char destination[100];
	char odd_numbers[150]="Numeros impares: \n";
    srand(time(NULL));

    

    for (h=0; h<20;){
  		carry= rand() % 1000;  	

		if (carry % 2 == 0){}

		else{
				sprintf(odd_number, "%d ", carry);
				strcat(destination, odd_number);
				h++;
				if (h==10){strcat(destination, "\n");}
		}
    }
	
	strcat(odd_numbers, destination);
   
	strcat(odd_numbers, "\n\n");
    printf("%s", odd_numbers);

    pipe1 = mq_open("/cola",O_WRONLY | O_CREAT, 0664, NULL);
    mq_send(pipe1, odd_numbers, strlen(odd_numbers)+1,0);
	mq_close(pipe1);
    return 0;
}

