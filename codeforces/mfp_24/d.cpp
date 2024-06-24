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

ll mat[10][10];
ll disp[10];

ll fm(int i) {
    if (i == 6) {
        return 0;
    }

    ll ans = 0;
    ll at = 0;
    for (int j = 0; j < 6; j++)
    {   
        if(disp[j] == 0) {
            disp[j] = 1;
            at = fm(i+1) + mat[i][j];
            disp[j] = 0;
        }
        ans = max(at, ans);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << fm(0) << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome