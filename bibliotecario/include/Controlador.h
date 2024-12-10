#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include<Biblioteca.h>
#include<Vista.h>

class Controlador
{
    public:
        Controlador(Biblioteca &, Vista &);
        virtual ~Controlador();
        void agregarArticulo();
        void eliminarArticulo();
        void consultarArticulo();
        void prestarArticulo();
        void avanzarDia();
        void actualizarVista();

    protected:

    private:
        Biblioteca & modelo;
        Vista vista;

};

#endif // CONTROLADOR_H
