#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char c;
    while (cin >> n && n != 0)
    {
        queue<char> q1;
        queue<char> q2;
        stack<char> s;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            q1.push(c);
        }
        
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            q2.push(c);
        }

        while (!q1.empty())
        {
            if (q1.front() == q2.front())
            {

                cout << "I";
                cout << "R";
                q1.pop();
                q2.pop();
            } else if(!s.empty()) {
                if (s.top() == q2.front()){
                    cout << "R";
                    q2.pop();
                    s.pop();
                } else {
                    cout << "I";
                    s.push(q1.front());
                    q1.pop();
                }
            } else {
                cout << "I";
                s.push(q1.front());
                q1.pop();
            }
        }

        if (!s.empty())
        {
            while (!s.empty() && q2.front() == s.top())
            {
                cout << "R";
                q2.pop();
                s.pop();
            }
        }
        

        if (!q2.empty())
        {
            cout << " Impossible\n";
        } else {
            cout << "\n";
        }
        

    }
    
    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome