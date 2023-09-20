#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

vector<string> v1, v2;
int memo[1123][1123];

int dp(int i1, int i2)
{
    if (i1 == v1.size()) return 0;
    if (i2 == v2.size()) return 0;
    
    if (memo[i1][i2] != -1) return memo[i1][i2];

    int ans = 0;
    if (v1[i1] == v2[i2]) ans = dp(i1 +1, i2 + 1) + 1;
    else ans = max(dp(i1 + 1, i2), dp(i1, i2 + 1));

    return memo[i1][i2] = ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    int t = 1;

    while (getline(cin, s1) && getline(cin, s2))
    {
        
        v1.clear();
        v2.clear();
        //DBG(s1);
        //DBG(s2);
        int ant = 0, i;
        memset(memo, -1, sizeof(memo));
        for (i = 0; i < s1.size(); i++)
        {
            if (s1[i] >= 'A' && s1[i] <= 'Z' || s1[i] >= 'a' && s1[i] <= 'z' || s1[i] >= '0' && s1[i] <= '9')
            {
                // uma letra valida
                continue;
            }
            else
            {
                // tratar
                if (i == ant)
                {
                    ant = i+1;
                }
                else
                {

                    v1.push_back(s1.substr(ant, abs(ant - i)));
                    //DBG(s1.substr(ant, abs(ant - i)));
                    ant = i+1;
                }
            }
        }
        // tratar
        if (i == ant)
        {
            ant = i+1;
        }
        else
        {

            v1.push_back(s1.substr(ant, abs(ant - i)));
            //DBG(s1.substr(ant, abs(ant - i)));
            ant = i+1;
        }

        ant = 0;

        for (i = 0; i < s2.size(); i++)
        {
            if (s2[i] >= 'A' && s2[i] <= 'Z' || s2[i] >= 'a' && s2[i] <= 'z' || s2[i] >= '0' && s2[i] <= '9')
            {
                // uma letra valida
                continue;
            }
            else
            {
                // tratar
                if (i == ant)
                {
                    ant = i+1;
                }
                else
                {
                    v2.push_back(s2.substr(ant, abs(ant - i)));
                    //DBG(s2.substr(ant, abs(ant - i)));
                    ant = i+1;
                }
            }
        }
        // tratar
        if (i == ant)
        {
            ant = i+1;
        }
        else
        {
            v2.push_back(s2.substr(ant, abs(ant - i)));
            //DBG(s2.substr(ant, abs(ant - i)));
            ant = i+1;
        }
        
        if (v1.empty() || v2.empty())
        {
            cout << t << ". Blank!\n";
        } 
        else 
        {
            cout << t << ". Length of longest match: " << dp(0, 0) << "\n";
        }

        t++;

    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome