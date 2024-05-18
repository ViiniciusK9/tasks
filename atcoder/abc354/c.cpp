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

const int MAX = int(2e5+10);

int n, a, c;
vector<pii> vp;
vector<int> vaux;
array<pi, 4*MAX> stmin;

void build(int c, int l, int r)
{
    if (l == r) {
        stmin[c] = {vp[l].second.first, vp[l].second.second};
        return;
    }

    int m = (l + r) / 2;

    build(left(c), l, m);
    build(right(c), m+1, r);

    if (stmin[left(c)].first <= stmin[right(c)].first) {
        stmin[c] = {stmin[left(c)].first, stmin[left(c)].second};
    } else {
        stmin[c] = {stmin[right(c)].first, stmin[right(c)].second};
    }
}

pi query(int c, int l, int r, int i, int j)
{
    if (r < i || l > j) {
        return {int(1e9+90), int(1e9+90)};
    }

    if (l >= i && r <= j) {
        return stmin[c];
    }

    int m = (l + r) / 2;

    pi le = query(left(c), l, m, i, j);
    pi ri = query(right(c), m + 1, r, i, j);

    if (le.first <= ri.first) {
        return le;
    } else {
        return ri;
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> c;
        vp.pb({a,{c,i}});
    }

    sort(vp.begin(), vp.end());

    build(1, 0, n-1);

    /*

    for (auto vi : vp)
    {
        vaux.pb(vi.first);
    }

    */
    

    vector<pii> res;
    set<int> ans;
    for (int i = 0; i < n-1; i++)
    {
        int mc = vp[i].second.first;

        pi qc = query(1, 0, n-1, i+1, n-1);

        if (!(qc.first < mc)) {
            res.pb(vp[i]);
            ans.insert(vp[i].second.second);
        }
    }
    res.pb(vp[n-1]);
    ans.insert(vp[n-1].second.second);
    
    cout << res.size() << '\n';

    bool flag = true;

    for (auto vi : ans)
    {
        cout << (flag == true ? "" : " ")  << vi;
        flag = false;
    }
    cout << '\n';
    
    


    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome