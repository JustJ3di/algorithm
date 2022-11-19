#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo
{
    
    struct nodo *next;
    

    //per le stringhe uso il trick del vettore dinamico infondo al nodo ;)

    char name[];

}Nodo;


Nodo *init_head_list(){

    return NULL;

}



void push(Nodo **head, char *new_name) 
{

    size_t size_str = strlen(new_name) + 1; //Mi prendo la dimensione della stringa considerando anche il carattere terminatore.

    Nodo *new  = malloc(sizeof(Nodo) + size_str);
    if (new == NULL)
    {
        printf("Errore! memoria non disponibile\n");
    }

    for (size_t i = 0; i <= size_str ; i++)
    {
        new->name[i] = new_name[i];
    }

    
    new->next = (*head);
    (*head) = new;

}

void delete_list(Nodo **head){

    Nodo *current = *head;
    Nodo *tmp;

    while (current!= NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    

}



int get_size(Nodo *head)
{   
    Nodo *current = head;
    int count = 0;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}


Nodo *reverse_mid_list(Nodo *head)
{

    int size_list = get_size((head)); // O(n)

    printf("\n\nsize list = %d\n",size_list);

    if(size_list == 0 || size_list == 1)
        printf("Lista vuota o con un solo elemento!\n");
    else
    {   

        int size_mid_list = size_list/2;

        Nodo *current = (head);
        Nodo *tmp;
        Nodo *new_head = NULL;
        while(head)
        {
            head = head->next;
            new_head = head;
            
        }

        int i = 0;
        while (tmp)
        {   

            tmp = current->next;
            current->next = new_head;
            new_head = current;
            current = tmp;
            i++;
            
            
        }
        
                
        (head) = new_head;
    }


    return head;
    

}


void print_list(Nodo *head)
{
    Nodo *current = head;
    while (current != NULL)
    {
        printf("%s \n", current->name);
        current = current->next;
    }
    

}

int main()
{

    Nodo *head = init_head_list();
/* 
    TEST 1

    push(&head , "Marco");
    push(&head, "hermo");
    push(&head ,"giuseppe");
    push(&head, "Raff");
    push((&head),"Lorenzo");
    push((&head), "Giacomo");
    push((&head), "Arianna");
    push((&head), "Pablo");

*/

/*

    TEST 2
    push(&head , "Marco");
    push(&head, "hermo");

*/


/*

    TEST 3
    push(&head, "hermo");

*/

//test 4
    
    push(&head , "Marco");
    push(&head, "hermo");
    push(&head ,"giuseppe");
    push(&head, "Raff");
    push((&head),"Lorenzo");
    push((&head), "Giacomo");
    push((&head), "Arianna");
    push((&head), "Pablo");
    push((&head), "Jhon");
    push((&head), "Marika");
    push((&head), "Mia");
    push((&head), "Uto");

    printf("Lista pre reverse\n");
    print_list(head);
    
    head = reverse_mid_list(head);
    printf("Lista post reverse\n");
    print_list(head); //O(n)
  
    
    delete_list(&head); //O(n)

    return 0;
}


