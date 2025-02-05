#include "RoboDeResgate.hpp"

RoboDeResgate::RoboDeResgate(EstacaoEspacial &estacao) : estacao(estacao)
{
    Posicao moduloSeguranca = iniciarResgate();
    posicaoInicialX = moduloSeguranca.coluna;
    posicaoInicialY = moduloSeguranca.linha;
    passos = 0;
    resgatados = std::vector<Astronauta>();
    naoResgatados = estacao.getAstronautas();

    visitados = std::vector<std::vector<bool>>(estacao.getLinhas(), std::vector<bool>(estacao.getColunas(), false));
    distancia = std::vector<std::vector<int>>(estacao.getLinhas(), std::vector<int>(estacao.getColunas(), -1));
}

Posicao RoboDeResgate::iniciarResgate()
{
    for (size_t i = 0; i < estacao.getLinhas(); i++)
    {
        for (size_t j = 0; j < estacao.getColunas(); j++)
        {
            if (estacao.getMatriz()[i][j].getTipo() == 'S')
            {
                return {(int)i, (int)j};
            }
        }
    }
    throw std::runtime_error("Módulo de segurança não encontrado");
}

bool RoboDeResgate::isPosicaoValida(int x, int y)
{
    return x >= 0 && x < (int)estacao.getLinhas() &&
           y >= 0 && y < (int)estacao.getColunas() &&
           !proximoAoFogo(x, y) &&
           estacao.getMatriz()[x][y].getTipo() != '#' &&
           estacao.getMatriz()[x][y].getTipo() != 'F' &&
           estacao.getMatriz()[x][y].getTipo() != '~';
}

bool RoboDeResgate::proximoAoFogo(int x, int y)
{
    std::vector<std::pair<int, int>> direcoes = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (const auto &dir : direcoes)
    {
        int novo_x = x + dir.first;
        int novo_y = y + dir.second;

        if (novo_x >= 0 && novo_x < (int)estacao.getLinhas() &&
            novo_y >= 0 && novo_y < (int)estacao.getColunas() &&
            estacao.getMatriz()[novo_x][novo_y].getTipo() == 'F')
        {
            return true;
        }
    }
    return false;
}

int RoboDeResgate::calcularDistanciaEntrePontos(Posicao inicio, Posicao destino)
{
    std::queue<Posicao> fila;
    std::vector<std::vector<int>> dist(estacao.getLinhas(),
                                       std::vector<int>(estacao.getColunas(), -1));

    std::vector<std::pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    fila.push(inicio);
    dist[inicio.linha][inicio.coluna] = 0;

    while (!fila.empty())
    {
        Posicao atual = fila.front();
        fila.pop();

        if (atual.linha == destino.linha && atual.coluna == destino.coluna)
        {
            passos += dist[atual.linha][atual.coluna];
            return dist[atual.linha][atual.coluna];
        }

        for (const auto &dir : direcoes)
        {
            int novo_x = atual.linha + dir.first;
            int novo_y = atual.coluna + dir.second;

            if (isPosicaoValida(novo_x, novo_y) && dist[novo_x][novo_y] == -1)
            {
                dist[novo_x][novo_y] = dist[atual.linha][atual.coluna] + 1;
                fila.push({novo_x, novo_y});
            }
        }
    }
    return -1;
}

void RoboDeResgate::imprimirMatriz(const Posicao &posicaoAtual)
{
    std::cout << "\033[2J\033[1;1H"; // Limpa a tela (ANSI escape code)
    for (size_t i = 0; i < estacao.getLinhas(); i++)
    {
        for (size_t j = 0; j < estacao.getColunas(); j++)
        {
            if (i == (size_t)posicaoAtual.linha && j == (size_t)posicaoAtual.coluna)
            {
                std::cout << "R "; // R para representar o robô
            }
            else
            {
                std::cout << estacao.getMatriz()[i][j].getTipo() << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pausa para visualização
}

void RoboDeResgate::moverRobo(Posicao inicio, Posicao fim)
{
    std::queue<Posicao> fila;
    std::vector<std::vector<int>> dist(estacao.getLinhas(),
                                       std::vector<int>(estacao.getColunas(), -1));
    std::vector<std::vector<Posicao>> parent(estacao.getLinhas(),
                                             std::vector<Posicao>(estacao.getColunas(), {-1, -1}));

    std::vector<std::pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    fila.push(inicio);
    dist[inicio.linha][inicio.coluna] = 0;

    while (!fila.empty())
    {
        Posicao atual = fila.front();
        fila.pop();

        if (atual.linha == fim.linha && atual.coluna == fim.coluna)
        {
            break;
        }

        for (const auto &dir : direcoes)
        {
            int novo_x = atual.linha + dir.first;
            int novo_y = atual.coluna + dir.second;

            if (isPosicaoValida(novo_x, novo_y) && dist[novo_x][novo_y] == -1)
            {
                dist[novo_x][novo_y] = dist[atual.linha][atual.coluna] + 1;
                parent[novo_x][novo_y] = atual;
                fila.push({novo_x, novo_y});
            }
        }
    }

    // Reconstrói o caminho
    std::vector<Posicao> caminho;
    Posicao atual = fim;
    while (atual.linha != -1 && atual.coluna != -1)
    {
        caminho.push_back(atual);
        atual = parent[atual.linha][atual.coluna];
    }

    // Mostra o movimento do robô
    for (auto it = caminho.rbegin(); it != caminho.rend(); ++it)
    {
        imprimirMatriz(*it);
    }
}

int RoboDeResgate::calcularMenorCaminhoResgate()
{
    std::vector<Posicao> pontos;
    Posicao inicio = {posicaoInicialY, posicaoInicialX};
    pontos.push_back(inicio);

    const std::vector<Astronauta> &astronautas = estacao.getAstronautas();
    for (const auto &astronauta : astronautas)
    {
        pontos.push_back({astronauta.getX(), astronauta.getY()});
        naoResgatados.push_back(astronauta);
    }

    int n = pontos.size();
    std::vector<std::vector<int>> matrizDistancias(n, std::vector<int>(n, 0));

    // Calcula distâncias entre todos os pontos
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int dist = calcularDistanciaEntrePontos(pontos[i], pontos[j]);
                if (dist == -1)
                    return -1;
                matrizDistancias[i][j] = dist;
            }
        }
    }

    std::vector<int> permutacao;
    for (int i = 1; i < n; i++)
    {
        permutacao.push_back(i);
    }

    int menorDistancia = INT_MAX;
    std::vector<int> melhorCaminho;

    do
    {
        int distanciaAtual = 0;
        int indiceAtual = 0;

        for (int i = 0; i < (int)permutacao.size(); i++)
        {
            distanciaAtual += matrizDistancias[indiceAtual][permutacao[i]];
            indiceAtual = permutacao[i];
        }
        distanciaAtual += matrizDistancias[indiceAtual][0];

        if (distanciaAtual < menorDistancia)
        {
            menorDistancia = distanciaAtual;
            melhorCaminho = permutacao;
        }
    } while (std::next_permutation(permutacao.begin(), permutacao.end()));

    std::cout << "\nIniciando resgate dos astronautas...\n"
              << std::endl;
    Posicao posicaoAtual = inicio;

    for (int idx : melhorCaminho)
    {
        std::cout << "Indo resgatar próximo astronauta..." << std::endl;
        Posicao destino = pontos[idx];
        moverRobo(posicaoAtual, destino);
        resgatarAstronauta(destino.linha, destino.coluna);
        posicaoAtual = destino;
    }

    std::cout << "Retornando ao módulo de segurança..." << std::endl;
    moverRobo(posicaoAtual, inicio);

    std::cout << "Resgate finalizado!" << std::endl;

    return menorDistancia;
}
void RoboDeResgate::resgatarAstronauta(int x, int y)
{
    if (estacao.getMatriz()[x][y].getTipo() == 'A')
    {
        const std::vector<Astronauta> &astronautas = estacao.getAstronautas();
        for (size_t i = 0; i < astronautas.size(); i++)
        {
            if (astronautas[i].getX() == x && astronautas[i].getY() == y)
            {
                resgatados.push_back(astronautas[i]);
                auto it = std::find_if(naoResgatados.begin(), naoResgatados.end(),
                                       [x, y](const Astronauta &a)
                                       {
                                           return a.getX() == x && a.getY() == y;
                                       });
                if (it != naoResgatados.end())
                {
                    naoResgatados.erase(it);
                }
            }
        }
    }
}

void RoboDeResgate::gerarRelatorio()
{
    std::cout << "Astronautas resgatados: " << std::endl;
    for (auto astronauta : resgatados)
    {
        std::cout << astronauta.toString() << std::endl;
    }
    std::cout << "Astronautas nao resgatados: " << std::endl;
    for (auto astronauta : naoResgatados)
    {
        std::cout << astronauta.toString() << std::endl;
    }

    std::cout << "Passos necessarios:" << std::endl;
    std::cout << passos << std::endl;
};

void RoboDeResgate::gerarRelatorio(std::any obj)
{
    std::cout << std::any_cast<std::string>(obj) << std::endl;
};
