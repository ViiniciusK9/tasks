#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    char s[51];

    char b[51];
    char snake[51];
    for (int i = 0; i < m; i++)
    {
        b[i] = '.';
        snake[i] = '#';
    }
    b[m] = '\0';
    snake[m] = '\0';
    size_t destination_size = sizeof (snake);
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0) strncpy(s, b, destination_size);
        else strncpy(s, snake, destination_size);

        if ((i % 2 == 0) && j == 0) s[m-1] = '#';
        if ((i % 2 == 0) && j == 1) s[0] = '#'; 

        if (i % 2 == 0)j = !j;
        cout << s << "\n";
    }
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome