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

const int MAX = int(1e5+10);

array<int, MAX> dist;
array<int, MAX> qnt;

int n;


int bottom(int k)
{
    int ans = 0;
    int m = 0;
    int val = k;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] <= val) {
            m = max(dist[i] + qnt[i], m);

        } else {
            if (m < dist[i]) {
                ans = -1;
                break;
            } else {
                val = m;
                m = max(dist[i] + qnt[i], m);
                ans++;
            }
        }
    }
    
    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> dist[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> qnt[i];
    }

    cout << bottom(k) << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome