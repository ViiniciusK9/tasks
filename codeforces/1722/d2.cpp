#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s1;
        cin >> s1;

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == 'R')
            {
                ans += (n - 1) - i;
            }
            else
            {
                ans += (i);
            }
        }
        

        priority_queue<ll> q;
        for (int i = 0; i < n/2; i++)
        {
            if (s1[i] == 'L') {
                q.push((n-1)-i - i);
            }
        }

        for (int i = n-1; i >= n/2; i--)
        {
            if (s1[i] == 'R') {
                q.push(i - ((n-1)-i));
            }
        }
        
        vi res;


        while (!q.empty())
        {
            ll cur = q.top();
            q.pop();
            ans += cur;
            res.pb(ans);
        }
        
        
        while (res.size() < n)
        {
            res.pb(ans);
        }
        

        sort(res.begin(), res.end());

        for (int i = 0; i < res.size(); i++)
        {
            cout << (i == 0 ? "" : " ") << res[i];
        }

        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome