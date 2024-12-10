#include "CD.h"
#include<iostream>
CD::CD(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int duracion) : Articulo(titulo, creador, genero, anioPublicacion, 5)
{
    if(duracion>0){
        this->duracion=duracion;
    }else{
        throw "No es posible construir pelicula";
    }
}

CD::~CD()
{
    //dtor
}
void CD::mostrarDetalles(){
    Articulo::mostrarDetalles();
    cout<<"Este CD dura "<<this->getDuracion()<<" minutos"<<endl;
}

string CD::mostrarTipo(){
    return "CD ";
}
