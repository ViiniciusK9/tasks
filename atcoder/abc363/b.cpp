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

    int n, t, p;
    vi v;
    vi a;
    int cnt = 0;
    cin >> n >> t >> p;
    for (int i = 0; i < n; i++)
    {
        int aux;

        cin >> aux;

        if (aux >= t) {
            cnt++;
        } else {
            a.pb(abs(aux - t));
        }

        v.pb(aux);
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (cnt < p) {
            ans=a[i];
            cnt++;
        } else {
            break;
        }
    }
    
    cout << ans << '\n';

    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome