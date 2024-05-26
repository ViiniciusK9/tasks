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

    int a, b, c;

    cin >> a >> b >> c;

    set<int> s1;
    s1.insert(a);
    s1.insert(b);
    s1.insert(c);
    
    for (int i = 0; i <= 3; i++)
    {
        if (s1.find(i) == s1.end()) {
            cout << i << '\n';
            break;
        }
    }
    

    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome