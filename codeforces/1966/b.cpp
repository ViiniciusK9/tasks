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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 505;

string s[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        char todav = s[0][0];
        for (int i = 1; i < n; i++)
        {
            if (todav != s[i][0])
                todav = 'D';
        }

        char todavf = s[0][m - 1];
        for (int i = 1; i < n; i++)
        {
            if (todavf != s[i][m - 1])
                todav = 'D';
        }

        if (todav != 'D' && todavf != 'D' && todav != todavf)
        {
            cout << "NO\n";
        }
        else
        {

            char todah = s[0][0];
            for (int i = 1; i < m; i++)
            {
                if (todah != s[0][i])
                    todah = 'D';
            }

            char todahf = s[n - 1][0];
            for (int i = 1; i < m; i++)
            {
                if (todahf != s[n - 1][i])
                    todahf = 'D';
            }

            if (todah != 'D' && todahf != 'D' && todah != todahf)
            {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }

        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome