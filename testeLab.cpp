#include <iostream>
#include <windows.h>

using namespace std;

char labMap[25][25] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', '#', '#', '#', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', '#', '#', '#', ' ', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
                       {' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' '},
                       {'|', '*', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '=', ' ', ' '},
                       {' ', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#', '#', '#', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

int carPath[2][200];
int carPathIndex = 0;

char path[100];
int pathIndex;

typedef struct Robot
{
    int initialX;
    int initialY;
    int x;
    int y;
    char direction;

    Robot()
    {
        initialX = 12;
        initialY = 1;
        x = initialX;
        y = initialY;
        direction = 'E';
    }
} Robot;

enum Intersections
{
    T = 0,
    Cross = 1,
    Left = 2,
    Right = 3,
    LeftFront = 4,
    RightFront = 5,
    Back = 6
};

Robot robot;

Intersections CheckIntersection()
{
}

void EastDirection()
{
    carPath[0][carPathIndex] = robot.x;
    carPath[1][carPathIndex] = robot.y;
    carPathIndex++;

    if (labMap[robot.x + 1][robot.y] == ' ' && labMap[robot.x - 1][robot.y] == ' ' && labMap[robot.x][robot.y + 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        return;
    }

    if (labMap[robot.x - 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        robot.direction = 'N';
        path[pathIndex] = 'L';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x][robot.y + 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        path[pathIndex] = 'F';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x + 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        robot.direction = 'S';
        path[pathIndex] = 'R';
        pathIndex++;
        return;
    }
    else
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        robot.direction = 'W';
        path[pathIndex] = 'B';
        pathIndex++;
        return;
    }
}

void WestDirection()
{
    carPath[0][carPathIndex] = robot.x;
    carPath[1][carPathIndex] = robot.y;
    carPathIndex++;

    if (labMap[robot.x + 1][robot.y] == ' ' && labMap[robot.x - 1][robot.y] == ' ' && labMap[robot.x][robot.y - 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        return;
    }

    if (labMap[robot.x + 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        robot.direction = 'S';
        path[pathIndex] = 'L';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x][robot.y - 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        path[pathIndex] = 'F';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x - 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        robot.direction = 'N';
        path[pathIndex] = 'R';
        pathIndex++;
        return;
    }
    else
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        robot.direction = 'E';
        path[pathIndex] = 'B';
        pathIndex++;
        return;
    }
}

void NorthDirection()
{
    carPath[0][carPathIndex] = robot.x;
    carPath[1][carPathIndex] = robot.y;
    carPathIndex++;

    if (labMap[robot.x][robot.y + 1] == ' ' && labMap[robot.x][robot.y - 1] == ' ' && labMap[robot.x - 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        return;
    }

    if (labMap[robot.x][robot.y - 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        robot.direction = 'W';
        path[pathIndex] = 'L';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x - 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        path[pathIndex] = 'F';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x][robot.y + 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        robot.direction = 'E';
        path[pathIndex] = 'R';
        pathIndex++;
        return;
    }
    else
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        robot.direction = 'S';
        path[pathIndex] = 'B';
        pathIndex++;
        return;
    }
}

void SouthDirection()
{
    carPath[0][carPathIndex] = robot.x;
    carPath[1][carPathIndex] = robot.y;
    carPathIndex++;

    if (labMap[robot.x][robot.y + 1] == ' ' && labMap[robot.x][robot.y - 1] == ' ' && labMap[robot.x + 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        return;
    }

    if (labMap[robot.x][robot.y + 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        robot.direction = 'E';
        path[pathIndex] = 'L';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x + 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        path[pathIndex] = 'F';
        pathIndex++;
        return;
    }
    else if (labMap[robot.x][robot.y - 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        robot.direction = 'W';
        path[pathIndex] = 'R';
        pathIndex++;
        return;
    }
    else
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        robot.direction = 'N';
        path[pathIndex] = 'B';
        pathIndex++;
        return;
    }
}

void Walk()
{
    switch (robot.direction)
    {
    case 'N':
        NorthDirection();
        break;
    case 'S':
        SouthDirection();
        break;
    case 'E':
        EastDirection();
        break;
    case 'W':
        WestDirection();
        break;
    default:
        break;
    }
}

bool IsVictory()
{
    if (labMap[robot.x][robot.y + 1] == '=')
        return true;
    if (labMap[robot.x][robot.y - 1] == '=')
        return true;
    if (labMap[robot.x - 1][robot.y] == '=')
        return true;
    if (labMap[robot.x + 1][robot.y] == '=')
        return true;
    return false;
}

bool CheckIfCarPath(int x, int y) {
    int i;
    for(i = 0; i < carPathIndex; i++) {
        if(carPath[0][i] == x && carPath[1][i] == y) {
            return true;
        }
    }
    return false;
}

void PrintMap()
{
    int i, j;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if (labMap[i][j] == '*')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            }
            else if(CheckIfCarPath(i, j)) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            cout << labMap[i][j];
        }
        cout << endl;
    }
}

void PrintPath(bool isOrganized)
{   
    if(isOrganized)
        cout << "Correct Path = [ ";
    else
        cout << "Path = [ ";
    int i;
    for (i = 0; i < pathIndex; i++)
    {
        cout << path[i] << " ";
    }
    cout << "]\n\n";
}

void OrganizePath(int position) {
    int i;
    for(i = position + 2; i < pathIndex - 1; i++) {
        path[i - 1] = path[i + 1];
    }
    pathIndex -= 2;
}

void CheckPath()
{
    char tempPath[100];
    int i = 0;
    while (true)
    {
        if(i + 2 > pathIndex)
            break;

        char firstChar = path[i];
        char secondChar = path[i + 1];
        char thirdChar = path[i + 2];

        if(firstChar == 'L' && secondChar == 'B' && thirdChar == 'R') {
            path[i] = 'B';
            OrganizePath(i);
            i = 0;
            continue;
        }
        if(firstChar == 'L' && secondChar == 'B' && thirdChar == 'F') {
            path[i] = 'R';
            OrganizePath(i);
            i = 0;
            continue;
        }
        if(firstChar == 'R' && secondChar == 'B' && thirdChar == 'L') {
            path[i] = 'B';
            OrganizePath(i);
            i = 0;
            continue;
        }
        if(firstChar == 'F' && secondChar == 'B' && thirdChar == 'L') {
            path[i] = 'R';
            OrganizePath(i);
            i = 0;
            continue;
        }
        if(firstChar == 'F' && secondChar == 'B' && thirdChar == 'F') {
            path[i] = 'B';
            OrganizePath(i);
            i = 0;
            continue;
        }
        if(firstChar == 'L' && secondChar == 'B' && thirdChar == 'L') {
            path[i] = 'F';
            OrganizePath(i);
            i = 0;
            continue;
        }

        i++;
    }
}

int main()
{
    PrintMap();
    while (!IsVictory())
    {
        Walk();
        system("cls || clear");
        PrintMap();
    }
    PrintPath(false);
    CheckPath();
    PrintPath(true);
    return 0;
}
