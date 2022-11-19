/*PROBLEMA 2
Un artigiano deve svolgere N lavori (ordini dai clienti). 
Egli può svolgere un solo lavoro al giorno. 
Per ogni i-esimo lavoro, è noto Ti (1 ≤ Ti ≤ 1000), un intero che indica il tempo in giorni impiegato dall’artigiano per finire il lavoro.
Per ogni giorno di ritardo accumulato prima di iniziare a lavorare l'i-esimo ordine, l’artigiano deve pagare una penale di Si (1 ≤ Si ≤ 10000) centesimi di euro. 
Si implementi un programma per trovare la sequenza dei lavori che comporta la minima somma di penali.
INPUT
L'input inizia con un singolo intero positivo su una riga a sé stante,
indicante il numero dei casi di test successivi, 
seguita da una riga vuota. Le righe successive descrivono il caso di test; 
la prima di tali righe contiene un numero intero N (1 ≤ N ≤ 1000), 
le successive N righe contengono ciascuna due numeri: 
il tempo impiegato e la penale di ogni attività (la prima coppia di numeri si riferisce al lavoro i=1, 
seconda coppia il lavoro i=2, ecc.).
OUTPUT
Per ogni caso di test, Il programma dovrà stampare la sequenza dei lavori che comporta una penale minima.
Ogni lavoro è identificato dall’ordine in cui è apparso in input, i.
Tutti i numeri interi devono essere posizionati su una sola riga di output e separati da uno spazio. 
Se sono possibili più soluzioni, stampare la prima soluzione in ordine lessicografico.
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T = 0;
    vector <pair<float,float> > tempo_penale;

    cin>>T;
    int n = 0;

    while(T--)
    {
        cin>>n;
        
        for (size_t i = 0; i < n; i++)
        {
            float t,p;
            cin>>t>>p;
            tempo_penale.push_back(make_pair(t/p, i+1));
        }
       
        stable_sort(tempo_penale.begin(), tempo_penale.end());

       // sort(tempo_penale.begin(),tempo_penale.end);

        for (size_t i = 0; i < tempo_penale.size(); i++)
        {
            cout<<tempo_penale[i].second<<" ";
        }
        
        cout<<endl;

    }
    
    return 0;
}
