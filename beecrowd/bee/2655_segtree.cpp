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

const int MAX = int(1e5 + 10);

int n, q;
bitset<55> neutro;
array<bitset<55>, MAX> a;
array<bitset<55>, 4 * MAX> st;

void build(int cur, int l, int r)
{
    if (l == r)
    {
        st[cur] = a[l];
        return;
    }

    int m = (l + r) / 2;

    build(left(cur), l, m);
    build(right(cur), m + 1, r);

    st[cur] = st[left(cur)] | st[right(cur)];
}

void update(int cur, int l, int r, int i, bitset<55> val)
{
    if (i < l || i > r)
        return;
    if (i == l && l == r)
    {
        st[cur] = val;
        return;
    }

    int m = (l + r) / 2;

    update(left(cur), l, m, i, val);
    update(right(cur), m + 1, r, i, val);

    st[cur] = st[left(cur)] | st[right(cur)];
}

bitset<55> query(int cur, int l, int r, int i, int j)
{
    if (r < i || l > j)
        return neutro;
    if (i <= l && r <= j)
    {
        return st[cur];
    }

    int m = (l + r) / 2;

    return query(left(cur), l, m, i, j) | query(right(cur), m + 1, r, i, j);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> q >> m;
    int aux;
    bitset<55> at;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        at = (ll(1) << (aux - 1));
        a[i] = at;
        // DBG(at);
    }

    build(1, 0, n - 1);

    // cout << st[1].count() << '\n';

    while (q--)
    {
        int op, i, j;
        cin >> op >> i >> j;

        if (op == 1)
        {
            i--;
            j--;
            cout << query(1, 0, n - 1, i, j).count() << '\n';
        }
        else
        {
            i--;
            at = (ll(1) << (j - 1));
            update(1, 0, n - 1, i, at);
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome