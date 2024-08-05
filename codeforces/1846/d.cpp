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
        int n, d, h;
        cin >> n >> d >> h;
        vi v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        double ans = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (v[i] + h < v[i+1]) {
                ans += d * h / (double)2.0;
            } else {
                double ht = abs((v[i] + h) - v[i+1]);

                ht = ((double)h - ht) / (double)h;
                ans += (d + (ht * d))/ 2 * (v[i+1] - v[i]);

            }
        }

        ans += d * h / (double)2.0;
        
        cout << ans << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome