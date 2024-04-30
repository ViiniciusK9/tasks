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

    ll t;
    string s;

    cin >> t;
    while (t--)
    {
        cin >> s;
        ll custo = 0;
        ll achou = 0;
        ll qnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1' && achou == 0) {
                achou = 1;
                qnt = 1;
            } else if (s[i] == '1') {
                qnt++;
            } else if (s[i] == '0' && achou == 1) {
                custo += qnt + 1;
            }

            
        }
        cout << custo << '\n';


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome