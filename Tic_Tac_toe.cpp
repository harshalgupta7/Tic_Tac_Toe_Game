#include <iostream>
using namespace std;

//  int space[3][3] = {{00, 01, 02} , {10, 11 , 12} , {20 , 21 , 22}};
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // labelled the cells of the matrix

int row;
int column;

char token = 'X';

bool tie = false;

string n1 = "";
string n2 = "";

void function1()
{
    

    cout << "      |     |      \n";
    cout << "   " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "    \n";
    cout << "______|_____|______\n";
    cout << "      |     |      \n";
    cout << "   " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "    \n";
    cout << "______|_____|______\n";
    cout << "      |     |      \n";
    cout << "   " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "    \n";
    cout << "      |     |      \n";

    
}

void function2()
{
    int digit;

    if (token == 'X')
    {
        cout << n1 << " Please Enter : ";
        cin >> digit;
    }
    if (token == '0')
    {
        cout << n2 << " Please Enter : " << endl;
        cin >> digit;
    }
    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if(digit<1 || digit >9)
    {
        cout << "INVALID MOVE " << endl;
    }

    if (token == 'X' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = 'X';
        token = '0';
    }
    else if (token == '0' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'X';
    }
    else
    {
        cout << "NO EMPTY SPACE " << endl;
        function2();
    }
    function1();
}

bool funtion3()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[1][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
        if (space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][0])
        {
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != '0')
            {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main()
{
    cout << "Enter the name of the PLAYER 1 - " << endl;
    getline(cin, n1);
    cout << "Enter the value o the PLAYER 2 =- " << endl;
    getline(cin, n2);

    cout << n1 << " is PLAYER 1 and will play FIRST." << endl;
    cout << n2 << " is PLAYER 2 and will play SECOND." << endl;

    while (!funtion3())
    {
        function1();
        function2();
        funtion3();
    }

    if (token == 'X' && tie == false)
    {
        cout << n2 << " WINS " << endl;
    }
    else if (token == '0' && tie == false)
    {
        cout << n1 << " WINS " << endl;
    }
    else
    {
        cout << " IT IS A DRAW ! " << endl;
    }
}