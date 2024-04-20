#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, ult ,fir, _min;
    string s;
    map<char, int> m;
    vector<pi> v;
    cin >> t;
    while (t--)
    {
        cin >> s;
        _min = 200000;
        ult = fir = 0;
        int ant = s[0];
        int i_ = 0;
        int qnt = 1;
        v.clear();
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == ant) {
                qnt++;
            } else {
                i_ = i_+1;
                v.push_back({ant, qnt});
                qnt = 1;
                ant = s[i];
            }

        }
        v.push_back({ant, qnt});
        set<pi> aux;
        for (int i = 0; i < v.size()-2; i++)
        {
            aux.insert(v[i]);
            aux.insert(v[i+1]);
            aux.insert(v[i+2]);

            if (aux.size() == 3) {
                _min = min(_min, v[i+1].second +2);
            }
            aux.clear();
        }
        if (_min != 200000) {
            cout << _min << '\n';
        } else {
            cout << "0\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome