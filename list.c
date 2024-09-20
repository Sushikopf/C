#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(int argc, char *argv[])
{
    node *list = NULL;
    //dumb appetion of arguments to list
    /*for(int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            free(n);
            return 1;
        }
        n->number = number;
        n->next = list;
        list = n;
    }
    */
    //smart append to list in sorted order
    //for each cmd arg 
    for(int i = 1; i < argc; i++)
    {
        //convert arg to int
        int number = atoi(argv[i]);
        //created node n of size node
        node *n = malloc(sizeof(node));
        //if memory allocation failed terminate
        if(n == NULL){
            return 1;
        }
        n->number = number;
        n->next = NULL;
        printf("n->number = %i\n", n->number);
        // when list empty, set list to argument
        if( list == NULL)
        {
            list = n;
        }
        else if(n->number < list->number)
        {
            printf("n-> number: %i is smaller than list-number: %i\n", n->number, list->number);
            n->next = list;
            list = n;
        }else 
        {
            for(node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if(ptr->next == NULL)
                {
                    printf("next argument is NULL");
                    ptr->next = n;
                    break;
                }
                if(n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }


// print whole list
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

}