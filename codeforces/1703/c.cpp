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

string mat[123];

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
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }


        for (int i = 0; i < n; i++)
        {
            int len;
            cin >> len;
            string path;
            cin >> path;

            for (int j = 0; j < len; j++)
            {
                if (path[j]  == 'D') {
                    a[i]++;
                    a[i] = a[i]%10;
                } else {
                    a[i]--;
                    if (a[i] == -1) {
                        a[i] = 9;
                    }
                }
            }
            
        }

        for (int i = 0; i < n; i++)
        {
            cout << (i == 0 ? "" : " ") << a[i];
        }
        cout << '\n';
        



        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome