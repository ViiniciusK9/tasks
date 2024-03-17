#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, aux, fail, nn;
    vector<int> vet;
    cin >> t;
    while (t--)
    {
        vet.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            vet.push_back(aux);
        }

        fail = 0;
        nn = n;
        while (nn--)
        {
            
        
            int tam = vet.size();
            int i = 0; 
            while (i < (tam -1))
            {
                if (vet[i] <= vet[i+1]) {
                    i++;
                    continue;
                } else {
                    //DBG((vet[i]/10));
                    //DBG((vet[i]%10));
                    //DBG((vet[i+1]));

                    if ((vet[i]/10) <= (vet[i]%10) && (vet[i]%10) <= (vet[i+1])) {
                        int n1 = vet[i]/10;
                        int n2 = vet[i]%10;
                        vet[i] = n1;

                        auto it = vet.begin();
                        vet.insert(it + i+1, n2);
                        tam++;
                        /*
                        for (int x = 0; x < vet.size(); x++)
                        {
                            //DBG(vet[x]);
                        }
                        */ 
                        
                    } else {
                        fail = 1;
                        break;
                    }
                }
                //DBG(1);
                i++;
            }
            if (fail == 1) break;
        }
        

        if (fail == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome