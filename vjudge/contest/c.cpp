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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vec(n + 1);
    vector<int> vec_c(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        vec_c[i] = vec[i];
    }

    int conta = 0;

    for (int i = 0; i < n; i++)
    {
        int conta_a = 0;
        for (int j = 1; j <= n; j++)
        {
            int ind_x = (j + i) % n + 1;
            vec[j] = vec_c[ind_x];
        }

        for (int x = 1; x <= n; x++)
        {
            // DBG(x);
            // DBG(vec[x]);
            // DBG(vec[vec[x]]);

            if (vec[vec[x]] == x)
            {
                conta++;
                conta_a++;
            }
        }

        DBG(conta_a);
    }
    DBG(conta);

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome