#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, ant1,  at1, ans;
    cin >> t;
    string s;

    while (t--)
    {
        cin >> n;
        ant1 = at1 = ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                //DBG(s[i]);
                if (s[j] == '1') at1++;
            }
            //DBG(at1);
            //DBG(ant1);

            if (ans == 0 && at1 != 0){
                if (ant1 == 0) {
                    ant1 = at1;
                    at1 = 0;
                } else if (at1 != ant1) {
                    ans = 1;
                } else {
                    ans = 2;
                }
            }

            
        }

        if (ans == 1) {
            cout << "TRIANGLE\n";
        } else {
            cout << "SQUARE\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome