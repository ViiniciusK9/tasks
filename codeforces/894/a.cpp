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

    long long ans = 0;
    int qnt = 0;
    vi v1;
    vi v2;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'Q'){
            qnt++;
        }
        v1.PB(qnt);
    }

    qnt = 0;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i] == 'Q'){
            qnt++;
        }
        v2.PB(qnt);
    }

    reverse(v2.begin(), v2.end());

    for (int i = 1; i < s.length()-1; i++)
    {
        if (s[i] == 'A'){
            ans += v1[i-1] * v2[i+1];
        }
    }
    
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome