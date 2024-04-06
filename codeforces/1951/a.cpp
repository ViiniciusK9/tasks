#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, cont, flag;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> n;
        cin >> s;
        cont = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1') cont++;
        }
        flag = 0;
        if (cont % 2 == 0) {
            if (n > 2 && cont > 2) {
                cout << "YES\n";
            } else if (n == 2 && cont == 2) {
                cout << "NO\n";
            } else if (cont == 2){
                for (int i = 0; i < n-1; i++)
                {
                    if (s[i] == '1' && s[i+1] == '1') {
                        cout << "NO\n";
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    cout << "YES\n";
                }
            } else {
                cout << "YES\n";
            }
        } else {
            cout << "NO\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome