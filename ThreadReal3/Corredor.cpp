#include "Principal.h"

Corredor::Corredor(const string nome):
    _nome(nome),
    _nvoltas(1000),
    _voltas(0)
{

}

Corredor::~Corredor()
{

}

void Corredor::run()
{
    // enquanto o semáforo estiver aberto;
    // este semáforo é o de “trânsito” da corrida...
    // não confundir com semáforos de threads...
    while(! Principal::_semaforoAberto)
    {
        //lock();
        //cout << _nome << " esta na frente. "  << _voltas << endl;
        _voltas++;
        //unlock();

        if(_voltas)
        {
            yield(); //pra ser mesmo uma corrida
        }

        if(_nvoltas == _voltas)
        {
            lock();
            Principal::_semaforoAberto = true;
            cout << "..................................................." << endl;
            cout << endl << "O grande Vencedor da Corrida eh " << _nome << endl << endl;
            unlock();
        }
    }
}

void Corredor::setNome(const string nome)
{
    _nome = nome;
}

const string Corredor::getNome() const
{
    return(_nome);
}

void Corredor::setVoltas(const unsigned int volta)
{
    _voltas = volta;
}

const unsigned int Corredor::getVoltas() const
{
    return(_voltas);
}

iostream& operator<<(iostream& saida, Corredor& c)
{
    saida << c.getNome();
    return(saida);
}
