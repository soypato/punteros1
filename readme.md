# P230404 → Diseño de software, punteros

por **Patricio Tubio** ([@soypato](http://soypato.github.io)) 


# Punteros

Un puntero es una variable que apunta a la dirección de otra, para modificar esta última.

Es, tener la posibilidad de trabajar sobre la originalidad de la variable que le vamos a mencionar. Si, vamos a trabajar con dirección de memoria.

Todo lo que modifiquemos en puntero teniendo el asterisco, modificará el valor de lo que se encuentre ubicado en la dirección de memoria de la variable.

Anteriormente, si “copiábamos” una variable, justamente trabajamos sobre una copia. Ahora, vamos a comenzar a trabajar sobre la variable original.

## Sobre asterisco (*)

El * es el símbolo que nos permite declarar que una variable ahora es un puntero.

## Sobre ampersands (&)

El **`&`** sirve para indicar a qué dirección de memoria de una variable tengo que apuntar.

## Ejemplo

```c
int main{
	int numero = 7;
	int *puntero = &numero;
	*puntero = &numero;
}
```

En el ejemplo, tenemos una variable ‘numero’ que vale 7, un puntero ‘puntero’ que apunta a la dirección de memoria de ‘numero’.

De modo que si hacemos ****************`printf()`**************** de puntero nos dará, en este caso, la dirección en memoria de número. Si modificamos este puntero, modificará ‘numero’.

## En funciones

Podemos pedir en los parámetros, que en vez de pasarnos una copia de la pila (sin asterisco *), nos pase la dirección de memoria (con asterisco *).

Esto se debe a que una característica de las funciones es que el alcance de la misma es regional: *“lo que pasa en la función, queda en la función”.*

```c
Pila cargarPilaSinRetorno(Pila A){} // por copia.
Pila cargarPilaSinRetorno(*Pila A){} // por puntero - directo.
```

### Pasaje de parámetros

Cuando pasamos parámetros, hasta ahora, la función trabajaba sobre una copia de la pila original, no sobre esta.

Con punteros, si quiero modificar una variable, en vez de modificar una copia, con esta utilidad nos permitimos ir a la dirección de memoria donde está.

> Si quiero modificar una puerta, no me pueden pasar una copia de esta, sino que una dirección de memoria en donde está ubicada para modificarla, trabajar la original.
> 

## Gráfico de punteros y referencias

![Untitled](https://file.notion.so/f/s/5a8dbb1e-f01e-4bcb-8951-f9e9b18fdfb0/Untitled.png?id=87424627-b70b-4308-8411-64201df2fc23&table=block&spaceId=94a9b483-60d7-451d-8901-06740bb5bde2&expirationTimestamp=1681787859656&signature=IFHDxAkhRmHYUVG3OVaQ0VEBFoncye2otPsZS0QWB-A&downloadName=Untitled.png)

![Untitled](https://file.notion.so/f/s/d657beb1-58fb-4a40-a750-7247fd557fac/Untitled.png?id=c02f4c5c-8b40-4e6f-917a-d983ac7af15e&table=block&spaceId=94a9b483-60d7-451d-8901-06740bb5bde2&expirationTimestamp=1681787892832&signature=-z9qecn251xo4DroKS9IbAPd4g6tGskftkwuNE8rdZ8&downloadName=Untitled.png)

## Ejemplo de función con punteros

Acá tenemos una función que lo que realiza es, calcular el menor y el mayor de cada serie de números:

```c
#include <stdio.h>
#include <stdlib.h>
void mayorDeLos3(int primerNumero, int segundoNumero, int tercerNumero, int *menor, int *mayor);
int main(){
			int primerNumeroMayor, segundoNumeroMayor, tercerNumeroMayor;
			int menor, mayor;
      printf("\nIntroduce el primer numero: ");
      scanf("%i", &primerNumeroMayor);

      printf("\nAhora el segundo: ");
      scanf("%i", &segundoNumeroMayor);

      printf("\nEl tercero: " );
      scanf("%i", &tercerNumeroMayor);

      mayorYMenorResultado = mayorDeLos3(primerNumeroMayor, segundoNumeroMayor, tercerNumeroMayor, &menor, &mayor);
      printf("El mayor es: %i\n", mayor);
      printf("El menor es: %i\n", menor);
      break;
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
```

- Se declaran las variables normalmente;
- Las invocamos usando & para decirles que acceda a la dirección de memoria;
- En la escritura e invocación de la función, se define nuevamente el tipo de dato (porque va a ir dentro del bloque de esta) posterior de un * para que acceda a la dirección de memoria de la variable que le invocamos anteriormente;
- El tratamiento dentro del bloque de la función es con *;
- void porque no retorna, cambia el valor de la variable del main.

*Nota: cuando se usan punteros dentro de una función, si esta requiere la toma de datos vía *scanf()*, no se requiere ampersand &.`*

```c
main(){
	int seleccionadoParaLaFuncion;
	cargaDeDato(&seleccionadoParaLaFuncion);
}
void cargaDeDato(int *seleccionadoParaLaFuncion){
    printf("Introduce el unico numero\n");
    scanf("%i", seleccionadoParaLaFuncion);
}
```