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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int mat[112][112];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n, m;
    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        int mud = 1;

        while (mud)
        {
            mud = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int val = mat[i][j];
                    int ma = 1;
                    int maior = 0;
                    if (i + 1 < n && mat[i + 1][j] >= val)
                    {
                        ma = 0;
                    }

                    if (i - 1 >= 0 && mat[i - 1][j] >= val)
                    {
                        ma = 0;
                    }

                    if (j + 1 < m && mat[i][j + 1] >= val)
                    {
                        ma = 0;
                    }

                    if (j - 1 >= 0 && mat[i][j - 1] >= val)
                    {
                        ma = 0;
                    }

                    if (ma == 1)
                    {
                        mud = 1;

                        if (i + 1 < n)
                        {
                            maior = max(mat[i+1][j], maior);
                        }

                        if (i - 1 >= 0)
                        {
                            maior = max(mat[i-1][j], maior);
                        }

                        if (j + 1 < m)
                        {
                            maior = max(mat[i][j+1], maior);
                        }

                        if (j - 1 >= 0)
                        {
                            maior = max(mat[i][j-1], maior);
                        }
                        mat[i][j] = maior;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome