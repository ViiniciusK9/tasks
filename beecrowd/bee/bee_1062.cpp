#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


void solve(int *vet, int n) {
    int value = 1, i = 0;
    stack<int> p;
    p.push(value++);
    while (true)
    {
        if (!p.empty())
        {
            if (p.top() == vet[i])
            {
                p.pop();
                i++;
            } else if (p.top() > vet[i]) {
                // deu ruim
                cout << "No\n";
                return;
            } else {
                p.push(value++);
            }
        } else {
            if (value > n)
            {
                cout << "Yes\n";
                return;
            }
            p.push(value++);
        }
        
    }
    return;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, vet[112345], first = 1;
    while (cin >> n)
    {   
        cout << (first ? "" : "\n");
        first = 0;
        while (true)
        {
            cin >> aux;
            //DBG(aux);
            if (aux == 0)
            {
                break;
            } else {
                vet[0] = aux;
                for (int i = 1; i < n; i++)
                {
                    cin >> vet[i];
                }
                solve(vet, n);
            }
        }   
    }  
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome


/*
p.push(pp);
                pp++;
                if (!p.empty())
                {
                    if (p.top() == aux)
                    {
                        p.pop();
                    } else if (p.top() > aux) {
                        // deu ruim
                    } else {
                        p.push(pp++);
                    }
                } else {
                    p.push(pp++);
                }

*/