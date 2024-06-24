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

    int n;

    cin >> n;
    string s1;
    getline(cin, s1);

    map<int, map<string, int>> ma;
    vector<vector<string>> vet;

    map<string, int> pnt;

    int it = 1;
    while (it <= n)
    {
        getline(cin, s1);
        string aux;
        aux.clear();

        vector<string> vat;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ' ') {
                vat.pb(aux);
                //ma[it][aux]++;
                aux.clear();
            } else {
                aux.pb(s1[i]);
            }
        }
        vat.pb(aux);
        //ma[it][aux]++;
        vet.pb(vat);

        it++;
    }
    int m;
    cin >> m;
    int x;
    while (m--)
    {
        cin >> s1 >> x;
        pnt[s1] = x;
    }


    ll ans = 0;
    ll maior = 0;
    ll in_maior = 0;

    
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;

        
        for (string st : vet[i])
        {
            if (pnt.find(st) != pnt.end()) {
                sum += pnt[st];
            }
        }
        
        ans+=sum;
        if (sum >= maior) {
            maior = sum;
            in_maior = i+1;
        }
    }

    cout << ans << " " << in_maior << '\n';
        
    
    

    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome