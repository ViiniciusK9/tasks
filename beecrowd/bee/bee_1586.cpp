#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef pair<int, int> ii;

int is_equal(vector<int> vet_i, int m) {
    long long a1 = 0, a2 = 0, aux = 1;
    for (int i = m; i >= 0; i--)
    {
        a1 += vet_i[i] * aux;
        aux++;
    }
    aux = 1;
    for (int i = m+1; i < vet_i.size(); i++)
    {
        a2 += vet_i[i] * aux;
        aux++;
    }
    //DBG(a1);
    //DBG(a2);
    if (a1 > a2)
    {
        return -1;
    } else if (a1 == a2) {
        return 0;
    } else {
        return 1;
    }
    
    
}

string bt(vector<int> vet_i, vector<string> vet, int source, int top){
    int m, r;
    top--;
    while (source <= top) {
        m = (source + top) / 2;
        //DBG(m);
        r = is_equal(vet_i, m);
        if (r == 0){
            return vet[m];
        } else if (r == 1){
            source = m + 1;
        } else {
            top = m - 1;
        }
    }
    return "Impossibilidade de empate.";
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }
        
        vector<string> vet;
        vector<int> vet_i;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            vet.push_back(s);
            int aux = 0;
            for (int j = 0; j < s.length(); j++)
            {
                aux += s[j];
            }
            vet_i.push_back(aux);
        }
        cout << bt(vet_i, vet, 0, n) << '\n';


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome