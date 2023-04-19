#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 51234
#define INF 112345678

typedef pair<int, int> ii;

int n, dist[MAX], ok[MAX];
vector<ii> lg[MAX];

int prim() { // use long long if necessary
    int ans = 0, u;
    priority_queue< ii, vector<ii>, greater<ii> > q; // min heap
    for(u = 0; u < n; u++) { dist[u] = INF; ok[u] = 0; }
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



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cases, m, cnt, wei, u, v, first = 1;

    cin >> cases;

    while (cases--)
    {
        map<string, int> s2u;
        cin >> n >> m;

        cnt = 0;
        while (m--)
        {
            string s1, s2;
            cin >> s1 >> s2 >> wei;
            u = s2u.find(s1) == s2u.end() ? (s2u[s1] = cnt++) : s2u[s1];
            v = s2u.find(s2) == s2u.end() ? (s2u[s2] = cnt++) : s2u[s2];
            lg[u].push_back(ii(v, wei));
            lg[v].push_back(ii(u, wei));
        }

        if (first)
        {
            first = 0;
        } else {
            cout << '\n';
        }
        
        cout << prim() << '\n';
        for(u = 0; u < n; u++) lg[u].clear();


    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome