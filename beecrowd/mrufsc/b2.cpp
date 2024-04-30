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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<char, int> m;

    int n;
    string s;
    cin >> n;
    cin >> s;
    
    for (int i = 0; i < s.length(); i++)
    {
        int maior = 0;
        for (auto j : m)
        {
            if (s[i] != j.first) {
                maior = max(maior, j.second);
            }
        }
        
        m[s[i]]++;

        if (m[s[i]] - maior >= 2) {
            cout << s[i] <<'\n';
            return 0;
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome