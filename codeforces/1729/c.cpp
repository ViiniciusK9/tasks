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

bool comp1(pair<char, int> a, pair<char, int> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first > b.first)
    {
        return false;
    }
    else if (a.first == b.first)
    {
        return a.second >= b.second;
    }
}

bool comp2(pair<char, int> a, pair<char, int> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first > b.first)
    {
        return false;
    }
    else if (a.first == b.first)
    {
        return a.second <= b.second;
    }
}

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
        int n = s1.size();
        int min = abs(s1[n - 1] - s1[0]);
        char ini = s1[0];
        char fin = s1[n - 1];

        if (ini > fin)
        {
            swap(ini, fin);
        }

        vector<pair<char, int>> vr;

        for (int i = 0; i < s1.size(); i++)
        {
            vr.pb({s1[i], i + 1});
        }

        vector<pair<char, int>> v;

        if (s1[0] > s1[n - 1])
        {
            sort(vr.begin(), vr.end(), comp1);
            for (int i = vr.size() - 1; i >= 0; i--)
            {
                if (vr[i].first >= ini && vr[i].first <= fin)
                {
                    v.pb(vr[i]);
                }
            }
        }
        else
        {
            sort(vr.begin(), vr.end(), comp2);
            for (int i = 0; i < vr.size(); i++)
            {
                if (vr[i].first >= ini && vr[i].first <= fin)
                {
                    v.pb(vr[i]);
                }
            }
        }

        cout << min << " " << v.size() << '\n';
        for (int i = 0; i < v.size(); i++)
        {
            cout << (i == 0 ? "" : " ") << v[i].second;
        }
        cout << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome