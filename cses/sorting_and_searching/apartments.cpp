#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> app;
    vector<int> ap;

    int n, m, k, i, aux, ans = 0, j;
    cin >> n >> m >> k;

    for (i = 0; i < n; i++)
    {
        cin >> aux;
        app.push_back(aux);
    }

    for (i = 0; i < m; i++)
    {
        cin >> aux;
        ap.push_back(aux);
    }
    
    sort(app.begin(), app.end());
    sort(ap.begin(), ap.end());
    i = 0; j = 0;

    while (true)
    {
        if (i == n || j == m)
        {
            break;
        }
        if (app[i] >= (ap[j] - k) && app[i] <= (ap[j] + k))
        {
            ans++;
            i++;
            j++;
        } else if (app[i] > ap[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans << '\n';
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome