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

const int MAX = int(90);
int n, x, y;
int a[MAX];
int b[MAX];
bool disp[MAX];

int solve(int t1, int t2, int qnt)
{
    if (qnt == n)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!disp[i] && t1 + a[i] <= x && t2 + b[i] <= y)
        {
            disp[i] = true;
            ans = solve(t1 + a[i], t2 + b[i], qnt + 1) + 1;
            ans = max(ans, solve(t1, t2, qnt));
            return ans;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    cout << solve(0, 0, 0) << '\n';

    // ERROR

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome