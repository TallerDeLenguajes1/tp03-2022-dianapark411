#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarDatos(char *vec,int n);
void mostrarDatos(char *vec, int n);

int main(){
    int n=5;
    char *Nombre;
    char *vector[n];
    Nombre = (char *)malloc(100*sizeof(char));

    for (int i = 0; i < n; i++){
        printf("Ingrese los nombres: ");
        gets(Nombre);

        vector[i]= (char *) malloc((strlen(Nombre+1)*sizeof(char)));
        strcpy(vector[i],Nombre);
    }
    printf("Los nombres ingresados son: ");
    for (int i = 0; i < n; i++){
        puts(vector[i]);
    }

    free(Nombre);
    free(vector);
    return 0;
}
