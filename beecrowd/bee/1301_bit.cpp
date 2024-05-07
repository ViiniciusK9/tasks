#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 112345;

int n, k, v[MAX], bitZero[MAX], bitNeg[MAX];

void setbit(int i, int delta, int *bit)
{
    while (i <= n)
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

    char op;
    int i, j, ans;
    while (cin >> n >> k)
    {
        memset(bitZero, 0, sizeof(bitZero));
        memset(bitNeg, 0, sizeof(bitNeg));
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            if (v[i])
            {
                v[i] /= abs(v[i]);
                if (v[i] == -1)
                {
                    setbit(i, 1, bitNeg);
                }
            }
            else
            {
                setbit(i, 1, bitZero);
            }
        }

        while (k--)
        {
            cin >> op >> i >> j;
            if (op == 'C')
            {
                if (j)
                {
                    j /= abs(j);

                    if (j == 1 && v[i] != 1)
                    {
                        if (v[i] == 0)
                        {
                            setbit(i, -1, bitZero);
                        }
                        else
                        {
                            setbit(i, -1, bitNeg);
                        }
                    }
                    else if (j == -1 && v[i] != -1)
                    {
                        setbit(i, 1, bitNeg);
                        if (v[i] == 0)
                        {
                            setbit(i, -1, bitZero);
                        }
                    }
                }
                else
                {
                    if (j == 0 && v[i] != 0)
                    {
                        setbit(i, 1, bitZero);
                        if (v[i] == -1)
                        {
                            setbit(i, -1, bitNeg);
                        }
                    }
                }
                v[i] = j;
            }
            else if (op == 'P')
            {
                int zeros = getbit(j, bitZero) - getbit(i-1, bitZero);
                
                if (zeros == 0)
                {
                    int neg = getbit(j, bitNeg) - getbit(i-1, bitNeg);
                    
                    if (neg % 2 == 0)
                    {
                        cout << '+';
                    }
                    else
                    {
                        cout << '-';
                    }
                }
                else
                {
                    cout << '0';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome