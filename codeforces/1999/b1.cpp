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
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;


        int ans = 0;

        for (int i = 0;i < 2; i++) {
            int c1 = 0, c2 = 0;

            if(a1 > b1) c1++;
            if(a1 < b1) c2++;
            if(a2 > b2) c1++;
            if(a2 < b2) c2++;
            swap(b1,b2);
            if(c1 > c2) ans++;
        }

        swap(a1,a2);
        for (int i = 0;i < 2; i++) {
            int c1 = 0, c2 = 0;

            if(a1 > b1) c1++;
            if(a1 < b1) c2++;
            if(a2 > b2) c1++;
            if(a2 < b2) c2++;
            swap(b1,b2);
            if(c1 > c2) ans++;
        }

        cout << ans << '\n';
        
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome