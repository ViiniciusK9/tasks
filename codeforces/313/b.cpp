#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 100005;

array<int, MAX> memo;


string s;


int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, l, r;
    string s;
    
    fill(memo.begin(), memo.end(), 0);
    

    cin >> s;
    cin >> t;
    memo[s.length()-1] = 0;
    for (int i = s.length()-2; i >= 0; i--)
    {
        if (s[i] == s[i+1]) {
            memo[i] = 1 + memo[i+1];
        } else {
            memo[i] = memo[i+1];
        }
    }
    
    
    
    while (t--)
    {
        cin >> l >> r;
        cout << abs(memo[l-1] - memo[r-1]) << '\n';
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome