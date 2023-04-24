#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(0)<<(x)

long long bt(long long nCards){
    long long top = 816496582, bottom = 0, m, r;
    while (bottom <= top) {
            m = bottom + (top - bottom) / 2;
            r = (m*(m*3+1)/2);
            if (r == nCards)
                return m;
    
            if (r < nCards)
                bottom = m + 1;
    
            else
                top = m - 1;
        }
    while (r > nCards)
    {
        m--;
        r = (m*(m*3+1)/2);
    }
    
    return m;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    unsigned long long aux;
    cin >> t;
    while (t--)
    {
        cin >> aux;
        cout << bt(aux) << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome