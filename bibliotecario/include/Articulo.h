#ifndef ARTICULO_H
#define ARTICULO_H
using namespace std;
#include<string>

class Articulo
{
    protected:
        string titulo="";
        string creador="";
        string genero="";
        unsigned int anioPublicacion=0;
        bool prestado=false;
        unsigned int cantPrestamos=0;
        unsigned int tiempoPrestar;
       // string vencePrestamo="";
    public:
        Articulo(string titulo, string creador, string genero, unsigned int anioPublicacion, unsigned int tiempoPrestar);
        virtual ~Articulo();
        virtual string getTitulo();
        virtual string getGenero();
        virtual string getCreador();
        virtual unsigned int getanioPublicacion();

        virtual unsigned int getCantidadPrestamos();
        virtual unsigned int getTiempoPrestar();
        virtual bool getPrestado();

        virtual void setPrestado(bool prestado);
        virtual void mostrarDetalles();
        virtual string mostrarTipo();
        void setTiempoPrestar();
        void setCantidadPrestamos();
        //virtual void setTiempoPrestar(unsigned int tiempoPrestar);
        //virtual void mostrarDetalles();
      //  void setVencePrestamo(string vencePrestamo);
};

#endif // ARTICULO_H
