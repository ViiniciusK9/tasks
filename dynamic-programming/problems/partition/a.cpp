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

const int MAX = int(1e5); // max é em relação ao K do subsets

vi v;
int n, aux;
ll sum = 0;
ll sum1 = 0;
ll meio;


int solve(int i, ll sum)
{
    if (sum == meio) {
        return 1;
    }

    if (i == n) {
        return 0;
    }

    if (sum > meio) {
        return 0;
    }

    return max(solve(i+1, sum+v[i]), solve(i+1, sum));
}

array<int, MAX> prev_dp;
array<int, MAX> dp;

int subsets(int k) {

    ll sum = 0;

    if (n == 0) {
        return 0;
    }

    for (auto va : v) {
        sum += va;
    }
    
    if (k > sum) {
        return 0;
    }

    prev_dp[0] = 1;

    if (v[0] <= k){
        prev_dp[v[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k+1; j++) {
            dp[j] = prev_dp[j] + ((j-v[i] >= 0) ? prev_dp[j-v[i]] : 0);
        }

        prev_dp = dp;
        fill(dp.begin(), dp.end(), 0);
    }
    return prev_dp[k];
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;

        sum += aux;
        v.pb(aux);
    }

    if (sum % 2 == 1) {
        cout << "false\n";
    } else {
        meio = sum / 2;
        sum1 = 0;
        bool ans = solve(0, 0);
        if (ans) {
            cout << "true\n";
        } else {
            cout << "false\n";
        } 

        // segunda opção 
        if (subsets(meio) > 0) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome