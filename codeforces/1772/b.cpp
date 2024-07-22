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

int mat[10][10];
int aux[10][10];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> mat[i][j];
                aux[i][j] = mat[i][j];
            }
        }

        if (mat[0][0] < mat[0][1] && mat[1][0] < mat[1][1] && mat[0][0] < mat[1][0] && mat[0][1] < mat[1][1])
        {
            cout << "YES\n";
        }
        else
        {
            mat[0][0] = aux[1][0];
            mat[0][1] = aux[0][0];
            mat[1][0] = aux[1][1];
            mat[1][1] = aux[0][1];

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    aux[i][j] = mat[i][j];
                }
            }

            if (mat[0][0] < mat[0][1] && mat[1][0] < mat[1][1] && mat[0][0] < mat[1][0] && mat[0][1] < mat[1][1])
            {
                cout << "YES\n";
            }
            else
            {
                mat[0][0] = aux[1][0];
                mat[0][1] = aux[0][0];
                mat[1][0] = aux[1][1];
                mat[1][1] = aux[0][1];

                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        aux[i][j] = mat[i][j];
                    }
                }

                if (mat[0][0] < mat[0][1] && mat[1][0] < mat[1][1] && mat[0][0] < mat[1][0] && mat[0][1] < mat[1][1])
                {
                    cout << "YES\n";
                }
                else
                {
                    mat[0][0] = aux[1][0];
                    mat[0][1] = aux[0][0];
                    mat[1][0] = aux[1][1];
                    mat[1][1] = aux[0][1];

                    for (int i = 0; i < 2; i++)
                    {
                        for (int j = 0; j < 2; j++)
                        {
                            aux[i][j] = mat[i][j];
                        }
                    }

                    if (mat[0][0] < mat[0][1] && mat[1][0] < mat[1][1] && mat[0][0] < mat[1][0] && mat[0][1] < mat[1][1])
                    {
                        cout << "YES\n";
                    }
                    else
                    {

                        cout << "NO\n";
                    }
                }
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome