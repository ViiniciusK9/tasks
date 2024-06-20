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

    int n, a, aux;
    cin >> n >> a;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        q.push(aux);
    }

    int ans = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (ans >= cur) {
            cout << ans + a << '\n';
            ans += a;
        } else {
            cout << cur + a << '\n';
            ans = cur + a;
        }
    }
    
    
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome