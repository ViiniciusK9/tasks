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

    int d;
    cin >> d;

    for (int a = 1; a <= 100; a++)
    {
        for (int b = 1; b <= 100; b++)
        {
            for (int c = 1; c <= 100; c++)
            {
                if (a == b || b == c || a == c) continue;

                if (
                a + b + c != d && 
                a + b - c != d &&
                a - b - c != d &&
                a - b + c != d &&

                (a + b) / c != d &&
                (a - b) / c != d &&
                (a / b) / c != d &&
                (a * b) / c != d &&
                (a + b) * c != d &&
                (a - b) * c != d &&
                (a / b) * c != d &&
                (a * b) * c != d &&

                a + (b / c) != d &&
                a - (b / c) != d &&
                
                a * (b / c) != d &&
                a + (b * c) != d &&
                a - (b * c) != d &&
                a / (b * c) != d &&
                a * (b * c) != d &&

                (a / b) + c != d &&
                (a / b) - c != d &&
                (a / b) / c != d &&
                (a / b) * c != d &&
                (a * b) + c != d &&
                (a * b) - c != d &&
                (a * b) / c != d &&
                (a * b) * c != d &&

                a / (b + c) != d &&
                a / (b * c) != d &&
                a / (b * c) != d &&
                a * (b + c) != d &&
                a * (b - c) != d &&
                a * (b / c) != d &&
                a * (b * c) != d 
                
                )
                {


                    cout << a << " " << b << " " << c << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome