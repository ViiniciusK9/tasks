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

const int MAX = 123;

string mat[MAX];
string au[MAX];
int maior[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int len = mat[i].size();
        mx = max(len, mx);
        maior[i] = mx;
    }

    for (int i = n-1; i >= 0; i--)
    {
        string aux;
        for (int j = 0; j < maior[i]; j++)
        {
            if (j < mat[i].size()) {
                aux.pb(mat[i][j]);
            } else {
                aux.pb('*');
            }
        }

        au[i] = aux;
    }

    for (int j = 0; j < maior[n-1]; j++)
    {
        for (int i = n-1; i >= 0; i--)
        {
            if (j < au[i].size()) {
                cout << au[i][j];
            }
        }
        cout << '\n';
    }
    
    




    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome