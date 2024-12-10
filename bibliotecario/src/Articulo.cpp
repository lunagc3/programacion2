#include "Articulo.h"
using namespace std;
#include<string>
#include<iostream>

Articulo::Articulo(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int tiempoPrestar):titulo(titulo), creador(creador), genero(genero), tiempoPrestar(tiempoPrestar){
     if(anioPublicacion>1000&&anioPublicacion<=2024){
        this->anioPublicacion=anioPublicacion;
     }else{
     throw "Error construyendo articulo";
     }

}

Articulo::~Articulo()
{
    //dtor
}

string Articulo::getTitulo(){
    return this->titulo;
}
string Articulo::getGenero(){
    return this->genero;
}
string Articulo::getCreador(){
    return this->creador;
}
//string Articulo::getVencePrestamo(){
//    return this->vencePrestamo;
//}
unsigned int Articulo::getanioPublicacion(){
    return this->anioPublicacion;
}
unsigned int Articulo::getCantidadPrestamos(){
    return this->cantPrestamos;
}
unsigned int Articulo::getTiempoPrestar(){
    return this->tiempoPrestar;
}
bool Articulo::getPrestado(){
    return this->prestado;
}

void Articulo::setPrestado(bool prestado){
    this->prestado = prestado;
}
void Articulo::mostrarDetalles(){
    cout<<"A continuacion, los detalles del articulo"<<endl;
    cout<<"Titulo: "<<this->getTitulo()<<endl;
    cout<<"Genero: "<<this->getGenero()<<endl;
    cout<<"Año de publicacion: "<<this->getanioPublicacion()<<endl;
    cout<<"Creador: "<<this->getCreador()<<endl;
    cout<<"Esta disponible? ";
    if(this->getPrestado()){
        cout<<"No"<<endl;
    }else{
        cout<<"Si"<<endl;
    }

}

void Articulo::setTiempoPrestar(){
    this->tiempoPrestar--;
}
void Articulo::setCantidadPrestamos(){
    this->cantPrestamos++;
}
string Articulo::mostrarTipo(){}
//void Articulo::setTiempoPrestar(unsigned int tiempoPrestar){
  //  if(tiempoPrestar>=5&&tiempoPrestar<=10){
    //    this->tiempoPrestar = tiempoPrestar;
   // }else{
    //    throw "error, tiempo prestado por fuera de los parametros de la biblioteca";
   // }
//}
//void Articulo::setVencePrestamo(string vencePrestamo){
    //ver fecha excepciones
//    this->vencePrestamo;
//}

