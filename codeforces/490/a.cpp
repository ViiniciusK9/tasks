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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int aux;
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;

    for (int i = 1; i <= n; i++)
    {
        cin >> aux;

        if (aux == 1) {
            q1.push(i);
        }

        if (aux == 2) {
            q2.push(i);
        }

        if (aux == 3) {
            q3.push(i);
        }

    }
    
    int qnt = min({q1.size(), q2.size(), q3.size()});

    cout << qnt << '\n';

    while (qnt--)
    {
        cout << q1.front() << " " << q2.front() << " " << q3.front() << '\n';
        q1.pop();
        q2.pop();
        q3.pop();
    }
    


    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome