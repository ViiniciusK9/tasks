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

    int t;
    string s;

    int ans;
    cin >> t;

    while (t--)
    {
        ans = 1;
        cin >> s;
        int pp = 0;
        int z = 0;
        int z1 = 0, z2 = 0, z3 = 0;
        if (s[0] == '0') {
            pp = 1;
        }
        for (int i = 0; i < s.size(); i++)
        {

            if (z == 0 && s[i] != '0') {
                z=1;
            } else if (z == 1 && z1 == 0 && s[i] == '0') {
                z1 = 1;
                ans++;
            } else if (z == 1 && z1 == 1 && s[i] == '1') {
                z1 = 0;
                if (pp == 0) {
                    pp = 1;
                } else {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
        
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome