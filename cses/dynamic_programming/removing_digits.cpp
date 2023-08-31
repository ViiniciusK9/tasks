#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define INF 112345678
#define MAX 1123456


stringstream buffer;
int n;
string num;

int memo[MAX];

int solve(int numero)
{
    if (numero < 0)
    {
        return INF;
    }

    if (numero == 0)
    {
        return 0;
    }

    if (memo[numero] != -1) return memo[numero];

    int ans = INF;
    string teste;
    stringstream buffer1;

    buffer1.str("");
    buffer1 << numero;
    teste = buffer1.str();

    for (auto c : teste)
    {
        if (c < '1' || c > '9') continue;

        //DBG(c);
        int x = c - '0';
        //DBG(x);

        //cout << numero - x << '\n';
        ans = min(ans, solve(numero - x) + 1);
        
    }
    

    return memo[numero] = ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    cin >> n;
    cout << solve(n) << '\n';




    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome