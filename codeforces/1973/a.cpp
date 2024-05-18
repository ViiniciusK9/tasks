#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
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

    int t, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        int ans = 0;
        while (a > 0)
        {
            if (a > 0) {
                c--;
                a--;
                ans++;
            }
            if (a > 0 && abs(c-b) == 1 && b > c) {
                b--;
                a--;
                ans++;
            }
        }

        while (b > 0 && c > 0)
        {
            b--;
            c--;
            ans++;
        }
        
        if (c % 2 == 0 && b % 2 == 0 && a % 2 == 0) {
            cout << ans << '\n';
        } else {
            cout << "-1\n";
        }
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome