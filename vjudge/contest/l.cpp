#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

const int MAX = 112345;

const int MAXT = 500;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
ll vet[MAX];
ll prefix[MAX];
    int n, g;
    
ll memo[MAX][MAXT];

ll solve(int at, int t) {

    if (at + (t-1) > n) {
        return 0;
    }

    if (memo[at][t] != 0) {
        return memo[at][t];
    }

    ll val = prefix[at + (t-1)] - prefix[at-1];
    ll ganho = g - val;

    return memo[at][t] = max(solve(at+1, t), solve(at+t, t+1) + ganho);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    memset(memo, sizeof(memo), 0);

    cin >> n >> g;

    vet[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> vet[i];
        prefix[i] = vet[i] + prefix[i-1];
    }

    cout << solve(1, 1) << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome