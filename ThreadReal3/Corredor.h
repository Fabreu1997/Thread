#ifndef INCLUDED_CORREDOR_H
#define INCLUDED_CORREDOR_H

#include "Thread.h"

class Corredor:
public Thread
{
private:

    string _nome;
    unsigned int _nvoltas;
    unsigned int _voltas;

public:

    Corredor(const string nome = "Default");
    ~Corredor();

    void run();

    void setNome(const string nome);
    const string getNome() const;

    void setVoltas(const unsigned int volta);
    const unsigned int getVoltas() const;
};

iostream& operator<<(iostream& saida, Corredor& c);

#endif // INCLUDED_CORREDOR_H
