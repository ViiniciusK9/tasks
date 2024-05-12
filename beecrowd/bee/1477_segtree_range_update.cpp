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

int n;
array<pii, 4 * MAX> st;
array<int, 4 * MAX> lazy;

pii op(pii a, pii b)
{
    pii res;
    res.f = a.f + b.f;
    res.s.f = a.s.f + b.s.f;
    res.s.s = a.s.s + b.s.s;
    return res;
}

void build(int cur, int l, int r)
{
    lazy[cur] = 0;

    if (r == l)
    {
        st[cur] = {1, {0, 0}};
        return;
    }

    int m = (l + r) / 2;

    build(left(cur), l, m);
    build(right(cur), m + 1, r);
    st[cur] = op(st[left(cur)], st[right(cur)]);
}

pii troca(pii a, int qnt)
{
    pii res;
    qnt = qnt % 3;
    if (qnt == 0)
    {
        return a;
    }
    else if (qnt == 1)
    {
        res.f = a.s.s;
        res.s.f = a.f;
        res.s.s = a.s.f;
        return res;
    }
    else
    {
        res.f = a.s.f;
        res.s.f = a.s.s;
        res.s.s = a.f;
        return res;
    }
}

void prop(int cur, int l, int r)
{
    st[cur] = troca(st[cur], lazy[cur]);

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
    st[cur] = op(st[left(cur)], st[right(cur)]);
}

pii query(int cur, int l, int r, int i, int j)
{
    prop(cur, l, r);
    if (r < i || l > j)
    {
        return {0, {0, 0}};
    }

    if (l >= i && r <= j)
    {
        return st[cur];
    }

    int m = (l + r) / 2;

    return op(query(left(cur), l, m, i, j), query(right(cur), m + 1, r, i, j));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char op;
    int a, b, m;
    while (cin >> n >> m)
    {
        build(1, 0, n-1);
        while (m--)
        {
            cin >> op >> a >> b;
            if (op == 'C')
            {
                // contagem
                a--;
                b--;
                pii ans = query(1, 0, n - 1, a, b);
                cout << ans.f << " " << ans.s.f << " " << ans.s.s << '\n';
            }
            else
            {
                // modificar
                a--;
                b--;
                update(1, 0, n - 1, a, b, 1);
            }
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome