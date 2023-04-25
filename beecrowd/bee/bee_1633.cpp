#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 112345

typedef pair<int, int> ii;

ii proc[MAX];
int n;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n) {
        priority_queue<ii, vector<ii>, greater<ii>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> proc[i].first >> proc[i].second;
        }
        sort(proc, proc + n);
        int i = 0, t = 1;
        long long ans = 0;

        while (i < n || !q.empty())
        {
            while (i < n && proc[i].first <= t)
            {
                q.push(ii(proc[i].second, proc[i].first));
                i++;
            }
            
            if (!q.empty())
            {
                ans +=  t - q.top().second;
                t += q.top().first;
                q.pop();
            } else if (i < n) {
                t = proc[i].first;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome