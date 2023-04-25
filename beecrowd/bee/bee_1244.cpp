#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


bool comparacao(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second)
    {
        return a.second >= b.second;
    }
    return a.second > b.second;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s, aux;


    cin >> n;

    while (n+1)
    {
        vector<pair<string, int>> vet;
        n--;
        getline(cin, s);
        //cout << s << '\n';
        int i = 0;
        int fim = 0;
        int ant = 0;
        for (int j = 0; j < s.length()+1; j++)
        {
            fim++;
            if (s[j] == ' ' or s[j] == '\0' or s[j] == '\n')
            {
                aux = s.substr(ant, abs(fim - ant));
                vet.push_back({aux, aux.size()});
                i++;
                ant = fim;
            }
            
        }

        
        sort(vet.begin(), vet.end(), comparacao);

        for (int j = 0; j < i; j++)
        {
            cout << vet[j].first << ' ';
        }
        cout << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome