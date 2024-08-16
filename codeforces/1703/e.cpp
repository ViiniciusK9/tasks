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

string mat[123];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];
        }

        int ans = 0;

        if (n % 2 == 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                for (int j = 0; j < n / 2; j++)
                {
                    int aux = 0;
                    aux += (mat[i][j] == '1' ? 1 : 0);
                    aux += (mat[j][n - 1 - i] == '1' ? 1 : 0);
                    aux += (mat[n - 1 - i][n - 1 - j] == '1' ? 1 : 0);
                    aux += (mat[n - 1 - j][i] == '1' ? 1 : 0);

                    if (aux == 0 || aux == 4)
                    {
                        continue;
                    }
                    else if (aux == 1 || aux == 3)
                    {
                        ans += 1;
                    }
                    else
                    {
                        ans += 2;
                    }
                }
            }

            map<int, int> ma;

            for (int i = 0; i < n; i++)
            {
                int m = n/2;
                ma[i] += (mat[i][m] == '1' ? 1 : 0 );
            }

            for (int i = 0; i < n; i++)
            {
                int m = n/2;
                ma[i] += (mat[n-1-i][m] == '1' ? 1 : 0 );
            }

            for (int i = 0; i < n; i++)
            {
                int m = n/2;
                ma[i] += (mat[m][i] == '1' ? 1 : 0 );
            }

            for (int i = 0; i < n; i++)
            {
                int m = n/2;
                ma[i] += (mat[m][n-1-i] == '1' ? 1 : 0 );
            }
            
            for (auto el : ma)
            {
                if (el.first == (n/2)) {
                    break;
                }
                
                if (el.second == 1 || el.second == 3) {
                    ans += 1;
                } else if (el.second == 0 || el.second == 4) {
                    ans = ans;
                } else if (el.second == 2){
                    ans += 2;
                }
            }
            

            cout << ans << '\n';
        }
        else
        {

            for (int i = 0; i < n / 2; i++)
            {
                for (int j = 0; j < n / 2; j++)
                {
                    int aux = 0;
                    aux += (mat[i][j] == '1' ? 1 : 0);
                    aux += (mat[j][n - 1 - i] == '1' ? 1 : 0);
                    aux += (mat[n - 1 - i][n - 1 - j] == '1' ? 1 : 0);
                    aux += (mat[n - 1 - j][i] == '1' ? 1 : 0);

                    if (aux == 0 || aux == 4)
                    {
                        continue;
                    }
                    else if (aux == 1 || aux == 3)
                    {
                        ans += 1;
                    }
                    else
                    {
                        ans += 2;
                    }
                }
            }

            cout << ans << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome