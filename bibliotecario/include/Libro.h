#ifndef LIBRO_H
#define LIBRO_H

#include <Articulo.h>


class Libro : public Articulo
{
    public:
        Libro(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int cantPaginas, string isbn);
        virtual ~Libro();
        unsigned int getCantPaginas(){return this->cantPaginas;};
        string getISBN(){return this->isbn;};
        void mostrarDetalles() override;
        string mostrarTipo() override;

    private:
        unsigned int cantPaginas = 0;
        string isbn = "";


};

#endif // LIBRO_H
