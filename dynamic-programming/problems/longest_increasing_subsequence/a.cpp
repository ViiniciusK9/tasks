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


int memo[MAX];
vi v;

int lis(int k) {
    memo[0] = 1;
    int maxn;
    for (int i = 1; i < k; i++) {

        maxn = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i] && memo[j] > maxn ) {
                maxn = memo[j];
            }
        }
        memo[i] = 1 + maxn;
    }

    int ans = 0;

    for (int i = 0; i < k; i++) {
        ans = max(ans, memo[i]);
    }

    return ans;
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
    memset(memo, 0, sizeof(memo));
    cout << lis(n) << '\n';
        
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome