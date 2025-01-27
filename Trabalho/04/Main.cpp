#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Astronauta.hpp"
#include "RoboDeResgate.hpp"
#include "EstacaoEspacial.hpp"
#include <algorithm>

using namespace std;

void bfs(int x, int y, int linhas, int colunas, vector<vector<int>> &distancia, vector<vector<bool>> &visitados, vector<vector<char>> &matriz)
{
    cout << "chegou no BFS" << endl;

    vector<pair<int, int>> direcoes = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    visitados[x][y] = true;
    distancia[x][y] = 0;
    vector<pair<int, int>> fila;
    fila.push_back({x, y});
    while (!fila.empty())
    {
        pair<int, int> atual = fila.front();
        fila.erase(fila.begin());
        for (auto direcao : direcoes)
        {
            int novoX = atual.first + direcao.first;
            int novoY = atual.second + direcao.second;
            if (novoX >= 0 && novoX < linhas && novoY >= 0 && novoY < colunas && !visitados[novoX][novoY] && matriz[novoX][novoY] != 'O' && matriz[novoX][novoY] != 'F')
            {
                visitados[novoX][novoY] = true;
                distancia[novoX][novoY] = distancia[atual.first][atual.second] + 1;
                fila.push_back({novoX, novoY});
            }
        }
    }
}

int main()
{
    EstacaoEspacial estacao;
    ifstream arquivo("Entrada1.txt");
    estacao.carregarDoArquivo(arquivo);

    // cout << "Matriz: " << endl;
    // estacao.exbirMatriz();
    // cout << "Astronautas: " << endl;
    // estacao.exibirAstronautas();

    RoboDeResgate robo(estacao);
    auto distancia = robo.calcularDistancia(0, 0);
    for (auto linha : distancia)
    {
        for (auto d : linha)
        {
            cout << d << " ";
        }
        cout << endl;
    }

    // robo.calcularDistancia(0, 0);
    // robo.iniciarResgate();
    // robo.gerarRelatorio();

    return 0;
}
