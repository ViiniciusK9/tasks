#include<bits/stdc++.h>
 
using namespace std;
 
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(0)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
 
const int MAX = int(1e5 + 9);
 
array<int, MAX> a;
array<int, MAX> b;
array<int, MAX> ti;
 
int solve(int tam) 
{
 
}
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    int n, k, q, con;
    cin >> t;
 
    while (t--)
    {
        cin >> n >> k >> q;
 
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
 
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
        }
 
        int fir = 0;
        while (q--)
        {
            cin >> con;
            if (con <= a[0]) {
                double vel = ((double) b[0]) / ((double) abs(0 - a[0]));
                cout << (fir == 0 ? "" : " ") << F(floor(con * vel));
                fir = 1;
            } else {
                int it = lower_bound(a.begin(), a.begin() + k, con) - a.begin();
                if (con == a[it+1]) {
                    cout << (fir == 0 ? "" : " ") << b[it+1];
                    fir = 1;
                } else {

                double vel = ((double) abs(b[it-1] - b[it])) / ((double) abs(a[it-1] - a[it]));
                cout << (fir == 0 ? "" : " ") << F(b[it-1] + (floor(abs(con - a[it-1]) * vel)));
                fir = 1;
                }
            }
 
        }
        cout << '\n';
        
        
        
        
 
    }
    
 
    
    return 0;
}
 
// g++ -O2 -Wall nome.cpp -o nome