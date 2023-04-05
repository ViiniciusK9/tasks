#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int home[31];
    int guest[31];

    int n, h, a, i = 0, t, ans = 0;
    cin >> n;
    t = n;
    while (n--)
    {
        cin >> h >> a;
        home[i] = h;
        guest[i] = a;
        i++;
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (i != j)
            {
                if (home[i] == guest[j]) {
                    ans++;
                }
            }   
        }
    }
    cout << ans << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome