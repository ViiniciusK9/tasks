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

int mat[2][26][112345];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n;

    string s1;
    vector<string> v;
    while (t--)
    {
        v.clear();
        cin >> n;
        memset(mat, 0, sizeof(mat));

        for (int i = 0; i < n; i++)
        {
            cin >> s1;
            v.pb(s1);
            mat[0][s1[0]-'a'][i] = 1;
            mat[1][s1[1]-'a'][i] = 1;
        }

        int ac = 0;
        for (int i = 'a'; i <= 'k'; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[0][i][j] = mat[0][i][j] + ac;
                ac = mat[0][i][j];
            }
        }

        ac = 0;
        for (int i = 'a'; i <= 'k'; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[1][i][j] = mat[1][i][j] + ac;
                ac = mat[1][i][j];
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            string at = v[i];

            

        }
        

        
        
    
    }


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome