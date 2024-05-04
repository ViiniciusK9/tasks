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

const int MAX = int(2e5+10);



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, aux;
    vector<pi> v;
    cin >> n >> k;

    for (int i = 1; i < n+1; i++)
    {
        cin >> aux;
        v.pb({aux, i});
    }

    sort(v.begin(), v.end());

    set<int> retirado;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pqm;
    

    for (int i = 0; i < k; i++)
    {
        pq.push(v[i].second);
        pqm.push(v[i].second);
    }

    int ans = abs(pq.top() - pqm.top());
    for (int i = k; i < n; i++)
    {
        pq.push(v[i].second);
        pqm.push(v[i].second);
        retirado.insert(v[i-k].second);
        
        while (retirado.find(pq.top()) != retirado.end())
        {
            pq.pop();
        }

        while (retirado.find(pqm.top()) != retirado.end())
        {
            pqm.pop();
        }
        ans = min(ans, abs(pq.top() - pqm.top()));
        
    }
    
    
    cout << ans << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome