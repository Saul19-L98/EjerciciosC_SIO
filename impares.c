#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int guard(int ret, char * err) {
          if (ret == -1) { perror(err); exit(1); }
            return ret;
	}

int main (){
    int h,carry,fd;
	char odd_number[100];
    int i=0;
	char destination[100];
	char odd_numbers[150]="Numeros impares: \n";
    srand(time(NULL));

    guard(fd = open("/home/williams/Siot2/fifodir/fifo",O_WRONLY), "No se pudo abrir FIFO");    

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
    printf("%s \n", odd_numbers);
	strcat(odd_numbers, "\n\n");

    guard(write(fd, odd_numbers, sizeof(odd_numbers)), "No se pudo escrbir el numero en el FIFO");
    close(fd);
	return 0;    
}

