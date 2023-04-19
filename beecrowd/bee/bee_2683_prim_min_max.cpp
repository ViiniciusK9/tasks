#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)



#define MAX 1123456
#define INFN -1
#define INFP 112345678

typedef pair<int, int> ii;

int n, dist[MAX], ok[MAX];
vector<ii> lg[MAX];
/*
int prim() { // use long long if necessary
    int ans = 0, u;
    priority_queue< ii, vector<ii>, greater<ii> > q; // min heap
    for(u = 0; u < n; u++) { dist[u] = INFP; ok[u] = 0; }
    dist[0] = 0;
    q.push(ii(dist[0], 0));
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();
        if (ok[u])
        {
            continue;
        }
        ok[u] = 1;
        ans += dist[u];
        for (auto &[v, wei] : lg[u])
        {
            if (dist[v] > wei)
            {
                dist[v] = wei;
                q.push(ii(wei, v));
            }
        }
    }
    return ans;
}
*/

long long prim_min() { // use long long if necessary 
    long long ans = 0, u, v, wei;
    ii e;
    priority_queue< ii, vector<ii>, greater<ii> > q; // min heap
    for(u = 0; u < n; u++) { dist[u] = INFP; ok[u] = 0; }
    dist[0] = 0;
    q.push(ii(dist[0], 0));
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();
        if (ok[u])
        {
            continue;
        }
        ok[u] = 1;
        ans += dist[u];
        //for (auto &[v, wei] : lg[u])
        for (auto &it : lg[u]) 
        {
            v = it.first; wei = it.second;
            if (dist[v] > wei)
            {
                dist[v] = wei;
                q.push(ii(wei, v));
            }
        }
    }
    return ans;
}

long long prim_max() { // use long long if necessary
    long long ans = 0, u, v, wei;
    ii e;
    priority_queue< ii, vector<ii>, less<ii> > q; // min heap
    for(u = 0; u < n; u++) { dist[u] = INFN; ok[u] = 0; }
    dist[0] = 0;
    q.push(ii(dist[0], 0));
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();
        if (ok[u])
        {
            continue;
        }
        ok[u] = 1;
        ans += dist[u];
        //for (auto &[v, wei] : lg[u])
        for (auto &it : lg[u]) 
        {
            v = it.first; wei = it.second;
            if (dist[v] < wei)
            {
                dist[v] = wei;
                q.push(ii(wei, v));
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int aux = n, u, v, wei;
    while (aux--)
    {
        cin >> u >> v >> wei;
        u--; v--;
        //eg.push_back(iii(wei, ii(u, v)));
        lg[u].push_back(ii(v, wei)); 
        lg[v].push_back(ii(u, wei)); 
    }
    cout << prim_max() << '\n';    
    cout << prim_min() << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome