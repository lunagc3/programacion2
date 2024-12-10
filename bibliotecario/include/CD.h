#ifndef CD_H
#define CD_H

#include <Articulo.h>


class CD : public Articulo
{
    public:
        CD(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int duracion);
        virtual ~CD();

        unsigned int getDuracion() { return this->duracion; }
        void mostrarDetalles() override;
        string mostrarTipo() override;

    protected:

    private:
        unsigned int duracion;
};

#endif // CD_H
