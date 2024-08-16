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
        int n;
        cin >> n;
        vi a(n);
        vi b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        bool ans = true;
        int diff = -1;
        for (int i = 0; i < n; i++)
        {
            diff = max(diff, abs(b[i] - a[i]));
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] - diff != b[i]) {
                if (b[i] == 0 && a[i] - diff <= 0) {
                    continue;
                }

                ans = false;
            }
        }

        

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome