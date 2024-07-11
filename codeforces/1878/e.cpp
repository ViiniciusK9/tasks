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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = int(2e5 + 10);

int n, q;
int neutro = (1ll << 31) -1;
array<int, MAX> a;
array<int, 4 * MAX> st;

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

    st[cur] = st[left(cur)] & st[right(cur)];
}

int query(int cur, int l, int r, int i, int j)
{
    if (r < i || l > j)
        return neutro;
    if (i <= l && r <= j)
    {
        return st[cur];
    }

    int m = (l + r) / 2;

    return query(left(cur), l, m, i, j) & query(right(cur), m + 1, r, i, j);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    vi v;
    vi pf;
    while (t--)
    {
        v.clear();
        pf.clear();
        cin >> n;
        int aux;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            a[i]=aux;
            v.pb(aux);
        }
        
        build(1, 0, n-1);

        cin >> q;
        int l, k;
        bool first = true;
        while (q--)
        {
            cin >> l >> k;
            l--;

            if (query(1, 0, n - 1, l, l) < k) {
                cout << (first == true ? "" : " ") << "-1";
            } else {

                int r = n-1;
                int ll= l;
                
                int ans = l;
                while (ll <= r)
                {
                    int m = (ll + r) / 2;

                    int num = query(1, 0, n - 1, l, m);
                        
                    if (num >= k) {
                        ll = m+1;
                        ans = max(ans, m);
                    } else {
                        r = m-1;
                    }
                }
                
                cout << (first == true ? "" : " ") << ans + 1;

            }

            first = false;
        }
        cout << '\n';

    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome