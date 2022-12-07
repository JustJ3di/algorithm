#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

//funziona comoda per che di dice se un numero è primo
//O(n) 
bool is_prime(int n)
{
    int sum = n;

    for (int i = sum - 1; i > 1; i--)
    {
        int r = sum%i;
        if(r == 0)return false;
    }
    
    return true;

}

//mi costruisce il set di numeri primi 
//O(n);
vector <int> give_me_prime_sequence(int P, int S){

    vector <int> my_arr;
    for (size_t i = P + 1; i <= S; i++)
    {
        if(is_prime(i))
        {
            my_arr.push_back(i);
        }
    }

    return my_arr;

}


//O(1)
bool is_sol(vector <int> &current_sub,int N, int S)
{   //Il sub set è una soluzione solo se valgono le condizione che è di cardinalità 3 
    //e la sua somma è pari ad S
    return (current_sub.size() == N && accumulate(current_sub.begin(), current_sub.end(), 0) == S);
}

//complessità esponenziale O(2^n) dato che le scelte sono due metto o non metto l'elemento per n elementi (n = size(my_vect_of_prime))
void all_subset(vector <int> &my_vect_of_prime, vector <int> &current_sub,int start_new, int N, int S)
{

    if(is_sol(current_sub, N, S)){
        for (size_t i = 0; i < N; i++)
        {
            cout<<current_sub[i]<<" ";

        }cout<<endl;
        
    }

    for(int i = start_new; i < my_vect_of_prime.size(); i++)
    {
        current_sub.push_back(my_vect_of_prime[i]); //fai mossa

        all_subset(my_vect_of_prime, current_sub , i + 1, N,S);

        current_sub.pop_back(); //ritira mossa
    }


}

int main()
{
    int i = 1;
    int p;
    int N, P, S;
    int T;
    cin>>T;
    while(T--)
        {
            
            cin>>S; //dove devonbo finire i sub_set
            cin>>N; //grandezza dei sub_set
            cin>>P; //dove devono partire i subset
            
            vector <int> array = give_me_prime_sequence(P, S);
            
            vector <int> current_set;

            cout<<"CASO DI TEST "<<i<<"\n";
            all_subset(array, current_set, 0, N, S);
            i++;
        }

    return 0;
}
