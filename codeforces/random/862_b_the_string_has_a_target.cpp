#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    char s[112345];
    string aa;
    //string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        int min = 150, ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= min)
            {
                min = s[i];
                ind = i;
            }
        }
        char aux = s[ind];
        //s[0] = s[ind];
        //s[ind] = 94; 
        aa = (string) s;
        aa = aa.erase(ind, 1);
        cout << aux << aa << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome