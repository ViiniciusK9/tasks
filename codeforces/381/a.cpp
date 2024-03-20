#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, aux, a1 = 0, a2 = 0;
    cin >> n;
    deque<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }

    
    for (int i = 0; i < n; i++)
    {
        if(i % 2 == 0){
            if (v.back() > v.front())
            {
                a1 += v.back();
                v.pop_back();
            } else {
                a1 += v.front();
                v.pop_front();
            }
            
        } else {
            if (v.back() > v.front())
            {
                a2 += v.back();
                v.pop_back();
            } else {
                a2 += v.front();
                v.pop_front();
            }
        }
    }
    
    cout << a1 << " " << a2 << '\n';
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome