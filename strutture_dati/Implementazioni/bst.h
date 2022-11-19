#ifndef BST
#define BST


#include <stdio.h>
#include <stdlib.h>


typedef struct nodo Nodo;

struct nodo{

    int value;
    int key;
    Nodo *left;
    Nodo *right;
    Nodo *parent;

};


Nodo *find_minimum_sub_tree(Nodo *x);

Nodo *find_maximum_sub_tree(Nodo *x);

void tree_walk(Nodo *root);

Nodo *searh_node(Nodo *root, int ele);

Nodo *left_rotate(Nodo *root);

Nodo *right_rotate(Nodo *root);

Nodo *insert(Nodo* nodo, int value, int key);


#endif