#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

#include<set>
#include<Articulo.h>
class Bibliotecario
{
    public:
        Bibliotecario();
        virtual ~Bibliotecario();

        void agregarArticulo(Articulo &);
        void eliminarArticulo(Articulo &);
        bool estaArticulo(Articulo &);
        void prestarArticulo(Articulo &);
        void devolverArticulo(Articulo &);
        void tiempoArticulo ();
        void consultarArticulo(Articulo & unArticulo);
        void revisarArticulos();
        unsigned int getArticulosTam();
        set<Articulo*>& getArticulos();

    protected:

    private:
        std::set <Articulo *> articulos;

};

#endif // BIBLIOTECARIO_H
