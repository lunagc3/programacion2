#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include<Bibliotecario.h>

class Biblioteca
{
    public:
        Biblioteca();
        virtual ~Biblioteca();
        Bibliotecario* bibliotecario;

        unsigned int getDias(){return this->contadorDias;};
        void incrementarDia();
        void reiniciarTiempo();
        unsigned int articulosDisponibles();
    protected:

    private:

        unsigned int contadorDias=0;
};

#endif // BIBLIOTECA_H
