#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define se second
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

        string s;
        string a;

        cin >> s >> a;
        int i = 0;
        int j = 0;
        bool ans = false;
        while (i < s.size())
        {
            if (j < a.size()) {
                if (a[j] == s[i]) {
                    j++;
                    i++;
                } else if (a[j] != s[i] && s[i] == '?') {
                    s[i] = a[j];
                    j++;
                    i++;
                } else {
                    i++;
                }
            } else if (s[i] == '?'){
                s[i] = 'a';
                i++;
            } else {
                i++;
            }
        }
        
        if (j == a.size()) {
            cout << "YES\n";
            cout << s << '\n';
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome