#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> hall;
    map<string, int> hall_f;
    string a, v;
    while (cin >> a)
    {
        cin >> v;
        hall[a]++;
        hall_f[v]++;

    }
    cout << "HALL OF MURDERERS\n";
    int resp = 0;
    for (auto &j : hall) {

        if (!(hall_f.find(j.first) != hall_f.end())) {
            cout << j.first << " " << j.second << '\n';
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome