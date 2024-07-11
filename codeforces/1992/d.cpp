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

    int t;

    cin >> t;

    while (t--)
    {
        int n, m, k;
        string s1;

        cin >> n >> m >> k;

        string s2;
        s2.push_back('L');

        cin >> s1;
        s2 = s2 + s1 + s2;

        // DBG(s2);
        int cur = 0;
        int log = 1;
        int jump = 0;
        bool ans = false;
        int nadar = k;
        int aux;
        while (cur != n+1)
        {
            if (s2[cur] == 'L')
            {
                ans = false;

                aux = cur;

                for (int i = cur + 1; i < cur + m + 1; i++)
                {
                    if (s2[i] == 'W')
                    {
                        aux = i;
                    }
                    else if (s2[i] == 'L')
                    {
                        ans = true;
                        cur = i;
                        break;
                    }
                }

                if (ans)
                {
                    continue;
                }
                if (aux == cur)
                {
                    break;
                }
                cur = aux;
            }
            else if (s2[cur] == 'W')
            {
                ans = false;

                for (int i = cur + 1; i < cur + nadar + 1; i++)
                {
                    if (s2[i] == 'C')
                    {
                        break;
                    }
                    if (s2[i] == 'L')
                    {
                        ans = true;
                        nadar -= i - cur;
                        cur = i;
                        break;
                    }
                }

                if (ans)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        cout << (cur == n + 1 ? "YES\n" : "NO\n");
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome