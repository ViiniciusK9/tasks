#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 2123
int n; 

vector<int> ag[MAX];




int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    // Kosaraju’s Algorithm
    int m, v, w, p;
    while (cin >> n >> m)
    {

        for (int i = 0; i < m; i++)
        {
            cin >> v >> w >> p;
            v--; w--;
            if (p == 2)
            {
                ag[v].push_back(w);
                ag[w].push_back(v);

            }else {
                ag[v].push_back(w);
            }
            

        }
        
        for (int i = 0; i < n; i++)
        {
            ag[i].clear();
        }
        
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome