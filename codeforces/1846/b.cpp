#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

string board[5];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> board[i];
        }

        bool achou = false;
        for (int i = 0; i < 3; i++)
        {
            char st = board[i][0];
            int qnt = 0;
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == st)
                {
                    qnt++;
                }
            }

            if (qnt == 3 && st != '.')
            {
                cout << st << '\n';
                achou = true;
                break;
            }
        }

        if (!achou)
        {

            for (int i = 0; i < 3; i++)
            {
                char st = board[0][i];
                int qnt = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (board[j][i] == st)
                    {
                        qnt++;
                    }
                }

                if (qnt == 3 && st != '.')
                {
                    cout << st << '\n';
                    achou = true;
                    break;
                }
            }
        }

        if (!achou)
        {

            char st = board[0][0];
            int qnt = 0;
            for (int i = 0; i < 3; i++)
            {

                if (board[i][i] == st)
                {
                    // DBG(board[i][i]);
                    qnt++;
                }

                // DBG(qnt);
            }

            if (qnt == 3 && st != '.')
            {
                cout << st << '\n';
                achou = true;
                
            }
        }

        if (!achou)
        {

            char st = board[0][2];
            int qnt = 0;

            if (board[0][2] == st)
            {
                qnt++;
            }

            if (board[1][1] == st)
            {
                qnt++;
            }

            if (board[2][0] == st)
            {
                qnt++;
            }

            if (qnt == 3 && st != '.')
            {
                cout << st << '\n';
                achou = true;
                
            }
        }

        if (!achou)
        {
            cout << "DRAW\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome