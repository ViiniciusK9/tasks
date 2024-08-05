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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;   
    int mi = INT_MIN;
    vi v;
    int aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.pb(aux);
        
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > v[mx]) {
            mx = i;
        }
    }
    v[mx] = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > v[mx]) {
            mx = i;
        }
    }

    cout << mx +1 << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome