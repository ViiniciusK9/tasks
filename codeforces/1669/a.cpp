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

    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 1399) {
            cout << "Division 4\n";
        } else if (n <= 1599) {
            cout << "Division 3\n";
        } else if (n <= 1899) {
            cout << "Division 2\n";
        } else {
            cout << "Division 1\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome