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
        int x;
        cin >> x;

        bitset<32> b = x;

        bitset<32> n1;
        bitset<32> n2;

        for (int i = 0; i <= 29; i++)
        {
            if (b[i] == 0 && b[i+1] == 1) {
                n1[i] = 1;
                n2[i] = 1;
            } else if (b[i] == 0 && b[i+1] != 1) {
                n1[i] = 0;
                n2[i] = 0;
            } else if (b[i] == 1) {
                n1[i] = 1;
                n2[i] = 0;
            }
        }
        
        int in1= n1.to_ullong();
        int in2= n2.to_ullong();

        if ((in1+in2) / 2 == x) {
            cout << in1 << " " << in2 << '\n';
        } else {
            cout << "-1\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome