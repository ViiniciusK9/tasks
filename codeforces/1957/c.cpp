#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

const int M = 1e9+7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int escolha(int n) {
    return (((n*n) - (((1+n)*n)/2)) * 2);
}



int solve(int n) {
    if (n == 2) return 3;
    if (n <= 1) return 1;


    return solve(n-1) + solve(n-2) * 2 * (n-1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, r, c, nn;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        nn = n;
        for (int i = 0; i < k; i++)
        {
            cin >> r >> c;
            if (r == c) {
                nn-=1;
            } else {
                nn-=2;
            }

        }
        DBG(nn);
        cout << solve(nn) << '\n';
        DBG(escolha(4));
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome