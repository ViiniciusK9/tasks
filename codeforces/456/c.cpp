#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 112345;
int n, aux, n_vec;
array<int, MAX> valid;
array<long long, MAX> memo;
vector<long long> vec;
int vezes = 0;

map<int, int> m;
set<int> s;

long long solve(int i)
{
    if (i == n_vec) {
        return 0;
    }


    if (valid[vec[i]] == 1) {
        return solve(i+1);
    }
    
    if (memo[i] != 0) {
        return memo[i];
    }
    
    //vezes++;

    long long ans = 0;

    valid[vec[i]-1] = 1;
    valid[vec[i]+1] = 1;
    ans = (m[vec[i]] * vec[i]) + solve(i+1);
    valid[vec[i]-1] = 0;
    valid[vec[i]+1] = 0;

    memo[i] = max(ans, solve(i+1));

    return memo[i];
}   


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    

    cin >> n;
    fill(valid.begin(), valid.end(), 0);
    fill(memo.begin(), memo.end(), 0);
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        s.insert(aux);
        m[aux]++;
    }

    for(auto i : s) {
        vec.push_back(i);
    }
    n_vec = vec.size();
    
    cout << solve(0) << '\n';

    //cout << vezes << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome