#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    string vet[500];

    cin >> n;

    while (n+1)
    {
        n--;
        getline(cin, s);
        cout << s << '\n';
        int i = 0;
        int fim = 0;
        int ant = 0;
        for (int j = 0; j < s.length()+1; j++)
        {
            fim++;
            if (s[j] == ' ' or s[j] == '\0' or s[j] == '\n')
            {
                vet[i] = s.substr(ant, abs(fim - ant));
                i++;
                ant = fim;
            }
            
        }

        for (int x = 0; x < i; x++)
        {
            int max = 0;
            
            for (int j = x; j < i; j++)
            {
                /* code */
            }
            
        }
        

        for (int j = 0; j < i; j++)
        {
            cout << vet[j] << '\n';
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome