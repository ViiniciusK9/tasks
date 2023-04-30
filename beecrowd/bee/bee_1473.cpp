#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 301

int mt[MAX][MAX];

int vl[MAX];
int vc[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, maior, menor, aux, ans;
    while (cin >> n >> l)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> maior;
            menor = maior;
            mt[i][0] = maior;
            for (int j = 1; j < l; j++)
            {
                cin >> aux;
                if (aux > maior)
                {
                    maior = aux;
                } else if (aux < menor)
                {
                    menor = aux;
                }
                mt[i][j] = aux;
            }
            if (abs(maior - menor) >= l)
            {
                ans = -1;
            }
            
        }

        if (ans == -1)
        {
            cout << "*\n";
        } else {
            int p;
            for (int i = 0; i < l; i++)
            {
                p = (mt[0][i] % l);
                for (int j = 0; j < n; j++)
                {
                    if (p != (mt[j][i] % l))
                    {
                        ans = -1;
                        break;
                    }
                    
                }
                if (ans == -1)
                {
                    break;
                }
            }
            if (ans == -1)
            {
                cout << "*\n";
            } else {
                
                for (int i = 0; i < n; i++)
                {
                    vl[i] = mt[i][0];
                }
                for (int i = 0; i < l; i++)
                {
                    vc[i] = mt[0][i];
                }

                int min_i = -1;
                for (int i = 0; i < n; i++)
                {
                    aux = vl[i];
                    min_i = -1;
                    for (int j = i+1; j < n; j++)
                    {
                        
                        if (aux > vl[j])
                        {
                            if (min_i == -1) {
                                min_i = j;
                            } else {
                                if (vl[j] < vl[min_i])
                                {
                                    min_i = j;
                                }
                            }
                        }
                    }
                    if (min_i != -1)
                    {
                        vl[i] = vl[min_i];
                        vl[min_i] = aux;
                        ans++;
                    }
                }

                for (int i = 0; i < l; i++)
                {
                    aux = vc[i];
                    min_i = -1;
                    for (int j = i+1; j < l; j++)
                    {
                        
                        if (aux > vc[j])
                        {
                            if (min_i == -1) {
                                min_i = j;
                            } else {
                                if (vc[j] < vc[min_i])
                                {
                                    min_i = j;
                                }
                            }
                        }
                    }
                    if (min_i != -1)
                    {
                        vc[i] = vc[min_i];
                        vc[min_i] = aux;
                        ans++;
                    }
                }
                cout << ans << '\n';
            }
        }
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome