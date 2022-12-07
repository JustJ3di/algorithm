
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>


/*
            PROBLEMA 1!

COMPLESSITà O(nlogn)

using namespace std;

//O(log(n)
int bsc(vector <int> &my_arr , int l, int r, int x)
{
	if (r < l)
		return -1;

	int mid = l + (r - l) / 2;
	if (my_arr[mid] == x)
		return mid;
	if (my_arr[mid] > x)
		return bsc(my_arr, l, mid - 1, x);

	return bsc(my_arr, mid + 1, r, x);
}
//bsc + conteggi 
//n + logn
int count_occ(vector <int> &my_arr, int x)
{
    int n = my_arr.size();

	int ind = bsc(my_arr, 0, n - 1, x);

	if (ind == -1) //l'elemento cercato non c'è
		return 0; 


	int count = 1; //sicuro c'è un occorrenza
	int l = ind - 1;

	while (l >= 0 && my_arr[l] == x)
        {   
            //vedi sulla sinistra
		    count++; 
            l--;
        }
	int r = ind + 1;
	while (r < n && my_arr[r] == x)
        {
            //vedi sulla destra
            count++;
            r++;
        
        }
	return count;
}


int main()
{
	
    int T,dim,k;
    cin>>T;
    while(T--)
        {   
            cin>>k;//dammi k            
            cin>>dim; //dammi array dim
            vector <int> my_arr;
            for (size_t i = 0; i < dim ; i++)
            {
                int ele;
                cin>>ele; //scrivi nel vector
                my_arr.push_back(ele);
            }

            sort(my_arr.begin(), my_arr.end()); //sort
               // Dalla reference:
                //O(N·log(N))la complessità

        

            cout << count_occ(my_arr, k)<<"\n";
            
        }

	return 0;
}

*/

//-------------------------------PROBLEMA 2-------------------------------------------

//complessità O(2^n)

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
