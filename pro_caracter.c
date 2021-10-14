#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <mqueue.h>

mqd_t pipe1;

int main (){
    int h,carry;
    int i=0;
	char caracteres[60];
    char caracter[150]="Caracteres: \n";  
    srand(time(NULL));
   
     for(int i=0; i<20; i++){         
         char letras = "abcdefghijklmnopqrstuvwxyz" [rand() % 26];  
            sprintf(caracteres,"%c ", letras);      
            strcat(caracter, caracteres);            
            if((i+1)%10 == 0){                
             strcat(caracter, "\n");               
            }        
        }    

	strcat(caracter, "\n\n");
    printf("%s", caracter);

	pipe1 = mq_open("/cola",O_WRONLY | O_CREAT, 0664, NULL);
    mq_send(pipe1, caracter, strlen(caracter) + 1,0);
    mq_close(pipe1);
    return 0;
}