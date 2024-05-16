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

const int MAX = int(1123);
string s[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#'){
                if (j + 1 < m && s[i][j+1] == '.' || j+1 == m) {
                    ans++;
                    continue;
                }
                if (j - 1 >= 0 && s[i][j-1] == '.' || j-1 == -1) {
                    ans++;
                    continue;
                }
                if (i + 1 < n && s[i+1][j] == '.' || i+1 == n) {
                    ans++;
                    continue;
                }
                if (i - 1 >= 0 && s[i-1][j] == '.' || i-1 == -1) {
                    ans++;
                    continue;
                }

                
            }
        }
        
    }
    
    cout << ans << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome