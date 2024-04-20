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

    int t, n, m;

    string s[20];


    cin >> t;
    while (t--)
    {
        cin >> n >> m;  

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans == 0 && s[j][i] == 'v') {
                    ans = 1;
                    break;
                } 
                if (ans == 1 && s[j][i] == 'i') {
                    ans = 2;
                    break;
                } 
                if (ans == 2 && s[j][i] == 'k') {
                    ans = 3;
                    break;
                } 
                if (ans == 3 && s[j][i] == 'a') {
                    ans = 4;
                    break;
                } 
            }
            if (ans == 4) break;
            
        }

        if (ans == 4) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
        


    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome