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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = int(2e5+10);

int mar[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n;
    char c;
    string s1;
    while (t--)
    {
        memset(mar, 0, sizeof(mar));
        cin >> n >> c;
        cin >> s1;

        int pos = -1;
        for (int i = n-1; i >= 0; i--)
        {
            if (s1[i] == 'g') {
                pos = i;
                mar[i] = pos;
            } else {
                mar[i] = pos;
            }
        }


        
        

        for (int i = n-1; i >= 0; i--)
        {
            if (mar[i] == -1) {
                mar[i] = (mar[0]);
            } else {
                break;
            }
            
        }
        /*
        cout << "mar: ";
        for (int i = 0; i < n; i++)
        {
            cout << mar[i] << " ";
        }

        cout << '\n';
        cout << '\n';
        */

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == c) {
                int val;

                if (mar[i] < i) {
                    val = mar[i] + 1 + (n-1 - i);
                } else if (mar[i] == i) {
                    val = 0;
                } else {
                    val = mar[i] - i;
                }

                ans = max(ans, (val));
            }
        }
        
        cout << ans << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome