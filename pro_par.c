#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

mqd_t pipe1;

int main (){
    int h,carry;
    int i=0;
	char even_number[100];
	char destination[100];
	char even_numbers[150]="Numeros pares: \n";
    srand(time(NULL));
   
    for (h=1; h<21;){
  		carry= rand() % 1000;  	
			if (carry % 2 == 0){
				sprintf(even_number, "%d ", carry);
				strcat(destination, even_number);
				h++;
				if (h==11){strcat(destination, "\n");}
			}
    }
	
	strcat(even_numbers, destination);
	strcat(even_numbers, "\n\n");
    printf("%s", even_numbers);

	pipe1 = mq_open("/cola",O_WRONLY | O_CREAT, 0664, NULL);
    mq_send(pipe1, even_numbers, strlen(even_numbers) + 1,0);
	mq_close(pipe1);
    return 0;
}


