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

    int e, v;

    cin >> e >> v;

    int h = 19;
    int m = 0;

    int e1 = e / v;
    e1 += h;
    e1 = e1 % 24;
    int m1 = e % v;
    m1 = m1 * 60;
    m1 = m1 / v;
    cout << (e1 < 10 ? "0" : "") << e1 << ":" << (m1 < 10 ? "0" : "") << m1 << '\n';


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome