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
        string s1, s2;

        cin >> s1 >>s2;

        map<char, int> ma1;
        map<char, int> ma2;

        for (int i = 0; i < s1.size(); i++)
        {
            ma1[s1[i]]++;
        }

        for (int i = 0; i < s2.size(); i++)
        {
            ma2[s2[i]]++;
        }

        int qx1 = 0;
        int qx2 = 0;
        char ch1;
        char ch2;
        for (auto el : ma1)
        {
            if (el.first == 'X') {
                qx1 = el.second;
            } else {
                ch1 = el.first;
            }
        }

        for (auto el : ma2)
        {
            if (el.first == 'X') {
                qx2 = el.second;
            } else {
                ch2 = el.first;
            }
        }

        if (ch1 > ch2) {
            cout << "<\n";
        } else if (ch1 == ch2) {
            if (qx1 == qx2) {
                cout << "=\n";
            } else if (ch1 == 'S'){
                if (qx1 > qx2) {
                    cout << "<\n";
                } else {
                    cout << ">\n";
                }
            } else {
                if (qx1 > qx2) {
                    cout << ">\n";
                } else {
                    cout << "<\n";
                }
            }
        } else {
            cout << ">\n";
        }
        
        
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome