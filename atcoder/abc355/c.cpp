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

array<int, 20000> col;
array<int, 20000> row;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, d1 = 0, d2 = 0;
    vi v;
    cin >> n >> t;
    int aux;
    for (int i = 0; i < t; i++)
    {
        cin >> aux;
        v.pb(aux);
    }

    int x, y;
    int ans = -1;
    for (int i = 0; i < t; i++)
    {
        x = ((v[i]-1)/n);
        y = ((v[i]-1)%n);
        if (x == y) {
            d1++;
            if (d1 == n) {
                ans = i+1;
                break;
            }
        }
        //DBG(d1);

        row[x]++;
        col[y]++;
        if (row[x] == n) {
            ans = i+1;
            break;
        }

        if (col[y] == n) {
            ans = i+1;
            break;
        }

        if (x == (n - (y + 1))) {
            d2++;
            if (d2 == n) {
                ans = i+1;
                break;
            }
        }

    }
    
    cout << ans << '\n';


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome