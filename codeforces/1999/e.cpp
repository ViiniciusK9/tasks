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

const int MAX = int(2e5 + 10);

ll memo[MAX];

ll pref[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= 200000; i++)
    {
        ll aux = 0;
        int cp = i;
        while (cp > 1)
        {
            cp = cp / 3;
            aux++;
        }

        if (cp == 1)
        {
            aux++;
        }
        pref[i] = aux;
    }

    for (int i = 0; i < 200000; i++)
    {
        pref[i+1] = pref[i] + pref[i+1];
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        
        cout << pref[r]-pref[l-1] + pref[l] - pref[l-1] << '\n';

        
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome