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
        string s1;
        cin >> n;
        cin >> s1;

        bool ans = true;
        int ct = 0;
        int m = 0;
        int e = 0;
        int o = 0;
        int w = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (ct == 0 && (s1[i] == 'm' || s1[i] == 'M')) {
                m++;
            } else if (ct == 0 && (s1[i] == 'e' || s1[i] == 'E') && m >= 1) {
                ct++;
                e++;
            } else if (ct == 1 && (s1[i] == 'e' || s1[i] == 'E')) {
                e++;
            } else if (ct == 1 && (s1[i] == 'o' || s1[i] == 'O') && e >= 1) {
                ct++;
                o++;
            }  else if (ct == 2 && (s1[i] == 'o' || s1[i] == 'O')) {
                o++;
            } else if (ct == 2 && (s1[i] == 'w' || s1[i] == 'W') && o >= 1) {
                ct++;
                w++;
            } else if (ct == 3 && (s1[i] == 'w' || s1[i] == 'W')) {
                w++;
            } else {
                ans = false;
            }
            //DBG(ct);
        }
        
        if (ans && m >= 1 && o >= 1 && w >= 1 && e >= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome