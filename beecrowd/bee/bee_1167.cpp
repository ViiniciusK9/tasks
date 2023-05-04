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
        }
        //vet.erase(vet.at(1));

        DBG(1);
        aux = vet.at(0);
        int desl = 0;
        int at = 0;   // at ira receber quem saiu + 1 se começar pela direita ou quem saiu -1 se começar pela esquerda (sentido da contagem)
        if (aux.second % 2 == 1)
        {
            // caso impar          0 1 2
            desl = at - (aux.second % vet.size());
            if (desl < 0)
            {
                desl = vet.size() - desl;
            }
            

        } else {
            //caso par
            desl = at + (aux.second % vet.size());
            if (desl >= vet.size())
            {
                desl = desl % vet.size();
            }
        }
        aux = vet.at(desl);
        cout << aux.second << " " << aux.first << '\n';


        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome