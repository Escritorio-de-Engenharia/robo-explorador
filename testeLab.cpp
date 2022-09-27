#include <iostream>
#include <windows.h>

using namespace std;

char labMap[25][25] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ','#','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' '},
                       {' ',' ','#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#',' ','#','#','#','#',' ',' ',' ',' '},
                       {' ',' ','#',' ','#',' ',' ',' ','#','#','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' '},
                       {'*','#','#',' ','#',' ',' ',' ',' ',' ','#',' ','#','#','#',' ',' ',' ','#',' ',' ',' ','=',' ',' '},
                       {' ',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' '},
                       {' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ','#',' ','#','#','#',' ',' ',' ','#',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#','#',' ','#',' ',' ','#','#','#',' '},
                       {' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                       {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

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
        initialY = 0;
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
        return;
    }
    else if (labMap[robot.x][robot.y + 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        return;
    }
    else if (labMap[robot.x + 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        robot.direction = 'S';
        return;
    }
    else {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        robot.direction = 'W';
        return;
    }
}

void WestDirection()
{
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
        return;
    }
    else if (labMap[robot.x][robot.y - 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        return;
    }
    else if (labMap[robot.x - 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        robot.direction = 'N';
        return;
    }
    else {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        robot.direction = 'E';
        return;
    }
}

void NorthDirection()
{
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
        return;
    }
    else if (labMap[robot.x - 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        return;
    }
    else if (labMap[robot.x][robot.y + 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y + 1] = '*';
        robot.y++;
        robot.direction = 'E';
        return;
    }
    else {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        robot.direction = 'S';
        return;
    }
}

void SouthDirection()
{
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
        return;
    }
    else if (labMap[robot.x + 1][robot.y] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x + 1][robot.y] = '*';
        robot.x++;
        return;
    }
    else if (labMap[robot.x][robot.y - 1] == '#')
    {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x][robot.y - 1] = '*';
        robot.y--;
        robot.direction = 'W';
        return;
    }
    else {
        labMap[robot.x][robot.y] = '#';
        labMap[robot.x - 1][robot.y] = '*';
        robot.x--;
        robot.direction = 'N';
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

void PrintMap()
{
    int i, j;
    for (i = 0; i < 25; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if(labMap[i][j] == '*') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            cout << labMap[i][j];
        }
        cout << endl;
    }
}

int main()
{
    PrintMap();
    while(!IsVictory()){
        Walk();
        system("cls || clear");
        PrintMap();
    }
    return 0;
}
