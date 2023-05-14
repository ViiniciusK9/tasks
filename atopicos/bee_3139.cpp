#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long so = 0, media = 0;
    long long int m, n, qnt = 0, aux;
    cin >> n >> m;
    queue<int> q;
    for (int i = 0; i < 30; i++)
    {
        cin >> aux;
        so+=aux;
        q.push(aux);
    }
    media = ceil((double)so / 30);
    
    n+=media;
    qnt++;
    
    so = so - q.front();
    q.pop();

    q.push(media);
    so += media;
    int x = 0;
    int ant = media;
    while (n < m)
    {
        
        
        //cout << media << '\n';
        media = ceil((double)so / 30);
        n+=media;
        qnt++;
        
        if (ant == media)
        {
            x++;
        } else {
            x = 0;
            ant = media;
        }
        if (x == 30)
        {
            break;
        }
        

        so = so - q.front();
        q.pop();

        q.push(media);
        so += media;
    }
    
    if (x == 30)
    {
        qnt += abs(n-m) / media;
        if(abs(n-m) % media != 0) qnt+=1;
    }
    cout << qnt << '\n';
    

    
    return 0;
}

// g++ -O2 -Wall nome.cpp -o nome