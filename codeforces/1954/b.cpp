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

const int MAX = 3e5+30;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, qnt, m;
    vi v;
    cin >> t;

    while (t--)
    {
        v.clear();
        cin >> n;
        int ant = 0;
        cin >> aux;
        ant = aux;
        qnt = 1;
        for (int i = 1; i < n; i++)
        {

            cin >> aux;
            if (ant == -1) {
                qnt = 1;
                ant = aux;
                continue;
            }
            
            if (aux == ant) {
                qnt++;
            } else {
                v.PB(qnt);
                qnt = 1;
                ant = -1;
            }

        }
        v.PB(qnt);
        
        m = MAX;

        for (auto i : v)
        {
            m = min(m, i);
            //cout << i << " ";
        }
        //cout << '\n';

        if (v.size() == 1) {
            cout << "-1\n";
        } else if (m == MAX) {
            cout << "1" << '\n';
        } else {
            cout << m << '\n';
        }
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome