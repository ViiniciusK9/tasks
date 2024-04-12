#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int t, n, aux, maior, menor, i_maior, i_menor;
vi v;
int memo[101][101][2][2];

int solve(int i, int j, bool me, bool ma)
{
    if (i > j || j < i)
    {
        return 0;
    }

    if (me == true && ma == true) return 0;

    if (memo[i][j][me][ma] != 0) return memo[i][j][me][ma];

    if (v[i] == maior) {
        return memo[i][j][me][ma] = solve(i+1, j, me, true) + 1;
    }

    if (v[i] == menor) {
        return memo[i][j][me][ma] = solve(i+1, j, true, ma)  + 1;
    }

    if (v[j] == maior) {
        return memo[i][j][me][ma] = solve(i, j-1, me, true) + 1;
    }

    if (v[j] == menor) {
        return memo[i][j][me][ma] = solve(i, j-1, true, ma) + 1;
    }
    
    return memo[i][j][me][ma] = min(solve(i+1, j, me, ma) +1, solve(i, j-1, me, ma) +1);
}
const int MAX = 1e9;
int arr[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;

    while (t--)
    {
        cin >> n;
        menor = 10000;
        maior = i_maior = i_menor = 0;
        v.clear();
        memset(memo, 0, sizeof(memo));
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (aux > maior) {
                maior = aux;
                i_maior = i;
            }
            if (aux < menor) {
                menor = aux;
                i_menor = i;
            }
            v.PB(aux);
        }

        cout << solve(0, n-1, false, false) << '\n';

        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome