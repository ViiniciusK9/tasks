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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;


    string s1;
    string aux;
    while (t--)
    {
        aux.clear();
        cin >> s1;

        if (s1.size() == 2) {
            cout << s1 << '\n';
            continue;
        }

        for (int i = 0; i < s1.size(); i++)
        {
            if (i % 2 == 0) {
                aux.push_back(s1[i]);
            }

            if (i == s1.size()-1) {
                aux.push_back(s1[i]);
            }
        }

        cout << aux << '\n';
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome