#include <bits/stdc++.h>

using namespace std;

void print_sol_current(vector <int> &pos)
{
    cout<< "current sol = ";
    for (auto i = 0; i < pos.size(); i++)
    {
        cout<<" "<<pos[i];
    }
    cout<<endl;
    
}


//posizioni_trovate è un vettore che associa la riga i alla colonna sulla quale si trova la regina posizioni_trovate[i]
void move(int *sol,int n, int riga_corrente ,vector <int> &posizione_sulla_riga_i)
{
    //se riga_corrente < n allora continua
    if(riga_corrente  >= n) //qui hai finito quindi incrementa il contatore delle soluzioni
    {   
        cout<<"end"<<endl;
        print_sol_current(posizione_sulla_riga_i);
        *sol += 1;
        
    }
    else
    { 
        for (int j = 0; j < n; j++) //scorri tutte le colonne
        {                
            int is_good_line = 1; //mi dice se la riga riesce a posizionare almeno (fottuta) una regina     
            int i = 0;
            for (i = 0; i < riga_corrente; i++) //scorri le righe da 1 a riga_corrente
            {   
                //devo scegliere la colonna da aggiungere a posizione_trovate  
                if(posizione_sulla_riga_i[i] == j)
                    is_good_line = 0;
                if(j == posizione_sulla_riga_i[i] + (-riga_corrente + i))
                    is_good_line = 0;
                if(j == posizione_sulla_riga_i[i] - (-riga_corrente + i))
                    is_good_line = 0;

            }
            if(is_good_line!=0)
            {   
                posizione_sulla_riga_i[i] = j;
                move(sol, n, i + 1, posizione_sulla_riga_i);
            
            }
            
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    int N;
    do{cin>>N;}while (N<=3);    

    vector <int> pos(N);    

    int count = 0;

    move(&count, N, 0, pos);

    cout<<endl<<count<<endl;

    return 0;
}
