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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    string s1;

    map<char, int> ma;

    cin >> t;

    while (t--)
    {
        ma.clear();
        cin >> n >> m;
        cin >> s1;

        for (auto vi : s1)
        {
            ma[vi]++;
        }

        int ans = 0;
        int sum = 0;
        
        if (ma['A'] < m) {
            ans += abs(m-ma['A']);
        }

        if (ma['B'] < m) {
            ans += abs(m-ma['B']);
        }

        if (ma['C'] < m) {
            ans += abs(m-ma['C']);
        }

        if (ma['D'] < m) {
            ans += abs(m-ma['D']);
        }

        if (ma['E'] < m) {
            ans += abs(m-ma['E']);
        }

        if (ma['F'] < m) {
            ans += abs(m-ma['F']);
        }

        if (ma['G'] < m) {
            ans += abs(m-ma['G']);
        }

        cout << ans << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome