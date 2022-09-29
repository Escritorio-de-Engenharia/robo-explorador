char lab[10][10] = {{'#', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                    {'*', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', '*'},
                    {'*', '.', '.', '.', '.', ' ', ' ', ' ', ' ', '*'},
                    {'*', '.', ' ', ' ', '.', ' ', '.', '.', '.', '*'},
                    {'*', '.', ' ', ' ', '.', ' ', '.', ' ', '.', '*'},
                    {'*', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
                    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '*'},
                    {'*', ' ', ' ', ' ', '.', '.', '.', '.', '.', '*'},
                    {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*'}};

// Conta quantas vezes o carro vai para cada dire��o
int contadorE = 0;
int contadorD = 0;
int contadorF = 0;
int contadorT = 0;

// Verifica se o carro andou para os lados sem necessidade
int verificarE = 0;
int verificarD = 0;
int verificarF = 0;
int verificarT = 0;

// Dire��o em que o carro andou
bool foiDireita = false;
bool foiEsquerda = false;
bool foiFrente = false;
bool foiTras = false;
int verificar = 0;

// Dire��es possiveis para o carro
bool podeEsquerda = true;
bool podeDireita = true;
bool podeFrente = true;

bool caminhoFrente = false;
bool caminhoDireita = false;
bool caminhoEsquerda = false;
bool caminhoTras = false;

bool caminhoAlt = false;

// Variaveis para manter o loop/pausar o programa
int loop = 54;
int loop2 = 55;
char lixo;

struct Coordenadas
{
    int x;
    int y;

    Coordenadas(int a, int b)
    {
        x = a;
        y = b;
    }
};

bool operator==(Coordenadas a, Coordenadas b);