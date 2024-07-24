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
        int ans = 0;
        int f = 0;
        int nn = n;
        while (k >= 1)
        {
            if (f == 0) {
                if (k >= nn) {
                    f = 1;
                    k-=nn;
                    ans++;
                    nn--;
                } else if (k>=1) {
                    k = 0;
                    ans++;
                    break;
                }
            } else {
                if (k >= nn) {
                    k-=nn;
                    ans++;
                } else if (k>=1) {
                    k = 0;
                    ans++;
                    break;
                }
                if (k >= nn) {
                    k-=nn;
                    ans++;
                } else if (k>=1){
                    k = 0;
                    ans++;
                    break;
                }
                nn--;
            }
        }
        
        cout << ans << '\n';
        
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome