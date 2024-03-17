#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, sum;
    
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    cin >> n;
    int j = n;
    while (j--)
    {
        cin >> aux;
        v1.push_back(aux);
        cin >> aux;
        v2.push_back(aux);
        cin >> aux;
        v3.push_back(aux);
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        //DBG(v1[i]);
        sum += v1[i];
    }
    
    if (sum != 0) {
        cout << "NO\n";
        return 0;
    }

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v2[i];
    }
    
    if (sum != 0) {
        cout << "NO\n";
        return 0;
    }

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v3[i];
    }
    
    if (sum != 0) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome