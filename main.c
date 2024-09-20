#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//note: x->member;
// is the same as (*x).member; -> meaning call the member variable of variable x of defined type struct

// define structure for list
typedef struct node_list
{
    int number;
    struct node_list *next;

}node_list;

// define structure for Tree 
typedef struct node_tree
{
    int Number;
    struct node_tree *left;
    struct node_tree *right;

}node_tree;


bool append(node_list *list, int number);
bool search_tree(node_tree *tree, int number);
bool search_list(node_list *list, int number);

int main(void)
{
    int i = 10;
    int* ptr = &i;
    printf("ptr= %i, i= %i\n",ptr, i);
    
    *ptr += 1;
    printf("ptr= %i, i= %i\n",ptr,i);

    if (true)
    {
        printf("true exists\n");
    }
    node_list *list = malloc(sizeof(node_list));
    append(list, 1);
    printf("%i", list->number);

    free(list);
    return 0;
}
// func to search through tree 
bool search_tree (node_tree *tree, int number)
{

    if(tree == NULL)
    {
        return false;
    }else if(number< tree->Number){
        return search_tree(tree->left, number);
    }else if(number > tree->Number){
        return search_tree(tree->right, number);

    }else{
        return true;
    }
    
}
bool search_list(node_list *list, int number)
{
    if(list == NULL)
    {
        return false;
    }else if(number == list->number)
    {
        return true;
    }else
    {
        search_list(list->next, number);
    }
    return true;
}

bool append(node_list *list, int number){
  node_list *n = malloc(sizeof(node_list));
  if(n == NULL)
  {
    return 0;
  }else
  {
    n->number = number;
    n->next = list;
    list = n;
    free(n);
    return true;
  }
}