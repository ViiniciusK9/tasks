#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, n4 = 10000, n3 = 1000, n2 = 100, n1 = 10;
    cin >> t;
    vector<int> vet;
    while (t--)
    {
        vet.clear();
        cin >> n;

        if (n / n4 != 0) {
            vet.push_back((n/n4) * n4);
        }

        if ((n%n4) / n3 != 0){
            vet.push_back(((n%n4) / n3) * n3);
        }

        if (((n%n4) % n3) / n2 != 0){
            vet.push_back((((n%n4) % n3) / n2) * n2);
        }

        if ((((n%n4) % n3) % n2) / n1 != 0){
            vet.push_back(((((n%n4) % n3) % n2) / n1) * n1);
        }

        if (n%10 != 0) {
            vet.push_back(n%10);
        }
        cout << vet.size() << '\n';
        cout << vet[0];
        for (int i = 1; i < vet.size(); i++)
        {
            cout << " " << vet[i];
        }
        cout << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome