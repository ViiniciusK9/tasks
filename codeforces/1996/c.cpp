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

const int MAX = int(2e5 + 10);

//int pf1[27][MAX];
//int pf2[27][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        string s1, s2;
        cin >> n >> q;

        cin >> s1 >> s2;
        vector<array<int,26>> pf1, pf2;
        //memset(pf1, 0, sizeof(pf1));
        //memset(pf2, 0, sizeof(pf2));
        //array<vector<int>, 26> pf1;
        //array<vector<int>, 26> pf2;

        array<int, 26> aux;
        for (int i = 0; i < n; i++) {
            aux[s1[i]-'a']++; 
            pf1.pb(aux);
        }
        for (auto &i : aux) i=0;
        
        for (int i = 0; i < n; i++) {
            aux[s2[i]-'a']++; 
            pf2.pb(aux);
        }

        /*
        for (int i = 1; i <= s1.size(); i++)
        {
            pf1[s1[i-1] - 'a'][i] = 1;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= s1.size(); j++)
            {
                pf1[i][j] = pf1[i][j] + pf1[i][j - 1];
            }
        }

        for (int i = 1; i <= s2.size(); i++)
        {
            pf2[s2[i-1] - 'a'][i] = 1;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                pf2[i][j] = pf2[i][j] + pf2[i][j - 1];
            }
        }
        */

        //continue;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            array<int, 26> ma1;
            array<int, 26> ma2;

            for (int i = 0; i < 26; i++)
            {
                ma1[i] = pf1[r][i] - pf1[l][i];
            }
            ma1[s1[l]-'a']++; 

            for (int i = 0; i < 26; i++)
            {
                ma2[i] = pf2[r][i] - pf2[l][i];
            }
            ma2[s2[l]-'a']++;
            int ans = 0;
            for (int i = 0; i < 26; i++)
            {
                ans += abs(ma1[i] - ma2[i]);
            }
            cout << ans/2 << '\n';
            

        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome