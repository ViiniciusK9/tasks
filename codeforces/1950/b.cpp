#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i%2 == 0) {
                    if (j%2 == 0) {
                        cout << "##";
                    } else {
                        cout << "..";
                    }
                } else {
                    if (j%2 != 0) {
                        cout << "##";
                    } else {
                        cout << "..";
                    }
                }
            }
            cout << '\n';
            for (int j = 0; j < n; j++)
            {
                if(i%2 == 0) {
                    if (j%2 == 0) {
                        cout << "##";
                    } else {
                        cout << "..";
                    }
                } else {
                    if (j%2 != 0) {
                        cout << "##";
                    } else {
                        cout << "..";
                    }
                }
            }
            cout << '\n';
            
        }
        
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome