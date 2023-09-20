#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int n, s, k;
int candies[60];
int eat[60];
string color;
int memo[60][2600];

int dp (int i, int quant_candies, char ult_color, int tot_candies, int qnt)
{
    DBG(i);
    DBG(quant_candies);
    DBG(ult_color);
    DBG(tot_candies);
    if (qnt == n) return 0;
    if (i < 0 || i >= n) return INT_MAX;
    if (tot_candies >= k) return 0;

    if (memo[i][tot_candies] != -1) return memo[i][tot_candies];
    /*
        caso existe estou na caixa i a caixa comida anteriormente é uma cor diferente 
        da caixa i e possuia menos doces que a caixa i e se eu comer os doces da caixa
        i eu completo o minimo de doces que eu preciso comer
    */

    int ans = 0;
    if (eat[i] == -1 && ult_color != color[i] && quant_candies < candies[i] && tot_candies + candies[i] >= k)
    {
        eat[i] = 1;
        qnt++;
        ans++;

    } else
    {
        int aux;
        // ans = o minimo entre comer o atual ou ir para a direita ou ir para a esquerda
        if (eat[i] == -1 && ult_color != color[i] && quant_candies < candies[i]) 
        {
            eat[i] = 1;
            aux = dp(i, candies[i], color[i], tot_candies + candies[i], qnt+1);
        }
        
        ans = min({aux, dp(i - 1, quant_candies, ult_color, tot_candies, qnt) + 1, dp(i + 1, quant_candies, ult_color, tot_candies, qnt) + 1 });
        //eat[i] = -1;
    }

    return memo[i][tot_candies] = ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> k;
    int aux = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> candies[i];
        aux += candies[i];
    }


    memset(eat, -1, sizeof(eat));
    memset(memo, -1, sizeof(memo));
    cin >> color;
    if ( aux < k)
    {
        cout << "-1\n";
    } else 
    {
        cout << dp (s-1, 0, 'N', 0, 0) << '\n';
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome