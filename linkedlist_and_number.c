#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *link ;
};

struct node* create ( int num ) {
    struct node *x = ( struct node * ) malloc (sizeof(struct node)) ;
    x -> data = num ;
    x -> link = NULL ;
    return x ;
}

void add ( struct node **start , int num ) {
    struct node *temp = create (num) ;
    if ( *start == NULL ) {
        *start = temp ;
    }else{
        temp -> link = *start ;
        *start = temp ;
    }
}

void display ( struct node *head ) {
    while ( head != NULL ) {
        printf ( "%d -> " , head -> data ) ;
        head = head -> link ;
    }
    printf ("NULL\n") ;
}

int add_to_list ( struct node *t , int x ) {
    int carry , base ;
    if ( t -> link == NULL ) {
        carry = t -> data + x ;
        if ( carry > 9 ) {
            t -> data = carry % 10 ;
            return carry/10 ;
        }
        t -> data = carry ;
        return 0 ;
    }
    carry = add_to_list ( t -> link , x ) ; 
    if ( ( t -> data + carry ) > 9 ) {
        base = (t -> data + carry ) / 10 ;
        t -> data = (t -> data + carry ) % 10 ;
        return base ; 
        
    }
    t -> data = t -> data + carry ;
    return 0;
}
struct node* addition_to_list( struct node **begin , int x ) {
    int carry = add_to_list (*begin,x) ;
    if ( carry > 0 ) {
        struct node *new_head = ( struct node * ) malloc (sizeof(struct node)) ;
        new_head -> data = carry ;
        new_head -> link = *begin ;
        *begin = new_head ;
    }
    return *begin ;
}


int main(){
    struct node *parent_list = NULL ;
    int x = 10000 ;
    add ( &parent_list , 9) ;
    add ( &parent_list , 9) ;
    add ( &parent_list , 9) ;
    display(parent_list);
    parent_list = addition_to_list(&parent_list,x) ;
    display(parent_list);
    return 0 ;
}
