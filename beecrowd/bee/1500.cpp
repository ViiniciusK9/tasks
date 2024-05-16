#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair
#define left(p) ((p) << 1)
#define right(p) ((left(p)) + 1)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;


const int MAX = int(112345);

array<ll, 4*MAX> st;
array<ll, 4*MAX> lazy;

void build(int cur, int l, int r)
{
    if (l == r) {
        st[cur] = 0;
    }

    int m = (l + r) / 2;

    build(left(cur), l, m);
    build(right(cur), m+1, r);
    st[cur] = st[left(cur)] + st[right(cur)];
}

void prop(int cur, int l, int r)
{
    st[cur] += lazy[cur] * (r - l + 1);

    if (l != r) {
        lazy[left(cur)] += lazy[cur];
        lazy[right(cur)] += lazy[cur];
    }

    lazy[cur] = 0;
}

void update(int cur, int l, int r, int i, int j, int val)
{
    prop(cur, l, r);
    if (r < i || l > j) return;
    if (l >= i && r <= j) {
        lazy[cur] += val;
        prop(cur, l, r);
        return;
    }

    int m = (l + r ) /2;

    update(left(cur), l, m, i, j, val);
    update(right(cur), m+1, r, i, j, val);

    st[cur] = st[left(cur)] + st[right(cur)];
}

ll query(int cur, int l, int r, int i, int j)
{
    prop(cur, l, r);
    if (r < i || l > j) return 0;
    if (l >= i && r <= j) return st[cur];

    int m = (l + r) / 2;

    return query(left(cur), l, m, i, j) +
           query(right(cur), m+1, r, i, j);
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, c;
    int op, p, q, v;
    cin >> t;

    while (t--)
    {
        cin >> n >> c;
        st.fill(0);
        lazy.fill(0);
        while (c--)
        {
            cin >> op;

            if (op == 1) {
                cin >> p >> q;
                p--;
                q--;
                if (p > q) {
                    swap(p, q);
                }
                cout << query(1, 0, n-1, p, q) << '\n'; 
            } else {
                cin >> p >> q >> v;
                p--;
                q--;
                if (p > q) {
                    swap(p, q);
                }
                update(1, 0, n-1, p, q, v);
            }
        }
                
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome