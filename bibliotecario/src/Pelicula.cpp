#include "Pelicula.h"
#include<iostream>
Pelicula::Pelicula(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int duracion, double puntaje) : Articulo(titulo, creador, genero, anioPublicacion, 7){
    if(duracion>0){
        this->duracion=duracion;
    }else{
        throw "No es posible construir pelicula";
    }
    if(puntaje>=0&&puntaje<=10){
        this->puntaje=puntaje;
    }else{
        throw "No es posible";
        }
}

Pelicula::~Pelicula()
{
    //dtor
}

void Pelicula::mostrarDetalles() {
    Articulo::mostrarDetalles();
    cout<<"Esta pelicula dura "<<this->getDuracion()<<" minutos"<<endl;
    cout<<"Su puntaje es "<<this->getPuntaje()<<endl;
}

string Pelicula::mostrarTipo(){
    return "Pelicula ";
}
