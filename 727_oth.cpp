/*******************************************************/
/* UVa 727 Equation                                    */
/* Author: LanyiKnight [at] knightzone.org             */
/* Version: 2012/01/17                                 */
/*******************************************************/
#include<iostream>
#include<cstdio>
#include<cctype>
#include<stack>
using namespace std;

int main(){
  int n;
  char c;
  stack<char> stk;
  while( scanf( "%d", &n ) != EOF ){
    getchar();
    getchar();
    for( int i = 0 ; i < n ; i++ ){
      if( i ) printf( "\n" );
      while( scanf( "%c", &c ) != EOF && c != '\n'){
        getchar();
        if( isdigit(c) )
          printf( "%c", c );
        else if( c == '(' )
          stk.push(c);
        else if( c == '*' || c == '/' ){
          while( !stk.empty() && (stk.top() == '*' || stk.top() == '/') ){
            printf( "%c", stk.top() );
            stk.pop();
          }
          stk.push(c);
        }
        else if( c == '+' || c == '-' ){
          while( !stk.empty() &&
                (stk.top() == '*' ||
                 stk.top() == '/' ||
                 stk.top() == '+' ||
                 stk.top() == '-' )){
            printf( "%c", stk.top() );
            stk.pop();
          }
          stk.push(c);
        }
        else if( c == ')' ){
          while( stk.top() != '(' ){
            printf( "%c", stk.top() );
            stk.pop();
          }
          stk.pop();
        }
      }
      while( !stk.empty() ){
        printf( "%c", stk.top() );
        stk.pop();
      }
      printf( "\n" );
    }
  }
  return 0;
}
