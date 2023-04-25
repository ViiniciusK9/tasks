#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

bool comparacao(pair<int , int> a, pair<int, int> b) {
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int firts = 0;
    while (cin >> s)
    {
        if (firts)
        {
           cout << '\n';
        }
        firts = 1;
        map<int, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        vector<pair<int, int>> vet;
        for (auto &j : m)
        {
            vet.push_back({j.second, j.first});
        }
        sort(vet.begin(), vet.end(), comparacao);

        for (auto &j : vet)
        {
            cout << j.second << " " << j.first << '\n';
        }
    
    }
    
    
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome