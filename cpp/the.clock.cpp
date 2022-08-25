#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)

int main(int argc, char const *argv[])
{
    int n, h;
    char linha[10];
    char a [3];
    int horas, minutos;
    int hora_i, minuto_i;
    int hora_aux, minuto_aux;
    

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> linha;
        a[0] = linha[0]; 
        a[1] = linha[1];
        hora_i = atoi(a);
        hora_aux = hora_i;
        a[0] = linha[3]; 
        a[1] = linha[4];
        minuto_i = atoi(a);
        minuto_aux = minuto_i;
        cin >> h;
        //cout << hora_i << minuto_i << '\n';
        //cout << h << '\n';
        horas = h / 24;
        minutos = h - (horas * 24);


        hora_aux += h;
        minuto_aux += minutos;

        if (minuto_aux > 59)
        {
            minuto_aux = minuto_aux - 60;
            hora_aux += 1;
        }
        
        if (hora_aux > 23)
        {
            hora_aux = hora_aux - 24;
        }
        int c = 0;

        while (hora_i != hora_aux && minuto_i != minuto_aux)
        {
            int aux_aux = hora_aux;
            int t = (aux_aux % 10) * 10;
            t += (aux_aux - (aux_aux % 10)) % 100;

            cout << t << " " << minuto_aux << '\n';
            if (t == minuto_aux)
            {
                c++;
            }
            

            hora_aux += h;
            minuto_aux += minutos;
            
            if (minuto_aux > 59)
            {
                minuto_aux = minuto_aux - 60;
                hora_aux += 1;
            }
            
            if (hora_aux > 23)
            {
                hora_aux = hora_aux - 24;
            }

        }
        cout << c << '\n';
        
    }
    
    return 0;
}

// g++ -o nome.cpp nome.exe