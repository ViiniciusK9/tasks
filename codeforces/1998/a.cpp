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
        int x, y, k;
        cin >> x >> y >> k;

        int x1 = x * k;
        int y1 = y * k;
        vector<ii> v(k+1);
        int sum = 0;
        for (int i = 1; i <= k - 1; i++)
        {
            v[i].first = i;
            v[i].second = i;
            sum += i;
        }

        if (x1 > 0)
        {
            v[k].first = x1 - sum;
        } else if (x1 <= 0) {
            v[k].first = x1 - sum;
        }

        v[k].second = (y1 <= 0 ? y1 - sum : y1 - sum);

        for (int i = 1; i <= k; i++)
        {
            ii el = v[i];
            cout << el.first << " " << el.second << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome