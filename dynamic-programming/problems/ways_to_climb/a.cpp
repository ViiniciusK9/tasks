#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed << std::setprecision(1) << (x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 100;

int memo[MAX][MAX];
int memo2[MAX];
int tab[MAX];
int t, n, aux;
vi v;

int solve(int i, int tam)
{
    if (tam == 0)
        return 1;
    if (tam < 0)
        return 0;
    if (memo[i][tam] != 0)
        return memo[i][tam];

    if (i == n || i < 0)
        return 0;

    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans += solve(j, tam - v[j]);
    }
    return memo[i][tam] = ans;

    // return solve(i, tam-v[i]) + solve(i+1, tam);
}

int solve2(int tam)
{
    if (tam == 0)
        return 1;
    if (tam < 0)
        return 0;
    if (memo2[tam] != 0)
        return memo2[tam];


    int ans = 0;
    for (auto pulo : v)
    {
        if (tam - pulo >= 0) {
            ans += solve2(tam - pulo);
        }
    }
    return memo2[tam] = ans;

    // return solve(i, tam-v[i]) + solve(i+1, tam);
}

int solve_bottom_up(int tam)
{
    tab[0] = 1;

    for (int i = 1; i <= tam; i++)
    {
        for (auto pulo : v)
        {
            if (i - pulo >= 0)
            {
                tab[i] += tab[i - pulo];
            }
        }
    }

    return tab[tam];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.PB(aux);
    }

    cout << solve_bottom_up(t) << '\n';

    cout << solve2(t) << '\n';

    for (int i = 0; i <= t; i++) {
        cout << memo2[i] << ' ';
    }
    cout << '\n';

    /*
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << memo[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    for (int i = 0; i <= t; i++)
    {
        cout << tab[i] << ' ';
    }
    cout << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome