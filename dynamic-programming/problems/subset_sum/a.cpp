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

const int MAX = int(500);

int memo[MAX][MAX];
int tab[MAX][MAX];

vi v(MAX);


int n, k;

int solve(int i, int qnt)
{
    if (qnt == 0) return 1;

    if (i == n) return 0;

    if (v[i] > qnt) {
        return memo[i][qnt] = solve(i+1, qnt);
    }

    return memo[i][qnt] = solve(i+1, qnt) + solve(i+1, qnt-v[i]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cout << solve(0, k) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome