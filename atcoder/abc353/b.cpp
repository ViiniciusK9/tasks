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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, aux;
    queue<int> a;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        a.push(aux);
    }

    int ans = 1;
    int lug = k;
    while (!a.empty())
    {
        int t = a.front();
        if (t <= lug) {
            a.pop();
            lug -= t;
        } else {
            ans++;
            lug = k - t;
            a.pop();
        }
    }
    
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome