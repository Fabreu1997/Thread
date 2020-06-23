#ifndef INCLUDED_PRINCIPAL_H
#define INCLUDED_PRINCIPAL_H

#include "Corredor.h"
#include <list>

class Principal
{
private:

    Corredor* c1;
    Corredor* c2;

    list< Corredor* > _corredores;
    list< Corredor* >::iterator _it;
public:

    static bool _semaforoAberto;

public:

    Principal();
    ~Principal();

    //Operações com a list
    void limpar();

    void iniciarCorrida(); //...................TO DO
    void cadastrarCorredor();
    void menu();
};

#endif // INCLUDED_PRINCIPAL_H
