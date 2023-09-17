#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;

int vet[60];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, n;
    
    while (cin >> l)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> vet[i];   
        }

        sort(vet, vet+n);
        
        

    }
    


    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome