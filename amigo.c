#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void executeThread(int id)
{

    int num1 = 0, num2, div1, div2, amigos;
    amigos = 0;
    int dato = 0;
    printf("Introduzca hasta donde se evaluaran los numeros amigos: ");
    scanf("%d", &dato);

    for (num1 = 2; num1 <= dato + 1; num1++)
    {
        div1 = 0;
        div2 = 0;

        int numd1 = 0;
        int numd2 = 0;

        for (int i = 1; i <= num1 / 2; i++)
        {
            if (num1 % i == 0)
            {
                div1 += i;
                numd1 = i;
                num2 = div1;
            }
        }

        for (int i = 1; i <= num2 / 2; i++)
        {

            if (num2 % i == 0)
            {
                numd2 = i;
                div2 += i;
            }
        }

        if (div1 == num2 && div2 == num1)
        {
            if (num1 <= num2)
            {
                amigos++;
                printf("\nLa pareja de amigos %d son: %d y %d \n ", amigos, num1, num2);
                printf("los divisores de %d son: ", num1);
                for (int p = 1; p < num1; p++)
                {
                    if (num1 % p == 0)
                    {
                        printf(" %d ", p);
                    }
                }
                printf("   que suman  %d", num2);
                if (num2 != num1)
                {
                    printf("\nLos divisores de %d son: ", num2);
                    for (int r = 1; r < num2; r++)
                    {
                        if (num2 % r == 0)
                        {
                            printf(" %d ", r);
                        }
                    }
                    printf("   que suman  %d", num1);
                }
                printf("\n\n");
            }
        }
    }
}

int main(void)
{
    pthread_t mihilo1;

    pthread_create(&mihilo1, NULL, &hilo1, NULL);
    pthread_join(mihilo1, NULL);

    return 0;
}
