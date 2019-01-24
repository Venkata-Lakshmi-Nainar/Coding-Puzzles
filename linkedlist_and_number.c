/*

Given : Two Sorted Linked Lists
To do : Combine them to form a single sorted linked list without creating a new linked list ( extra space )

Example:
Input:
List 1 : 4 -> 8 -> 32 -> 45 
List 2: 3 -> 6 -> 7 -> 40

Output :
3 -> 4 -> 6 -> 7 -> 8 -> 32 -> 40 -> 45

*/
#include <stdio.h>
#include <stdlib.h>

struct node{
  int data ;
  struct node *link ;
};

struct node* create ( int num ) {
  struct node* x = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
  x -> data = num ;
  x -> link = NULL ;
  return x ;
}

void add ( struct node **start , int num ) {
  struct node *temp = create ( num ) ;
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
  printf ("NULL \n") ;
}

struct node* merge_list ( struct node* list1 , struct node* list2 ) {
  struct node *list_head, *p , *q , *prev , *temp;
  if ( list1 == NULL ) {
    return list2 ;
  }
  if ( list2 == NULL ) {
    return list1 ;
  }
  if ( ( list1 -> data ) < ( list2 -> data ) ) {
    list_head = list1 ;
    q = list2 ;
  }
  else {
    list_head = list2 ;
    q = list1 ;
  }
  p = list_head ;

  while ( ( p != NULL ) && ( q != NULL ) )  {
    if ( (q -> data) > (p -> data) ){
      prev = p ;
      p = p -> link ;
    }
    else {
      temp = q -> link ;
      prev -> link = q ;
      prev = prev -> link ;
      prev -> link = p ;
      p = prev ;
      q = temp ;
    }
  }

if ( p == NULL ) {
  prev -> link = q ;
}
return list_head ;
}

int main(){
  struct node *list_1 = NULL , *list_2 = NULL ;
  add ( &list_1 , 78 ) ;
  add ( &list_1 , 67 ) ;
  add ( &list_1 , 54 ) ;
  add ( &list_1 , 35 ) ;
  add ( &list_1 , 22 ) ;
  add ( &list_1 , 9 ) ;
  display(list_1) ;

  add ( &list_2 , 65 ) ;
  add ( &list_2 , 44 ) ;
  add ( &list_2 , 10 ) ;
  add ( &list_2 , 1 ) ;
  display(list_2) ;

  display(merge_list(list_1,list_2)) ;

  return 0;
}
