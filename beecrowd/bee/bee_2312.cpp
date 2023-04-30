#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


bool comp(pair<int, pair<int, pair<int, string>>> a, pair<int, pair<int, pair<int, string>>> b) {
    if (a.first == b.first)
    {
        if (a.second.first == b.second.first)
        {
            if (a.second.second.first == b.second.second.first)
            {
                return a.second.second.second < b.second.second.second;
            }
            return a.second.second.first > b.second.second.first;
        }
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, o, p, b;
    string s;
    vector<pair<int, pair<int, pair<int, string>>>> vet;
    cin >> n;
    while (n--)
    {
        cin >> s >> o >> p >> b;
        vet.push_back({o, {p, {b, s}}});
    }
    sort(vet.begin(), vet.end(), comp);
    for (auto &j : vet)
    {
        cout << j.second.second.second << " " << j.first << " " << j.second.first << " " << j.second.second.first << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome