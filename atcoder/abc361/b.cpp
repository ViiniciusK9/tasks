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

    int a1, a2, b1, b2, c1, c2, d1, d2, e1, e2, f1, f2;

    cin >> a1 >> b1 >> c1 >> d1 >> e1 >> f1;
    cin >> a2 >> b2 >> c2 >> d2 >> e2 >> f2;

    int l1, l2, l3;

    l1 = abs(a1 - d1);
    l2 = abs(b1 - e1);
    l3 = abs(c1 - f1);

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome