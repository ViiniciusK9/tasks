#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s1, s2;
    int n;

    cin >> t;

    while (t--)
    {
        cin >> s1 >> s2;

        for (int i = s1.length()-1; i > 0 ; i--)
        {
            int n2 = s2[i] - '0';
            int n1 = s1[i] - '0';
            int n3 = s1[i-1] - '0';
            if ((n2 * ((n3 * 10) + n1)) < (n1 * ((n3 * 10) + n2))) {
                swap(s2[i], s1[i]);
                i--;
            }
        }
        cout << s1 << '\n';
        cout << s2 << '\n';


    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome