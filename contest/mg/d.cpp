#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
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
    vi v;
    vi r;

    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        v.pb(aux);
    }

    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        r.pb(aux);
    }

    ll mud = 0;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {

        int at = ((v[i] + mud) + 10) % 10;

        int val1 = abs(at - r[i]);
        int val2 = 10 - val1;


        //DBG(at);
        //DBG(val1);
        //DBG(val2);

        if (val1 <= val2)
        {
            ans += val1;
            if (at > r[i])
            {
                mud -= val1;
            }
            else
            {
                mud += val1;
            }
        }
        else
        {
            ans += val2;
            if (at > r[i])
            {
                mud += val2;
            }
            else
            {
                mud -= val2;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome