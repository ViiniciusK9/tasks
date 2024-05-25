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

const int MAX = int(11234);

int r, k;
array<int, 110> vet;
vector<int> ax;

array<int, MAX> dp;

int bottom()
{
    dp[0] = 1;

    for (auto c : ax)
    {
        for (int i = 1; i <= k; i++)
        {
            if (i >= c) {
                dp[i] = max(dp[i-c], dp[i]);
            }
        }
    }

    return dp[k];
    
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    int a, b;
    while (cin >> r >> k)
    {
        vet.fill(0);
        ax.clear();
        dp.fill(0);
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;

            vet[a]++;
            vet[b]++;
        }

        for (int i = 1; i <= r; i++)
        {
            if (vet[i] != 0){
                ax.pb(vet[i]);
            }
        }
        
        cout << (bottom() == 1 ? "S" : "N") << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome