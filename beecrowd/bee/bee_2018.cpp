#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

bool comparacao(const pair<string, int> j, const pair<string, int> i) {
    if (j.second != i.second)
    {
        return j.second > i.second;
    }
    return j.first < i.first;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string des, ouro, prata, bronze;
    map<string, int> medalhas;
    vector<pair<string, int>> aux;

    while (getline(cin, des))
    {
        getline(cin, ouro);
        getline(cin, prata);
        getline(cin, bronze);

        medalhas[ouro]+= 100;
        medalhas[prata] += 10;
        medalhas[bronze]++;
    }

    
    for (const auto &j : medalhas)
    {
        aux.emplace_back(j);
    }
    
    sort(aux.begin(), aux.end(), comparacao);

    /*
        Não funcionou
        quando tem mais de 10 medalhas de prata conta como se fosse uma de ouro 
        (e o mesmo acontece com 10 de bronze virando uma de prata), com isso o 
        resultado final fica invalido. 
    */

    cout << "Quadro de Medalhas\n";
    for (const auto &j : aux)
    {
        cout << j.first << " " << j.second / 100 << " " << (j.second % 100) / 10 << " " << (j.second % 100) % 10 << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome