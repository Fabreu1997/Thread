#include "Principal.h"

bool Principal::_semaforoAberto = false;

Principal::Principal()
{
    //c1 = new Corredor("Raft Speed");
    //c2 = new Corredor("Michael Schumacher");

    //_corredores.push_back(c1);
    //_corredores.push_back(c2);

}

Principal::~Principal()
{
    limpar();
}

void Principal::limpar()
{
    for(_it = _corredores.begin(); _it != _corredores.end(); _it++)
    {
        delete(*_it);
    }
}

void Principal::iniciarCorrida()
{
    system("cls");
    cout << "Iniciando a Corrida:            " << endl;
    cout << "................................" << endl;
    cout << "Participantes:                  " << endl;
    cout << "................................" << endl;

    for(_it = _corredores.begin(); _it != _corredores.end(); ++_it)
    {
        cout << (*_it)->getNome() << endl;
    }
    cout << endl;

    for(_it = _corredores.begin(); _it != _corredores.end(); ++_it)
    {
        (*_it)->start();
    }

    /*for(_it = _corredores.begin(); _it != _corredores.end(); ++_it)
    {
        (*_it)->join();
    }*/

    while(!_semaforoAberto)
    {

    }
    system("pause");
}

void Principal::cadastrarCorredor()
{
    string nome;
    Corredor* novo;

    cout << endl <<"Nome do Corredor: ";
    cin >> nome;
    fflush(stdin);

    novo = new Corredor(nome);
    _corredores.push_back( novo );

}

void Principal::menu()
{
    int opcao = -1;

    while(opcao != 0)
    {
        system("cls");
        cout << "MENU PRINCIPAL" << endl << endl;
        cout << "1 - Cadastrar Corredor........." << endl;
        cout << "2 - Iniciar Corrida............" << endl;
        cout << "0 - Sair......................." << endl << endl;
        cout << "Digite sua opcao: ";
        cin >> opcao;

        switch(opcao)
        {
        case 1:
            {
                cadastrarCorredor();
                break;
            }
        case 2:
            {
                iniciarCorrida();
                break;
            }
        case 0:
            {
                opcao = 0;
                break;
            }
        default:
            {
                cout << endl << " Opcao Invalida!!! " << endl;
                Sleep(2000);
                break;
            }
        }
    }
}
