#include "EstacaoEspacial.hpp"
#include "Modulo.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <bits/algorithmfwd.h>

using namespace std;

EstacaoEspacial::EstacaoEspacial(int linhas, int colunas)
{
    this->linhas = linhas;
    this->colunas = colunas;
    this->matriz = std::vector<std::vector<Modulo>>(linhas, std::vector<Modulo>(colunas));
}

void EstacaoEspacial::carregarDoArquivo(std::ifstream &arquivo)
{
    if (!arquivo.is_open())
    {
        throw std::runtime_error("Erro ao abrir o arquivo");
    }

    int linhas, colunas;
    if (!(arquivo >> linhas >> colunas))
    {
        throw std::runtime_error("Erro ao ler dimensões da matriz");
    }

    this->matriz.clear();
    this->matriz.resize(linhas, std::vector<Modulo>(colunas));

    std::vector<std::vector<char>> matrizTemp(linhas, std::vector<char>(colunas));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (!(arquivo >> matrizTemp[i][j]))
            {
                throw std::runtime_error("Erro ao ler dados da matriz");
            }
        }
    }
    matrizCharToModulo(matrizTemp);

    std::string linha;
    while (std::getline(arquivo, linha))
    {

        if (linha == "Posições dos astronautas na matriz:")
        {
            break;
        }

        std::istringstream ss(linha);
        std::string nome;
        int nivelSaude, urgenciaMedico;

        std::getline(ss, nome, ',');

        nome.erase(0, nome.find_first_not_of(" "));
        nome.erase(nome.find_last_not_of(" ") + 1);

        if (ss >> nivelSaude)
        {

            ss.ignore(1, ',');
            if (ss >> urgenciaMedico)
            {
                Astronauta astronauta(nome, nivelSaude, urgenciaMedico, -1, -1);
                astronautas.push_back(astronauta);
            }
        }
    }

    while (std::getline(arquivo, linha))
    {
        std::istringstream ss(linha);
        std::string nome;
        int x = -1, y = -1;

        std::getline(ss, nome, ':');

        auto trim = [](std::string &str)
        {
            str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
            str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
            return str;
        };
        trim(nome);

        char openParen, closeParen, comma;
        if (ss >> openParen >> x >> comma >> y >> closeParen)
        {
            for (Astronauta &astronauta : astronautas)
            {
                if (astronauta.getNome() == nome)
                {
                    astronauta.setX(x);
                    astronauta.setY(y);
                    break;
                }
            }
        }
    }
}

void EstacaoEspacial::matrizCharToModulo(const std::vector<std::vector<char>> &matrizChar)
{
    if (matrizChar.empty())
    {
        throw std::runtime_error("Matriz vazia");
    }

    for (size_t i = 0; i < matrizChar.size(); i++)
    {
        for (size_t j = 0; j < matrizChar[i].size(); j++)
        {
            adicionarModulo(i, j, matrizChar[i][j]);
        }
    }
}

void EstacaoEspacial::adicionarModulo(size_t x, size_t y, char tipo)
{
    if (x >= matriz.size() || y >= matriz[0].size())
    {
        std::cout << "Fora da nave" << std::endl;
        return;
    }

    switch (tipo)
    {
    case '.':
        matriz[x][y] = ModuloNormal(tipo);
        break;
    case '#':
        matriz[x][y] = ModuloObstaculo(tipo);
        break;
    case '~':
        matriz[x][y] = ModuloVazio(tipo);
        break;
    case 'S':
        matriz[x][y] = ModuloSeguranca(tipo);
        break;
    case 'F':
        matriz[x][y] = ModuloComFogo(tipo);
        break;
    case 'A':
        matriz[x][y] = ModuloComAstronauta(tipo);
        break;
    default:
        throw std::invalid_argument("Tipo de módulo inválido");
    }
}

void EstacaoEspacial::adicionarAstronauta(Astronauta astronauta)
{
    this->astronautas.push_back(astronauta);
}

// const std::vector<std::vector<char>> EstacaoEspacial::getMatriz() const
// {
//     std::vector<std::vector<char>> matrizChars;
//     matrizChars.resize(linhas);
//     for (int i = 0; i < linhas; i++)
//     {
//         matrizChars[i].resize(colunas);
//         for (int j = 0; j < colunas; j++)
//         {
//             matrizChars[i][j] = matriz[i][j].getTipo();
//         }
//     }
//     return matrizChars;
// }

std::vector<Astronauta> EstacaoEspacial::getAstronautas()
{
    return this->astronautas;
}

size_t EstacaoEspacial::getLinhas() const { return matriz.size(); }
size_t EstacaoEspacial::getColunas() const { return matriz.empty() ? 0 : matriz[0].size(); }

EstacaoEspacial::~EstacaoEspacial()
{
    matriz.clear(); // Limpa a matriz corretamente
}

const std::vector<Astronauta> &EstacaoEspacial::getAstronautas() const
{
    return astronautas;
}

void EstacaoEspacial::exbirMatriz()
{
    std::cout << "" << std::endl;
    if (matriz.empty())
    {
        std::cout << "Matriz vazia" << std::endl;
        return;
    }

    for (const auto &linha : matriz)
    {

        for (const auto &modulo : linha)
        {

            std::cout << modulo.getTipo() << " ";
        }
        std::cout << std::endl;
    }
}

void EstacaoEspacial::exibirAstronautas()
{
    for (auto astronauta : astronautas)
    {
        cout << astronauta.toString() << endl;
    }
}
