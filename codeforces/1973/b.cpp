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
bitset<25> neutro;
array<bitset<25>, MAX> a;
array<bitset<25>, 4 * MAX> st;

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

    st[cur] = st[left(cur)] | st[right(cur)];
}

void update(int cur, int l, int r, int i, bitset<25> val)
{
    if (i < l || i > r)
        return;
    if (i == l && l == r)
    {
        st[cur] = val;
        return;
    }

    int m = (l + r) / 2;

    update(left(cur), l, m, i, val);
    update(right(cur), m + 1, r, i, val);

    st[cur] = st[left(cur)] | st[right(cur)];
}

bitset<25> query(int cur, int l, int r, int i, int j)
{
    if (r < i || l > j)
        return neutro;
    if (i <= l && r <= j)
    {
        return st[cur];
    }

    int m = (l + r) / 2;

    return query(left(cur), l, m, i, j) | query(right(cur), m + 1, r, i, j);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, aux;

    cin >> t;
    while (t--)
    {
        st.fill(neutro);
        a.fill(neutro);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            bitset<25> at(aux);
            // cout << at << " ";
            a[i] = at;
        }
        // cout << '\n';
        build(1, 0, n - 1);

        bitset<25> fir;
        bitset<25> att;
        int ans = 1;
        //DBG(n);
        int k = 1;
        for (int i = 1; i < n; i++)
        {
            int flag = 1;
            if (n % i == 0)
            {
                k = i;
                //DBG(k);
                for (int j = 0; j < n; j += k)
                {
                    if (j == 0) {
                        //cout << "first: " << 0 <<" "<< k-1;
                        fir = query(1, 0, n-1, 0, k-1);
                    } else {
                        //cout << "Por: " << j << " " << j+k -1;
                        att = query(1, 0, n-1, j, j+k-1);

                        if (att != fir) {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            if (flag == 1) {
                cout << k << '\n';
                break;
            }
            //cout << "\n";
        }
        
        //cout << k << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome