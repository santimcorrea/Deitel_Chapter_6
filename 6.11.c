#include <stdio.h>
#include <stdlib.h>

#define TAMANIO 10
/*
6.11
                        made by Santiago Martín Correa
*/

void bubbleSort( int array[], int tamanio);
void printArray( int array[], int tamanio );

int main(void)
{
        //static int array[ TAMANIO ] = { 12, 3, 24, 35, 68, 2, 7, 98, 25, 36 };
        static int array[ TAMANIO ] = { 3, 4, 5, 35, 68, 69, 70, 78, 85, 96 };

        bubbleSort( array, TAMANIO );

        printArray( array , TAMANIO);

        return 0;
}

void bubbleSort( int array[], int tamanio)
{
    for( int pasadas = 1; pasadas < tamanio; pasadas++ )
    {
        int intercambio = 0;
        // al poner tamanio - pasadas en vez de tamanio - i optimiza el bubble sort
        for( int i = 0; i < tamanio - pasadas ; i++ )
        {
            if( array[ i ] > array[ i + 1 ] )
            {
                int temp;
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                intercambio = 1;
            }
        // si no hubo ningun intercambio, salir del for loop ( no hacer mas pasadas, el array esta ordenado )
        }
        if ( intercambio == 0 )
        {
            break;
        }
    }

}

void printArray( int array[], int tamanio )
{
    printf("Array ordenado:\n%d", array[0] );

    for( int i = 1; i < tamanio; i++)
    {
        printf( "%4d", array[ i ]);
    }
}
