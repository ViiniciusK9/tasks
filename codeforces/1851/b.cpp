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

const int MAX = int(2e5+10);

int mat[MAX];
int met[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n, aux;
    while (t--)
    {
        vi v;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            mat[i] = aux%2;
            v.pb(aux);
        }

        sort(v.begin(), v.end());

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 != mat[i]) {
                ans = false;
                break;
            }
        }
        
        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome