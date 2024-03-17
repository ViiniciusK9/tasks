#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    string s;
    
    cin >> n >> t;
    cin >> s;

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (s[j] == 'B' && s[j+1] == 'G') {
                s[j] = 'G';
                s[j+1] = 'B';
                j++;
            }
        }
    }

    cout << s << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome