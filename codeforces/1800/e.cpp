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
        int n, k;

        cin >> n >> k;

        string s1, s2;
        cin >> s1 >> s2;

        if (n <= k) {
            bool ans = true;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] != s2[i]) ans = false; 
            }
            cout << (ans == true ? "YES\n" : "NO\n");
        } else if (n < 2*k){
            map<char, int> m1;
            map<char, int> m2;

            bool ans = true;
            for (int i = 0; i < s1.size(); i++)
            {
                if (i >= n-k && i <= 0+k-1){
                    if (s1[i] != s2[i]) ans = false; 
                } else {
                    m1[s1[i]]++;
                    m2[s2[i]]++;
                }
            }
            if (ans) {
                ans = true;
                for (auto el : m1) {
                    if (el.second != m2[el.first]) {
                        ans = false;
                    }
                }

                if (ans) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }

            } else {
                cout << "NO\n";
            }


        } else {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            bool ans = true;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] != s2[i]) ans = false; 
            }
            cout << (ans == true ? "YES\n" : "NO\n");
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome