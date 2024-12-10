#ifndef VISTA_H
#define VISTA_H
#include<string>
#include<set>
#include<Articulo.h>
using namespace std;
class Vista
{
    public:
        Vista();
        virtual ~Vista();
        void mostrarMenu();
        void mostrarArticulos(std::set <Articulo *>& articulos);
        unsigned int pedirOpcion();
        unsigned int pedirTipo();
        void avanzaDia();

        string pedirTitulo();
        string pedirCreador();
        string pedirGenero();
        unsigned int pedirAnio();

        unsigned int pedirDuracion();
        double pedirPuntaje();
        unsigned int pedirPaginas();
        string pedirISBN();


    protected:

    private:
};

#endif // VISTA_H
