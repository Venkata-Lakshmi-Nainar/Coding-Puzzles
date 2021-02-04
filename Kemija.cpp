/*
Luka is fooling around in chemistry class again! Instead of balancing equations he is writing coded sentences on a piece of paper. Luka modifies every word in a sentence by adding, after each vowel (letters ’a’, ’e’, ’i’, ’o’ and ’u’), the letter ’p’ and then that same vowel again. For example, the word “kemija” becomes “kepemipijapa” and the word “paprika” becomes “papapripikapa”. The teacher took Luka’s paper with the coded sentences and wants to decode them.

Write a program that decodes Luka’s sentence.

Input
The coded sentence will be given on a single line. The sentence consists only of lowercase letters of the English alphabet and spaces. The words will be separated by exactly one space and there will be no leading or trailing spaces. The total number of character will be at most 100.

Output
Output the decoded sentence on a single line.

Sample Input 1	: zepelepenapa papapripikapa
Sample Output 1 : zelena paprika
Sample Input 2 : bapas jepe doposapadnapa opovapa kepemipijapa
Sample Output 2 : bas je dosadna ova kemija
*/

#include<bits/stdc++.h>
using namespace std ;
int main(int argc, char const *argv[]) {
  string input = "" ;
  set <char> vowels { 'a' , 'e' , 'i' , 'o' , 'u' } ;
  getline ( cin , input ) ;
  cout << endl << input ;
  unsigned int itr = 0 ;
  unsigned int input_length = input.size() ;
  while ( itr < input_length ) {
    if ( vowels.find ( input[itr] ) != vowels.end() ) {
      itr += 2 ;
    }
    cout << input[itr] ;
    itr += 1 ;
  } // while
  return 0;
}
