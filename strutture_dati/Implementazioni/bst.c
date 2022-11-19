
#include "bst.h"




Nodo *find_minimum_sub_tree(Nodo *x){

    while(x!=NULL && x->left != NULL)
    {
        x = x->left;
    }
    return x;

}


Nodo *find_maximum_sub_tree(Nodo *x){

    while (x != NULL && x->right != NULL)
    {
        x = x->right;
    }
    
    return x;

}

void tree_walk(Nodo *root){
    if (root != NULL)
        tree_walk(root->left); //go to left
        printf("value Nodo = %d",root->value);
        tree_walk(root->right); // go to right
}


Nodo *searh_Nodo(Nodo *root, int ele){

    while(root!=NULL && root->value != ele){

        if(root->value > ele)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }

    }

    return root;
}

Nodo *left_rotate( Nodo *new_son){

    Nodo *x = new_son->parent;
    Nodo *tmp = new_son;
    x->right = tmp->right;
    if (tmp->left!=NULL)
    {
        tmp->left->parent = x;
    }
    tmp->parent = x->parent;
    if(x = x->left->parent)
    {
        tmp = x->parent->left;
    }
    else
    {
        tmp = x->parent->right;
    }
    tmp->left = x;
    x->parent = tmp;

    return tmp;

}

Nodo *right_rotate( Nodo *new_son){

    Nodo *x = new_son->parent;
    Nodo *y = new_son;
    x->left = y->right;
    if (y->right != NULL)
    {
        x = y->right->parent;
    }
    y->parent = x->parent;

    if(x = y->right->parent)
    {
        x->parent->right = y;
    }else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;

    return y;

}


Nodo *insert(Nodo* nodo, int value, int k)
{

    if (nodo == NULL){
        Nodo *temp =  malloc(sizeof(Nodo)) ;
        temp->value = value;
        temp->key = k;
        temp->left = temp->right = NULL;
        temp->parent = NULL;
        return temp;
    } 
    if (nodo->value < value)
    {
        Nodo *right = insert(nodo->right, value, k);
        nodo->right = right;
        right->parent = nodo;
        if (nodo->right->key > nodo->key)
        {
            nodo = left_rotate(nodo);
        }
        
    }
    else
    {
        Nodo *left = insert(nodo->left, value, k);
        nodo->left = left;
        left->parent = nodo;
        if (nodo->left->key > nodo->key)
        {
            nodo = right_rotate(nodo);
        }
        
    }
    


    return nodo;


}