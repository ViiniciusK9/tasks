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
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

const int MAX = int(2e5 + 10);

array<ll, MAX> pref;
array<ll, 4 * MAX> st;
array<ll, 4 * MAX> lazy;
array<ll, 4 * MAX> lazy_min;

array<ll, 4 * MAX> stp;

void build(int cur, int l, int r)
{
    lazy_min[cur] = 0;
    if (l == r)
    {
        st[cur] = pref[l];
        return;
    }

    int m = (l + r) / 2;

    build(left(cur), l, m);
    build(right(cur), m + 1, r);

    st[cur] = min(st[left(cur)], st[right(cur)]);
}

void build_p(int cur, int l, int r)
{
    lazy[cur] = 0;
    if (l == r)
    {
        stp[cur] = pref[l];
        return;
    }

    int m = (l + r) / 2;

    build_p(left(cur), l, m);
    build_p(right(cur), m + 1, r);

    stp[cur] = stp[left(cur)] + stp[right(cur)];
}

void prop(int cur, int l, int r)
{
    stp[cur] += lazy[cur];

    if (l != r)
    {
        lazy[left(cur)] += lazy[cur];
        lazy[right(cur)] += lazy[cur];
    }
    lazy[cur] = 0;
}

void prop_min(int cur, int l, int r)
{
    st[cur] += lazy_min[cur];

    if (l != r)
    {
        lazy_min[left(cur)] += lazy_min[cur];
        lazy_min[right(cur)] += lazy_min[cur];
    }
    lazy_min[cur] = 0;
}

void update_min(int cur, int l, int r, int i, int j, ll val)
{
    prop_min(cur, l, r);
    if (r < i || l > j)
        return;
    if (l >= i && r <= j)
    {
        lazy_min[cur] += val;
        prop_min(cur, l, r);
        // st[cur] = val;
        return;
    }

    int m = (l + r) / 2;

    update_min(left(cur), l, m, i, j, val);
    update_min(right(cur), m + 1, r, i, j, val);

    st[cur] = min(st[left(cur)], st[right(cur)]);
}

void update_p(int cur, int l, int r, int i, int j, ll val)
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

    update_p(left(cur), l, m, i, j, val);
    update_p(right(cur), m + 1, r, i, j, val);

    stp[cur] = stp[left(cur)] + stp[right(cur)];
}

ll query_min(int cur, int l, int r, int i, int j)
{
    prop_min(cur, l, r);
    if (r < i || l > j)
        return ll(1e18);
    if (l >= i && r <= j)
    {
        return st[cur];
    }

    int m = (l + r) / 2;

    ll lf = query_min(left(cur), l, m, i, j);
    ll rg = query_min(right(cur), m + 1, r, i, j);

    return min(lf, rg);
}

ll query_p(int cur, int l, int r, int i, int j)
{
    prop(cur, l, r);
    if (r < i || l > j)
        return 0;
    if (l >= i && r <= j)
    {
        return stp[cur];
    }

    int m = (l + r) / 2;

    ll lf = query_p(left(cur), l, m, i, j);
    ll rg = query_p(right(cur), m + 1, r, i, j);

    return lf + rg;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vi b(n);
    vi c(n);

    vi d(2 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n * 2; i++)
    {
        if (i >= n)
        {
            d[i] = b[i - n] - c[i - n];
        }
        else
        {
            d[i] = b[i] - c[i];
        }
    }

    for (int i = 0; i < n * 2 - 1; i++)
    {
        pref[i] = (i == 0 ? ll(0) : pref[i - 1]) + d[i];
        // pref[i] = d[i];
    }

    /*
    for (int i = 0; i < n * 2; i++)
    {
        cout << pref[i] << " ";
    }

    cout << '\n';
    */

    build(1, 0, n * 2 - 1);
    build_p(1, 0, n * 2 - 1);

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {

            int i;
            cin >> i;
            i--;

            ll mi = (i == 0 ? 0 : query_p(1, 0, 2 * n - 1, i-1, i - 1));

            // DBG(mi);

            int l = i;
            int r = 2 * n;

            while (l <= r)
            {
                int m = (l + r) / 2;

                ll qu = query_min(1, 0, 2 * n - 1, i, m);

                // DBG(m);
                // DBG(qu - mi);

                if (qu - mi >= 0)
                {
                    l = m + 1;
                }
                else
                {
                    r = m-1;
                }
            }

            //DBG(l);
            //DBG(r);

            if (l >= i + n)
            {
                cout << "-1\n";
            }
            else
            {
                cout << max(l, r) + 1 << '\n';
            }
        }
        else if (op == 2)
        {
            ll i, x;
            cin >> i >> x;
            i--;

            b[i] = x;

            ll val = x - c[i];
            update_p(1, 0, 2 * n - 1, i, 2 * n - 1, val);
            update_p(1, 0, 2 * n - 1, i + n, 2 * n - 1, val);

            update_min(1, 0, 2 * n - 1, i, 2 * n - 1, val);
            update_min(1, 0, 2 * n - 1, i + n, 2 * n - 1, val);
        }
        else
        {
            ll i, x;
            cin >> i >> x;
            i--;

            c[i] = x;

            ll val = b[i] - c[i];

            // DBG(val);

            update_p(1, 0, 2 * n - 1, i, 2 * n - 1, val);
            update_p(1, 0, 2 * n - 1, i + n, 2 * n - 1, val);

            update_min(1, 0, 2 * n - 1, i, 2 * n - 1, val);
            update_min(1, 0, 2 * n - 1, i + n, 2 * n - 1, val);
        }

        /*
        for (int i = 0; i < 2*n; i++)
        {
            cout << query_p(1, 0, 2 * n - 1, i, i) << " ";
        }

        cout << '\n';
        */
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome