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

    int n, aux;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.pb(aux);
    }
    int fir = v[0];
    int ind = 1;
    for (int i = 1; i < v.size(); i++)
    {   
        if (v[i] > fir) {
            ind = i+1;
            break;
        }
    }

    if (ind != 1) {
        cout << ind << '\n';
    } else {
        cout << "-1\n";
    }
    
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome