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

const int MAX = int(2e5 + 10);

vi p(MAX);
vi a(MAX);

bool visited[MAX];

ll solve(int i, ll sum, int k) {
    //DBG(i);
    //DBG(sum);
    //DBG(k);
    if (k == 0) return sum;

    if (visited[i]) {
        
        return sum + ((ll)a[i] * (ll)k);
    }

    visited[i] = true;

    return max(sum + ((ll) a[i] * (ll) k), solve(p[i]-1, sum+a[i], k-1));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    int p_b, p_s;
    ll sum1, sum2;

    cin >> t;

    while (t--)
    {
        p.clear();
        a.clear();
        sum1 = sum2 = 0;
        cin >> n >> k >> p_b >> p_s;

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        memset(visited, false, sizeof(visited));
        //cout << solve(p_b-1, 0, k) << '\n';
        sum1 =solve(p_b-1, 0, k);
        memset(visited, false, sizeof(visited));
        //cout << solve(p_s-1, 0, k) << '\n';
        sum2 = solve(p_s-1, 0, k);

        if (sum1 > sum2) {
            cout << "Bodya\n";
        } else if (sum2 > sum1) {
            cout << "Sasha\n";
        } else {
            cout << "Draw\n";
        }

        /*
        memset(visited, false, sizeof(visited));
        queue<int> q;

        int max_b = a[p_b-1];
        q.push(p_b-1);
        //visited[p_b-1] = true;

        while (!q.empty())
        {
            int at = q.front();
            q.pop();
            if (!visited[at]) {
                visited[at] = true;
                max_b = max(max_b, a[at]);
                q.push(p[at]-1);
            }
        }

        memset(visited, false, sizeof(visited));
        queue<int> q1;
        int max_s = a[p_s-1];
        q1.push(p_s-1);
        //visited[p_b-1] = true;
        sum2 = 1;
        ll cont2 = 1;
        while (!q1.empty())
        {
            int at = q1.front();
            q1.pop();
            if (!visited[at]) {
                visited[at] = true;
                cont2++;
                //max_s = max(max_s, a[at]);
                if (a[at] > max_s) {
                    sum2 = cont2;
                    max_s = a[at];
                }
                q1.push(p[at]-1);
            }
        }
        
        */
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome