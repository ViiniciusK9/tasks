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

    int t, n, m;

    cin >> t;
     
    while (t--)
    {
        cin >> n >> m;

        bitset<35> ai(n);
        
        int aux = n-1;

        while (m--)
        {
            if (aux <= 0) {
                break;
            }
            bitset<35> ax(aux);

            ai |= ax;
            aux--;
            
        }

        int at = (int)ai.to_ullong();

        cout << at << '\n';

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome