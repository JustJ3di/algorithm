#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Problema 3 homework 1
Quesito: implementare un insert in un treap.
Soluzione: È stato effettuato un inserimento BST, seguito da delle rotazioni del nodo inserito, per mantere le proprietà richieste dal treap. 
*/

//struct del nodo
typedef struct node{

    int priority, key;
    struct node *left,*right,*parent;

}TNode;

//Rotazione a sinistra di un nodo. (O(1))
TNode *left_rotate(TNode *node)
{

    TNode *y = node->parent; //y nodo padre di x;
    TNode *x = node;   
    TNode *B = x->left;    
    //figlio sinistro di x diventa il figlio destro di  y
    if (B != NULL) // se non è null
    {
        B->parent = y;
    }
    y->right = B;
    
    x->parent = y->parent; //scambio padri
    
    if (x->parent != NULL) //il padre di x non è NULL ===> non è root
    {
        //assegnazione di x al padre di y
        if(y == y->parent->left) 
            y->parent->left = x;
        else
            y->parent->right = x;
    
    }
    //si associa x a y 
    x->left = y;
    y->parent = x;
    
    return x;
    
}
//Rotazione destra di un nodo. (O(1))
TNode *right_rotate(TNode *node){

    TNode *y = node->parent; //y nodo padre di x;
    TNode *x = node;
    TNode *B = x->right;
    //il figlio destro di y diventa figlio sinistro di x
    y->left = B; 
    if (B != NULL)
    {
        B->parent = y;
    }

    //scambio i padri di x e y
    x->parent = y->parent;
    if (x->parent != NULL)
    {   
        //si associa x al padre di y 
        if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
        
    }
    //si associa y ad x
    x->right = y;
    y->parent = x;

    return x;

}

//treap insert: esegue prima una BST e poi delle rotazione per ripristinare la proprietà min-heap. (O(log(n))
void treap_insert(TNode **root, TNode *new){

    //Nodi di supporto per l'inserimento
    TNode *p = NULL; //Nodo inseguitore
    TNode *current = *root; //Nodo inseguito

    //Inizio procedura BST
    if (*root == NULL)
    {
        *root = new;
        new = *root;
    }
    else
    { 
        while (current)
        {    
            p = current;
            if (current->key > new->key)
            {        
                current = current->left;   
            }
            else
            {  
                current = current->right;
            }
           
        }
        
        new->parent = p;
        
        if ( new->key < p->key)
            p->left = new;
        else
            p->right = new;
        
        
    }
    //Fine procedura BST

    //new è il nodo appena inserito
    //Si eseguono delle rotazioni finchè la proprietà min-heap non è rispettata e il nodo non è radice
    while ((new->parent) != NULL && new->parent->priority >= new->priority)
    {

        if (new->parent->left == new)
        {   
            
            new = right_rotate(new);
        }
        else
        {
            
            new = left_rotate(new);
            
        }
        
        
    }
    //nel caso in cui il nodo appena inserito dopo le rotazion è diventato la nuova radice si assegna come tale.
    if (new->parent == NULL)
    {
        *root = new;
    }
    
    
}


//stampa del albero
void print_tree(TNode *root)
{


    if (root!=NULL)
    {
    
        print_tree(root->left);
        printf("Nodo key = %d Nodo priority  = %d, Nodo padre %p\n",(root)->key, (root)->priority,(root)->parent);
        if (root->left == NULL && root->right == NULL)
        {
            printf("sono foglia %p\n",root);
        }
        if (root->left != NULL){ 
           printf("Nodo figlio sinistro key = %d Nodo figlio sinistro  priority  = %d, sono il Nodo %p\n",(root)->left->key, (root)->left->priority,(root)); 
        } if(root->right != NULL)
        {
            printf("Nodo figlio destro key = %d Nodo figlio destro priority  = %d, sono il Nodo %p\n",(root)->right->key, (root)->right->priority,(root)); 
        }
        print_tree(root->right);

        
    }

    
}

int main()
{
    
    TNode *root = NULL;

    srand(time(NULL));
    

    treap_insert(&root, &(TNode){rand()%100, 12,NULL, NULL,NULL});
    treap_insert(&root,  &(TNode){rand()%100, 1,NULL, NULL,NULL});
    treap_insert(&root,  &(TNode){rand()%100,29,NULL, NULL,NULL});
    treap_insert(&root,  &(TNode){rand()%100,4,NULL, NULL,NULL});
    treap_insert(&root,  &(TNode){rand()%100,30,NULL, NULL,NULL});
    treap_insert(&root,  &(TNode){rand()%100, 10,NULL, NULL,NULL});
    treap_insert(&root,  &(TNode){rand()%100, 100,NULL, NULL,NULL});
    treap_insert(&root,  &(TNode){rand()%100, 5,NULL, NULL,NULL});

    print_tree(root);

    return 0;
}
