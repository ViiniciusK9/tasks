#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
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



const int MAX = int(2e5 + 10);

int n, q;
array<int, MAX> a;
array<int, 4 * MAX> st;
array<int, 4 * MAX> lazy;

void build(int cur, int l, int r)
{
    lazy[cur] = 0;

    if (l == r)
    {
        st[cur] = 0;
        return;
    }

    int m = (l + r) / 2;

    build(left(cur), l, m);
    build(right(cur), m + 1, r);
    st[cur] = 0;
}

void prop(int cur, int l, int r)
{
    st[cur] += lazy[cur];

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

    st[cur] = max(st[left(cur)], st[right(cur)]);
}

int query(int cur, int l, int r, int i, int j)
{
    prop(cur, l, r);
    if (r < i || l > j)
        return 0;
    if (l >= i && r <= j)
    {
        return st[cur];
    }

    int m = (l + r) / 2;

    return max(query(left(cur), l, m, i, j), query(right(cur), m+1, r, i, j));
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    int i, j;
    for (int i = 0; i < m; i++)
    {
        cin >> i >> j;
        update(1, 0, n-1,i, j, 1);
    }

    
    for (int i = 0; i < n; i++)
    {
        a[i] = query(1, 0, n-1, i, i+1);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome