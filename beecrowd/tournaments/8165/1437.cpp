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

    int n;
    string s1;

    map<int, char> ma;

    ma[0] = 'N';
    ma[1] = 'L';
    ma[2] = 'S';
    ma[3] = 'O';
    

    while (cin >> n)
    {
        if (n == 0) {
            break;
        }

        cin >> s1;
        int ans = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == 'D') {
                ans++;
                if (ans == 4) {
                    ans = 0;
                }
            } else {
                ans--;
                if (ans == -1) {
                    ans = 3;
                }
            }
        }
        cout << ma[ans] << '\n';
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome