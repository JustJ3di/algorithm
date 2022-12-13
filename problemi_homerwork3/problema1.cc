#include<iostream>
#include <string>

#define len(str) str.size()
using namespace std;

/*
            Homework 3 ---------------- PROBLEMA 1
            Emanuele d'Ajello           Marco D'Elia

    Si è utilizzato l'approccio di programmazione dinamica top-down + memoization.

    Vengono quindi qui elencati i 5 punti:(n = lunghezza della stringa)

    
    1)  Il sottoproblema è trovare la più grande sottosequenza palindroma in una sotto-stringa.
        Il numero dei sotto problemi risulta essere O(n^2) perchè, a partire dal inizio e dalla fine della stringa,
        se ricorsivamente si elimina il carattere di inizio o fine, si hanno O(n^2) sotto-stringhe.
    
    2)  Il numero di scelte possibili sono due: si riduce la stringa dall' inizio o dalla fine.
        Nota:
        Un caso notevole è quando i caratteri di inizio e fine della stringa sono uguali. 
        In questo caso la stringa si riduce di entrambi i caratteri, 
        quindi si incrementa di 2 la grandezza del possibile palindromo.
        Il tempo per sottoproblema è O(1).

    3) La ricorrenza ricavata nel approccio è:

                    { max(dp(i+1,j),dp(i,j-1)),     se i caratteri indicizzati da i e j sono diversi.
        dp(i,j) =   { 2 + max(dp(i+1,j),dp(i,j-1)), se i caratteri indicizzati da i e j sono uguali.
                    { 1,                            se i == j sono un singolo carattere : caso base.
                    { 0,                            se i > j stringa vuota : caso base.
    
    4) Il tempo totale è uguale a: #sottoproblemi*tempo-per-sottoproblema = O(n^2).

    5) Il problema originario si risolve utilizzando la ricorrenza dp(0,n-1), dove n è la lunghezza della stringa.
    
*/


//Init memoization
int dp[1001][1001];

//Funzione ricorsiva. 
//Nota: è case sensitive.
int lsps(string s,int i, int j)
{
    if(i == j)return 1;
    if(i>j) return 0;
    if(dp[i][j]!= -1)
        return dp[i][j];
    
    if(s[i]==s[j])
        dp[i][j] = 2 +  lsps(s, i+1, j-1);
    else
        dp[i][j] = max(lsps(s, i+1, j),lsps(s,i,j-1));
        
    return dp[i][j];
    
}

/*

    Possibili casi di test con i corrispettii output attesi:

    qwerty
    1
    anna
    4
    otasspto
    6
    onorarono
    9
    spingegniep
    9

*/

int main()
{

    string s;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>s;
        memset(dp, -1, sizeof(dp[0][0]) *1001 * 1001);
        cout<<lsps(s,0,len(s)-1)<<endl;
    }

    return 0;
}
