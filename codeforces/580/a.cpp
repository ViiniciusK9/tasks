#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, big = 0, at = 0, ant;
    cin >> n;

    cin >> aux;
    big = 0;
    at = 1;
    ant = aux;
    for (int i = 1; i < n; i++)
    {
        cin >> aux;
        if (aux < ant) {
            if (at > big) {
                big = at;
                at = 1;
            }
            at = 1;
        } else {
            at++;
        }
        ant = aux;
    }

    if (at > big) {
        big = at;
    }
    
    cout << big << '\n';

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome