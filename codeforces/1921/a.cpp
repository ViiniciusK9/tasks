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
        int xi, yi;
        vector<ii> v;
        for (int i = 0; i < 4; i++)
        {
            cin >> xi >> yi;
            
            v.pb({xi, yi});
        }

        if (v[0].f == v[1].f) {
            
            cout << (abs(v[0].s - v[1].s) * abs(v[2].s - v[3].s)) << '\n';
        } else if (v[0].f == v[2].f) {
            cout << (abs(v[0].s - v[2].s) * abs(v[1].s - v[3].s)) << '\n';
        } else if (v[0].f == v[3].f) {
            cout << (abs(v[0].s - v[3].s) * abs(v[2].s - v[1].s)) << '\n';
        } else if (v[1].f == v[2].f) {
            cout << (abs(v[1].s - v[2].s) * abs(v[0].s - v[3].s)) << '\n';
        } else if (v[1].f == v[3].f) {
            cout << (abs(v[1].s - v[3].s) * abs(v[0].s - v[2].s)) << '\n';
        } else if (v[2].f == v[3].f) {
            cout << (abs(v[2].s - v[3].s) * abs(v[0].s - v[1].s)) << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome