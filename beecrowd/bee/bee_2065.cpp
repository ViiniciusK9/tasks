#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 11234

typedef pair<int, int> ii;
typedef pair<int, ii> iii;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<int> c_queue;

    int n, m, aux;
    priority_queue<ii, vector<ii>, greater<ii>> f_heap;
    priority_queue<iii, vector<iii>, greater<iii>> t_heap;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        f_heap.push(ii(i, aux));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        c_queue.push(aux);
    }
    int t = 0;
    while (true)
    {
        while (!f_heap.empty() && !c_queue.empty())
        {
            t_heap.push(iii(t + f_heap.top().second * c_queue.front(), ii(f_heap.top())));
            f_heap.pop();
            c_queue.pop();
        }
        t = t_heap.top().first;
        f_heap.push(t_heap.top().second);
        t_heap.pop();
        if (c_queue.empty() && t_heap.empty())
        {
            break;
        }
    }
    cout << t << '\n';

    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome


// HEAP PARA FUNCIONARIO LIVRE COM SEU IDENTIFICADOR

