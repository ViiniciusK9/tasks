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

const int MAX = 51000;
int r, ta;
array<int, 110> vet;

array<int, MAX> prev_dp;
array<int, MAX> dp;

int subsets(int k) {
    prev_dp[0] = 1;

    if (vet[0] <= k){
        prev_dp[vet[0]] = 1;
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < k+1; j++) {
            dp[j] = prev_dp[j] + ((j-vet[i] >= 0) ? prev_dp[j-vet[i]] : 0);
        }

        prev_dp = dp;
        //fill(dp.begin(), dp.end(), 0);
        dp.fill(0);
    }
    return prev_dp[k];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    int a, b;
    while (cin >> r >> ta)
    {
        vet.fill(0);
        dp.fill(0);
        prev_dp.fill(0);
        
        for (int i = 0; i < ta; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            vet[a]++;
            vet[b]++;
        }

        //cout << (solve(1, k) == 1 ? "S" : "N") << '\n';
        if (subsets(ta) > 0) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }


        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome