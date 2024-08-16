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
        cin >> s1;
        ll p;
        cin >> p;

        ll sum = 0;
        map<int, int> ma;
        for (int i = 0; i < s1.size(); i++)
        {
            ma[abs(s1[i] - 'a') + 1]++;
            sum += abs(s1[i] - 'a') + 1;
        }

        if (sum <= p)
        {
            cout << s1 << '\n';
        }
        else
        {

            vector<ii> v;

            for (auto el : ma)
            {
                v.push_back({el.first, el.second});
            }

            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());

           

            for (auto &el : v)
            {
                if (sum - (el.first * el.second) <= p)
                {
                    //DBG(1);
                    int aux = abs(sum - p);
                    int qnt = aux / el.first;
                    if (aux % el.first != 0)
                    {
                        qnt++;
                    }

                    sum -= el.first * qnt;
                    el.second -= qnt;
                    break;
                }
                else
                {
                    //DBG(2);
                    sum -= el.first * el.second;
                    el.second = 0;
                }
            }

            

            map<int, int> nma;

            for (auto el : v)
            {
                nma[el.first] = el.second;
            }

            string aux;

            for (int i = 0; i < s1.size(); i++)
            {
                if (nma[abs(s1[i] - 'a') + 1] >= 1)
                {
                    aux.push_back(s1[i]);
                    nma[abs(s1[i] - 'a') + 1]--;
                }
            }

            cout << aux << '\n';
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome