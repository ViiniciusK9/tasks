#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    vector<pair<int, int>> vet;
    int n, aux;
    cin >> n;
    int cn = n;

    while (n--)
    {
        cin >> aux;
        int achou = 0;
        
        
        for (int i = 0; i < vet.size(); i++)
        {
            if (vet[i].first == aux)
            {
                vet[i].second++;
                achou = 1;
                break;
            }
            
        }
        if (!achou)
        {
            pair<int, int> tmp;
            tmp.first = aux;
            tmp.second = 1;
            vet.push_back(tmp);
        }  
        
    }
    sort(vet.begin(), vet.end()); 
    for (int i = 0; i < vet.size(); i++)
    {
        cout << vet[i].first << " aparece " << vet[i].second <<" vez(es)\n";
    }
    

    return 0;
}

// g++ -o nome.cpp nome.exe