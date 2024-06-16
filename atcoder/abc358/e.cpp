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

const ll M = 998244353;

ll arrfat[2000];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    vi v;
    int aux;
    ll sum = 1;
    cin >> k;
    for (int i = 0; i < 26; i++)
    {
        cin >> aux;
        sum += aux;
        v.pb(aux);
    }

    ll fat = 1;
    for (int i = 1; i <= 1000; i++)
    {
        fat = (fat * i) % M;
        arrfat[i] = fat;
    }

    ll fatk = 1;

    for (int i = 1; i <= k; i++)
    {
        fatk = (fatk * i) % M;
    }


    
    ll fat2 = 1;

    for (int i = 0; i < 26; i++)
    {
        if (v[i] >= 1) {
            fat2 = (fat2 * arrfat[v[i]]) % M;
        }
    }


    DBG(fat);
    DBG(fatk);
    DBG(fat2);
    
    cout << (fatk / fat2) << '\n';
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome