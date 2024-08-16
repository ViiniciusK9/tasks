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

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        if (a - x >= 0 && b - y >= 0)
        {
            cout << "YES\n";
        }
        else
        {

            int res = a-x;
            if (res <= 0)
            {
                res = c + res;
            
                
                if (res >= 0 && (res + b) - y >= 0)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            } else {
                res = c;
                if (res >= 0 && (res + b) - y >= 0)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome