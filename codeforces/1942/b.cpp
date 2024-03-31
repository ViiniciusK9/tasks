#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> s;
    int t, n, aux, ans, next_min, min;
    cin >> t;
    while (t--)
    {
        cin >> n;

        if (n == 1) {
            cout << "0\n";
        } else {
            s.clear();
            min = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> aux;
                
                int it = 1;
                while (s.find(min+it) != s.end())
                {
                    it++;
                }
                next_min = min+it;

                if (next_min - min == aux){
                    if (i == n-1) {
                        cout << min; 
                    } else {
                        cout << min << " ";
                    }
                    s.insert(min);
                    min = next_min;
                } else {
                    ans = min - aux;
                    if (i == n-1) {
                        cout << ans;
                    } else {
                        cout << ans << " ";
                    }
                    s.insert(ans);
                }
                
            }
            cout << "\n";
            

        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome