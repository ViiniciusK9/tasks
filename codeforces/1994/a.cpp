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

int mat[11][11];
int aux[11][11];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        deque<int> q;
        vi v;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                v.pb(mat[i][j]);
                q.pb(mat[i][j]);
            }
        }

        if (n == 1 && m == 1)
        {
            cout << "-1\n";
        }
        else
        {

            int qnt = n * m;
            bool ans = false;
            while (qnt--)
            {
                q.pb(q.front());
                q.pop_front();
                ans = true;
                for (int i = 0; i < v.size(); i++)
                {
                    if (v[i] == q[i])
                    {
                        ans = false;
                        break;
                    }
                }

                if (ans == true)
                {
                    qnt = 0;
                    break;
                }
            }

            if (ans)
            {
                int ind = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        cout << (j == 0 ? "" : " ") << q[ind];
                        ind++;
                    }
                    cout << '\n';
                }
            }
            else
            {
                cout << "-1\n";
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome