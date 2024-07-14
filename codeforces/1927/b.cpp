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
        vi v;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int aux;
            cin >> aux;

            v.pb(aux);

        }

        int qnt = 0;
        string aux;

        int mat[29];

        memset(mat, 0, sizeof(mat));

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0) {
                aux.pb('a'+qnt);
                mat[qnt]++;
                qnt++;
            } else {
                
                for (int j = 0; j < 26; j++)
                {
                    if (v[i] == mat[j]) {
                        aux.pb('a'+j);
                        mat[j]++;
                        break;
                    }
                }
                

            }
        }

        cout << aux << '\n';
        


        


    }


    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome