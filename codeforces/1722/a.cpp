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

    while(t--) {
        int n;
        string s1;
        cin >> n;
        cin >> s1;

        map<char, int> ma;

        if (n != 5) {
            cout << "NO\n";
        } else {
            for (int i = 0; i < s1.size(); i++) {
                ma[s1[i]]++;
            }

            if (ma['T'] != 1 || ma['i'] != 1 || ma['m'] != 1 || ma['u'] != 1 || ma['r'] != 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }

    }

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome