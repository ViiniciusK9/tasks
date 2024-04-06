#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

const int MAX = 112345;

int n;

array<int, MAX> arr;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int mm = 1;
    int ans = 1, ant, aux;
    cin >> ant;
    for (int i = 1; i < n; i++)
    {
        cin >> aux;
        if (ant < aux) {
            ans++;
        } else {
            ans = 1;
        }
        ant = aux;
        mm = max(mm, ans);
    }
    
    cout << mm << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome