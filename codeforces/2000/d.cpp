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
        vector<ll> v(n);
        vector<ll> pref(n+1);
        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            pref[i+1] = pref[i] + v[i];
        }

        
        
        int l = 0;
        int r = n-1;

        string s1;
        cin >> s1;

        while (l < r)
        {
            if (s1[l] == 'L' && s1[r] == 'R') {
                sum += pref[r+1] - pref[l];
                l++;
                r--;
            }

            if (s1[l] != 'L') l++;
            if (s1[r] != 'R') r--;
        }
        

        

        cout << sum << '\n';


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome