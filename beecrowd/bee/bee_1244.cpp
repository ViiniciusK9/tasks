#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef pair<string, int> si;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s, aux;

    cin >> n;
    getline(cin, s);
    while (n--)
    {
        vector<si> vet;
        getline(cin, s);
        int i = 0;
        int ant = 0;
        for (int j = 1; j < s.length()+1; j++)
        {
            if (s[j] == ' ' or s[j] == '\0' or s[j] == '\n')
            {
                aux = s.substr(ant, j-ant);
                ant = j+1;
                vet.push_back(si(aux, aux.size()));
            }   
        }

        
        for (int i = 0; i < vet.size(); i++)
        {
            for (int j = 0; j < vet.size()-1; j++)
            {
                if (vet[j].second < vet[j+1].second )
                {
                    si aux_s = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = aux_s;
                }
            }
            
        }

        for (int j = 0; j < vet.size(); j++)
        {
            cout << (j == 0 ? "" : " ") << vet[j].first;
        }
        
        cout << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome