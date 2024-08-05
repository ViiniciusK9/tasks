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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n;
    string s1;
    while (t--)
    {
        cin >> n;

        cin >> s1;

        int flag = true;
        int r = 0;
        int b = 0;
        int w = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == 'W')
            {
                if (r == 1 && b == 0 || r == 0 && b == 1)
                {
                    flag = false;
                }
                else
                {
                    r = 0;
                    b = 0;
                }
            }
            else if (s1[i] == 'B')
            {
                b = 1;
            }
            else if (s1[i] == 'R')
            {
                r = 1;
            }
        }

        if (r == 1 && b == 0 || r == 0 && b == 1)
        {
            flag = false;
        }
        
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome