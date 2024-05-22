#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;


vector<pi> vet;
int memo[12312][110];
int n;

int solve(int i, int tam) {
    if (i == n) {
        return 0;
    }

    if (memo[i][tam] != 0) {
        return memo[i][tam];
    }

    if (vet[i].first <= tam) {
        return memo[i][tam] = max(solve(i+1, tam-vet[i].first) + vet[i].second, solve(i+1, tam)); 
    }

    return memo[i][tam] = solve(i+1, tam);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, w, v;
    int caso =1;
    while (cin >> n >> c)
    {
        if (n == 0) {
            break;
        }

        vet.clear();
        memset(memo, 0, sizeof(memo));

        for (int i = 0; i < n; i++)
        {
            cin >> w >> v;
            vet.pb({w, v});
        }

        cout <<"Caso " << caso << ": " << solve(0, c) << '\n';

        caso++;
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome