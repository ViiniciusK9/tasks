#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

array<array<long long, 512345>, 4> matriz;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n, p;
    cin >> n >> p;

    bitset<64> x;
    bitset<64> xx;

    for (int i = 0; i < 4; i++)
    {
        fill(matriz[i].begin(), matriz[i].end(), 0);
    }
    

    for (int i = 0; i < p; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            long long a = 1;
            if (s[j] == 'A') {
                matriz[0][j] |= (a << (i)); 
            } else if (s[j] == 'C') {
                matriz[1][j] |= (a << (i));
            } else if (s[j] == 'T'){
                matriz[2][j] |= (a << (i));
            } else {
                matriz[3][j] |= (a << (i));
            }
        }
    }
    
    cin >> s;
    /*
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A') {
            x = matriz[0][i];
            DBG(x);
        } else if (s[i] == 'C') {
            x = matriz[1][i];
            DBG(x);
        } else if (s[i] == 'T') {
            x = matriz[2][i];
            DBG(x);
        } else if (s[i] == 'G') {
            x = matriz[3][i];
            DBG(x);
        }
    }
    */
    
    int j = 0;
    string sub;
    x = 0;
    for (int i = 0; i < s.length(); i++)
    {   //DBG(s[i]);
        
        if (j == 0) {
            sub.push_back(s[i]);
            j++;
            if (s[i] == 'A') {
                x = matriz[0][i];
                //DBG(x);
            } else if (s[i] == 'C') {
                x = matriz[1][i];
                //DBG(x);
            } else if (s[i] == 'T') {
                x = matriz[2][i];
                //DBG(x);
            } else if (s[i] == 'G') {
                x = matriz[3][i];
                //DBG(x);
            }
            if (x == 0) {
                //DBG(-1);
                j = 0;
                cout << sub << " -1\n";
                sub.clear();
            } else {
                xx = x;
            }
        } else {
            xx = x;
            if (s[i] == 'A') {
                x &= matriz[0][i];
                //DBG(x);
            } else if (s[i] == 'C') {
                x &= matriz[1][i];
                //DBG(x);
            } else if (s[i] == 'T') {
                x &= matriz[2][i];
                //DBG(x);
            } else if (s[i] == 'G') {
                x &= matriz[3][i];
                //DBG(x);
            }
            if (x == 0) {
                //DBG(j);
                j = 0;
                i--;
                
                string aaux = xx.to_string();
                int ans = 0;
                //DBG(aaux);
                for (int j = 0; j < aaux.length(); j++)
                {
                    if (aaux[j] == '1') {
                        ans = abs(64 - j);
                    }
                }
                
                cout << sub << " " << ans << '\n';
                sub.clear();
            } else {
                sub.push_back(s[i]);
                j++;
                xx = x;
            }
        }
    }
    if (j != 0) {
        //DBG(j);
        string aaux = xx.to_string();
        int ans = 0;
        for (int j = 0; j < aaux.length(); j++)
        {
            if (aaux[j] == '1') {
                
                ans = abs(64 - j);
            }
        }
        cout << sub << " " << ans << '\n';
        sub.clear();
    }

    
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome