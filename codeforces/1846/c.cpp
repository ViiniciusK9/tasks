#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

bool comp(iii a, iii b) {


    if (a.f > b.f) {
        return true;
    } else if (a.f == b.f && a.s.f < b.s.f) {
        return true;
    } else if (a.f == b.f && a.s.f == b.s.f && a.s.s < b.s.s) {
        return true;
    } else {
        return false;
    }

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        ll n, m, h;
        cin >> n >> m >> h;
        vector<iii> result;
        for (int i = 0; i < n; i++)
        {
            vi v;
            for (int j = 0; j < m; j++)
            {
                int aux;
                cin >> aux;
                v.pb(aux);
            }

            sort(v.begin(), v.end());
            ll tm = 0;
            ll pen = 0;
            ll qnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (tm + v[j] <= h) {
                    qnt++;
                    pen += tm + v[j];
                    tm += v[j];
                } else {
                    break;
                }
            }

            result.pb({qnt, {pen, i}});

        }

        sort(result.begin(), result.end(), comp);

        for (int i = 0; i < result.size(); i++)
        {
            if (result[i].second.s == 0) {
                cout << i+1 << '\n';
            }
            
        }  
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome