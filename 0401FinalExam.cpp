/*

The Vietnamese High School graduation exam is in progress! For most Vietnamese high school students, this is their most important exam, as its result not only decides whether they can graduate from high school, but is also used for their university applications.

Today, Hanh finished his final exam, Math, which is Hanh’s strongest subject. In this exam, there are n questions, numbered from 1 to n. Each one is a multiple choice question, with 4 answers, A, B, C, and D. The students have to write the answers on an answer sheet with n lines, the i-th line should contain the answer for the i-th question. Each question has only one correct answer, and the student will receive one point if their answer matches the correct one.

Hanh started checking his results with his friends confidently. After few minutes, Hanh’s confidence turned into fright: Most of Hanh’s answers are different from his friends’.

Hanh quickly realized that he made a terrible mistake: Hanh wrote the answer for the 2nd question on the 1st line of the answer sheet, the answer for the 3rd question on the 2nd line, the answer for the 4th question on the 3rd line, and so on. Hanh left the n-th line of the answer sheet empty, and did not write the answer for the 1st question anywhere!

Please help Hanh check what will be his final score. Given that Hanh is a great Math student, his answers for all n questions would be correct if they were on the correct line of the answer sheet.

Input
The first line of the input contains a single integer n (1≤n≤1000) — the number of questions.

n lines follow, the i-th line contains a single character, A, B, C, or D — the correct answer for the i-th question.

Output
Print a single integer — Hanh’s final score.

Explanation of the first sample input
Fortunately for Hanh, all 4 questions have A as correct answer. So Hanh wrote A on the first three lines, and left the 4-th line empty. Hanh’s final score is 3.

Sample Input 1
4
A
A
A
A

Sample Output 1
3

Sample Input 2
6
A
D
B
B
C
A

Sample Output 2
1


CPU Time limit: 1 second

Memory limit: 1024 MB

Difficulty: 1.4

Download:
Sample data files
Source: The 2020 ICPC Asia Can Tho Regional Contest
License: Creative Commons License (cc by-sa)
*/


#include<bits/stdc++.h>
using namespace std ;
int main(){
  unsigned int N ;
  unsigned int count = 0 ;
  cin >> N ;
  char prev = '\0' ;
  char now = '\0' ;
  while ( N -- ) {
      cin >> now ;
      if ( prev == now ) {
        count += 1 ;
      }
      prev = now ;
  }
  cout << count ;
  return 0;
}
