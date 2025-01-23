#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Astronauta.hpp"

using namespace std;

void lerMatrizELista(const string &nomeArquivo)
{

    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo" << endl;
        return;
    }

    int linhas, colunas;
    arquivo >> linhas >> colunas;

    vector<vector<char>> matriz(linhas, vector<char>(colunas));
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            arquivo >> matriz[i][j];
        }
    }

    string lixo;
    arquivo >> lixo;
    cout << "Lixo: " << lixo << endl;
    arquivo.ignore();

    int nivelSaude, urgenciaMedico;
    string nome;
    string linha;
    while (getline(arquivo, linha))
    {
        if (linha == "Posições dos astronautas na matriz:")
        {
            break;
        }
        stringstream ss(linha);

        getline(ss, nome, ',');

        nome.erase(0, nome.find_first_not_of(" "));
        nome.erase(nome.find_last_not_of(" ") + 1);

        char virgula;
        ss >> nivelSaude >> virgula >> urgenciaMedico;

        cout << "Nome: " << nome << ", Nivel Saude: " << nivelSaude << ", Urgencia: " << urgenciaMedico << endl;
    }

    int x, y;
    while (getline(arquivo, linha))
    {
        stringstream ss(linha);

        string nome;
        getline(ss, nome, ':');

        nome.erase(0, nome.find_first_not_of(" "));
        nome.erase(nome.find_last_not_of(" ") + 1);

        char virgula;
        char parenteses;
        char espaco;
        ss >> parenteses >> x >> virgula >> y >> parenteses;

        cout << "Nome: " << nome << ", X: " << x << ", Y: " << y << endl;
    }

    cout << "Matriz:" << endl;
    for (const auto &linha : matriz)
    {
        for (char valor : linha)
        {
            cout << valor << " ";
        }
        cout << endl;
    }

    Astronauta a(nome, nivelSaude, urgenciaMedico, x, y);
    cout << a.toString() << endl;
}

int main()
{
    lerMatrizELista("Entrada1.txt");
    return 0;
}