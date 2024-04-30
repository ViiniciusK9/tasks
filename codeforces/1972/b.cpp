#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

string s;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> s;
        int qnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'U') qnt++;
        }

        if (qnt % 2 == 1 && qnt != 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome