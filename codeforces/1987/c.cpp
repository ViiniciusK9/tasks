#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int at;
    vi v;
    vi aux;
    int n;
    while (t--)
    {
        v.clear();
        aux.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> at;
            v.pb(at);
            aux.pb(0);
        }

        aux[n-1] = v[n-1];

        for (int i = n-2; i >= 0; i--)
        {
            if (v[i] > v[i+1]) {
                if (abs(v[i] - v[i+1]) <= aux[i+1] - v[i+1]) {
                    aux[i] = aux[i+1]+1;
                } else {
                    aux[i] = v[i];
                }
            } else {
                aux[i] = aux[i+1] +1;
            }
        }

        cout << *max_element(aux.begin(), aux.end()) << '\n';
        
        
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome