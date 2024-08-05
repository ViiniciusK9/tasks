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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    int n, m;
    while (t--)
    {
        vi v;
        cin >> n >> m;
        int aux;
        map<int, int> ma;
        priority_queue<int> pq;
        ll qz = 0;
        ll qd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            string s1 = to_string(aux);
            qd+= int(s1.size());
            //bitset<32> a = aux;
            //DBG(a);

            int qnt = 0;
            int start = 10;
            while (aux % start == 0)
            {
                qnt++;
                start *=10;
            }
            if (qnt >= 1) {
                pq.push(qnt);
                qz+=qnt;
            }
            ma[qnt]++;
        }

        for (auto el : ma)
        {
            //cout << el.first << " : " << el.second << '\n';
        }

        ll sm = 0;
        bool ana = true;
        while (!pq.empty())
        {
            //cout << pq.top() << ' ';
            int cur = pq.top();

            if (!ana) {
                sm+=cur;
            }
            ana=!ana;
            pq.pop();
        }

        //DBG(sm);
        //DBG(qd);
        //DBG(qz);
        if (sm + qd - qz > m) {
            cout << "Sasha\n";
        } else {
            cout << "Anna\n";
        }


    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome