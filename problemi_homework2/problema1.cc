#include <iostream>
#include <vector>
#include<unistd.h>

//#include <bits/stdc++.h>


/*
Soluzione con backtracking
*/

using namespace std;

//Struttura definita per identificare una posizione all'interno della matrice.
typedef struct pos{

    int x,y;//x= riga, y = colonna
    bool operator==(const struct pos &my){return (this->x==my.x && this->y == my.y);} //Overload dell operatore di uaguaglianza
    void print(){cout<<this->x<<","<<this->y;}                                        //Funzione di comodo.

}Pos;

//stampa la boards nel caso di stampa post soluzioen fa vedere anche i valori "- 1" assegnati che percorrono il percorso trovato. 
void print_boards(vector <vector<int> > &boards)
{
    for (size_t i = 0; i < boards.size(); i++)
    {
        for (size_t j = 0; j < boards[i].size(); j++)
        {
            cout<<boards[i][j]<<" ";
        }cout<<"\n";
        
    }
}

//Stampa la soluzione trovata.
void display_solution(vector <Pos> &solution)
{
    cout<<"PATH = ";
    for (size_t i = 0; i < solution.size(); i++)
    {
        solution[i].print();
        if(i<solution.size()-1)
            cout<<" -> ";

    }
    cout<<endl;
    cout<<"Solution size = "<<solution.size()<<"\n";    

}

//Posizione che verifica le next move se sono possibili ritorna true
bool check_0(vector < vector <int> > &visit,Pos current, vector <vector <int> > &boards){

    if(current.x >= 0 && current.y < boards[current.x].size() && current.x < boards.size() && current.y >= 0)
        if(visit[current.x][current.y] != 1 )
            if(boards[current.x][current.y] != 0 && boards[current.x][current.y] != 2)
                return true;
    
    return false;

}

//funziona ricorsiva che prova tutti i percorsi .
//"main" del backtracking tenta ogni possibile strada fattibile finchè riesce a proseguire.
//La complessità è esponenzia ed è dipendente da quanti vincoli ho sul percorso.
void backtracking(vector < vector <int> > &visit ,vector <Pos> &ending_solution, vector <Pos> &current_solution, Pos current_posizion, vector <vector <int> > &boards){

    if(current_posizion.y == boards[0].size()-1)
    {
        current_solution.push_back(current_posizion);

        visit[current_posizion.x][current_posizion.y] = 1;

        if (ending_solution.empty()==true)
        {
            ending_solution = current_solution;
        }
        else if( ending_solution.size() > current_solution.size()) //process solution
        {   
            ending_solution.clear();
            ending_solution = current_solution;
        }

    }
    else
    {  
        
        /*-------------------------------------------------------------------------------------------------   
        |    Qui verifico se la soluzione corrente è già maggiore si una soluzione trovata in precedenza,  |
        |    in queso caso non c'è alcun motivo di continuare la ricerca,                                  |
        |    quindi applico un "pruning dell'albero di ricorsione."                                        |
        ---------------------------------------------------------------------------------------------------*/
        current_solution.push_back(current_posizion);
        if(ending_solution.empty()==false)
        {
            if(current_solution.size() >= ending_solution.size())
                return;            
        }

        //La matrice visit mi tiene traccia dei percorsi già visitati.
        visit[current_posizion.x][current_posizion.y] = 1;
        
        //Possibili nuovi spostamenti.
        Pos current_go_right = {.x = current_posizion.x, .y = current_posizion.y + 1};
        Pos current_go_down = {.x = current_posizion.x-1, .y = current_posizion.y};
        Pos current_go_up = {.x = current_posizion.x + 1, .y = current_posizion.y};
        Pos current_go_left = {.x = current_posizion.x, .y = current_posizion.y -1};

        //Per ogni possibile nuova posizione sulla matrice eseguo prima un check sulla fattibilità dello spostamento,
        //dopo questo richiamo ricorsivamente "backtraking" con il nuovo punto dato dalla mossa eseguita.
        if(check_0(visit,current_go_right,boards))
            backtracking(visit, ending_solution, current_solution,current_go_right,boards);

        if(check_0(visit, current_go_down,boards))
            backtracking(visit, ending_solution, current_solution, current_go_down,boards);
        
        if(check_0(visit, current_go_up,boards))
            backtracking(visit, ending_solution, current_solution, current_go_up,boards);
        
        if(check_0(visit, current_go_left, boards))
            backtracking(visit, ending_solution, current_solution, current_go_left,boards);     

        
        current_solution.pop_back();
        visit[current_posizion.x][current_posizion.y] = 0;

    }
}

//Processa una matrice data in quanto essendo anche i punti adiacenti agli "0" inaccessibili,
//è coneventiente preprocessare la matrice con gli "0" inserendo dei "2" vicino a quest'ultimi,
//così facendo la funzione di check per le posizione possibili risulta di immediata implementazione.
vector <vector <int > > pre_processing_matrix(vector < vector <int> > &matrix)
{

    vector < vector <int> >new_matrix = matrix;

    for (size_t i = 0; i < new_matrix.size(); i++)
    {
        for (size_t j = 0; j < new_matrix[0].size(); j++)
        {
            if (new_matrix[i][j] == 0)
            {
                if(j < new_matrix[i].size()-1)
                    {
                        if(new_matrix[i][j+1]!= 0)
                            new_matrix[i][j+1] = 2;
                    }
                if(j > 0)
                    {
                        if(new_matrix[i][j-1]!= 0)
                            new_matrix[i][j-1] = 2;
                    }
                if(i > 0)
                    {
                        if(new_matrix[i-1][j]!= 0)
                            new_matrix[i-1][j] = 2;
                    }
                if(i< new_matrix.size()-1)
                    {
                        if(new_matrix[i+1][j]!= 0)
                            new_matrix[i+1][j] = 2;
                    }
            }
            
            
        }
            
    }
    
   return new_matrix;    

}

//Per ridurre ulteriormente la complessità verifico se esiste almeno una soluzione,
//tale verifica è effettuata considerando una colonna fissata verificare se esiste almeno un "1" altrimenti, 
//c'è un muro di "0" o di "1" vicino agli zero.
bool is_there_a_wall(vector <vector <int> > &matrix)
{
    
    for (size_t i = 0; i < matrix[0].size(); i++)
    {
        int count = 0;
        for (size_t j = 0; j < matrix.size(); j++)
        {
            if(matrix[j][i] ==0 || matrix[j][i]==2)count++;
        }
        if(count==matrix.size())return true; //ho trovato un muro
    }
    return false;
}

//La funzione find_min_path inizia già il backtracking, prunacompletamente dei rami se portano a percorsi senza soluzione,
//o se non hanno punti di partenza.
//Infine lancia per ogni punto di partenza disponibile il backtracking.
vector <Pos> find_min_path(vector <vector <int> > &boards)
{

    vector <Pos> curr;
    vector <Pos> ending;

    vector <vector <int> >visit;

    visit.resize(boards.size(),vector <int> (boards[0].size()));

    vector <vector <int> >max = pre_processing_matrix(boards);

    vector <Pos> real_ending(3000);

    if (is_there_a_wall(max)) 
    {
        real_ending.clear();
        return real_ending;
    }
    int i,j;
    for (i = 0; i < max.size(); i++)
        {
            for (j=0;j<max.size();j++)
                {
                    vector <Pos> curr;
                    vector <Pos> ending;
                    vector <vector <int> >visit;
                    visit.resize(boards.size(),vector <int> (boards[0].size()));
                    vector <vector <int> >max = pre_processing_matrix(boards);
                    
                    if(check_0(visit,(Pos){i,0},max) && check_0(visit,(Pos){j,(int)boards[0].size()-1},max))
                        backtracking(visit, ending, curr, (Pos){i,0}, max);
                    
                    
                    if(real_ending.empty() != true && ending.empty() != true && real_ending.size() > ending.size())
                        {
                            real_ending = ending;
                        }

                }
            
        }
        
    if(real_ending.size()==2000)real_ending.clear();

    return real_ending;
}

int main()
{

    vector <vector <int> > boards;

    cout<<"Numero casi di test: ";
    int T;
    cin>>T;
    while(T--)
    {
        int n; //righe 
        int m; //colonne
        cout<<"inserire dimensione matrice \n inserire righe: ";
        cin>>n;
        cout<<"\ninserire colonne: ";
        cin>>m;
        boards.resize(n,vector<int>(m));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                int a ;
                cin >> a;
                boards[i][j] = a;
            }
            
        }
    
        cout<<"Matrice inserita :\n";
        print_boards(boards);
        cout<<endl;
        vector <Pos> solution = find_min_path(boards);
        
        display_solution(solution);

    }



    return 0;
}
