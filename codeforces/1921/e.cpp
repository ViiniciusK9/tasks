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
        int h, w, xa, ya, xb, yb;

        cin >> h >> w >> xa >> ya >> xb >> yb;

        if (xa >= xb) {
            cout << "Draw\n";
            continue;
        }

        if (abs(xa - xb) % 2 == 1)
        {
            if (abs(ya - yb) <= 1 && abs(xa - xb) >= 1)
            {
                cout << "Alice\n";
            }
            else
            {
                if (ya <= yb) {

                    if (abs(yb - w) + abs(ya - yb) <= abs(xa - xb)) {
                        cout << "Alice\n";
                    } else {
                        cout << "Draw\n";
                    }

                } else {
                    if (abs(yb) + abs(ya - yb) <= abs(xa - xb)) {
                        cout << "Alice\n";
                    } else {
                        cout << "Draw\n";
                    }
                }
            }
        }
        else
        {
            if (abs(ya - yb) <= 1 && abs(xa - xb) >= 1)
            {
                cout << "Bob\n";
            }
            else 
            {
                if (yb < ya) {

                    if (abs(ya - w) + abs(ya - yb) <= abs(xa - xb)) {
                        cout << "Bob\n";
                    } else {
                        cout << "Draw\n";
                    }

                } else {
                    if (abs(ya) + abs(ya - yb) <= abs(xa - xb)) {
                        cout << "Bob\n";
                    } else {
                        cout << "Draw\n";
                    }
                }
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome