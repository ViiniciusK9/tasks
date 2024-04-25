#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 5e5+3;


vector<int> v;
vector<pi> v1;
vector<pi> v2;
ll ans, n, sum_total;



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll aux, sum = 0;
    ans = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.PB(aux);
        sum += aux;
        v1.PB({sum, i});
    }

    sum_total = sum;
    
    reverse(v.begin(), v.end());

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        v2.PB({sum, i});
    }
    

    

    cout << ans << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome