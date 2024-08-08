#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
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
        int a1, a2, b1, b2;
        set<int> a;
        set<int> b;
        cin >> a1 >> a2 >> b1 >> b2;
        a.insert(a1);
        a.insert(a2);
        b.insert(b1);
        b.insert(b2);


        if (min(a1, a2) > max(b1, b2))
        {
            cout << "4\n";
        }
        else if (max(a1, a2) <= min(b1, b2))
        {
            cout << "0\n";
        }
        else if (a1 == b1) 
        {
            if (a2 <= b2) {
                cout << "0\n";
            } else {
                cout << "2\n";
            }   
        }
        else if (a1 == b2) 
        {
            if (a2 <= b1) {
                cout << "0\n";
            } else {
                cout << "2\n";
            }   
        }
        else if (a2 == b1) 
        {
            if (a1 <= b2) {
                cout << "0\n";
            } else {
                cout << "2\n";
            }   
        }
        else if (a2 == b2) 
        {
            if (a1 <= b1) {
                cout << "0\n";
            } else {
                cout << "2\n";
            }   
        } else {
            cout << "2\n";
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome