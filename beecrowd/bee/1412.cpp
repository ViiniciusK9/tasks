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
    string s;
    while (cin >> s)
    {
        if (s[0] == '*') break;
        int ant = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int ah = s[i] - 'a';
            int h = 26 - (s[i] - 'a');
            int ahh = ah;
            int hh = h;

            if (ant < 0) {
                if (ah + ant < 0) {
                    ah = 0;
                } else {
                    ah = ah + ant;
                }
            } else {
                if (h - ant < 0) {
                    h = 0;
                } else {
                    h = h - ant;
                }
            }

            //DBG(h);
            //DBG(ah); 
            //DBG(hh);
            //DBG(ahh);

            if (ahh <= min({h, hh, ah})) {
                ans += min({h, ah, hh, ahh});
                ant = min({h, ah, hh, ahh});
            } else if (hh <= min({h, ah, ahh})) {
                ans += min({h, ah, hh, ahh});
                ant = min({h, ah, hh, ahh});
            }else if (ah <= min({h, hh, ahh})) {

                ans += min({h, ah, hh, ahh});
                //ant = -min({h, ah, hh, ahh});
                if (ahh + ant < 0) {
                    ant = -ahh;
                } else {
                    ant = -min({h, ah, hh, ahh});
                }
            } else if (h <= min({ah, hh, ahh})) {
                ans += min({h, ah, hh, ahh});
                //ant = min({h, ah, hh, ahh});
                if (hh - ant < 0) {
                    ant = hh;
                } else {
                    ant = min({h, ah, hh, ahh});
                }
            }
            //DBG(ant);
        }
        cout << ans << '\n';
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome