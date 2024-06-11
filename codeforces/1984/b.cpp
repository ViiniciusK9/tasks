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
    ll n;
    while (t--)
    {   
        cin >> n;

        ll n1 = n/2;
        ll n2 = n/2;

        if (n%2 != 0) {
            n2++;
        }

        string s1 = to_string(n1);
        string s2 = to_string(n2);
        //DBG(s1);
        //DBG(s2);
        int ajuda = 0;
        int deuruim = 0;
        if (s1.size() == s2.size()) {
            for (int i = 0; i < s1.size(); i++)
            {
                //DBG(i);
                //DBG(s1[i]);
                if (s1[i] == '5' && s2[i] == '5') {
                    ajuda = 0;
                } else if (s1[i] >= '5' && s2[i] >= '5') {
                    ajuda = 1;
                } else {
                    int v1 = s1[i] - '0';
                    int v2 = s2[i] - '0';
                    //DBG(s1[i]);
                    //DBG(s2[i]);
                    //DBG(v1);
                    //DBG(v2);

                    //DBG(ajuda);

                    if (v1 + v2 == 0) {
                        if (ajuda == 1) {
                            ajuda = 0;
                        } else {
                            deuruim = 1;
                            break;
                        }
                    } else if (v1 + v2 <= 8) {
                        if (ajuda == 1) {
                            ajuda = 1;
                        } else {
                            deuruim = 1;
                            break;
                        }
                    } else if (v1 + v2 == 9){
                        deuruim = 1;
                        break;
                    } else if (v1 + v2 == 10) {
                        ajuda = 0;
                    } else {
                        ajuda = 1;
                    }
                }
            }
            if (deuruim == 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else  {
            cout << "NO\n";
        }
        
        

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome