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
    int x;
    vi v;
    while (t--)
    {
        v.clear();
        string s1;
        cin >> s1;
        string s2;

        s2 = s1;
        bool aux = false;
        int ind;
        for (int i = s2.size()-1; i >= 0;i--)
        {
            if (s2[i]-'0' >= 5) {
                aux= true;
                ind = i;
            }
            v.pb(s2[i]-'0');
        }
        
        if (aux) {

            for (int i = 0; i < v.size()-1; i++)
            {
                if (v[i] >= 5) {
                    v[i] = 0;
                    v[i+1]++;
                } else if (i < v.size()-ind) {
                    v[i] = 0;
                } else {
                    break;
                }
            }

            if (v.back() >= 5) {
                int auu = v.back();
                v[v.size()-1] = 0;
                v.pb(1);
            }
            

        }

        reverse(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        

        cout << '\n';
        
        
        





    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome