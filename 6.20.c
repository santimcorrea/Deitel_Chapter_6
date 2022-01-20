#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD_JUEGOS 1000
/*
6.20
        made by Santiago Martín Correa
*/

enum status { CONTINUA, GANA, PIERDE};

int rollDices( void );
int play( int cantidadTiros[] );

int main(void)
{       
        //initialize variables
        int arrayGanador[21] = {};
        int arrayPerdedor[21] = {};
        int cantidadGano = 0;
        int cantidadPerdio = 0;
        float sumaTotaldeTiros = 0;
        int cantidadTiros[1] = { 1 };

        srand( time(NULL) );

        // play games
        for ( int i = 0; i < CANTIDAD_JUEGOS; i++)
        {
                int juego;
                cantidadTiros[0] = 1;

                juego = play( cantidadTiros );

                // how many times roll the dices?
                if( cantidadTiros[0] < 21)
                {       
                        // if win
                        if( juego == 1 )
                        {
                                arrayGanador[ cantidadTiros[0] - 1 ]++;
                                cantidadGano++;
                        }
                        else    // if lost
                        {
                                arrayPerdedor[ cantidadTiros[0] - 1 ]++;
                                cantidadPerdio++;
                        }
                }
                else    // if play more than 20 games
                {
                        if( juego == 1 )
                        {
                                arrayGanador[ 20 ]++;
                                cantidadGano++;
                        }
                        else
                        {
                                arrayPerdedor[ 20 ]++;
                                cantidadPerdio++;
                        }
                }

                // count how many times roll the dices to then take the average
                sumaTotaldeTiros += cantidadTiros[0];
        }

        // finish the program printing the stadistics
        printf("From 1000 games of craps, computer win %d times and lost %d times.\n", cantidadGano, cantidadPerdio);

        printf("\n#Roll \t    Win \t  Lost\n");
        for( int i = 0; i < 20 ; i++)
        {
                printf("%4d\t %6d\t \t%5d\n", i+1, arrayGanador[ i ], arrayPerdedor[ i ]);
        }
        printf(" +21\t %6d\t \t%5d\n", arrayGanador[ 20 ], arrayPerdedor[ 20 ]);

        printf("\nThe average of Rolls per game are: %.2f\n", ( sumaTotaldeTiros / CANTIDAD_JUEGOS) );
        return 0;
}


// rollDices functions that returns a random sum of the 2 dices
int rollDices( void )
{
        int dado1;
        int dado2;
        int sumaTemp;

        dado1= 1 + ( rand() % 6 );
        dado2= 1 + ( rand() % 6 );
        sumaTemp = dado1 + dado2;

        return sumaTemp;
}


// play function. It has inside the terms of the game, and it use the rollDices function
int play( int cantidadTiros[] )
{
        int suma;
        int miPunto;

        enum status estatusJuego;

        // srand( time(NULL) );
        suma = rollDices();

        // which status takes if wins, tie or lose
        switch( suma )
        {
                // win
                case 7:
                case 11:
                        estatusJuego = GANA;
                        break;
                // lose
                case 2:
                case 3:
                case 12:
                        estatusJuego = PIERDE;
                        break;
                // not win or lose
                default:
                        estatusJuego = CONTINUA;
                        miPunto = suma;
                        //printf( "Su punto es %d\n", miPunto );
                        break;
        }

        while( estatusJuego == CONTINUA ) // looking for the number
        {
                cantidadTiros[0]++;
                suma = rollDices();

                if( suma == miPunto )
                {
                        estatusJuego = GANA;
                }
                else
                {
                        if ( suma == 7 )
                        {
                                estatusJuego = PIERDE;
                        }
                }
        }

        // return if player win or lost
        if ( estatusJuego == GANA )
                return 1;
        else
                return 0;
}
