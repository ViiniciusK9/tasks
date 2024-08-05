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

        vi v1;
        vi v2;

        string s1;
        string s2;

        cin >> s1 >> s2;
        int ans = 0;
        int ct1 = 0;
        int ct2 = 0;
        int df = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i]) {
                df++;
                ans = -1;
            }
            if (s1[i] == '1') {
                ct1++;
            }
            if (s2[i] == '1') {
                ct2++;
            }
        }
        
        if (ans == 0) {
            cout << "0\n";
        } else {
            cout << abs(ct1 -  ct2) + ((df - abs(ct1 -  ct2)) != 0 ? ((df - abs(ct1 -  ct2)) / 2) : 0) << '\n';
        }
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome