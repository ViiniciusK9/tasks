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

vi v;

int memo[120][4];

int solve(int i, int ant)
{
    if (i == v.size()) {
        return 0;
    }

    if (memo[i][ant]) return memo[i][ant];

    if (v[i] == 0) {
        // não pode fazer nada
        return memo[i][ant] = solve(i+1, 0);
    } else if (v[i] == 1) {
        // contest
        if (ant == 1) {
            return memo[i][ant] = solve(i+1, 0);
        } else {
            return memo[i][ant] = solve(i+1, 1) +1;
        }
    } else if (v[i] == 2) {
        // gym
        if (ant == 2) {
            return memo[i][ant] = solve(i+1, 0);
        } else {
            return memo[i][ant] = solve(i+1, 2) +1;
        }
    } else {
        // contest and gym
        if (ant == 1) {
            return memo[i][ant] = solve(i+1, 2) + 1;
        } else if (ant == 2) {
            return memo[i][ant] = solve(i+1, 1) + 1;
        } else {
            return memo[i][ant] = max(solve(i+1, 1) +1, solve(i+1, 2) +1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.pb(aux);
    }
    
    cout << n - solve(0, 0) << '\n';




    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome