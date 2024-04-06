#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, k, aux, a1, a2;
    vector<int> vet;
    vet.reserve(10e5);
    cin >> t;
    while (t--)
    {
        vet.clear();
        cin >> n >> k;
        m = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            if (aux > m) {
                m = aux;
            }
            vet.push_back(aux);
        }
        k = vet[k-1];
        //DBG(k);
        //DBG(m);
        if (k == m) {
            cout << n-1 << '\n';
        } else if (vet[0] >= k && vet[1] >= k) {
            cout << 0 << '\n';
        } else {
            
            a1 = -5, a2 = -5;
            for (int i = 0; i < n; i++)
            {
                //DBG(i);
                //DBG(a1);
                //DBG(a2);
                if (a1 == -5 && vet[i] > k) {
                    a1 = i-1;
                } else if (a1 != -5 && a1 != -2 && vet[i] >= k) {
                    a2 = i - (a1 + 1);
                    if (a1 == -1)a2--;
                    if (a1 > a2) {
                        cout << a1 << '\n';
                    } else {
                        cout << a2 << '\n';
                    }
                    break;
                } else if (a1 == -5 && vet[i] == k) {
                    a1 = -2;
                } else if (a1 == -2 && vet[i] > k) {
                    cout << i-1 << '\n';
                    break;
                }
            }
            
        }

    }
     

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome