#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    string s;
    pair<string, int> aux;

    while (cin >> n && n != 0)
    {
        vector<pair<string, int>> vet;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> num;
            vet.push_back({s, num});
            //DBG(i);
        }
        //vet.erase(vet.at(1));

        //DBG(1);
        aux = vet[0];
        cout << aux.first << " " << aux.second << '\n';
        int desl = 0;
        int at = 0;   // at ira receber quem saiu + 1 se começar pela direita ou quem saiu -1 se começar pela esquerda (sentido da contagem)
        if (aux.second % 2 == 1)
        {
            // caso impar          0 1 2
            desl = at - (aux.second % vet.size());
            //DBG(desl);
            if (desl < 0)
            {
                desl = vet.size() - abs(desl);
                //DBG(desl);
            }
            

        } else {
            //caso par
            desl = at + (aux.second % vet.size());
            if (desl >= vet.size())
            {
                desl = desl % vet.size();
            }
        }
        DBG(desl);
        aux = {vet.at(desl).first, vet.at(desl).second};
        vet.erase(vet.begin() + desl);
        //cout << aux.second << " " << aux.first << '\n';

        while (!vet.empty())
        {   
            if (aux.second % 2 == 1)
            {
                at = desl;
                DBG(at);
                if (at < 0)
                {
                    at = vet.size() - abs(at);
                }
                
                // caso impar          0 1 2
                desl = at - (aux.second % vet.size());
                //DBG(desl);
                if (desl < 0)
                {
                    desl = vet.size() - abs(desl);
                    //DBG(desl);
                }
                if (desl >= vet.size())
                {
                    desl = desl % vet.size();
                }
                

            } else {
                //caso par
                at = desl ;
                DBG(at);
                if (at >= vet.size())
                {
                    at = at % vet.size();
                }
                
                desl = at + (aux.second % vet.size());
                if (desl >= vet.size())
                {
                    desl = desl % vet.size();
                }
                if (desl < 0)
                {
                    desl = vet.size() - abs(desl);
                    //DBG(desl);
                }
            }
            DBG(desl);
            aux = {vet.at(desl).first, vet.at(desl).second};
            cout << aux.first << " " << aux.second << '\n';
            
            vet.erase(vet.begin() + desl);

        }
        cout << aux.first << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome