#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

    string linha;
    while (getline(arquivo, linha))
    {

        stringstream ss(linha);

        string nome;
        getline(ss, nome, ',');

        nome.erase(0, nome.find_first_not_of(" "));
        nome.erase(nome.find_last_not_of(" ") + 1);

        int nivelSaude, urgenciaMedico;

        char virgula;
        ss >> nivelSaude >> virgula >> urgenciaMedico;

        cout << "Nome: " << nome << ", Nota 1: " << nivelSaude << ", Nota 2: " << urgenciaMedico << endl;
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

    // cout << "Lista Adicional:" << endl;
    // for (int valor : listaAdicional)
    // {
    //     cout << valor << " ";
    // }
    // cout << endl;
}

int main()
{
    lerMatrizELista("Entrada1.txt");
    return 0;
}