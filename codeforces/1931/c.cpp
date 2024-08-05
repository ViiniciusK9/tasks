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
        map<int, int> ma;
        cin >> n;
        int aux;
        vi v;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            
            v.pb(aux);
        }
        
        int i = 0;
        int at = v[0];
        int qnt = 0;
        while (at == v[i] && i < n)
        {
            i++;
            qnt++;
        }


        int j = n-1;
        int at2 = v[n-1];
        int qnt2 = 0;
        while (at2 == v[j] && j >= 0 && j >= i)
        {
            j--;
            qnt2++;
        }

        if (at2 == at) {
            cout << n - qnt - qnt2 << '\n';
        } else {
            cout << n - max(qnt, qnt2) << '\n';
        }
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome