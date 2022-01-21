#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 25

//prototY[0]pes
void printFloor( int array[][TAMANIO], int X[], int Y[]);
void moveFoward(int cantidad, int direction, int X[0], int Y[0], int piso[][TAMANIO], int write);
void printDirection( int direction);


int main(void)
{
        // crear piso
        int piso[TAMANIO][TAMANIO] = {0};

        // ingreso comandos
        int comando;
        // TOURTLE
        static int X[1] = {};
        static int Y[1] = {};
        static int write = 0;
        //initial direction to right
        static int direction = 2;
        /*
                    1=up
            4=left        2=right
                   3=down
        */


        while(comando != 9)
        {
            printf("Ingrese Comandos para la Tortuga:\n") ;
            scanf("%d", &comando);

            int cantidad = 0;

            if (comando > 50 && comando < 60)
            {
                cantidad = comando % 10;
                comando /= 10;
            }
            if ( comando > 509 && comando < 600 )
            {
                cantidad = comando % 100;
                comando /= 100;
            }

            switch (comando)
            {
                case 1: // no write
                        write = 0;
                        break;
                case 2: // write
                        write = 1;
                        break;
                case 3: // turn to the right
                        if(direction < 4)
                                direction++;
                        else
                                direction = 1;
                        printDirection(direction);
                        break;
                case 4: // turn to the left
                        if(direction > 1)
                                direction--;
                        else
                                direction = 4;
                        printDirection(direction);
                        break;
                case 5: // move foward and how manY[0] steps
                        moveFoward(cantidad, direction, X, Y, piso, write);
                        break;
                case 6: // print the floor
                        printFloor( piso, X, Y);
                        break;
                case 9: // exit
                        break;
                default:
                        printf("Ingrese un Comando Válido\n");
                        break;
            }
        } // fin del while

        // imprimir piso
        printf("\n Last Map of the Floor: \n");
        printFloor( piso , X, Y);
        // fin programa
        return 0;
}

void printFloor( int piso[][TAMANIO] , int X[], int Y[])
{
        for (size_t i = 0; i < TAMANIO; i++)
        {
                for (size_t j = 0; j < TAMANIO; j++)
                {
                    if ( piso[i][j] == 1)
                    {
                          (i==X[0] && j==Y[0]) ? printf("X") : printf("*");
                    }
                    else if (piso[i][j] == 0)
                    {
                        (i==X[0] && j==Y[0]) ? printf("X") : printf(" ");
                    }
                }
                printf("\n");
        }
}

void moveFoward(int cantidad, int direction, int X[], int Y[], int piso[][TAMANIO], int write)
{
    switch (direction)
    {
        case 1: // up
            if ( ( X[0] - cantidad < 0 ) )
            {
                printf("Excede el suelo, Ingrese un comando valido\n");
            }
            else
            {
                for( int i = 0; i < cantidad; i ++ )
                {
                    piso[ X[0] - i ][Y[0]] = write;
                }
                X[0] -= cantidad;
            }
            break;
        case 2: // right
            if ( ( Y[0] + cantidad > TAMANIO - 1 ) )
            {
                printf("Excede el suelo, Ingrese un comando valido\n");
            }
            else
            {
                for( int i = 0; i < cantidad; i ++ )
                {
                    piso[X[0]][ Y[0] + i ] = write;
                }
                Y[0] += cantidad;
            }
            break;
        case 3: // down
            if ( ( X[0] + cantidad > TAMANIO - 1 ) )
            {
                printf("Excede el suelo, Ingrese un comando valido\n");
            }
            else
            {
                for( int i = 0; i < cantidad; i ++ )
                {
                    piso[ X[0] + i ][Y[0]] = write;
                }
                X[0] += cantidad;
            }
            break;
        case 4: // left
            if ( ( Y[0] - cantidad < 0 ) )
            {
                printf("Excede el suelo, Ingrese un comando valido\n");
            }
            else
            {
                for( int i = 0; i < cantidad; i ++ )
                {
                    piso[X[0]][ Y[0] - i ] = write;
                }
                Y[0] -= cantidad;
            }
            break;
        default:
            break;
    }
}

void printDirection( int direction)
{
    switch (direction)
    {
    case 1:
        printf("NOW:   UP\n");
        break;
    case 2:
        printf("NOW:   RIGHT\n");
        break;
    case 3:
        printf("NOW:   DOWN\n");
        break;
    case 4:
        printf("NOW:   LEFT\n");
        break;

    default:
        break;
    }
}
