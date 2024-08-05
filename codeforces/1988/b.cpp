#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        string s1;
        cin >> n;
        cin >> s1;
        string aux;
        int ant = -1;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '0' && ant != 0) {
                aux.pb('0');
                ant = 0;
            } else if (s1[i] == '1') {
                aux.pb('1');
                ant = 1;
            }
        }

        int z, u;
        z = u = 0;
        for (int i = 0; i < aux.size(); i++)
        {
            if (aux[i] == '0') {
                z++;
            } else {
                u++;
            }
        }
        
        if (z >= u) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome