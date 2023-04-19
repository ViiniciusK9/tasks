#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num, qnt;

    while (cin >> n)
    {   
        while (true)
        {
            stack<int> p;
            qnt = 0;
            cin >> num;
            if (num == 0)
            {
                break;
            }
            int aux = 1;
            p.push(aux);
            aux++;
            while (qnt < n and aux <= n)
            {
                if (!p.empty())
                {
                    if (p.top() == num)
                    {
                        p.pop();
                        cin >> num;
                        qnt++;
                    } else {
                        p.push(aux);
                        aux++;
                    }
                    
                } else {
                    p.push(aux);
                    aux++;
                }        
            }
            if (qnt < n)
            {
                /* code */
            }
            
            if (p.empty())
            {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            
        }
        
        

        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome