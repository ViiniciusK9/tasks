#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

typedef long long ll;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;
    vector<int> vet;
    cin >> t;
    while (t--)
    {
        vet.clear();
        cin >> s;
        int cont = 0;
        int c = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B') 
            {
                if (c != 0)
                {
                    vet.push_back(c);
                    c = 0;
                }
                cont++;
            } else
            {
                c++;
            }
        }
        if (c != 0)
        {
            vet.push_back(c);
            c = 0;
        }

        sort(vet.begin(), vet.end());
        if (!vet.empty() && cont != 0)
        {
            int j = vet.size()-1;
            int ans = 0;
            while (cont-- && j >= 0)
            {
                ans += vet[j];
                j--;
            }
            cout << ans << '\n';
        } 
        else
        {
            cout << "0\n";
        }
        
    }
    
    

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome