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
        int n, h, m;

        cin >> n >> h >> m;
        vector<ii> hs;
        vi hr(n);
        vi mi(n);
        for (int i = 0; i < n; i++)
        {
            int h1, m1;
            cin >> h1 >> m1;
            hs.pb({h1, m1});
        }

        sort(hs.begin(), hs.end());
        int ah=-1, am=0;
        for (auto el : hs)
        {
            if (el.first >= h && el.second >= m) {
                ah = abs(h - el.first);
                am = abs(m - el.second);
                break;
            } else if (el.first > h && el.second < m) {
                ah = abs(h - el.first)-1;
                am = abs(m - (el.second + 60));
                break;
            }
        }

        if (ah == -1) {
            ii el = hs[0];
            el.first += 24;
            if (el.second >= m) {
                ah = abs(h - el.first);
                am = abs(m - el.second);
                
            } else if (el.second < m) {
                ah = abs(h - el.first)-1;
                am = abs(m - (el.second + 60));
                
            }
            cout << ah << " " << am << '\n';
        } else {
            cout << ah << " " << am << '\n';
        }


        

        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome