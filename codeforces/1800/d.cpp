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
        cin >> n;

        string s1;
        set<string> st;

        cin >> s1;

        string aux;
        int cont = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (i+2 < s1.size()) {
                if (s1[i] == s1[i+2]) cont++;
            }
        }

        cout << s1.size() -1 - cont << '\n';
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome