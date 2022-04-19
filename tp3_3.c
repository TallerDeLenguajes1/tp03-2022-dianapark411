#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
};
typedef struct Producto Producto;

struct Cliente{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
};
typedef struct Cliente Cliente;


char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
void cargarDatosClientes(Cliente *Clientes, int cantClientes);
void mostrarDatosClientes(Cliente *Clientes, int cantClientes);


int main(){
    
    int cantClientes;

    printf("\nIngrese la cantidad de clientes:");
    do{
        scanf("%i", &cantClientes);
    } while (cantClientes<1 || cantClientes>5);

    Cliente *Clientes;
    Clientes = malloc(cantClientes*sizeof(Cliente));

    cargarDatosClientes(Clientes, cantClientes);

    free(Clientes->Productos);
    free(Clientes);
}

void cargarDatosClientes(Cliente *Clientes, int cantClientes){

    int indice;
    char *buffer;
    buffer = (char *)malloc(50*sizeof(char));

    for (int i = 0; i < cantClientes; i++){

        printf("\nCARGAR DATOS DEL CLIENTE %i: ", i);
        
        Clientes->ClienteID = i;

        Clientes->NombreCliente = (char*)malloc((strlen(buffer+1)*sizeof(char)));
        printf("\nIngrese el nombre del cliente: ");
        fflush(stdin);
        gets(Clientes->NombreCliente);    
        fflush(stdin);

        srand((int)time(NULL));
        Clientes->CantidadProductosAPedir = rand () % 5 + 1;

        Clientes->Productos = malloc(Clientes->CantidadProductosAPedir*sizeof(Producto));
        for (int j = 0; j < (Clientes->CantidadProductosAPedir); j++){
            
            printf("\nCARGAR DATOS DEL PRODUCTO %i: ", i);

            Clientes->Productos->ProductoID= j;
            fflush(stdin);
            do{
                printf("\nIngrese la cantidad (entre 1 y 10): ");
                scanf("%i", &Clientes->Productos->Cantidad);
            } while (Clientes->Productos->Cantidad < 1 || Clientes->Productos->Cantidad>10);
            
            do{
                printf("\nIngrese el tipo del producto(0 para Galletas, 1 para snack, 3 para Cigarrillos, 4 para Caramelos, 5 para Bebidas): ");
                scanf("%i", &indice);
            } while (indice < 0 || indice>5);
            
            Clientes->Productos->TipoProducto = TiposProductos[indice];


            do{
                printf("\nEl precio por unidad (entre 10 y 100): ");
                scanf("%f", &Clientes->Productos->PrecioUnitario)
                ;
            } while (Clientes->Productos->PrecioUnitario < 10 || Clientes->Productos->PrecioUnitario>100);

            Clientes->Productos ++;
        }
        Clientes ++;
    }
    
    free(buffer); //  Elimino lo que reserve en esta funcion 
}


void mostrarDatosClientes(Cliente *Clientes, int cantClientes){

}