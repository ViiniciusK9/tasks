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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int d1, d2, d3, d4, d5, d6;
    while (n--)
    {
        cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6;
        set<int> st;
        st.insert(d1);
        st.insert(d2);
        st.insert(d3);
        st.insert(d4);
        st.insert(d5);
        st.insert(d6);

        if (st.size() == 6) {
            int e2 = 1;
            for (auto vi : st)
            {
                if (e2 == vi) {
                    e2++;
                } else {
                    d1 = 1000;
                    break;
                }   
            }
            

            if ((d1 + d6) == 7 && (d2 + d4) == 7 && (d3 + d5) == 7)
            {
                cout << "SIM\n";
            } else {
                cout << "NAO\n";
            }
        } else {
            cout << "NAO\n";
        }
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome