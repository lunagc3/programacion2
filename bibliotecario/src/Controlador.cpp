#include "Controlador.h"
#include<Libro.h>
#include<Pelicula.h>
#include<CD.h>
#include<iostream>
#include<algorithm>
using namespace std;
Controlador::Controlador(Biblioteca & b, Vista & v):modelo(b), vista(v)
{
    //ctor
}

Controlador::~Controlador()
{
    //dtor
}

void Controlador::agregarArticulo(){
    switch(this->vista.pedirTipo()){
    case 1:
        {
            Libro* libro = new Libro(this->vista.pedirTitulo(),this->vista.pedirCreador(),this->vista.pedirGenero(),this->vista.pedirAnio(),this->vista.pedirPaginas(),this->vista.pedirISBN());
            cout<<"Intentando agregar articulo "<<endl;
            try{
                this->modelo.bibliotecario->agregarArticulo(*libro);
            }catch(const char *p){
                cout<<*p<<endl;
            }
            break;
        }
    case 2:{
        Pelicula* peli = new Pelicula(this->vista.pedirTitulo(),this->vista.pedirCreador(),this->vista.pedirGenero(),this->vista.pedirAnio(), this->vista.pedirDuracion(), this->vista.pedirPuntaje());
        try{
            this->modelo.bibliotecario->agregarArticulo(*peli);
        }catch(const char *p){
            cout<<*p<<endl;
        }
        break;
    }
    case 3:{
        CD* cd = new CD(this->vista.pedirTitulo(),this->vista.pedirCreador(),this->vista.pedirGenero(),this->vista.pedirAnio(), this->vista.pedirDuracion());
        try{
            this->modelo.bibliotecario->agregarArticulo(*cd);
        }catch(const char *p){
            cout<<*p<<endl;
        }
        break;
    }
    }
}

void Controlador::eliminarArticulo(){
    string titulo = this->vista.pedirTitulo();
    bool articuloEncontrado =false;
    std::transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);

    for(auto it=this->modelo.bibliotecario->getArticulos().begin();it!=this->modelo.bibliotecario->getArticulos().end(); it++){
        string articuloTitulo = (*it)->getTitulo();
        std::transform(articuloTitulo.begin(), articuloTitulo.end(), articuloTitulo.begin(), ::tolower);

        titulo.erase(std::remove_if(titulo.begin(), titulo.end(),:: isspace), titulo.end());
        articuloTitulo.erase(std::remove_if(articuloTitulo.begin(), articuloTitulo.end(),:: isspace), articuloTitulo.end());

        if(articuloTitulo==titulo){
            try{
                this->modelo.bibliotecario->eliminarArticulo(**it);
                articuloEncontrado = true;
            }catch(const char *p){
                cout<<*p<<endl;
                }
            break;
        }
    }
    if(articuloEncontrado==false){
        cout<<"No hay un articulo en la biblioteca con ese nombre"<<endl;
    }
}

void Controlador::consultarArticulo(){
    string titulo = this->vista.pedirTitulo();
    std::transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
    bool articuloEncontrado = false;
    for(auto it=this->modelo.bibliotecario->getArticulos().begin();it!=this->modelo.bibliotecario->getArticulos().end(); it++){
        string articuloTitulo = (*it)->getTitulo();
        std::transform(articuloTitulo.begin(), articuloTitulo.end(), articuloTitulo.begin(), ::tolower);

        titulo.erase(std::remove_if(titulo.begin(), titulo.end(),:: isspace), titulo.end());
        articuloTitulo.erase(std::remove_if(articuloTitulo.begin(), articuloTitulo.end(),:: isspace), articuloTitulo.end());

        if(titulo==articuloTitulo){
         cout<<"Se encontro el articulo!"<<endl;
         try{
             this->modelo.bibliotecario->consultarArticulo(**it);
             articuloEncontrado=true;
         }catch(const char *p)
         {
             cout<<*p<<endl;
         }

         break;
        }
    }
    if(articuloEncontrado==false){
        cout<<"No se encontro el articulo"<<endl;
    }

}

void Controlador::prestarArticulo(){
    string titulo = this->vista.pedirTitulo();
    std::transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower);
    bool articuloPrestado = false;
    for(auto it=this->modelo.bibliotecario->getArticulos().begin();it!=this->modelo.bibliotecario->getArticulos().end(); it++){
        string articuloTitulo = (*it)->getTitulo();
        std::transform(articuloTitulo.begin(), articuloTitulo.end(), articuloTitulo.begin(), ::tolower);

        titulo.erase(std::remove_if(titulo.begin(), titulo.end(),:: isspace), titulo.end());
        articuloTitulo.erase(std::remove_if(articuloTitulo.begin(), articuloTitulo.end(),:: isspace), articuloTitulo.end());
        if(articuloTitulo==titulo){
                try{
                    this->modelo.bibliotecario->prestarArticulo(**it);
                    articuloPrestado=true;
                }catch(const char *p)
                {
                    cout<<*p<<endl;
                }
         break;
        }
    }
    if(articuloPrestado==false){
        cout<<"El articulo no pudo prestarse"<<endl;
    }
}

void Controlador::avanzarDia(){
    this->vista.avanzaDia();
    this->modelo.incrementarDia();
    cout<<"Pasaron ya "<<this->modelo.getDias()<<" dias"<<endl;
    this->modelo.bibliotecario->tiempoArticulo();
    if(this->modelo.getDias()==15){
        this->modelo.reiniciarTiempo();
        cout<<"Se eliminaran los articulos que no fueron prestados nunca en estos 15 dias"<<endl;
        this->modelo.bibliotecario->revisarArticulos();
    }
}

void Controlador::actualizarVista(){
    this->vista.mostrarArticulos(this->modelo.bibliotecario->getArticulos());
    if(this->modelo.getDias()==0)
    {
        this->vista.mostrarMenu();
    }
}

