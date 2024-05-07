#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(112345);

int v[MAX];
int st[4 * MAX];
int n, k;

int _build(int p, int l, int r)
{
    if (l == r)
    {
        return st[p] = v[l];
    }

    int mid = (l + r) / 2;

    return st[p] = _build(left(p), l, mid) * _build(right(p), mid + 1, r);
}

int _update(int p, int l, int r, int i, int val)
{
    if (i < l || i > r) return st[p];
    if (i == l && l == r) return st[p] = val;

    int mid = (l + r) / 2;

    return st[p] = _update(left(p), l, mid, i, val) * _update(right(p), mid + 1, r, i, val); 
}

int _query(int p, int l, int r, int i, int j)
{
    if (r < i || l > j) return 1;
    if (i <= l && r <= j)
    {
        return st[p];
    }

    int mid = (l + r) / 2;

    return _query(left(p), l, mid, i, j) * _query(right(p), mid + 1, r, i, j);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char op;
    int i, j, ans;
    while (cin >> n >> k)
    {
        memset(st, 0, sizeof(st));
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i])
                v[i] /= abs(v[i]);
        }

        _build(1, 0, n - 1);

        while (k--)
        {
            cin >> op >> i >> j;
            if (op == 'C')
            {
                i--;
                if (j)
                    j /= abs(j);
                _update(1, 0, n - 1, i, j);
            }
            else if (op == 'P')
            {
                i--;
                j--;
                ans = _query(1, 0, n - 1, i, j);

                if (ans)
                {
                    if (ans > 0)
                    {
                        cout << '+';
                    }
                    else
                    {
                        cout << '-';
                    }
                }
                else
                {
                    cout << '0';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome