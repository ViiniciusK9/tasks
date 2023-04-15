#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num, aux, deuruim, qnt;

    while (cin >> n)
    {   
        stack<int> p;
        aux = 1;
        while (true)
        {
            qnt = 0;
            cin >> num;
            if (n == 0)
            {
                break;
            }
            qnt++;
            while (true)
            {

                if (p.empty())
                {
                    p.push(aux);
                }
                if (p.top() > num)
                {
                    break;
                }
                if (p.top() == num)
                {
                    p.pop();
                } else {
                    p.push(aux);
                    aux++;
                }
                if (qnt < n)
                {
                    cin >> num;
                    qnt++;
                } else {
                    break;
                }
                
            }
            
            
            
        }
        
        

        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome