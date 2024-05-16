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

const int MAX = int(212345);

array<int, MAX> a;
array<ll, 4*MAX> st;

void build(int cur, int l, int r)
{
    if (l == r) {
        st[cur] = a[l];
    }

    int m = (l + r) / 2;

    build(left(cur), l, m);
    build(right(cur), m+1, r);
    st[cur] = st[left(cur)] + st[right(cur)];
}

ll query(int c, int l, int r, int i, int j)
{
    if (r < i || l > j) return 0;
    if (l >= i && r <= j) return st[c];

    int m = (l + r) / 2;

    return query(left(c), l, m, i, j) + query(right(c), m+1, r, i, j);
}

void point_update(int c, int l, int r, int i, int v)
{
    if (r < i || l > i) return;

    if (l == r && r == i) {
        st[c] = v;
        return;
    }

    int m = (l + r) / 2;

    point_update(left(c), l, m, i, v);
    point_update(right(c), m+1, r, i, v);

    st[c] = st[left(c)] + st[right(c)];
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        build(1, 0, n-1);
                
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome