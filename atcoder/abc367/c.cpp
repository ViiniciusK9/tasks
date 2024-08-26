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

int n, k, mx;
int r[10];
set<vector<int>> ans;
vector<int> ts;
void bc(int i) {

    if (i == n) {
        int sum = 0;

        for (auto el : ts)
        {
            sum += el;
        }

        if (sum % k == 0) {
            ans.insert(ts);
        }

        return;
        
    }

    for (int j = 1; j <= r[i]; j++)
    {
        ts.pb(j);
        bc(i+1);
        ts.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        //int aux;
        cin >> r[i];
    }

    bc(0);
    
    for (auto vet : ans)
    {   
        bool fir = false;
        for (auto el : vet)
        {
            cout << (fir == false ? "" : " ") << el;
            fir = true;
        }
        cout << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome