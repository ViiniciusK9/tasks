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

    char d;
    string s;
    string aux, aux2;
    int z;
    while (cin >> d >> s)
    {
        if (d == '0' && s[0] == '0' && s.size() == 1) break;
        z = 0;
        aux.clear();
        aux2.clear();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != d) {
                aux.push_back(s[i]);
            }
        }
        for (int i = 0; i < aux.size(); i++)
        {
            if (z) {
                aux2.pb(aux[i]);
            }
            if (z == 0 && aux[i] != '0'){
                z = 1;
                aux2.pb(aux[i]);
            } 
        }
        
        cout << (aux2.size() == 0 ? "0" : aux2) << '\n';
    }
    

    
    return 0;
}

