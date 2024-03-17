#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    vector<int> v;
    int aux, a, b, c;  
    for (int i = 0; i < 4; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }
    
    sort(v.begin(), v.end());

    //  a+b, a+c, b+c and a+b+c.

    a = abs(v[3] - v[2]);
    b = abs(v[0] - a);
    c = abs(v[1] - a);

    cout << a << " " << b << " " << c << '\n'; 

    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome