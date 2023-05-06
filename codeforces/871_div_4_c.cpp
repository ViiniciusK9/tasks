#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define MAX 212345


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, time;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a1 = MAX, a2 = MAX, a3 = MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> time >> s;
            if (s == "11")
            {
                if (time < a1)
                {
                    a1 = time;
                }
            }else if (s == "10") {
                if (time < a2)
                {
                    a2 = time;
                }
            } else if (s == "01") {
                if (time < a3)
                {
                    a3 = time;
                }
            }
            
            
        }

        if (a1 != MAX && a1 < a2 + a3)
        {
            cout << a1 << '\n';
            
        } else if (a2 != MAX && a3 != MAX) {
            cout << a2 + a3 << '\n';
        } else {
            cout << "-1\n";
        }
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome