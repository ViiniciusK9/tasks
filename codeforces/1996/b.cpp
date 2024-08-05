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

string mat[1123];
string aux[1123];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> mat[i];
        }
        int i1 = 0;
        for (int i = 0; i < n; i+=k)
        {
            for (int j = 0; j < n; j+=k)
            {
                aux[i1].pb(mat[i][j]);
            }
            i1++;
        }

        int nn = n / k;

        for (int i = 0; i < nn; i++)
        {
            cout << aux[i] << '\n';
        }

        for (int i = 0; i < nn; i++)
        {
            aux[i].clear();
        }
        
        


        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome