#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int t, n, k, aux;
    deque<int> dq;

    cin >> t;

    while (t--)
    {
        dq.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            dq.push_back(aux);
        }

        long long int frente = k/2;
        long long int costa = k/2;
        if (k%2 != 0) frente++;
        while (frente != 0)
        {
            if (!dq.empty() && dq.front() <= frente) {
                frente -= dq.front();
                dq.pop_front();
            } else {
                break;
            }
        }

        while (costa != 0)
        {
            if (!dq.empty() && dq.back() <= costa) {
                costa -= dq.back();
                dq.pop_back();
            } else {
                break;
            }
        }

        frente = frente + costa;

        if (dq.size() == 1 && dq.front() <= frente) {
            dq.pop_back();
        }
        
        cout << n - dq.size() << '\n';
    }

        

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome