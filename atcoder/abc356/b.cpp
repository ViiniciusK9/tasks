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


int mat[120][120];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, aux;
    vi a;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        a.pb(aux);
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    bool flag = true;
    for (int i = 0; i < a.size(); i++)
    {
        int val = a[i];
        ll sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum+= mat[j][i];
        }

        if (sum < val) {
            flag = false;
            break;
        }
    }

    cout << (flag == true ? "Yes\n" : "No\n");
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome