#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define f first
#define se second
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

    int cnt = 1;

    map<string ,int> ma;

    for (int i = 'a'; i <= 'z'; i++)
    {
        for (int j = 'a'; j <= 'z'; j++)
        {
            if (i != j) {
                string aux;
                aux.pb(i);
                aux.pb(j);
                ma[aux] = cnt;
                cnt++;
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        cin >> s1;
        cout << ma[s1] << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome