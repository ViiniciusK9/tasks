#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int s, n, xi, yi;
    map<int, int> m;
    vector<pair<int, int>> vet;
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> xi >> yi;
        vet.push_back({xi, yi});
        //m[xi] = yi;
    }

    sort(vet.begin(), vet.end());
    
    for (auto i = vet.begin() ; i != vet.end(); i++)
    {
        //cout << i->first << " " << i->second << '\n';
        //DBG(s);
        //DBG(i->first);
        if (s > i->first) {
            s += i->second;
        } else {
            cout << "NO\n";
            return 0;
        }
        
    }
    
    cout << "YES\n";
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome