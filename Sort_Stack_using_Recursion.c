#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

struct arraystack{
  int top;
  int capacity;
  int *array;
};

struct arraystack *createstack(){
  struct arraystack *s = malloc ( sizeof ( struct arraystack ) ) ;
  if ( !s )
    return NULL;
  s -> capacity = MAXSIZE ;
  s -> top = -1 ;
  s -> array = malloc ( ( s -> capacity ) * sizeof ( int ) )  ;
  if ( !s->array )
    return NULL;
  return s;
}
int isemptystack ( struct arraystack *s ) {
  return ( s -> top == -1 ) ; // if condition is true 1 is returned. Else 0.
}
int isfullstack ( struct arraystack *s ) {
  return ( s -> top >= s -> capacity - 1 ) ;
}
void push ( struct arraystack *s , int data ) {
  if ( isfullstack(s) ) {
   // printf ( "Stack Overflow\n" ) ;
  }else{
    s -> array[++ (s -> top) ] = data ;
  }
}
int pop ( struct arraystack *s ) {
  if ( isemptystack (s) ) {
   // printf("Stack Underflow - Pop\n") ;
    return FALSE;
  }
    return ( s -> array[s->top --] ) ;
}
void deletestack ( struct arraystack *s ) {
  if ( s ) {
    if ( s -> array )
      free ( s -> array ) ;
      free ( s ) ;
  }
}
int peek ( struct arraystack *s ) {
  if ( isemptystack (s) ) {
    //printf("Stack Underflow - Peek\n") ;
    return FALSE;
  }
    return ( s -> array[s->top] ) ;
}
void displaystack ( struct arraystack *s ) {
  int i ;
  if ( isemptystack (s) ) {
    //printf("Stack Underflow - Display\n") ;
    return ;
  }
  for ( i = s ->top ; i >= 0 ; i-- ) {
    printf ( " |   ");
    printf ( " %d " , s -> array[i]);  
    printf ( "   | \n "   ) ;
  }
}
struct arraystack* stack_sort( struct arraystack *s ) {
int top_element , temp;
if ( peek(s) == FALSE ) {
    return s ;
}
top_element = pop(s) ;

if ( peek(s) != FALSE ) {
    if ( top_element < peek(s) ) {
        temp = pop(s) ;
        push ( s , top_element ) ;
        top_element = temp ;
    }
    s = stack_sort(s) ;

    if ( top_element < peek(s) ) {
        temp = pop(s) ;
        push ( s , top_element ) ;
        top_element = temp ;
    }
    s = stack_sort(s) ;
}
push ( s , top_element ) ;
return s ;
}

int main(){
    struct arraystack *s = createstack();
    push( s , 19 ) ;
    push( s , 4 ) ;
    push( s , 32) ;
    push( s , 12 ) ;
    push( s , 71 ) ;
    push( s , 25 ) ;
    push( s , 14 ) ;
    push( s , 83) ;
    push( s , 2 ) ;
    push( s , 11 ) ;
    displaystack(s);
    printf ("\n") ;
    displaystack(stack_sort(s));
return 0;
}
