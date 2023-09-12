#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, j;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        i = 0; j = n-1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                i++;
                j--;
                n -= 2;
            } else {
                break;
            }
            
        }
        cout << n << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome