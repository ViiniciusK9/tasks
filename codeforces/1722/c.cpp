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
        int n;
        cin >> n;
        set<string> v1;
        set<string> v2;
        set<string> v3;

        for (int i = 0; i < n; i++)
        {
            string aux;
            cin >> aux;
            v1.insert(aux);
        }

        for (int i = 0; i < n; i++)
        {
            string aux;
            cin >> aux;
            v2.insert(aux);
        }

        for (int i = 0; i < n; i++)
        {
            string aux;
            cin >> aux;
            v3.insert(aux);
        }

        int p1 = 0, p2 = 0, p3 = 0;

        for (auto el : v1)
        {
            if (v2.find(el) != v2.end() && v3.find(el) != v3.end())  {
                continue;
            } else if (v2.find(el) != v2.end() && v3.find(el) == v3.end()) {
                p1++;
            } else if(v2.find(el) == v2.end() && v3.find(el) != v3.end()) {
                p1++;
            } else {
                p1+=3;
            }
        }

        for (auto el : v2)
        {
            if (v1.find(el) != v1.end() && v3.find(el) != v3.end())  {
                continue;
            } else if (v1.find(el) != v1.end() && v3.find(el) == v3.end()) {
                p2++;
            } else if(v1.find(el) == v1.end() && v3.find(el) != v3.end()) {
                p2++;
            } else {
                p2+=3;
            }
        }

        for (auto el : v3)
        {
            if (v2.find(el) != v2.end() && v1.find(el) != v1.end())  {
                continue;
            } else if (v2.find(el) != v2.end() && v1.find(el) == v1.end()) {
                p3++;
            } else if(v2.find(el) == v2.end() && v1.find(el) != v1.end()) {
                p3++;
            } else {
                p3+=3;
            }
        }

        
        

        cout << p1 << " " << p2 << " " << p3 << "\n";
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome