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

        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                if (s1[i] == '_')
                {
                    s1[i] = '(';
                    st.push('(');
                    continue;
                }

            if (s1[i] == '_')
            {
                st.pop();
                s1[i] = ')';
                continue;
            }
            if (s1[i] == ')')
            {
                st.pop();
                continue;
            }
            st.push('(');
        }

        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            if (pq.empty())
            {
                pq.push(i);
                continue;
            }

            if (s1[i] == '(')
            {
                pq.push(i);
                continue;
            }

            int k = pq.top();
            pq.pop();
            ans += abs(k - i);
        }

        cout << ans << '\n';

    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome