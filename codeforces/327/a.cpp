#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

array<array<int, 123>, 2> memo;

vector<int> vet;
int solve(int i, bool start, bool parou)
{
    if (i == vet.size() && start == false)
    {
        return -1;
    }

    if (i == vet.size() && start == true)
    {
        return 0;
    }

    if (memo[start][i] != 0) return memo[start][i];

    if (!parou && start && vet[i] == 1) {
        memo[start][i] = max({solve(i+1, true, false) - 1, solve(i+1, true, true) +1});
        return memo[start][i];
    } else if (!parou && start && vet[i] == 0) {
        memo[start][i] = max({solve(i+1, true, false) + 1, solve(i+1, true, true)});
        return memo[start][i]; 
    } else if (!parou && vet[i] == 0) {
        memo[start][i] = max({solve(i+1, false, false), solve(i+1, true, false) + 1});
        return memo[start][i]; 
    } 

    if (parou) {
        if (vet[i] == 1){
            memo[start][i] = solve(i+1, true, true) +1;
            return memo[start][i];
        } else {
            memo[start][i] = solve(i+1, true, true);
            return memo[start][i];
        }
    }

    memo[start][i] = max({solve(i+1, false, false) + 1});
    return memo[start][i]; 
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux;
    cin >> n;

    fill(memo[0].begin(), memo[0].end(), 0);
    fill(memo[1].begin(), memo[1].end(), 0);

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet.push_back(aux);
    }
    
    
    cout << solve(0, false, false) << '\n';
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome