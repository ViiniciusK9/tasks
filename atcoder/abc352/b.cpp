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

    string s, t;

    cin >> s >> t;

    int i = 0;
    int j = 0;
    vi v;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j]) {
            v.pb(j);
            i++;
            j++;
        } else {
            j++;
        }
    }
    
    cout << v[0] + 1;
    for (int x = 1; x < v.size(); x++)
    {
        cout << " " << v[x] + 1;
    }
    cout << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome