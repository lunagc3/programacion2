#ifndef PELICULA_H
#define PELICULA_H

#include <Articulo.h>


class Pelicula : public Articulo
{
    public:
        Pelicula(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int duracion, double puntaje);
        virtual ~Pelicula();

        unsigned int getDuracion() { return this->duracion; }
        double getPuntaje() { return this->puntaje; }
        void mostrarDetalles() override;
        string mostrarTipo() override;
    protected:

    private:
        unsigned int duracion=0;
        double puntaje=0;
};

#endif // PELICULA_H
