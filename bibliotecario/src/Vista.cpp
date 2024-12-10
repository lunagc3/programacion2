#include "Vista.h"
#include<iostream>
#include<set>
#include<string>
#include<limits>
using namespace std;

Vista::Vista()
{
    //ctor
}

Vista::~Vista()
{
    //dtor
}

void Vista::mostrarMenu(){
    cout<<"*****BIENVENIDO A LA BIBLIOTECA*****"<<endl;
    cout<<"Que quieres hacer ahora?"<<endl;
    cout<<"OPCION 1. Agregar un articulo a la biblioteca"<<endl;
    cout<<"OPCION 2. Consultar un articulo de la biblioteca"<<endl;
    cout<<"OPCION 3. Eliminar un articulo de la biblioteca"<<endl;
    cout<<"OPCION 4. Prestar un articulo de la biblioteca"<<endl;
    cout<<"OPCION 5. Avanzar un dia"<<endl;
    cout<<"OPCION 6. Salir de la biblioteca"<<endl;
}
void Vista::mostrarArticulos(std::set <Articulo *>& articulos){
    string arts="";
    if(articulos.empty()){
        arts="No hay";
    }else{
        for(auto it=articulos.begin();it!=articulos.end();it++)
        {
            if(!(*it)->getPrestado())
            {
                arts += "Titulo: \"" + (*it)->getTitulo() + "\" - " + (*it)->mostrarTipo() + "\n";
            }
        }
    }
    cout<<"LOS ARTICULOS DISPONIBLES DE ESTA BIBLIOTECA SON: "<<endl<<arts;

}
void Vista::avanzaDia(){
    cout<<"Paso un dia en la biblioteca..."<<endl;
}
unsigned int Vista::pedirOpcion(){
    unsigned int opcion;
    cout<<"SELECCIONE UNA OPCION: "<<endl;
    std::cin.clear();
    //std::cin.ignore();
    cin>>opcion;
    return opcion;
}

string Vista::pedirTitulo()
{
    std::string titulo;
    std::cout << "Ingrese titulo: ";
    //std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    //cin.ignore();
    getline(std::cin, titulo);
    if(titulo.empty())
    {
        cout<<"Ingrese un titulo valido"<<endl;
        return this->pedirTitulo();
    }
    return titulo;
}
string Vista::pedirCreador(){
    std::string creador;
    std::cout << "Ingrese creador: ";
    //cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    //cin.ignore();
    getline(std::cin, creador);
    if(creador.empty())
    {
        cout<<"Ingrese un creador valido"<<endl;
        return this->pedirCreador();
    }
    return creador;
}
string Vista::pedirGenero(){
    std::string genero;
    std::cout << "Ingrese genero: ";
    //std::cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    //cin.ignore();
    getline(std::cin, genero);
    if(genero.empty())
    {
        cout<<"Ingrese un genero valido"<<endl;
        return this->pedirGenero();
    }
    return genero;
}
unsigned int Vista::pedirAnio(){
    unsigned int anio=0;
    cout<<"Ingrese anio publicacion: ";
    cin>>anio;
    if((std::cin.fail())||anio<1000||anio>2024){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, ingrese un año válido" << std::endl;
            return this->pedirAnio();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
   // cin.clear();
   //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    return anio;
}

unsigned int Vista::pedirDuracion(){
    unsigned int duracion=0;
    cout<<"Ingrese su duracion: ";

    //cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin>>duracion;
    if((std::cin.fail())||duracion==0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, ingrese duracion valida" << std::endl;
            return this->pedirDuracion();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return duracion;
}
double Vista::pedirPuntaje(){
    double puntaje=0.0;
    cout<<"Ingrese puntaje: ";
    //cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin>>puntaje;
    if((std::cin.fail())||puntaje<0||puntaje>10){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese puntaje valido" << std::endl;
            return this->pedirPuntaje();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return puntaje;
}
unsigned int Vista::pedirPaginas()
{
    unsigned int paginas=0;
    cout<<"Ingrese cant de paginas: ";
    //cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin>>paginas;
    if((std::cin.fail())||paginas==0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese cantidad valida" << std::endl;
            return this->pedirPaginas();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return paginas;
}
string Vista::pedirISBN(){
    std::string isbn="";
    std::cout << "Ingrese ISBN: ";
    //std::cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin, isbn);
    if(isbn.empty()||isbn.size()!=13)
    {
        cout<<"Ingrese un ISBN valido"<<endl;
        return this->pedirISBN();
    }
    return isbn;
}

unsigned int Vista::pedirTipo(){
    unsigned int opcion=0;
    cout<<"Si el articulo es un libro, PRESIONE 1."<<endl;
    cout<<"Si el articulo es una pelicula, PRESIONE 2."<<endl;
    cout<<"Si el articulo es un cd, PRESIONE 3."<<endl;
    //cin.clear();
    //
    cin>>opcion;
    if(opcion==1||opcion==2||opcion==3){
        return opcion;
    }else{
        cout<<"Esa opcion no es valida, seleccione una opcion. "<<endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return this->pedirTipo();
    }
}
