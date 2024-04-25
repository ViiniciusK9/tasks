#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define FF(x) std::fixed <<std::setprecision(1)<<(x)
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const int MAX = 100015;
int visited[MAX];
vi ng[MAX];
int n;

double dist(pii a1, pii a2) {
    return sqrt( (a1.F-a2.F)*(a1.F-a2.F) + (a1.S.F-a2.S.F)*(a1.S.F-a2.S.F));
} 

void bfs(int startNode, int it)
{
    // Create a queue for BFS
    queue<int> q;
 
    // Mark the current node as visited and enqueue it
    visited[startNode] = it;
    q.push(startNode);
 
    // Iterate over the queue
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        //cout << currentNode << " ";
 
        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int neighbor : ng[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = it;
                q.push(neighbor);
            }
        }
    }
}

int total_visited() {
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0) {
            return i;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, xi, yi;
    double d;
    vector<pii> vpi;
    vector<pii> vpi2;

    cin >> n >> q >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> xi >> yi;
        vpi.PB({xi, {yi, i}});
        vpi2.PB({xi, {yi, i}});
    }

    sort(vpi.begin(), vpi.end());


    memset(visited, 0, sizeof(visited));

    int iiii = 1;
    bfs(0, iiii);
    int i_a;

    while (1)
    {
        i_a = total_visited();
        if (i_a == 0) break;
        iiii++;
        bfs(i_a, iiii);
    }

    
    for (int i = 0; i < q; i++)
    {
        cin >> xi >> yi;
        xi--;
        yi--;
        if (visited[xi] == visited[yi]) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
        
    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome