#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const ll MAX = int ((2e5 + 10) * 2) ;

ll n;
array<ll, MAX> aux;
array<ll, MAX * 4> st;

void build(int cur, int l, int r)
{
    if (l == r) {
        st[cur] = aux[l];
        return;
    }

    int m = (l + r) >> 1;

    build(2 * cur, l, m);
    build(2 * cur + 1, m + 1, r);

    st[cur] = min(st[2 * cur], st[2 * cur + 1]);
}

ll query(int cur, int l, int r, int i, int j, ll val) {

    if (r < i || l > j) {
        return -1;
    }

    if (st[cur] >= val) {
        return -1;
    }

    if (l == r) {
        return l;
    }

    int m = (l + r) / 2;

    ll left_query = query(2 * cur, l, m, i, j, val);
    if (left_query != -1) {
        return left_query;
    }
    return query(2 * cur + 1, m + 1, r, i, j, val);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;

    vector<ll> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }


    for (int i = 0; i < n*2; i++) {
        ll val = A[i % n];
        aux[i] = val - k * i;
    }

    for (int i = 0; i < n*2; i++) {
        //DBG((i%n) + 1);
        //DBG(aux[i]);
    }
    
    build(1, 0, n * 2 - 1);

    vector<ll> ans;

    for (int i = 0; i < n; i++)
    {
        ll val = aux[i];
        ll busca = query(1, 0, n * 2 - 1, i + 1, i+n, val);
        ll indice = (busca % n) + 1;
        ans.push_back(indice);
    }

    bool first = true;
    for (int i = 0; i < n; i++) {
        cout << (first ? "" : " ") << ans[i];
        first = false;
    }

    cout << endl;


    



    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome