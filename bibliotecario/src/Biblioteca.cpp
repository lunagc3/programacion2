#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    bibliotecario = new Bibliotecario();
}

Biblioteca::~Biblioteca()
{
    delete bibliotecario;
}

void Biblioteca::incrementarDia(){
    this->contadorDias++;
}
void Biblioteca::reiniciarTiempo(){
    this->contadorDias=0;
}

unsigned int Biblioteca::articulosDisponibles(){
    unsigned int cont=0;
    for(auto it=this->bibliotecario->getArticulos().begin();it!=this->bibliotecario->getArticulos().end();it++){
        if((*it)->getPrestado()==false){
            cont++;
        }
    }
    return cont;
}
