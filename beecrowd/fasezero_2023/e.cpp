#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

set<long long int> vet;
set<long long int> vet2;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long int aux;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet.insert(aux);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        vet2.insert(aux);
    }


    map<long long int, long long int> mm;



    int x = 0;
    for (auto i : vet)
    {
        x++;
        if (x == 100)
        {
            break;
        }
        
        for (auto j : vet2)
        {
            if (i - j >= 1)
            {
                mm[i - j]++;
            }
            if (i + j <= (long long int)10e9) {
                mm[i + j]++;
            }
        }
    }



    int flag = 1;
    for (auto &j : mm)
    {
        //cout << j.first << " " << j.second << "\n";
        if (n > 99) {
            if (j.second == 99)
            {
                cout << j.first << '\n';
                flag = 0;
                break;
            }
        } else {
            if (j.second == n)
            {
                cout << j.first << '\n';
                flag = 0;
                break;
            }
        }
        
        
    }
    
    if (flag)
    {
        for (auto &j : mm)
        {
            cout << j.first << " " << j.second << "\n";
            if (n > 99) {
                if (j.second == 99)
                {
                    cout << j.first << '\n';
                    flag = 0;
                    break;
                }
            } else {
                if (j.second == vet.size())
                {
                    cout << j.first << '\n';
                }
            }
            
        }
    }
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome