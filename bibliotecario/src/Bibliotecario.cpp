#include "Bibliotecario.h"
#include<set>
#include<Libro.h>
#include<Pelicula.h>
#include<CD.h>
#include<iostream>
Bibliotecario::Bibliotecario()
{
    //articulos base para mi biblioteca
    Libro* l = new Libro("Harry Potter", "JK Rowling", "Fantasia", 2001, 320, "1234567890123");
    Libro* m = new Libro("El Manuscrito", "Pilar Andujar", "Romance", 2021, 1000, "0987654321321");
    Pelicula* p = new Pelicula("Percy Jackson", "Rick Riordan", "Fantasia", 2005, 120, 1.5);
    CD* c = new CD("1989", "Taylor Swift", "Pop", 2014, 90);
    this->agregarArticulo(*l);
    this->agregarArticulo(*m);
    this->agregarArticulo(*p);
    this->agregarArticulo(*c);
}

Bibliotecario::~Bibliotecario()
{
    for (auto articulo : articulos) {
        delete articulo;
    }
}

void Bibliotecario::agregarArticulo(Articulo & unArticulo){
    if(this->estaArticulo(unArticulo)==false){
        this->articulos.insert(& unArticulo);
        //cout << "Articulo agregado: " << unArticulo.getTitulo() << endl;
    }else
    {
        throw "error, este articulo ya fue agregado";
    }
}

void Bibliotecario::eliminarArticulo(Articulo & unArticulo){
    if(this->estaArticulo(unArticulo))
    {
        auto pos=this->articulos.find(& unArticulo);
        this->articulos.erase(pos);
    }
    else
    {
        throw "error, este articulo no esta, por lo que no se puede eliminar";
    }

}

bool Bibliotecario::estaArticulo(Articulo & unArticulo){
    auto pos=this->articulos.find(& unArticulo);
    if(pos==this->articulos.end())
    {
        //cout<<"el articulo no esta previamente en la biblio"<<endl;
        return false;
    }
    return true;
}

void Bibliotecario::prestarArticulo(Articulo & unArticulo){
    if(this->estaArticulo(unArticulo)&&unArticulo.getPrestado()==false){
        unArticulo.setPrestado(true);
        unArticulo.setCantidadPrestamos();
    }else{
        throw "no puede prestarse un articulo que no fue devuelto";
    }
}

void Bibliotecario::devolverArticulo(Articulo & unArticulo){
    if(this->estaArticulo(unArticulo)&&unArticulo.getPrestado()){
        unArticulo.setPrestado(false);
    }else{
        throw "no puede devolverse un articulo que no fue prestado";
    }
}

void Bibliotecario::tiempoArticulo(){
    for(auto it=this->articulos.begin();it!=this->articulos.end();it++){
        if((*it)->getPrestado()){
            if((*it)->getTiempoPrestar()>0){
                (*it)->setTiempoPrestar();
            }else{
                try{
                    this->devolverArticulo(**it);
                }catch(const char *p){
                    cout<<*p<<endl;
                }
            }
        }
    }
}

void Bibliotecario::consultarArticulo(Articulo & unArticulo){
    if(this->estaArticulo(unArticulo)){
        unArticulo.mostrarDetalles();
    }else{
        throw "No está ese articulo";
    }
}

unsigned int Bibliotecario::getArticulosTam(){
    this->articulos.size();
}

void Bibliotecario::revisarArticulos(){
    std::set <Articulo *> articulosEliminar;
    for(auto it=this->articulos.begin();it!=this->articulos.end();)
    {
        if((*it)->getCantidadPrestamos()==0){
            it = this->articulos.erase(it);
        }
        else
        {
            it++;
        }
    }
}

set<Articulo*>& Bibliotecario::getArticulos(){
    return this->articulos;
}
