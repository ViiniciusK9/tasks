#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(4)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    getline(cin, s);
    getline(cin, s);
    map<string, int> mapp;
    int qnt = 0;
    while (true)
    {
        if (!getline(cin, s)) {

            for (auto &j : mapp)
            {
                cout << j.first << " " << F( (double)(100 * j.second) / qnt) << '\n';
            }
            
            mapp.clear();
            qnt = 0;

            break;
        }
        if (s.size() == 0)
        {
            for (auto &j : mapp)
            {
                cout << j.first << " " << F( (double)(100 * j.second) / qnt) << '\n';
            }
            cout << "\n";
            mapp.clear();
            qnt = 0;
            continue;
        }
        mapp[s]++;
        qnt++;
        //cout << s << '\n';
    }
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome