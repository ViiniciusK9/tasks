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
typedef pair<ll, ll> pi;
typedef pair<ll, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int c, t;

    cin >> n >> k;

    priority_queue<pi, vector<pi>, greater<pi>> qe;
    priority_queue<pi, vector<pi>, greater<pi>> qa;
    priority_queue<ll, vector<ll>, greater<ll>> qs;

    for (int i = 0; i < n; i++)
    {
        cin >> c >> t;
        qe.push({c, t});
    }

    ll maior = 0;

    ll at = 0;
    ll time = 0;
    ll kd = k;

    while (!qe.empty())
    {
        pi cur;
        ll ct;
        if (time == 0)
        {
            cur = qe.top();
            qe.pop();

            time = cur.first;
            qs.push(cur.first + cur.second);
            kd--;
            at++;
            maior = max(at, maior);
        }
        else
        {
            cur = qe.top();
            ct = qs.top();

            if (cur.first < ct) {
                if (kd > 0) {
                    qs.push(cur.first + cur.second);
                    qe.pop();
                    at++;
                    kd--;
                } else {
                    at++;
                    qs.push(ct+cur.second);
                    qe.pop();
                    
                    while (!qe.empty() && qe.top().first < ct)
                    {
                        cur = qe.top();
                        qe.pop();
                        qs.push(ct+cur.second);
                        at++;
                    }
                    

                    //qs.pop();
                }
            } else {


                qs.pop();
                at--;
                qe.pop();
                qs.push(cur.first+cur.second);
            }
        }


        maior = max(at, maior);
    }

    cout << maior << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome