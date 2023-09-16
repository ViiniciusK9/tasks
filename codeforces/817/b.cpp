#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define ll long long int

int vet[112345];

unsigned long fat[100045];



ll combinatorics( int n, int k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    map<int, int> m;

    int n, m1, m2, m3;
    cin >> n;
    m1 = 1123456789;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        m1 = min(m1, vet[i]);
    }

    m2 = 1123456789;
    for (int i = 0; i < n; i++)
    {
        if (m1 != vet[i]) m2 = min(m2, vet[i]);

    }
    m3 = 1123456789;
    for (int i = 0; i < n; i++)
    {
        if (m1 != vet[i] && m2 != vet[i]) m3 = min(m3, vet[i]);
    }
    

    for (int i = 0; i < n; i++)
    {
        if (vet[i] == m1)
        {
            m[m1]++;
        }

        if (vet[i] == m2)
        {
            m[m2]++;
        }
        
        if (vet[i] == m3)
        {
            m[m3]++;
        }
    }
    
    /*
    DBG(m1);
    DBG(m[m1]);
    DBG(m2);
    DBG(m[m2]);
    DBG(m3);
    DBG(m[m3]);
    */
    

    if (m[m1] >= 3)
    {
        cout << combinatorics(m[m1],3) << '\n';
    } else if (m[m1] == 2)
    {
        cout << m[m2] << '\n';
    } else if (m[m1] == 1 && m[m2] == 2) 
    {
        cout << "1\n";
    }
    else if (m[m1] == 1 && m[m2] > 2)
    {
        cout << combinatorics(m[m2], 2) << '\n';
    } else if (m[m1] == 1 && m[m2] == 1) {
        cout << m[m3] << '\n';
    }

    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome