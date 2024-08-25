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

    int n, k;
    cin >> n >> k;

    vi v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bool fir = true;
    for (int i = (n)-k; i < n; i++)
    {
        cout << (fir == true ? "" : " ") << v[i];
        fir = false;
    }

    for (int i = 0; i <= (n-1)-k; i++)
    {
        cout << (fir == true ? "" : " ") << v[i];
        fir = false;
    }
    
    cout << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome