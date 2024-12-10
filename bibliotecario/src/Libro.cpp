#include "Libro.h"
#include<iostream>
Libro::Libro(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int cantPaginas, string isbn) : Articulo(titulo, creador, genero, anioPublicacion, 10)
{
    if(cantPaginas>0){
        this->cantPaginas=cantPaginas;
    }else{
    throw "Error construyendo objeto";}
    if(isbn.length()==13){
        this->isbn = isbn;
    }else{
    throw "Error construyendo objeto";}
}


Libro::~Libro()
{
    //dtor
}

void Libro::mostrarDetalles(){
    Articulo::mostrarDetalles();
    cout<<"Este libro tiene "<<this->getCantPaginas()<<" paginas"<<endl;
    cout<<"Su codigo ISBN es "<<this->getISBN()<<endl;
}

string Libro::mostrarTipo(){
    return "Libro ";
}
