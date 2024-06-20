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

int stoint(string sn) {
    int ans = 0;
    int c = 1;
    for (int i = sn.size()-1; i >= 0; i--)
    {
        ans += (sn[i] - '0') * c;
        c = c * 10;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    string s1;
    string p1, p2, p3;
    int f1, f2, op, n1, n2;
    while (cin >> s1)
    {
        f1 = 0;
        f2 = 0;
        op = 0;
        p1.clear();
        p2.clear();
        p3.clear();
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == 'R') op = 1;
            if (s1[i] == 'L') op = 2;
            if (s1[i] == 'J') op = 3;

            if (f1 == 0) {
                if (s1[i] == '+') {
                    f1 = 1;
                } else {
                    p1.pb(s1[i]);
                }
            } else if (f2 == 0) {
                if (s1[i] == '=') {
                    f2 = 1;
                } else {
                    p2.pb(s1[i]);
                }
            } else {
                p3.pb(s1[i]);
            }
        }

        if (op == 1) {
            n1 = stoint(p2);
            n2 = stoint(p3);
            cout << n2 - n1 << '\n';
        } else if (op == 2) {
            n1 = stoint(p1);
            n2 = stoint(p3);
            cout << n2 - n1 << '\n';
        } else {
            n1 = stoint(p1);
            n2 = stoint(p2);
            cout << n1 + n2 << '\n';
        }

        //DBG(p1);
        //DBG(p2);
        //DBG(p3);
        //DBG(op);
        
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome