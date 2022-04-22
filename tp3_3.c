#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Product{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
};
typedef struct Product Producto;

struct Cliente{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
};
typedef struct Cliente Cliente;


char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
void cargarDatosClientes(Cliente *Client, int cantClientes);
void mostrarProducto(Producto *pProducto);
void mostrarDatosClientes(Cliente *Client, int cantClientes);
float costoProducto(Producto *pProducto);


int main(){
    
    int cantClientes;

    printf("\nIngrese la cantidad de clientes:");
    do{
        scanf("%i", &cantClientes);
    } while (cantClientes<1 || cantClientes>5);

    Cliente *Clientes;
    Clientes = (Cliente *) malloc(cantClientes*sizeof(Cliente));
 
    cargarDatosClientes(Clientes, cantClientes);
    mostrarDatosClientes(Clientes, cantClientes);

    free(Clientes->NombreCliente);
    free(Clientes->Productos);
    free(Clientes);
}

void cargarDatosClientes(Cliente *Client, int cantClientes){

    int indice;
    char *buffer;
    buffer = (char *)malloc(50*sizeof(char));

    for (int i = 0; i < cantClientes; i++){

        printf("\nCARGAR DATOS DEL CLIENTE %i: ", i+1);
        
        Client[i].ClienteID = i;
        
        printf("\nIngrese el nombre del cliente: ");
        scanf(" %s", buffer);
        int cantCaracteres = strlen(buffer+1);
        Client[i].NombreCliente = (char*)malloc(( cantCaracteres *sizeof(char)));
        strcpy(Client[i].NombreCliente, buffer);   

        srand((int)time(NULL));
        Client[i].CantidadProductosAPedir = 2; //rand () % 5 + 1

        //Producto * pProducto = Client->Productos = (Producto*)malloc(Client->CantidadProductosAPedir*sizeof(Producto));
        Client[i].Productos = (Producto*)malloc(Client[i].CantidadProductosAPedir*sizeof(Producto));

        for (int j = 0; j < Client[i].CantidadProductosAPedir; j++){
            
            printf("\n     CARGAR DATOS DEL PRODUCTO %i: ", j+1);

            //DIFERENTES FORMAS DE MOVERSE
            //(Client[i].Productos + j)->Cantidad = 0;
            //pProducto[j].ProductoID= j;

            Client[i].Productos[j].ProductoID = j;

            do{
                printf("\n     Ingrese la cantidad (entre 1 y 10): ");
                scanf("%i", &Client[i].Productos[j].Cantidad);
            } while (Client[i].Productos[j].Cantidad < 1 || Client[i].Productos[j].Cantidad>10);

            do{
                printf("\n     Ingrese el tipo del producto (0 para Galletas, 1 para snack, 2 para Cigarrillos, 3 para Caramelos, 4 para Bebidas): ");
                scanf("%i", &indice);
            } while (indice < 0 || indice>5);

            Client[i].Productos[j].TipoProducto = TiposProductos[indice];
            
            do{
                printf("\n     El precio por unidad (entre 10 y 100): ");
                scanf("%f", &Client[i].Productos[j].PrecioUnitario);
            } while (Client[i].Productos[j].PrecioUnitario < 10 || Client[i].Productos[j].PrecioUnitario>100);

        }
        //Client ++; SI PODRIA USAR ESTA FORMA PARA MOVERME, CUANDO TENGO UNA ESTRUCTURA DENTRO DE OTRA NO CONVIENE
    }
    free(buffer); 
}


void mostrarDatosClientes(Cliente *Client, int cantClientes){
    float costoProd, costoTotal = 0;

    for (int i = 0; i < cantClientes; i++){

        printf("\n\n--------- DATOS DEL CLIENTE [%i] ---------- ", i+1);

        printf("\nID del cliente: %i", Client[i].ClienteID);
        printf("\nNombre del cliente:");
        puts(Client[i].NombreCliente);
        printf("Cantidad de productos a pedir: %i", Client[i].CantidadProductosAPedir);

        Producto * pProducto =  Client[i].Productos;
        for (int j=0; j < Client[i].CantidadProductosAPedir; j++){
            
            printf("\n       ---- DATOS DEL PRODUCTO [%i] ---- ", j+1);
            mostrarProducto(pProducto);
            costoProd = costoProducto(pProducto);
            costoTotal = costoTotal + costoProd;
            pProducto++;
        }
        printf("\nTotal a pagar por todos los productos: %f\n", costoTotal);
    }  
}

void mostrarProducto(Producto *pProducto){
            
    printf("\n       ID del producto: %i", pProducto->ProductoID);
    printf("\n       Cantidad: %i", pProducto->Cantidad);
    printf("\n       Tipo: %s", pProducto->TipoProducto);
    //puts(Client->Productos->TipoProducto);
    printf("\n       Precio por unidad: %f", pProducto->PrecioUnitario);
}

float costoProducto(Producto *pProducto){
    int costo = 0;
    costo = pProducto->Cantidad * pProducto->PrecioUnitario;
    return costo;
}