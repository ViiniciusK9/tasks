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

ll combinacao(ll n) {
    return n * (n - 1) * (n - 2) / 6;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> topicos, dificuldades;
    map<ii, int> par;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        topicos[x]++;
        dificuldades[y]++;
        par[mp(x, y)]++;
    }

    // Todas as combinações possíveis
    ll total = combinacao(n);

    // Subtrair combinações inválidas
    for (auto &it : topicos) {
        if (it.s >= 3) {
            total -= combinacao(it.s);
        }
    }

    for (auto &it : dificuldades) {
        if (it.s >= 3) {
            total -= combinacao(it.s);
        }
    }

    // Adicionar interseção (que foi subtraída duas vezes)
    for (auto &it : par) {
        if (it.s >= 3) {
            total += combinacao(it.s);
        }
    }

    cout << total << endl;

    return 0;
}
