#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<char> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        {
            stack<char> q;
            for (int i = 0; i < n; i++)
            {
                if (q.empty())
                    if (a[i] == '_')
                    {
                        a[i] = '(';
                        q.push('(');
                        continue;
                    }

                if (a[i] == '_')
                {
                    q.pop();
                    a[i] = ')';
                    continue;
                }
                if (a[i] == ')')
                {
                    q.pop();
                    continue;
                }
                q.push('(');
            }
        }
        ll sum = 0;
        priority_queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (q.empty())
            {
                q.push(i);
                continue;
            }

            if (a[i] == '(')
            {
                q.push(i);
                continue;
            }

            int k = q.top();
            q.pop();
            sum += abs(k - i);
        }

        cout << sum << endl;

        /*
        for (auto i: a) {
            cout << i<< " ";
        }
        cout << endl;
        */
    }
    return 0;
}