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


const int MAX = int(2e5+10);

ii v[MAX];
ii st[4 * MAX];
ii st_min[4 * MAX];
int n, k;

ii _build(int p, int l, int r)
{
    if (l == r)
    {
        st[p].f = v[l].f;
        st[p].s = v[l].s;
        return st[p];

    }

    int mid = (l + r) / 2;

    ii le = _build(left(p), l, mid);
    ii ri = _build(right(p), mid + 1, r);
    if (le.f > ri.f) {
        return st[p] = le;
    } else {
        return st[p] = ri;
    }
    
}

ii _build_min(int p, int l, int r)
{
    if (l == r)
    {
        st_min[p].f = v[l].f;
        st_min[p].s = v[l].s;
        return st_min[p];
    }

    int mid = (l + r) / 2;

    ii le = _build_min(left(p), l, mid);
    ii ri = _build_min(right(p), mid + 1, r);
    if (le.f < ri.f) {
        return st_min[p] = le;
    } else {
        return st_min[p] = ri;
    }
    
}


ii _query(int p, int l, int r, int i, int j)
{
    if (r < i || l > j) return {INT_MIN, INT_MIN};
    if (i <= l && r <= j)
    {
        return st[p];
    }

    int mid = (l + r) / 2;

    ii le = _query(left(p), l, mid, i, j);
    ii ri = _query(right(p), mid + 1, r, i, j);
    if (le.f > ri.f) {
        return le;
    } else {
        return ri;
    }
}

ii _query_min(int p, int l, int r, int i, int j)
{
    if (r < i || l > j) return {INT_MAX, INT_MAX};
    if (i <= l && r <= j)
    {
        return st_min[p];
    }

    int mid = (l + r) / 2;

    ii le = _query_min(left(p), l, mid, i, j);
    ii ri = _query_min(right(p), mid + 1, r, i, j);
    if (le.f < ri.f) {
        return le;
    } else {
        return ri;
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    bool pri = true;
    while (t--)
    {
        cout << (pri == true ? "" : "\n");
        pri = false;
        cin >> n;

        
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].f;
            v[i].s=i+1;
        }
        
        _build(1, 0, n - 1);
        _build_min(1, 0, n - 1);

        int q;
        cin >> q;

        while (q--)
        {   
            int i,j;
            cin >> i >> j;
            i--;
            j--;

            ii qma = _query(1, 0, n - 1, i, j);
            ii qmi = _query_min(1, 0, n - 1, i, j);

            //DBG(qma.f);
            //DBG(qma.s);
            //DBG(qmi.f);
            //DBG(qmi.s);



            if (qma.f == qmi.f) {
                cout << "-1 -1\n";
            } else {
                cout << min(qma.s, qmi.s) << " " << max(qma.s, qmi.s) << '\n';
            }
        }

        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome