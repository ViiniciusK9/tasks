#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define fi first 
#define se second 
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

    int n, c, sum = 0;
    string s;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> c;
        sum+=c;
        v.pb(s);
    }

    sort(v.begin(), v.end());

    int ans = sum % n;
    cout << v[ans] << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome