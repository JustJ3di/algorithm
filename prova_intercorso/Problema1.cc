
#include <algorithm>
#include <iostream>
#include <vector>


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