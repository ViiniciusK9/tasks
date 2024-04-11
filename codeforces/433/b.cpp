#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

const int MAX = 1e5+3;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

array<ll, MAX> arr1;
array<ll, MAX> arr2;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, aux, m, type, l, r;
    vi v;
    arr1[0]=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> aux;
        arr1[i] = arr1[i-1] + aux;
        v.PB(aux);
    }

    sort(v.begin(), v.end());

    arr2[0]=0;
    for (int i = 1; i <= n; i++)
    {
        arr2[i] = arr2[i-1] + v[i-1] ;
    }
    
    cin >> m;

    while (m--)
    {
        cin >> type >> l >> r;
        if (type == 1) {
            cout << arr1[r] - arr1[l-1] << '\n';
        } else {
            cout << arr2[r] - arr2[l-1] << '\n';
        }
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome