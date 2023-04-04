#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) setprecision(2)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h, m, a;
    cin >> n;
    while (n--)
    {   
        cin >> h >> m >> a;
        string x = (a == 1) ? "A porta abriu!\n" : "A porta fechou!\n";
        string esp = (h <= 9) ? "0" : "";
        string esp2 = (m <= 9) ? "0" : "";
        cout << esp << h << ":" << esp2 << m << " - " << x ;
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome