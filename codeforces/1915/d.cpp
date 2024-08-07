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
        string s1;
        cin >> s1;
        vector<string> a;
        string aux;
        int len = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (s1[i] != 'a' && s1[i] != 'e' && len != 0) {
                aux.pb(s1[i]);
                len = 0;
                reverse(aux.begin(), aux.end());
                a.pb(aux);
                aux.clear();
            } else {
                aux.pb(s1[i]);
                len++;
            }
        }
        bool f = true;
        reverse(a.begin(), a.end());
        for (auto st : a)
        {
            cout << (f ? "" : ".") << st;
            f = false;
        }

        cout << '\n';
        
        
    }


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome