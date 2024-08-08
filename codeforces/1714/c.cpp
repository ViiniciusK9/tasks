#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define se second 
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
        int s;
        cin >> s;
        vi aux;

        if (s <= 9) {
            cout << s << '\n';
        } else {
            int at = 9;
            while (s > at)
            {
                aux.push_back(at);
                s-=at;
                at--;
            }
            if (s > 0) {
                aux.push_back(s);
            }
            
            reverse(aux.begin(), aux.end());

            for (auto el : aux)
            {
                cout << el;
            }
            cout << '\n';
            
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome