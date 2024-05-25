#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

string mat[101][101];

int vaildVect(int x, map<string, int> valid, vector<string> vet)
{
    bool hasX;
    set<string> matches;
    bool isInValid;
    int y = 0

    sort(vet.begin(), vet.end());
    for(auto &x:vet){
        
    }




}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, c;
    cin >> l >> c;
    int vl[l];
    int vc[c];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
        cin >> vl[i];
    }
    for (int j = 0; j < c; j++)
    {
        cin >> vc[j];
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome