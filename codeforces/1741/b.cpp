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
        int n;
        cin >> n;

        if (n == 3) {
            cout << "-1\n";
        } else if (n == 2) {
            cout << "2 1\n";
        } else {

            deque<int> q;

            for (int i = 1; i <= n; i++)
            {
                q.push_back(i);
            }

            q.push_front(q.back());
            q.pop_back();
            q.push_front(q.back());
            q.pop_back();
            int i = 1;
            for (auto el : q)
            {
                cout << (i == 1 ? "" : " ") << el;
                i = 2;
            }
            cout << '\n';

        }

    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome