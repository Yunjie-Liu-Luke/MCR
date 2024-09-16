#include <iostream>
#include <string>
using namespace std;

int isWin(char game[3][3])
{
    int win = 0;
    for (int i = 0; i < 3; i++)
    {
        if (game[i][0] != ' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2])
        {
            win = (game[i][0] == 'X') ? 1 : -1;
        }
        if (game[0][i] != ' ' && game[0][i] == game[1][i] && game[1][i] == game[2][i])
        {
            win = (game[0][i] == 'X') ? 1 : -1;
        }
    }
    if (game[0][0] != ' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2])
    {
        win = (game[0][0] == 'X') ? 1 : -1;
    }
    if (game[2][0] != ' ' && game[2][0] == game[1][1] && game[1][1] == game[0][2])
    {
        win = (game[2][0] == 'X') ? 1 : -1;
    }
    return win;
}

void showMatrix(char game[3][3]){
    cout << game[0][0] << " | " << game[0][1] << " | "<< game[0][2] << endl;
    cout << "---------"<<endl;
    cout << game[1][0] << " | " << game[1][1] << " | "<< game[1][2] << endl;
    cout << "---------"<<endl;
    cout << game[2][0] << " | " << game[2][1] << " | "<< game[2][2] << endl;
}

int main()
{
    
    char game[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true;
    cout << "X = Player 1" << endl
         << "O = Player 2" << endl;

    int n = 0;
    while (n<9)
    {
        turn = !turn;
        if (!turn)
            cout << "Player 1: ";
        else
            cout << "Player 2: ";
        
        int i = 0;
        int j = 0;
        char ch1, ch2;
        
        while (true){
            cout << "Which cell to mark? i:[1..3], j:[1..3]:";
            cin >> ch1 >> ch2;
            if (ch1 >= '0' && ch1 <= '9' && ch2 >= '0' && ch2 <= '9') {
                i = ch1 - '0';
                j = ch2 - '0';
            } else {
                std::cout << "i, j should be in 1~3" << std::endl;
                continue;
            }
            if (i>3 || i<1 || j>3 || j<1 || game[i-1][j-1]!=' '){
                if (game[i-1][j-1]!=' ')
                    cout << "Already have chess pieces" << endl;
                else
                    cout << "i, j should be in 1~3" << endl;
                continue;
            }else{
                break;
            }
        }
        if (!turn)
            game[i-1][j-1] = 'X';
        else
            game[i-1][j-1] = 'O';
        int res = isWin(game);
        if (res == 1)
        {
            cout << "Player 1 Win";
            break;
        }
        else if (res == -1)
        {
            cout << "Player 2 Win";
            break;
        }
        showMatrix(game);
        n++;
    }
    if (n == 9)
        cout << "Tie!" << endl;

    showMatrix(game);

    return 0;
}
