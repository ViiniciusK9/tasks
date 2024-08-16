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
        int n, k;
        cin >> n >> k;
        string s1;

        cin >> s1;

        map<char, int> ma;

        int ind = -1;
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] - 'a' > k)
            {
                ind = i;
                break;
            }
            else
            {
                mx = max(mx, s1[i] - 'a');
            }
            // cout <<  s1[i] - 'a' << " ";
        }

        if (ind == -1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "a";
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (s1[i] - 'a' <= mx)
                {
                    s1[i] = 'a';
                }
            }

            k -= mx;

            while (k--)
            {
                char aux = s1[ind];
                for (int i = 0; i < n; i++)
                {
                    if (s1[i] == aux) {
                        s1[i] = s1[i]-1;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                cout << s1[i];
            }
        }

        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome