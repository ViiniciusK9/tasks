#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


bool comp(pair<string, pair<string, string>> a, pair<string, pair<string, string>> b) {
    if (a.first == "branco" && b.first == "vermelho")
    {
        return true;
    } else if (a.first == "vermelho" && b.first == "branco") {
        return false;
    } else if (a.first == b.first) {
        if (a.second.first == "P" && (b.second.first == "M" || b.second.first == "G"))
        {
            return true;
        } else if (a.second.first == "M" && b.second.first == "G") {
            return true;
        } else if (a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        } else {
            return false;
        }
    }
    return true;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    string n, c, t;
    int x, first = 1;
    while (cin >> x && x != 0)
    {
        vector<pair<string, pair<string, string>>> vet;
        getline(cin, n);
        while (x--)
        {
            // GETLINE TA BUGADO '-'
            getline(cin, n);
            cin >> c >> t;
            //cout << n << '\n';
            vet.push_back({c, {t, n}});
            getline(cin, n);
        }
        

        cout << ((first == 1) ? "" : "\n");
        first = 0;

        sort(vet.begin(), vet.end(), comp);
        for (auto &j : vet)
        {
            cout << j.first << " " << j.second.first << " " << j.second.second << '\n';
        }
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome