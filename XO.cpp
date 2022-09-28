#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,r,c;
    cin >> n;
    char a[n][n]; // grid
    int v[n][n]; // checking for reserved values

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = '.';
            v[i][j] = 0;
        }
    char player = 'O';

    int flag = -1;
    int co = 1;

    while (true){
        
        cout << "player " << player << " turn. Enter empty location (r,c): ";
        cin >> r >> c;
        r--;
        c--;
        if (r > n || c > n || r < 0 || c < 0 || v[r][c] == -1)
        {
            cout << "Invalid input. Try again";
            continue;
        }
        else
        {
            a[r][c] = player;
            v[r][c] = -1;
        }

        //printing the board
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }


        // check row
        for (int i = 0; i < n; i++)
        {
            if (a[r][i] == player)
            {
                flag = 1;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
        cout << "Player " << player << " won" << endl;
        return 0;
        }

        //check column
        for (int i = 0; i < n; i++)
        {
            if (a[i][c] == player)
            {
                flag = 1;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        // check right di
        for (int i = 0; i < n; i++)
        {
             if (a[i][i] == player)
            {
                flag = 1;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
        cout << "Player " << player << " won" << endl;
        return 0;
        }


        // check left di
        for (int i = 0; i < n; i++)
        {
             if (a[i][n-i-1] == player)
            {
                flag = 1;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
        cout << "Player " << player << " won" << endl;
        return 0;
        }

        // checking for tie
        if (co == (n*n))
        {
            cout << "It is Tie!" << endl;
            return 0;
        }
        else
        {
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }
        co++;
    }
}