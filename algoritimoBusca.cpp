#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Coordenadas{
	int x;
	int y;

    Coordenadas(int a, int b)
    {
        a = x;
        b = y;
    }
};

bool operator==(Coordenadas a, Coordenadas b)
{
	if(a.x == b.x && a.y == b.y)
	{
		return true;
	}
	else
	{
		false;
	}
}

int main()
{
	//Posi��es do carro
    vector<Coordenadas> coordenadas;
    vector<Coordenadas> carro;
    carro.push_back(Coordenadas(8, 4)); //Inicia em 8 e 4

    int posOgX = 8;
    int posOgY = 4;

	//Posi��o do final do labirinto
	Coordenadas saida(1, 4);
	
	//Labirinto
	string lab[10][10];

    int contador = 1;

    int i = 0;
	
	//Conta quantas vezes o carro vai para cada dire��o
    int contadorE = 0;
    int contadorD = 0;
    int contadorF = 0;
    int contadorT = 0;
	
	//Verifica se o carro andou para os lados sem necessidade
    int verificarE = 0;
    int verificarD = 0;
    int verificarF = 0;
    int verificarT = 0;
	
	//Dire��o em que o carro andou
    bool foiDireita = false;
    bool foiEsquerda = false;
    bool foiFrente = false;
    bool foiTras = false;
    int verificar = 0;
	
	//Dire��es possiveis para o carro
    bool podeEsquerda = true;
    bool podeDireita = true;
    bool podeFrente = true;

    bool caminhoFrente = false;
    bool caminhoDireita = false;
    bool caminhoEsquerda = false;
    bool caminhoTras = false;

    bool caminhoAlt = false;
	
	//Variaveis para manter o loop/pausar o programa
    int loop = 54;
    int loop2 = 55;
    char lixo;	
	
	//Primeira corrida
	//Gera��o da matriz
    while(loop == 54)
    {
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
        
        //Labirinto/Caminho
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
        lab[carro[0].x][carro[0].y] = "C"; //Icone do carro

		//Printa o labirinto
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                cout << lab[i][j] << " ";
            }
            cout << endl;
        }
		
		//Quando o carro chega no final, ele quebra o loop
        if(carro[0].x == saida.x && carro[0].y == saida.y)
        {
        	if(coordenadas.size() > 0)
        	{
        		cout << "Carro encontrou outros possiveis caminhos" << endl;
        		cout << "Pressione qualquer tecla para continuar: ";
        		cin >> lixo;
        		carro[0].x = posOgX;
        		carro[0].y = posOgY;
                caminhoAlt = true;
        		system("clear || cls");
			}
            else
            {
                break;
            }
        }

        if(lab[carro[0].x][carro[0].y-1] == "." && lab[carro[0].x-1][carro[0].y] == "." && foiDireita == false && caminhoAlt == false)
        {
            coordenadas.push_back(Coordenadas(carro[0].x, carro[0].y));
        }

        if(carro[0] == coordenadas[coordenadas.size()-1] && carro[0] == coordenadas[coordenadas.size()-1] && caminhoAlt == true)
        {
            carro[0].x--;
        }
        
        if(lab[carro[0].x][carro[0].y-1] != " " && lab[carro[0].x][carro[0].y-1] != "*" && podeEsquerda == true) //Carro vai para esquerda
        {
            carro[0].y--;
            if(foiDireita == true) //Se o carro for para a esquerda logo ap�s ir para a direita, ele subtrai 1 do contadorD
            {
                contadorD -= 1;
            }
            else
            {
                contadorE += 1;
            }
            
            //Carro foi para esquerda
            foiEsquerda = true;
            foiFrente = false;
            foiTras = false;
        }
        else
        {
            if(lab[carro[0].x-1][carro[0].y] != " " && lab[carro[0].x-1][carro[0].y] != "*" && podeFrente == true) //Se nao der, o carro vai para frente
            {
                carro[0].x--;
                podeEsquerda = true;
                if(foiTras == true) //Se o carro for para frente logo ap�s ir para tras, ele subtrai 1 do contadorT
                {
                    contadorT -= 1;
                }
                else
                {
                    contadorF += 1;
                }
                
                //Carro foi para frente
                foiFrente = true;
                foiDireita = false;
                foiEsquerda = false;
            }
            else
            {
                if(lab[carro[0].x][carro[0].y+1] != " " && lab[carro[0].x][carro[0].y+1] != "*" && podeDireita == true) //Se nao der, o carro vai para direita
                {
                    carro[0].y++;
                    podeFrente = true;
                    podeEsquerda = false;
                    if(foiEsquerda == true) //Se o carro for para a direita logo ap�s ir para a esquerda, ele subtrai 1 do contadorE
                    {
                         contadorE -= 1;
                    }
                    else
                    {
                        contadorD += 1;
                    }
                    
                    //Carro foi para esquerda
                    foiDireita = true;
                    foiFrente = false;
                    foiTras = false;
                }
                else
                {
                    if(lab[carro[0].x+1][carro[0].y] != " " && lab[carro[0].x+1][carro[0].y] != "*") //Se nao der, o carro vai para tras
                    {
                        carro[0].x++;
                        podeEsquerda = false;
                        podeFrente = false;
                        podeDireita = true;
                        if(foiFrente == true) //Se o carro for para tras logo ap�s ir para frente, ele subtrai 1 do contadorF
                        {
                            contadorF -= 1;
                        }
                        else
                        {
                            contadorT += 1;
                        }
                        
                        //Carro foi para tras
                        foiTras = true;
                        foiDireita = false;
                        foiEsquerda = false;
                        
                    }
                    else
                    {
                        if(lab[carro[0].x][carro[0].y+contador] != "." && lab[carro[0].x+contador][carro[0].y] != "." && lab[carro[0].x-contador][carro[0].y] != ".") //Se o carro encontrar um caminho fechado no lado direito, ele da um "giro" e volta
                        {
                            carro[0].y--;
                            contador++;
                            podeEsquerda = false;
                            podeFrente = false;
                            podeDireita = false;
                            if(foiDireita == true)
                            {
                                contadorD -= 1;
                            }
                            else
                            {
                                contadorE += 1;
                            }
                            foiEsquerda = true;
                            foiFrente = false;
                            foiTras = false;
                        }
                    }
                }
            }
        }

        cout << endl;
        cout << endl;
        cout << "Caminhos alternativos: " << coordenadas.size() << endl;
        //cout << "Caminho x: " << caminhoX[i] << "\nCaminho y: " << caminhoY[i] << endl;
        cout << "Pressione qualquer botao para continuar: ";
        cin >> lixo;

        system("clear || cls");
    }

    cout << endl;
    cout << endl;
    cout << "Carro chegou ao final" << endl;
    cout << "Pressione qualquer botao para a segunda corrida: ";
    cin >> lixo;
	
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

        cout << endl;
        cout << endl;
        cout << "Pressione qualquer botao para continuar: ";
        cin >> lixo; 
    }
    cout << endl;
    cout << endl;
    cout << "Carro chegou ao final" << endl;*/
	
    return 0;
}
