#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string s;
    int a1, a2, a3, a4;
    string aux;
    string zero = "0";
    int flag = 0;
    while (t--)
    {
        cin >> s;
        a1 =  s[0] - '0';
        a2 = s[1]  - '0';
        a3 = s[3]  - '0';
        a4 = s[4] - '0';

        //cout << a1  << a2 << '\n';

        a1 = (a1 * 10) + a2;
        
        //DBG(a1);
        if (a1 > 12) {
            a1 = a1 - 12;

            if (a1 < 10) {
                flag = 1;
            }

            aux = " PM\n";
        }else if (a1 == 0) {
            a1 = 12;
            aux = " AM\n";
        } else if (a1 < 10) {
            flag = 1;
            aux = " AM\n";
        } else if (a1 == 12) {
            aux = " PM\n";
        }
        else {
            aux = " AM\n";
        }

        cout << ((flag == 1) ? "0" : "") <<  a1 << ":" << a3 << a4 << aux;

        
        flag = 0;

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome