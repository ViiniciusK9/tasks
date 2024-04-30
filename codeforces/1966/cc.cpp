#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
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

    int t, n, aux;

    cin >> t;

    set<int> s;

    while (t--)
    {
        s.clear();

        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            s.insert(aux);
        }

        priority_queue<int> pq;

        for (auto e : s)
        {
            pq.push(-e);
        }
        int at = 0;
        int start = 0;
        while (!pq.empty())
        {
            // cout << pq.top() << '\n';

            at = abs(pq.top());

            if (at - sum < 0)
            {
                // quem ta na vez perdeu
                break;
            }

            if (pq.size() % 2 == 0 && (at - sum) != 1)
            {
                sum = sum + (at - sum) - 1;
            }
            else
            {
                sum = sum + (at - sum);
                pq.pop();
            }

            // troca
            if (start == 0)
            {
                start = 1;
            }
            else
            {
                start = 0;
            }
        }

        if (start == 1)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome