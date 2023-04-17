#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void cargaDeDatos(int *seleccionadoParaLaFuncion, int *seleccionadoParaLaFuncion2);
void cargaDeDato(int *seleccionadoParaLaFuncion);
int random();
void mayorDeLos3(int primerNumero, int segundoNumero, int tercerNumero, int *menor, int *mayor);
void menorCombinado(int numeroMayor, int *totalDeLaSumaDelMayor);
void tablaDeMultiplicar(int multiplo);
void suma(int primerNumero, int segundoNumero, int *totalCalculo);
void resta(int primerNumero, int segundoNumero, int *totalCalculo);
void multiplicacion(int primerNumero, int segundoNumero, int *totalCalculo);
void division(int primerNumero, int segundoNumero, int *totalCalculo);
void moduloDeUnNumero(int primerNumero, int *totalCalculo);

int main()
{
    srand(time(NULL));
    int primerNumeroMayor, segundoNumeroMayor, tercerNumeroMayor;
    int randNumber;
    char option;
    int mayorYMenorResultado;
    int menor, mayor;
    int resultadoDelMayor;
    int invalid = 0;
    int seleccionadoParaLaFuncion = 0;
    int seleccionadoParaLaFuncion2 = 0;
    int menorCombinadoEntero = 0;
    int totalDeLaSumaDelMayor = 0;
    int totalCalculo = 0;
    do{
        printf("\n********************\n");
        printf("\Bienvenido nuevamente al menu!:\n");
        printf("\n********************\n");
        printf("1- Devuelve un numero aleatorio del 0 al 100 \n");
        printf("2- Devuelve el mayor de los 3 \n");
        printf("3- Devuelve la multiplicacion de sus menores combinados\n");
        printf("4- Devuelve la tabla del numero\n");
        printf("5- Suma\n");
        printf("6- Resta\n");
        printf("7- Multiplicacion\n");
        printf("8- Division\n");
        printf("9- Modulo de un numero");
        printf("\n********************\n");
        printf("Tu eleccion: ");

        scanf("%i", &option);
        switch(option){
            case 1:
                randNumber = random();
                printf("%i", randNumber);
                break;
            case 2:
                printf("\nIntroduce el primer numero: ");
                scanf("%i", &primerNumeroMayor);

                printf("\nAhora el segundo: ");
                scanf("%i", &segundoNumeroMayor);

                printf("\nEl tercero: " );
                scanf("%i", &tercerNumeroMayor);

                mayorDeLos3(primerNumeroMayor, segundoNumeroMayor, tercerNumeroMayor, &menor, &mayor);
                printf("El mayor es: %i\n", mayor);
                printf("El menor es: %i\n", menor);
                break;
            case 3:
                cargaDeDato(&seleccionadoParaLaFuncion);
                menorCombinado(seleccionadoParaLaFuncion, &totalDeLaSumaDelMayor);
                printf("%i\n", totalDeLaSumaDelMayor);
                break;
            case 4:
                cargaDeDato(&seleccionadoParaLaFuncion);
                tablaDeMultiplicar(seleccionadoParaLaFuncion);
                break;
            case 5:
                cargaDeDatos(&seleccionadoParaLaFuncion, &seleccionadoParaLaFuncion2);
                suma(seleccionadoParaLaFuncion, seleccionadoParaLaFuncion2, &totalCalculo);
                printf("La suma total es: %i\n", totalCalculo);
                break;
            case 6:
                cargaDeDatos(&seleccionadoParaLaFuncion, &seleccionadoParaLaFuncion2);
                resta(seleccionadoParaLaFuncion, seleccionadoParaLaFuncion2, &totalCalculo);
                printf("La resta total es: %i\n", totalCalculo);
                break;
            case 7:
                cargaDeDatos(&seleccionadoParaLaFuncion, &seleccionadoParaLaFuncion2);
                multiplicacion(seleccionadoParaLaFuncion, seleccionadoParaLaFuncion2, &totalCalculo);
                printf("La multiplicacion total es: %i\n", totalCalculo);
                break;
            case 8:
                cargaDeDatos(&seleccionadoParaLaFuncion, &seleccionadoParaLaFuncion2);
                division(seleccionadoParaLaFuncion, seleccionadoParaLaFuncion2, &totalCalculo);
                printf("La division total es: %i\n", totalCalculo);
                break;
            case 9:
                cargaDeDato(&seleccionadoParaLaFuncion);
                moduloDeUnNumero(seleccionadoParaLaFuncion, &totalCalculo);
                printf("El modulo del numero es: %i", totalCalculo);
                break;
            default:
                printf("\n\nLa tecla que presionanste no es valida. Por favor, intenta de nuevo\n\n");
                printf("\nQuieres seguir ejecutando? Presiona 0 para salir.\n");
                break;
        }

        printf("\n\nContinuar? (y/n): \n\n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while(option != 'n');
        return 0;
}
void cargaDeDato(int *seleccionadoParaLaFuncion){
    printf("Introduce el unico numero\n");
    scanf("%i", seleccionadoParaLaFuncion);
}
// Ejercicio 9
void cargaDeDatos(int *seleccionadoParaLaFuncion, int *seleccionadoParaLaFuncion2){
    printf("Introduce el primer numero\n");
    scanf("%i", seleccionadoParaLaFuncion);
    printf("Ahora, el segundo\n");
    scanf("%i", seleccionadoParaLaFuncion2);
}

int random(){
    int random_number = rand()%101;
    return random_number;
}
void mayorDeLos3(int primerNumero, int segundoNumero, int tercerNumero, int *menor, int *mayor){
    *mayor = primerNumero;
    *menor = primerNumero;

    if(segundoNumero > *mayor ){
        *mayor = segundoNumero;
    }
    else{
        *menor = segundoNumero;
    }
    if(tercerNumero > *mayor){
        *mayor = tercerNumero;
    }
    else if(tercerNumero < *menor){
        *menor = tercerNumero;
    }

}
void menorCombinado(int numeroMayor, int *totalDeLaSumaDelMayor){
    int total = 0;
    *totalDeLaSumaDelMayor = 0;
    for(int i = 1; i < numeroMayor; i++){
        total += i;
    }
    *totalDeLaSumaDelMayor = total;
}
void tablaDeMultiplicar(int multiplo){
    int tmp;
    for(int i = 0; i <= 10; i++){
        tmp = multiplo * i;
        printf("%i * %i = %i\n", multiplo, i, tmp);
    }
}
void suma(int primerNumero, int segundoNumero, int *totalCalculo)
{
    *totalCalculo = primerNumero + segundoNumero;
}
void resta(int primerNumero, int segundoNumero, int *totalCalculo)
{
    *totalCalculo = primerNumero - segundoNumero;
}
void multiplicacion(int primerNumero, int segundoNumero, int *totalCalculo)
{
    *totalCalculo = primerNumero * segundoNumero;
}
void division(int primerNumero, int segundoNumero, int *totalCalculo)
{
    *totalCalculo = primerNumero / segundoNumero;
}
void moduloDeUnNumero(int primerNumero, int *totalCalculo){
    *totalCalculo = primerNumero*(-1);
}
