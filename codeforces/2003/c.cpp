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

        map<char, int> ma;
        for (int i = 0; i < n; i++)
        {
            ma[s1[i]]++;
        }

        vector<pair<int, char>> ve;

        for (auto el : ma)
        {
            ve.pb({el.second, el.first});
        }

        sort(ve.begin(), ve.end());
        reverse(ve.begin(), ve.end());

        for (auto el : ve)
        {
            for (int i = 0; i < el.first; i++)
            {
                cout << el.second;
            }
            
        }

        cout << '\n';
        


        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome