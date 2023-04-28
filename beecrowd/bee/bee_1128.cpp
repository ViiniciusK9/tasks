#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

#define MAX 2123

typedef pair<int, int> ii;

int n; 

vector<int> ag[MAX];
vector<int> i_ag[MAX];
vector<int> pai;
vector<int> marcado;

void dfs(int v, int pass) {
    pai[v] = -1;
    marcado[v] = 1;
    stack<int> s;
    s.push(v);
    while (!s.empty())
    {
        int w = s.top();
        s.pop();
        //DBG(w);
        for (int j : ag[w])
        {
            //DBG(j);
            if (marcado[j] == 0)
            {
                pai[j] = w;
                marcado[j] = 1;
                s.push(j); 
            }
        }
    }
    /*
    for (auto &j : marcado)
    {
        DBG(j);
    }
    */
}

void dfs_i(int v, int pass) {
    pai[v] = -1;
    marcado[v] = 1;
    stack<int> s;
    s.push(v);
    while (!s.empty())
    {
        int w = s.top();
        s.pop();
        for (int j : i_ag[w])
        {
            if (marcado[j] == 0)
            {
                pai[j] = w;
                marcado[j] = 1;
                s.push(j); 
            }
        }
        //cout << "\n";
    }
    
}

int is_str_con() {
    priority_queue<ii, vector<ii>, less<ii>> h;
    pai.clear();
    marcado.clear();
    for (int i = 0; i < n; i++)
    {
        pai.push_back(0);
        marcado.push_back(0);
    }
    
    int tam = 1;

    for (int i = 0; i < n; i++)
    {
        //DBG(tam);
        //cout << "\n";
        if (marcado[i] == 0)
        {
            dfs(i, 1);
            h.push(ii(tam, i));
            tam++;
        }
        if (tam == 3)
        {
            //cout << "CASO1\n";
            return 0;
        }
    }
    pai.clear();
    marcado.clear();
    
    for (int i = 0; i < n; i++)
    {
        pai.push_back(0);
        marcado.push_back(0);
    }

    dfs_i(h.top().second, 0);
    
    for (int i = 0; i < n; i++)
    {
        if (marcado[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    // Kosaraju’s Algorithm
    int m, v, w, p;
    while (cin >> n >> m && n != 0 && m != 0)
    {

        for (int i = 0; i < m; i++)
        {
            cin >> v >> w >> p;
            v--; w--;
            if (p == 2)
            {
                ag[v].push_back(w);
                ag[w].push_back(v);
                i_ag[v].push_back(w);
                i_ag[w].push_back(v);

            }else {
                ag[v].push_back(w);
                i_ag[w].push_back(v);
            }
            

        }
        /*
        cout << "ag\n";
        for (int i = 0; i < n; i++)
        {
            cout << i << " :";
            for (int j : ag[i])
            {
                cout << " " << j;
            }
            cout << '\n';
        }
        
        cout << "i_ag\n";
        for (int i = 0; i < n; i++)
        {
            cout << i << " :";
            for (int j : i_ag[i])
            {
                cout << " " << j;
            }
            cout << '\n';
        }
        */

        cout << is_str_con() << '\n';
        
        for (int i = 0; i < n; i++)
        {
            ag[i].clear();
            i_ag[i].clear();
        }
        
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome