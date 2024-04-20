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

const int MAX = 3650;

int tam = 0;
int memo[MAX][MAX];
vector<pi> vpi;

int solve(int i, int time) {
    if (i == tam) {
        return 0;
    }

    if (memo[i][time] != 0) {
        return memo[i][time];
    }

    if (time > vpi[i].F) {
        return memo[i][time] = solve(i+1, time);
    }

    return memo[i][time] = max(solve(i+1, time), solve(i+1, vpi[i].S) + vpi[i].S - vpi[i].F);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    int n, a1, a2;
    cin >> n;
    while (n--)
    {
        cin >> a1 >> a2;
        vpi.PB({a1, a2});
    }
    
    sort(vpi.begin(), vpi.end());
    tam = vpi.size();
    cout << solve(0, 0) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome