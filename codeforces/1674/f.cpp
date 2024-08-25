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

const int MAX = 1123456;

int len, k, v[MAX], bitQ[MAX];

string mat[1123];

void setbit(int i, int delta, int *bit)
{
    while (i <= len)
    {
        bit[i] += delta;
        i += i & -i;
    }
}

ll getbit(int i, int *bit)
{
    ll ans = 0;
    while (i)
    {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    len = n*m;

    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    int cnt = 1;
    ll qnt = 0;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j] == '*') {
                setbit(cnt, 1, bitQ);
                v[cnt] = 1;
                qnt++;
            }else {
                v[cnt] = 0;
            }
            cnt++;
        }
    }
    

    while (q--)
    {
        int x,y;
        cin >> x >> y;

        int ind = n * (y-1) + x;

        if (v[ind] == 1) {
            v[ind] = 0;
            setbit(ind, -1, bitQ);
            qnt--;
        } else {
            v[ind] = 1;
            setbit(ind, 1, bitQ);
            qnt++;
        }

        cout << qnt - getbit(qnt, bitQ) << '\n';

    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome