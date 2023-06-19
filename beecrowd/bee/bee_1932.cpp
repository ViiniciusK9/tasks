#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
typedef long long int ll;


int vet[212345];
//int memo[212345][2];
int memo[212345];
int n, c;


/*

ll dp(int i, int w, int price){
    ll ans = 0;
    if (i == n)
    {
        cout << "aqui\n";
        return 0;
    }

    if (memo[i][w] != -1)
    {
        return memo[i][w];
    }

    if (i == n-1)
    {
        if (w == 1)
        {
            // vender
            return vet[i] - price;
        } else {
            // só voltar
            return 0;
        }
    }
        

    if (w == 1)
    {
        // continuar ou vender
        ans = max(dp(i+1, w, price), dp(i+1, 0, 0) + vet[i] - price);
    } else {
        // continuar ou comprar
        ans = max(dp(i+1, w, price), dp(i+1, 1, vet[i]) - c);
    }
    

    return memo[i][w] = ans;
}

*/

ll dp_lin(){
    memo[0] = 0;

    for (int i = 1; i < n; i++)
    {
        memo[i] = memo[i-1];
        for (int j = i-1; j < i; j++)
        {
            memo[i] = max(memo[i], vet[i] - vet[j] - c + memo[j]);
        }
        
    }

    return memo[n-1];
}




int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    //memset(memo, -1, sizeof(memo));
    cout << dp_lin() << "\n";

    /*
    for (int i = 0; i < n; i++)
    {
        cout << memo[i][0] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << memo[i][1] << " ";
    }
    cout << "\n";
    */
    for (int i = 0; i < n; i++)
    {
        cout << memo[i] << " ";
    }
    cout << "\n";
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome