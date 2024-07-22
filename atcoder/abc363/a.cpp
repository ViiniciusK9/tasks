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

    int r;

    cin >> r;

    if (r <= 99)
    {
        cout << abs(r - 99) + 1 << '\n';
    }
    else if (r <= 199)
    {
        cout << abs(r - 199) + 1<< '\n';
    }
    else if (r <= 299)
    {
        cout << abs(r - 299) + 1 << '\n';
    }
    else
    {
        cout << abs(r - 399) + 1 << '\n';
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome