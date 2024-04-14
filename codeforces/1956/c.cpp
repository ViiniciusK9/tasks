#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed << std::setprecision(1) << (x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 500;

int mat[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, col, col2, res, qnt;
    ll sum = 0;
    vector<pi> vet_res;

    cin >> t;

    while (t--)
    {
        vet_res.clear();
        memset(mat, 0, sizeof(mat));
        sum = 0;
        cin >> n;
        m = (n * (n + 1)) / 2;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = j + 1;
            }
        }
        vet_res.push_back({1, n});

        col = 0;
        col2 = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) * n >= m)
            {
                col = i;
                break;
            }
            for (int j = 0; j < n; j++)
            {
                mat[j][i] = j + 1;
            }
        }
        if (col != 0)
        {
            vet_res.push_back({2, col});
        }

        res = ((n - col) * ((col + 1) + n)) / 2;
        // cout << res << '\n';

        for (int i = 0; i < n; i++)
        {
            if (col * (i + 1) + (res) >= m)
            {
                col2 = i;
                break;
            }
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = j + 1;
            }
        }

        if (col2 != 0)
        {
            vet_res.push_back({1, col2});
        }

        while (col > 0 && col2 > 0)
        {
            res = ((n - col2) * ((col2 + 1) + n)) / 2;
            // cout << res << '\n';

            for (int i = 0; i < n; i++)
            {
                if (col2 * (i + 1) + (res) >= m)
                {
                    col = i;
                    break;
                }
                for (int j = 0; j < n; j++)
                {
                    mat[j][i] = j + 1;
                }
            }

            if (col == 0)
                break;

            if (col != 0)
            {
                vet_res.push_back({2, col});
            }

            res = ((n - col) * ((col + 1) + n)) / 2;
            // cout << res << '\n';

            for (int i = 0; i < n; i++)
            {
                if (col * (i + 1) + (res) >= m)
                {
                    col2 = i;
                    break;
                }
                for (int j = 0; j < n; j++)
                {
                    mat[i][j] = j + 1;
                }
            }

            if (col2 != 0)
            {
                vet_res.push_back({1, col2});
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += mat[i][j];
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }

        continue;

        qnt = 0;
        for (auto i : vet_res)
        {
            qnt += i.second;
        }

        cout << sum << " " << qnt << '\n';

        for (auto i : vet_res)
        {
            for (int j = 1; j <= i.second; j++)
            {
                cout << i.first;
                cout <<  " " << j;
                cout << " " << 1;
                for (int jj = 2; jj <= n; jj++)
                {
                    cout << " " << jj;
                }
                cout << '\n';
            }
            

        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome