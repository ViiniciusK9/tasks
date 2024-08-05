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
        vi v;
        int p1 = 0;
        int p2 = 0;
        int c1 = 0;
        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;
            if (aux != i+1 && aux != n-i) {
                c1++;
            } else if (aux != i+1) {
                p1++;
            } else if (aux != n-i) {
                p2++;
            }

            v.pb(aux);
        }


        //DBG(c1);
        //DBG(p1);
        //DBG(p2);

        if (p1 + c1 <= p2) {
            cout << "First\n";
        } else if (p2 + c1 < p1) {
            cout << "Second\n";
        } else {
            cout << "Tie\n";
        }

        //cout << '\n';
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome