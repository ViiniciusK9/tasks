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

string s;
string aux = "0000";
string ans = "2020";


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, r;

    cin >> t;
    while (t--)
    {
        r = 0;
        cin >> n;
        cin >> s;
        if (n == 4) {
            if (s == ans) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            // 0-4 1-3 2-2 3-1 4-0
            aux[0] = s[s.length()-4];
            aux[1] = s[s.length()-3];
            aux[2] = s[s.length()-2];
            aux[3] = s[s.length()-1];
            if (aux == ans) {
                cout << "YES\n";
                r = 1;
            }

            aux[0] = s[0];
            aux[1] = s[s.length()-3];
            aux[2] = s[s.length()-2];
            aux[3] = s[s.length()-1];

            if (r == 0 && aux == ans) {
                cout << "YES\n";
                r = 1;
            }

            aux[0] = s[0];
            aux[1] = s[1];
            aux[2] = s[s.length()-2];
            aux[3] = s[s.length()-1];

            if (r == 0 && aux == ans) {
                cout << "YES\n";
                r = 1;
            }

            aux[0] = s[0];
            aux[1] = s[1];
            aux[2] = s[2];
            aux[3] = s[s.length()-1];

            if (r == 0 && aux == ans) {
                cout << "YES\n";
                r = 1;
            }

            aux[0] = s[0];
            aux[1] = s[1];
            aux[2] = s[2];
            aux[3] = s[3];

            if (r == 0 && aux == ans) {
                cout << "YES\n";
                r = 1;
            }

            if (r == 0) {
                cout << "NO\n";
            }
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome