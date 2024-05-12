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

array<int, 2 * MAX> st;
array<int, 2 * MAX> stmin;
int n, q;

void build()
{
    for (int i = n - 1; i > 0; --i)
    {
        st[i] = max(st[i << 1], st[i << 1 | 1]);
        stmin[i] = min(stmin[i << 1], stmin[i << 1 | 1]);
    }
}

void modify(int p, int value)
{
    stmin[p + n] = value;
    for (st[p += n] = value; p > 1; p >>= 1)
    {
        st[p >> 1] = max(st[p], st[p ^ 1]);
        stmin[p >> 1] = min(stmin[p], stmin[p ^ 1]);
    }
}

int querymin(int l, int r)
{
    int res = MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = min(res, stmin[l++]);
        if (r & 1)
            res = min(res, stmin[--r]);
    }
    return res;
}

int query(int l, int r)
{
    int res = -MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, st[l++]);
        if (r & 1)
            res = max(res, st[--r]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n)
    {

        st.fill(0);
        stmin.fill(0);
        for (int i = 0; i < n; i++)
        {
            cin >> st[n + i];
            stmin[n + i] = st[n + i];
        }
        build();

        cin >> q;

        while (q--)
        {
            int op;
            cin >> op;

            if (op == 1)
            {
                int x, val;

                cin >> x >> val;
                x--;
                modify(x, val);
            }
            else
            {
                int i, j;
                cin >> i >> j;
                i--;
                cout << query(i, j) - querymin(i, j) << '\n';
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome