#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

bool comparacao(const pair<int, pair<int, pair<int, string>>> j, const pair<int, pair<int, pair<int, string>>> i) {
    if (j.first != i.first)
    {
        return j.first > i.first;
    } else {
        if (j.second.first != i.second.first)
        {
            return j.second.first > i.second.first;
        } else {
            if (j.second.second.first != i.second.second.first)
            {
                return j.second.second.first > i.second.second.first;
            } else {
                return j.second.second.second < i.second.second.second;
            }
        }
    }
    return j.first < i.first;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string des, ouro, prata, bronze;

    map<string, pair<int, pair<int, int>>> medalhas;

    vector<pair<int, pair<int, pair<int, string>>>> vet;

    while (getline(cin, des))
    {
        getline(cin, ouro);
        getline(cin, prata);
        getline(cin, bronze);

        medalhas[ouro].first++;
        medalhas[prata].second.first++;
        medalhas[bronze].second.second++;
    }
    
    for (const auto &j : medalhas)
    {
        vet.push_back(make_pair(j.second.first, make_pair(j.second.second.first, make_pair(j.second.second.second, j.first))));
    }
    
    sort(vet.begin(), vet.end(), comparacao);

    cout << "Quadro de Medalhas\n";
    for (const auto &j : vet)
    {
        cout << j.second.second.second << " " << j.first << " " << j.second.first << " " << j.second.second.first << '\n';
    }
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome