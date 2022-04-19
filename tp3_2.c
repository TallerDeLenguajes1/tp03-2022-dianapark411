#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarDatos(char *vec,int n);
void mostrarDatos(char *vec, int n);

int main(){
    int n;

    printf("\nEscriba la cantidad de nombres que desea ingresar: ");
    scanf("%i", &n);

    char *Nombre;
    char *vector[n];

    Nombre = (char *)malloc(100*sizeof(char));

    for (int i = 0; i < n; i++){
        fflush(stdin);
        printf("\nIngrese los nombres: ");
        gets(Nombre);
        fflush(stdin);

        vector[i]= (char *) malloc((strlen(Nombre+1)*sizeof(char)));
        strcpy(vector[i],Nombre);
    }
    printf("\nLos nombres ingresados son: \n");
    for (int i = 0; i < n; i++){
        puts(vector[i]);
    }

    free(Nombre);
    free(vector);
    return 0;
}
