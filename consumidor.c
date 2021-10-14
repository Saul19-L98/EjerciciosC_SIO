#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define BUF_SIZE 8192

mqd_t pipe1;
char things[BUF_SIZE];
int bytes;

int main (void)
{   
    int i;

    for(i=1; i<=4; i++){
        pipe1 =  mq_open("/cola", O_RDONLY);
        bytes= mq_receive(pipe1, things, BUF_SIZE, NULL);
        printf("%s", things);
    }
    mq_close(pipe1);
    return 0;
}



