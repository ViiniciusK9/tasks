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
    string s_res;

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
            for (int j = 0; j < n - i; j++)
            {
                for (int jj = 0; jj < n; jj++)
                {
                    mat[j][jj] = jj + 1;
                }
            }
            if (0 < n - i)
            {
                vet_res.push_back({1, n - i});
            }

            for (int j = 0; j < n - i - 1; j++)
            {
                for (int jj = 0; jj < n; jj++)
                {
                    mat[jj][j] = jj + 1;
                }
            }
            if (0 < n - i - 1)
            {
                vet_res.push_back({2, n - i - 1});
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += mat[i][j];
                // cout << mat[i][j] << " ";
            }
            // cout << "\n";
        }

        // continue;

        qnt = 0;
        for (auto i : vet_res)
        {
            qnt += i.second;
        }

        cout << sum << " " << qnt << '\n';

        s_res.clear();

        for (int jj = 1; jj <= n; jj++)
        {
            
            if (jj == 1) {
                s_res += to_string(jj);
            } else {
                s_res += " " + to_string(jj);
            }
        }
        //cout << '\n';

        for (auto i : vet_res)
        {
            for (int j = 1; j <= i.second; j++)
            {
                cout << i.first;
                cout << " " << j;
                cout << " " << s_res;
                cout << '\n';
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome