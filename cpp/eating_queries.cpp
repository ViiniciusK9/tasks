#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)


// C++ implementation of Radix Sort -> Site: https://www.geeksforgeeks.org/radix-sort/


// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// ----------------- my code ----------------

void busca_lenta(int vet[150009], int n, int busca){
    
    if(vet[0] > busca){
        cout << "-1\n";
        return;
    }else if (vet[n-1] < busca){
        cout << "-1\n";
        return;
    }
    
    int achou = 0;
    for (int i = 0; i < n; i++)
    {
        if(vet[i] >= busca){
            achou = i+1;
            break;
        }
    }
    if(achou){
        cout << achou << '\n';
    }else {
        cout << "-1\n";
    }
}


void busca(int vet[150009], int n, int busca){
    //print(vet, n);
    int achou, inicio, meio, fim, lugar_achado, final_maior, final_maior_ant;
    achou = 0;
    lugar_achado = 0;
    inicio = 0;
    fim = n-1;
    meio = ((inicio + fim) / 2);
    while(inicio <= fim && achou == 0){
        final_maior = meio;
        if(vet[meio] == busca){
            achou = 1;
            lugar_achado = meio+1;
        }else {
            if(busca < vet[meio]){
                fim = meio -1;
                final_maior_ant = meio;
            }else {
                inicio = meio +1;
            }
            meio = ((inicio + fim) / 2);
        }
    }
    if(achou){
        cout << lugar_achado << '\n';
    } else if (vet[final_maior] > busca){
        cout << final_maior + 1 << '\n';
    }else if (vet[final_maior_ant] > busca){
        cout << final_maior_ant + 1 << '\n';
    } else {
        cout << "-1\n";
    }
}


int main(int argc, char const *argv[])
{
    int t, n, q, i, aux_q, sum;
    int vet[150009];
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        sum = 0;
        for (i = 0; i < n; i++)
        {
           cin >> vet[i];
        }

        radixsort(vet, n); // ordenação do vetor

	    for ( i = 0; i < n; i++)
        {
            sum += vet[i];
            vet[i] = sum;
        }
        


        for (i = 0; i < q; i++)
        {
            cin >> aux_q;

            // buscando o numero digitado no vetor
            busca_lenta(vet, n, aux_q);
            
        }
    }
    
    
    return 0;
}

// g++ -o nome.cpp nome.exe