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

    int t, n;
    string s1;
    string aux;
    set<char> se;
    vector<char> v;

    cin >> t;

    while (t--)
    {
        se.clear();
        v.clear();
        aux.clear();

        cin >> n;

        cin >> s1;

        for (int i = 0; i < s1.size(); i++)
        {
            se.insert(s1[i]);
        }

        for (auto vi : se)
        {
            //DBG(vi);
            v.pb(vi);
        }

        reverse(v.begin(), v.end());

        map<char, char> ma;
        int i = 0;
        int j = v.size()-1;
        while (i<=j)
        {
            ma[v[i]] = v[j];
            ma[v[j]] = v[i];
            i++;
            j--;
        }

        for (int i = 0; i < s1.size(); i++)
        {
            aux.pb(ma[s1[i]]);
        }

        cout << aux << '\n';
        
        

        


        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome