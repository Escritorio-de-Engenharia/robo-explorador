#include <iostream>
#include <string>
#include <vector>
#include "header.h"

/// <summary>
/// - Ao invés de criar o mapa com string e laço de repetição para as posições, criei com char e coloquei os caracteres manualmente
/// - Criei uma função que printa o mapa
/// - Criei um arquivo Header para deixar as funções e variáveis
/// - Adicionei uma função para verificar se o carro está no fim do Labirinto
/// - Troquei as linhas que pediam para o usuário apertar um botão para continuar por system("pause")
/// - Coloquei algumas variáveis que só estavam no escopo da main para o escopo global, para podermos acessá-las de qualquer função
/// - Mudei a estrutura do Struct Coordenadas, atribuindo os valores passados como parâmetros para o construtor aos atributos
/// </summary>

using namespace std;

vector<Coordenadas> coordenadas;
vector<Coordenadas> carro;

bool operator==(Coordenadas a, Coordenadas b)
{
    if (a.x == b.x && a.y == b.y)
    {
        return true;
    }
    return false;
}

void printMaze()
{
    // Printa o labirinto
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << lab[i][j] << " ";
        }
        cout << endl;
    }
}

bool isCarInTheEnd(Coordenadas saida, int posOgX, int posOgY)
{
    // Quando o carro chega no final, ele quebra o loop

    if (carro[0].x == saida.x && carro[0].y == saida.y && coordenadas.size() > 0)
    {
        cout << "Carro encontrou outros possiveis caminhos" << endl;
        system("pause");
        carro[0].x = posOgX;
        carro[0].y = posOgY;
        caminhoAlt = true;
        system("clear || cls");

        return false;
    }
    return true;
}

int main()
{
    carro.push_back(Coordenadas(8, 4)); // Inicia em 8 e 4

    // Posicoes do Carro
    int posOgX = 8;
    int posOgY = 4;

    // Posi��o do final do labirinto
    Coordenadas saida(1, 4);

    // Labirinto
    //  string lab[10][10];

    int contador = 1;

    int i = 0;

    // Primeira corrida
    // Gera��o da matriz
    while (loop == 54)
    {
        /* for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i == 0 || i == 10-1 || j == 0 || j == 10-1)
                {
                    lab[i][j] = "*";
                }
                else
                {
                    lab[i][j] = " ";
                }
            }
        }

        Labirinto/Caminho
         for(int i = 4; i <= 8; i++)
         {
             lab[8][i] = ".";
         }

        for(int i = 8; i >= 4; i--)
        {
            lab[i][8] = ".";
        }

        for(int i = 8; i >= 6; i--)
        {
            lab[4][i] = ".";
        }

        for(int i = 4; i <= 6; i++)
        {
            lab[i][6] = ".";
        }

        for(int i = 8; i >= 1; i--)
        {
            lab[6][i] = ".";
        }

        for(int i = 6; i >= 3; i--)
        {
            lab[i][4] = ".";
        }

        for(int i = 6; i >= 3; i--)
        {

            lab[i][1] = ".";
        }

        for(int i = 2; i <= 4; i++)
        {
            lab[3][i] = ".";
        }

        for(int i = 3; i >= 2; i--)
        {
            lab[i][4] = ".";
        }

        lab[saida.x][saida.y] = "#"; //Ponto final
        lab[carro[0].x][carro[0].y] = "C"; //Icone do carro */

        printMaze();

        if (isCarInTheEnd(saida, posOgX, posOgY))
            break;

        // if(lab[carro[0].x][carro[0].y-1] == "." && lab[carro[0].x-1][carro[0].y] == "." && foiDireita == false && caminhoAlt == false)
        // {
        //     coordenadas.push_back(Coordenadas(carro[0].x, carro[0].y));
        // }

        // if(carro[0] == coordenadas[coordenadas.size()-1] && carro[0] == coordenadas[coordenadas.size()-1] && caminhoAlt == true)
        // {
        //     carro[0].x--;
        // }

        // if(lab[carro[0].x][carro[0].y-1] != " " && lab[carro[0].x][carro[0'].y-1] != "*" && podeEsquerda == true) //Carro vai para esquerda
        // {
        //     carro[0].y--;
        //     if(foiDireita == true) //Se o carro for para a esquerda logo ap�s ir para a direita, ele subtrai 1 do contadorD
        //     {
        //         contadorD -= 1;
        //     }
        //     else
        //     {
        //         contadorE += 1;
        //     }

        //     //Carro foi para esquerda
        //     foiEsquerda = true;
        //     foiFrente = false;
        //     foiTras = false;
        // }
        // else
        // {
        //     if(lab[carro[0].x-1][carro[0].y] != " " && lab[carro[0].x-1][carro[0].y] != "*" && podeFrente == true) //Se nao der, o carro vai para frente
        //     {
        //         carro[0].x--;
        //         podeEsquerda = true;
        //         if(foiTras == true) //Se o carro for para frente logo ap�s ir para tras, ele subtrai 1 do contadorT
        //         {
        //             contadorT -= 1;
        //         }
        //         else
        //         {
        //             contadorF += 1;
        //         }

        //         //Carro foi para frente
        //         foiFrente = true;
        //         foiDireita = false;
        //         foiEsquerda = false;
        //     }
        //     else
        //     {
        //         if(lab[carro[0].x][carro[0].y+1] != " " && lab[carro[0].x][carro[0].y+1] != "*" && podeDireita == true) //Se nao der, o carro vai para direita
        //         {
        //             carro[0].y++;
        //             podeFrente = true;
        //             podeEsquerda = false;
        //             if(foiEsquerda == true) //Se o carro for para a direita logo ap�s ir para a esquerda, ele subtrai 1 do contadorE
        //             {
        //                  contadorE -= 1;
        //             }
        //             else
        //             {
        //                 contadorD += 1;
        //             }

        //             //Carro foi para esquerda
        //             foiDireita = true;
        //             foiFrente = false;
        //             foiTras = false;
        //         }
        //         else
        //         {
        //             if(lab[carro[0].x+1][carro[0].y] != " " && lab[carro[0].x+1][carro[0].y] != "*") //Se nao der, o carro vai para tras
        //             {
        //                 carro[0].x++;
        //                 podeEsquerda = false;
        //                 podeFrente = false;
        //                 podeDireita = true;
        //                 if(foiFrente == true) //Se o carro for para tras logo ap�s ir para frente, ele subtrai 1 do contadorF
        //                 {
        //                     contadorF -= 1;
        //                 }
        //                 else
        //                 {
        //                     contadorT += 1;
        //                 }

        //                 //Carro foi para tras
        //                 foiTras = true;
        //                 foiDireita = false;
        //                 foiEsquerda = false;

        //             }
        //             else
        //             {
        //                 if(lab[carro[0].x][carro[0].y+contador] != "." && lab[carro[0].x+contador][carro[0].y] != "." && lab[carro[0].x-contador][carro[0].y] != ".") //Se o carro encontrar um caminho fechado no lado direito, ele da um "giro" e volta
        //                 {
        //                     carro[0].y--;
        //                     contador++;
        //                     podeEsquerda = false;
        //                     podeFrente = false;
        //                     podeDireita = false;
        //                     if(foiDireita == true)
        //                     {
        //                         contadorD -= 1;
        //                     }
        //                     else
        //                     {
        //                         contadorE += 1;
        //                     }
        //                     foiEsquerda = true;
        //                     foiFrente = false;
        //                     foiTras = false;
        //                 }
        //             }
        //         }
        //     }
        // }

        // cout << endl;
        // cout << endl;
        // cout << "Caminhos alternativos: " << coordenadas.size() << endl;
        // //cout << "Caminho x: " << caminhoX[i] << "\nCaminho y: " << caminhoY[i] << endl;
        // system("pause");

        // system("clear || cls");
    }

    // cout << endl;
    // cout << endl;
    // cout << "Carro chegou ao final" << endl;
    // system("pause");

    /*
    //Segunda corrida
    carro[0].x = 8;
    carro[0].y = 4;

    podeEsquerda = true;
    podeDireita = true;
    podeFrente = true;

    while(loop2 == 55)
    {
        system("clear || cls");

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i == 0 || i == 10-1 || j == 0 || j == 10-1)
                {
                    lab[i][j] = "*";
                }
                else
                {
                    lab[i][j] = " ";
                }
            }
        }

        for(int i = 4; i <= 8; i++)
        {
            lab[8][i] = ".";
        }

        for(int i = 8; i >= 4; i--)
        {
            lab[i][8] = ".";
        }

        for(int i = 8; i >= 6; i--)
        {
            lab[4][i] = ".";
        }

        for(int i = 4; i <= 6; i++)
        {
            lab[i][6] = ".";
        }

        for(int i = 8; i >= 1; i--)
        {
            lab[6][i] = ".";
        }

        for(int i = 6; i >= 3; i--)
        {
            lab[i][4] = ".";
        }

        for(int i = 6; i >= 3; i--)
        {

            lab[i][1] = ".";
        }

        for(int i = 2; i <= 4; i++)
        {
            lab[3][i] = ".";
        }

        for(int i = 3; i >= 2; i--)
        {
            lab[i][4] = ".";
        }

        lab[saida.x][saida.y] = "#";

        lab[carro[0].x][carro[0].y] = "C";

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                cout << lab[i][j] << " ";
            }
            cout << endl;
        }

        if(carro[0].x == saida.x && carro[0].y == saida.y)
        {
            break;
        }

        if(lab[carro[0].x][carro[0].y-1] != " " && lab[carro[0].x][carro[0].y-1] != "*" && podeEsquerda == true && contadorE > 0) //Carro vai para esquerda
        {
            carro[0].y--;
            contadorE--;
        }
        else if(lab[carro[0].x-1][carro[0].y] != " " && lab[carro[0].x-1][carro[0].y] != "*" && podeFrente == true && contadorF > 0) //Carro vai para frente
        {
            carro[0].x--;
            contadorF--;
            podeEsquerda = true;
        }
        else if(lab[carro[0].x][carro[0].y+1] != " " && lab[carro[0].x][carro[0].y+1] != "*" && podeDireita == true && contadorD > 0) //Carro vai para direita
        {
            carro[0].y++;
            contadorD--;
            podeEsquerda = false;
            podeFrente = true;
        }
        else if(lab[carro[0].x+1][carro[0].y] != " " && lab[carro[0].x+1][carro[0].y] != "*" && contadorT > 0) //Carro vai para tras
        {
            carro[0].x++;
            contadorT--;
            podeDireita = true;
            podeEsquerda = false;
            podeFrente = false;
        }

        cout << "\n\n";
        // system("pause");
    }
    cout << "\n\n";
    cout << "Carro chegou ao final" << endl;*/

    return 0;
}
