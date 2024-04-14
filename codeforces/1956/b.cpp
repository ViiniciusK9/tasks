#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 2e5 + 10;

array<bool, MAX> arr;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, ans;
    cin >> t;

    while (t--)
    {
        fill(arr.begin(), arr.end(), false);
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (arr[aux] == true) ans++;
            arr[aux] = true;
        }

        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome