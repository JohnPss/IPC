#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include "Astronauta.hpp"
#include "RoboDeResgate.hpp"
#include "EstacaoEspacial.hpp"

using namespace std;

int main()
{
    ifstream arquivo("Entrada1.txt");
    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }

    EstacaoEspacial estacao;
    try
    {
        estacao.carregarDoArquivo(arquivo);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao carregar a estação espacial: " << e.what() << endl;
        return 1;
    }

    RoboDeResgate robo(estacao);
    int distanciaTotal = robo.calcularMenorCaminhoResgate();

    if (distanciaTotal == -1)
    {
        cout << "Não foi possível resgatar todos os astronautas." << endl;
    }
    else
    {
        cout << "Distância mínima necessária para resgatar todos: " << distanciaTotal << endl;
    }

    cout << "\nRelatório final:" << endl;
    robo.gerarRelatorio();

    return 0;
}
