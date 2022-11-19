#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
PROBLEMA 1 Il signor Rossi si trasferisce a Napoli. 
Ha una famiglia molto numerosa a Napoli, 
e tutti vivono a via Roma.  Dal  momento  che  intende  visitare  spesso  tutti  i  suoi  parenti,  
sta  cercando  di  trovare  casa vicino  a  loro.  
Il  signor  Rossi  vuole  ridurre  al  minimo  la  distanza  totale  da  tutti  loro  
(ossia,  vuole determinare la posizione ottimale della casa che minimizza 
la somma delle distanze dalle case dei suoi parenti),
e ti ha ingaggiato per scrivere un programma che risolva il problema.
INPUTL'input è costituito da diversi casi di test.
La prima riga contiene il numero di casi di test.
Per ogni test case è fornito un numero
intero che indica il numero dei parenti r(0 < r < 500),
ed i numeri civici (anche essi interi) s1, s2,..., si,..., sr 
dove vivono (0 < si< 30000 ). 
Nota che diversi parenti potrebbero vivere allo stesso civico.
OUTPUT
Per  ogni  test  case,
il  programma  riporti  in  output la somma minima delle  distanze
dalla  casa  del signor  Rossi alle  case  diciascuno  dei  suoi  parenti. 
La  distanza  tra  due  numeri  civici  sied  sjè dij= |si− sj|*/

int main()
{

    //TEST CASE
    int T = 0;
    cin>>T;

    while(T--)
    {
        int r = 0;
        cin>>r;
        int n = 0;
        int tot = 0;
        vector <int> parent_n;
        while(r--)
        {   
            int s;
            cin>>s;
            parent_n.push_back(s);

        }
        sort(parent_n.begin(),parent_n.end());
        int med = parent_n[parent_n.size()/2];
        cout <<med<<endl;
        int sommma_distanze = 0;
        for (size_t i = 0; i < n; i++)
        {
            sommma_distanze += abs(parent_n[i]-med+1);   
        }
        cout<<sommma_distanze<<endl;
        

    }


    return 0;
}

