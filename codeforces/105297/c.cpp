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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;


const int MAX = int(2e5 + 10);
int n, q;

array<ll, 4 * MAX> st_b;
array<ll, 4 * MAX> lazy_b;

array<ll, 4 * MAX> st_c;
array<ll, 4 * MAX> lazy_c;

array<ll, MAX> b;
array<ll, MAX> c;

void build_b(int cur, int l, int r)
{
    lazy_b[cur] = 0;

    if (r == l)
    {
        st_b[cur] = b[r];
        return;
    }

    int m = (l + r) / 2;

    build_b(left(cur), l, m);
    build_b(right(cur), m + 1, r);
    st_b[cur] = st_b[left(cur)] + st_b[right(cur)];
}

void prop_b(int cur, int l, int r)
{
    st_b[cur] += lazy_b[cur];

    if (l != r)
    {
        lazy_b[left(cur)] += lazy_b[cur];
        lazy_b[right(cur)] += lazy_b[cur];
    }
    lazy_b[cur] = 0;
}

void update_b(int cur, int l, int r, int i, int j, int val)
{
    prop_b(cur, l, r);
    if (r < i || l > j)
        return;
    if (l >= i && r <= j)
    {
        lazy_b[cur] += val;
        prop_b(cur, l, r);
        return;
    }

    int m = (l + r) / 2;

    update_b(left(cur), l, m, i, j, val);
    update_b(right(cur), m + 1, r, i, j, val);

    st_b[cur] = st_b[left(cur)] + st_b[right(cur)];
}


ll query_b(int cur, int l, int r, int i, int j)
{
    prop_b(cur, l, r);
    if (r < i || l > j)
        return 0;
    if (l >= i && r <= j)
    {
        return st_b[cur];
    }

    int m = (l + r) / 2;

    ll lf = query_b(left(cur), l, m, i, j);
    ll rg = query_b(right(cur), m+1, r, i, j);
    
    return lf + rg;
}

void build_c(int cur, int l, int r)
{
    lazy_c[cur] = 0;

    if (r == l)
    {
        st_c[cur] = c[r];
        return;
    }

    int m = (l + r) / 2;

    build_c(left(cur), l, m);
    build_c(right(cur), m + 1, r);
    st_c[cur] = st_c[left(cur)] + st_c[right(cur)];
}

void prop_c(int cur, int l, int r)
{
    st_c[cur] += lazy_b[cur];

    if (l != r)
    {
        lazy_c[left(cur)] += lazy_c[cur];
        lazy_c[right(cur)] += lazy_c[cur];
    }
    lazy_c[cur] = 0;
}

void update_c(int cur, int l, int r, int i, int j, int val)
{
    prop_c(cur, l, r);
    if (r < i || l > j)
        return;
    if (l >= i && r <= j)
    {
        lazy_c[cur] += val;
        prop_c(cur, l, r);
        return;
    }

    int m = (l + r) / 2;

    update_c(left(cur), l, m, i, j, val);
    update_c(right(cur), m + 1, r, i, j, val);

    st_c[cur] = st_c[left(cur)] + st_c[right(cur)];
}


ll query_c(int cur, int l, int r, int i, int j)
{
    prop_c(cur, l, r);
    if (r < i || l > j)
        return 0;
    if (l >= i && r <= j)
    {
        return st_c[cur];
    }

    int m = (l + r) / 2;

    ll lf = query_c(left(cur), l, m, i, j);
    ll rg = query_c(right(cur), m+1, r, i, j);
    
    return lf + rg;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> q;

    vi pref_b(n*2+1);
    vi pref_c(n*2+1);

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < 2*n; i++)
    {
        pref_b[i+1] = pref_b[i] + b[i % n];
        pref_c[i+1] = pref_c[i] + c[i % n];
    }

    for (int i = 1; i <= 2*n; i++)
    {
        cout << pref_b[i] << " ";
    }
    cout << "\n";


    for (int i = 1; i <= 2*n; i++)
    {
        cout << pref_c[i] << " ";
    }
    cout << "\n";

    for (int i = n; i < 2*n; i++)
    {
        b[i] = b[i % n];
        c[i] = c[i % n];
    }

    build_b(1, 0, (2*n)-1);
    build_c(1, 0, (2*n)-1);

    //cout << query_b(1, 0, (2*n)-1, 0, 9) << '\n';
    //cout << query_c(1, 0, (2*n)-1, 0, 9) << '\n';


    while (q--)
    {
        int op, ih, x;
        cin >> op;

        if (op == 1)
        {
            cin >> ih;

            int l = ih-1;
            int r = (2*n) -1;
            DBG(l);
            DBG(r);
            while (l < r)
            {

                int m = (l + r) / 2;
                //int m = l + (r - l + 1) / 2;

                ll q1 = query_b(1, 0, (2*n)-1, 0, m) - query_b(1, 0, (2*n)-1, 0, ih-1);
                ll q2 = query_c(1, 0, (2*n)-1, 0, m) - query_c(1, 0, (2*n)-1, 0, ih-1);
                DBG(q1);
                DBG(q2);
                DBG(m);

                if (q1 >= q2) {
                    l = m;
                } else {
                    r = m-1;
                }
            }

            DBG(l);
            DBG(r);
            if (r == n) {
                cout << "-1\n";
            } else {
                cout << r%n << '\n';
            }
            

        }
        else if (op == 2)
        {
            cin >> ih >> x;
            ih--;
            b[ih] = x;

            
        }
        else
        {
            cin >> ih >> x;
            ih--;
            c[ih] = x;

            
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome