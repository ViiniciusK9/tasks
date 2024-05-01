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

    int t;
    ll n, k, aux;

    map<ll, ll> m;

    vector<pair<ll, ll>> vt;
    vector<ll> vv;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        vv.clear();
        vt.clear();
        m.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vv.PB(aux);
            m[aux]++;
        }

        for (auto i : m)
        {
            //cout << i.first << " : " << i.second << '\n';
            vt.push_back({i.first, i.second});
        }

        for (int i = 0; i < vt.size(); i++) {
            if (vt[i].second <= k) {
                if (i+1 < vt.size()) {
                    while (vt[i].first+1 <= vt[i+1].first && vt[i].second <= k)
                    {
                        //DBG(i);
                        k-=vt[i].second;
                        vt[i].first = vt[i].first + 1;
                    }
                    
                    if (vt[i+1].first == vt[i].first) {
                        k-=vt[i].second;
                        vt[i+1].second += vt[i].second;
                        vt[i].second = -1;
                    }
                }
            }
        }

        ll m1, m2;

        for (auto i : vt)
        {
            if (i.second != -1) {
                m1 = i.first;
                m2 = i.second;
                break;
            }
        }
        
        ll tam = m1*n;

        
        for (auto i : vv)
        {
            if (i <= m1 && k >= 1) {
                tam++;
                k--;
            } else if (i <= m1 && k == 0) {
                break;
            } else if (i > m1) {
                tam++;
            }
            
        }
            
        

        cout << tam - (n-1) << '\n';

        /*
        for(auto i : vt) {
            cout << i.first << " : " << i.second << '\n';
        }
        
        */
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome