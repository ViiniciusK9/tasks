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

        vector<ii> res;
        
        queue<ii> q;
        for (int i = 2; i <= n; i++)
        {
            q.push({1, i});
        }

        while (!q.empty())
        {
            ii fr = q.front();
            q.pop();

            cout << "? " << fr.first << " " << fr.second << '\n';
            cout << '\n';
            cout.flush();
            int rs;
            cin >> rs;

            if (rs == fr.first) {
                res.pb(fr);
            } else {
                q.push({rs, fr.second});
            }
        }

        cout << "!";

        for (auto el : res)
        {
            cout << " " << el.first << " " << el.second;
        }
        cout << '\n';
        cout.flush();
        


        



    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome