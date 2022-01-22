#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 1000
/*
6.30
                        made by Santiago Martín Correa
*/

int main(void)
{
        int cantidad = 0;
        int numeros[ TAMANIO + 1 ] = {};
        // fill with 1 the array
        for ( int i = 1; i <= TAMANIO; i++)
        {
                numeros[i] = 1;
        }
        // formula to cousin numbers
        for( int i = 2; i <= TAMANIO; i++ )
        {
                int total;
                for ( int w = 2; w <= TAMANIO; w++)
                {
                        total = i * w;
                        if( total > TAMANIO)
                                break;
                        numeros[total] = 0;
                }

        }
        // print array
        for( int i = 1; i < TAMANIO; i++)
        {
                if( numeros[i] == 1)
                {
                    printf("%d es un numero primo\n", i);
                    cantidad++;
                }


        }

        printf("\n\nDel 1 al %d hay %d numeros primos\n", TAMANIO, cantidad);
        return 0;
}

