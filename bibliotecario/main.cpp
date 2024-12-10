
//#include <tau/tau.h>

#include <iostream>
#include<Articulo.h>
#include<Libro.h>
#include<Pelicula.h>
#include<Biblioteca.h>
#include<Bibliotecario.h>
#include<CD.h>
#include<Controlador.h>
#include<Vista.h>
using namespace std;

int main(){
    Biblioteca biblioteca;
    Vista vista;
    Controlador controlador(biblioteca, vista);
    while(true){
        controlador.actualizarVista();
        unsigned int opcion = vista.pedirOpcion();
        switch(opcion){
        case 1:
            controlador.agregarArticulo();
            break;
        case 2:
            controlador.consultarArticulo();
            break;
        case 3:
            controlador.eliminarArticulo();
            break;
        case 4:
            controlador.prestarArticulo();
            break;
        case 5:
            controlador.avanzarDia();
            break;
        case 6:
            cout<<"Saliendo del programa. Adios!"<<endl;
            return 0;
            break;
        default:
            cout<<"Opcion invalida, vuelva a intentarlo"<<endl;
        }
    }
}



