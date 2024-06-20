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
int t;

int solve(int qnt, int i, int sum)
{
    if (i == v.size()) {
        return (sum / t) + ((sum % t != 0 ? 1 : 0));
    }

    if (qnt == 1) {
        int ans = 0;
        for (int j = i; j < v.size(); j++)
        {
            ans += v[j];
        }
        return (ans / t) + ((ans % t != 0) ? 1 : 0);
    }

    return min(solve(qnt-1, i+1, 0) + (sum / t) + ((sum % t != 0 ? 1 : 0)), solve(qnt, i+1, sum+v[i]));
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;

    cin >> n >> c >> t;

    int aux;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.pb(aux);
    }
    
    cout << solve(c, 0, 0) << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome