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
        int n;
        cin >> n;
        vi a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n != 2) {
            cout << "NO\n";
        } else {
            if (abs(a[0] - a[1]) > 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome