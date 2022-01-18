#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TIMES 36000
/*
6.19
                        made by Santiago Martín Correa
*/

int rollDices( void );

int main(void)
{
        static int arrayValor[11] = {};

        //A random seed
        srand( time(NULL) );

        // How many times I roll the dice
        for(int i = 0; i < TIMES; i++)
        {
                arrayValor[ rollDices() - 2 ]++;
        }

        // print the frequency of each value of dices
        for(int j = 0; j < 11; j++)
        {
                if( j < 8)
                    printf("The frequency of value %d in %d times is %7d (%d)\n", j+2, TIMES, arrayValor[j], j+2);
                else
                    printf("The frequency of value %d in %d times is %6d (%d)\n", j+2, TIMES, arrayValor[j], j+2);
        }
        return 0;
}

int rollDices( void )
{
        int dado1;
        int dado2;
        int sumaTemp;

        dado1= 1 + ( rand() % 6 );
        dado2= 1 + ( rand() % 6 );
        sumaTemp = dado1 + dado2;

        // printf( "el jugador tiro %d + %d = %d\n", dado1, dado2, sumaTemp);

        return sumaTemp;
}
