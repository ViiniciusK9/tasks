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

const int INF = int(1e9);

vi train_days;
set<int> t_d;
vi costs;
int n, aux, k;

int memo[100000];
int dp[100000];

int solve(int i) 
{
    //DBG(i);
    if (i >= train_days.back()) {
        return 0;
    }

    if (memo[i]) return memo[i];

    int up = train_days[upper_bound(train_days.begin(), train_days.end(), i) - train_days.begin()];
    
    return memo[i] = min({solve(up) + costs[0], solve(up+6) + costs[1], solve(up+29) + costs[2],});
}

int cost()
{
    int day_cost, week_cost, month_cost;
    for (int i = 0; i < k; i++) {
        if (t_d.find(i) == t_d.end()) {
            dp[i] = ((i-1 >= 0) ? dp[i-1] : 0);
        } else {
            day_cost = costs[0] + ((i-1 >= 0) ? dp[i-1] : 0);
            week_cost = costs[1] + ((i-7 >= 0) ? dp[i-7] : 0);
            month_cost = costs[2] + ((i-30 >= 0) ? dp[i-30] : 0);
            dp[i] = min({day_cost, week_cost, month_cost});
        }
    }
    return dp[k-1];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        train_days.pb(aux);
        t_d.insert(aux);
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> aux;
        costs.pb(aux);
    }

    cout << solve(0) << '\n';
    
    cout << cost() << '\n';

    //DBG(k);

    for (int i = 0; i < k; i++)
    {
        //cout << dp[i] << " ";
    }
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome