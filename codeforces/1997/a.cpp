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
        string s1;
        string aux;
        cin >> s1;
        int ind = 0;
        int f = 0;
        for (int i = 0; i < s1.size() - 1; i++)
        {
            if (s1[i] == s1[i + 1])
            {
                ind = i;
                f = 1;
                break;
            }
        }

        for (int i = 0; i < s1.size(); i++)
        {
            if (i == ind)
            {
                if (f == 1)
                {

                    aux.pb(s1[i]);
                    aux.pb((s1[i] == 'a' ? 'b' : 'a'));
                } else {
                    aux.pb((s1[i] == 'a' ? 'b' : 'a'));
                    aux.pb(s1[i]);
                }
            }
            else
            {
                aux.pb(s1[i]);
            }
        }

        cout << aux << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome