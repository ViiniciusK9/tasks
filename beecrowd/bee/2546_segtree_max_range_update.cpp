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
array<int, MAX> a;
array<pi, 4 * MAX> st;
array<int, 4 * MAX> lazy;

void build(int cur, int l, int r)
{
    lazy[cur] = 0;

    if (l == r)
    {
        st[cur].f = a[l];
        st[cur].s = l;
        return;
    }

    int m = (l + r) / 2;

    build(left(cur), l, m);
    build(right(cur), m + 1, r);

    if (st[left(cur)].f < st[right(cur)].f) {
        st[cur].f = st[right(cur)].f;
        st[cur].s = st[right(cur)].s;
    } else if (st[left(cur)].f == st[right(cur)].f) {
        if (st[left(cur)].s < st[right(cur)].s) {
            st[cur].f = st[left(cur)].f;
            st[cur].s = st[left(cur)].s;
        } else {
            st[cur].f = st[right(cur)].f;
            st[cur].s = st[right(cur)].s;
        }
    } else {
        st[cur].f = st[left(cur)].f;
        st[cur].s = st[left(cur)].s;
    }
    
}

void prop(int cur, int l, int r)
{
    st[cur].f += lazy[cur];

    if (l != r)
    {
        lazy[left(cur)] += lazy[cur];
        lazy[right(cur)] += lazy[cur];
    }
    lazy[cur] = 0;
}

void update(int cur, int l, int r, int i, int j, int val)
{
    prop(cur, l, r);
    if (r < i || l > j)
        return;
    if (l >= i && r <= j)
    {
        lazy[cur] += val;
        prop(cur, l, r);
        return;
    }

    int m = (l + r) / 2;

    update(left(cur), l, m, i, j, val);
    update(right(cur), m + 1, r, i, j, val);

    if (st[left(cur)].f < st[right(cur)].f) {
        st[cur].f = st[right(cur)].f;
        st[cur].s = st[right(cur)].s;
    } else if (st[left(cur)].f == st[right(cur)].f) {
        if (st[left(cur)].s < st[right(cur)].s) {
            st[cur].f = st[left(cur)].f;
            st[cur].s = st[left(cur)].s;
        } else {
            st[cur].f = st[right(cur)].f;
            st[cur].s = st[right(cur)].s;
        }
    } else {
        st[cur].f = st[left(cur)].f;
        st[cur].s = st[left(cur)].s;
    }
}

pi query(int cur, int l, int r, int i, int j)
{
    prop(cur, l, r);
    if (r < i || l > j)
        return {-1e9, -1e9};
    if (l >= i && r <= j)
    {
        return st[cur];
    }

    int m = (l + r) / 2;

    pi lf = query(left(cur), l, m, i, j);
    pi rg = query(right(cur), m+1, r, i, j);
    if (lf.f < rg.f) {
        return rg;
    } else if (lf.f == rg.f) {
        if (lf.s < rg.s) {
            return lf;
        } else {
            return rg;
        }
    } else {
        return lf;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> q)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        build(1, 0, n-1);

        while (q--)
        {
            char op;
            cin >> op;
            if (op == 'C')
            {
                int i, j;
                cin >> i >> j;
                i--;
                j--;
                cout << query(1, 0, n-1, i, j).s + 1 << '\n';
            }
            else
            {
                int i, j, v;
                cin >> i >> j >> v;
                i--;
                j--;
                update(1, 0, n-1, i, j, v);
            }
        }
    }
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome