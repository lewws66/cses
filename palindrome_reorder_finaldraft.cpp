#include <iostream>
#include <fstream>
#include <sstream>
//#include <stdio.h>
#include <string>
//#include <cmath>
//#include <bits/stdc++.h> 
using namespace std;
int main() {
  char c;
  string cp;   //  comment out if reading file
  cin>>cp;     //  comment out if reading file
  //string cp ="AAAAAAAAAA"; //test_input1
  //string cp ="ABABABABAB"; //test_input2
  //string cp ="CBPPBFCFAA"; //test_input3
  //string cp ="SQAADSDTQ"; //test_input4
  //string cp ="MWNYFUIRUX"; //test_input5
  //string cp ="BBCCCCAAA";
  //string cp ="BBCCAAA";
  //string cp ="BBCCAA";
  long long int l, h, m;
  
// read input from file for now
  /*
  ifstream file("test_input3.txt");
  if (!file.is_open()) {
    cerr << "Error: Could not open file " << "test_input.txt" << endl;
    return 1;
  }

  // Read the file into a string cp
  string cp((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

  //cp.pop_back();   // to get rid of the eof marker.
  file.close();

 // end of read in file 
 */
  // Print the contents of the file to the console
  //cout << strp << endl;  
  l = cp.size();
 // cout<<cp <<" length ="<<l<<endl;
 // To find the 
 //
   if(l%2==0){
     h = l/2;
     m = h;
   }else {
     h = (l+1)/2;
     m = h - 1;
   }
// Code for gathering statistics really starts here
  
  long long int k[l],r[l];
  for(long long int i=0;i<l;i++){
    r[i]=0, k[i] =0; //initialize array for detecting duplicates 
  }
    for(long long int i=0; i<l; i++) {
      if(r[i]==0) {
           for(long long int j=i+1;j<l;j++){
              if(cp[i]==cp[j]){
                   k[i]+=1;
                   r[j]=1;
               }
           }
      } else{
        continue;
      }
    }

// Code for gathering statistics end here

  
// This is the part for analysing and reporting the stats.
/*  Notes:
  k[i] represents the number of repetitions
  of the character in the ith + 1 position from 
  the leftmost of the string. If k[i] = 4 it 
  means that character has a total of 5 occurences
  in the string. When k[i] is 1 or other odd numbers
  it means that character has an even number of 
  occurence and is possible to be mirrored on both 
  sides of the palindrome halves.
  In the case of strings with even number of
  characters (l%2===0), there must be no cases of odd
  occurence of any characters, ie. no k[i] should be 
  even, ie !k[i]%2==0 
  In the case of strings with odd number of 
  characters, notice that there can only be one
  character that appears once or has odd numbered 
  occurences. All the rest must be even occurences
  ie. !k[i]%2==0 should only appear once among all
  all the characters.
  r[i] is the flag used to track the first 
  occurence of a particular character when it
  apppears in the string. r[i] = 0 means at that
  ith position, that character first appears, and 
  all subsequent appearances of that character has
  their r[i] = 1. This flag is very useful as it 
  is also used to terminate loops for searching 
  duplicates.
  When both k[i] = 0 and r[i] = 0 it means that
  character has appeared only once in the whole 
  string. 
  Variables used in this section :
  bool canPal is true when conditions of palindrome
  are satisfied. 
  int r1 is used to check the number of unique
  characters whose occurences are odd numbered, ie 
  when k[i]%2==0&&r[i]==0
  Also take note of the character(s) which have this
  odd occurence, as if it is the only one, it is the
  character to be placed in the middle of palindrome.
  int rc will note which character identified by 
  its position i, needs to be the middle character.
  To summarise simply, canPal=true if and only if 
   when l%2==0 and r1==0, or when l%2==1 and r1==1.
*/ //end of Notes
bool canPal = false;
long long int r1=0, rc=0;
// gather information on how many unique 
// characters have odd occurences
for(long long int i=0;i<l;i++) {
  //print out stats  
  /*
  if(k[i]>0||(k[i]==0&&r[i]==0)){
      printf("char %c : No of reps :%lli  r value : %lli\n",cp[i],k[i],r[i]);
  }
  */
  // search only unique characters
  if(r[i]==0){
    //count the number of characters with odd
    // occurence and note the first(only) case
    if(k[i]%2==0) {
      r1 +=1;
      //note possible middle character
      // invalid if eventually r1>1
      c=cp[i];
      rc = i;
    }
    //This case of single unique character will
    //take precedence over other middle characters
    if(k[i]==0){
      //cout<<"i = "<<i<<" k[i] ="<<k[i]<<endl;
      c=cp[i];
      //cout<<"c = "<<c<<" rc="<<rc<<endl;
      rc = i;
    }
   } //end if for unique characters
 } //end for loop for search
  
//Make judgement on whether input string can 
// be palindrome
//cout<<"r1 = "<<r1<<endl;
//cout<<"l%2 :"<<l%2<<"  r1 = "<<r1<<" c = "<<c<<endl;
if(l%2==0&&r1==0||l%2==1&&r1==1){
  canPal = true;
} else{
  canPal = false;
  cout<<"NO SOLUTION"<<endl;
}
  // if fails test canPal remains false
//

  // older code below to be discarded
  /*
  bool canPal;
  long long int r1 = 0, r2 = 0, sum = 0;
  for(long long int i=0;i<l;i++) {
    if(k[i]>0||(k[i]==0&&r[i]==0)){
      printf("char %c : No of reps :%lli  r value : %lli\n",cp[i],k[i],r[i]);
      }
    if(k[i]==0&&r[i]==0){
      c = cp[i]; // this will be invalid if r1 >1 but otherwise will be the middle character of the palindrome. default c =''
     // printf("%i  k[i] =  %c  c = %c\n", i,ch[i],c);
      r1+=1;   //number of characters with only one occurrence
    } 
    if(k[i]>0&&r[i]==0){
    sum = sum + k[i] +1;
    }
    if(k[i]%2==0&&r[i]==0&&l%2==0){
      r2+=1;  //number of characters with odd occurences when total characters are even
    }
  }
  //sum = sum+r1;
 cout<<"r1 : "<<r1<<endl;
 cout<<"r2 : "<<r2<<endl;
  printf("sum = %i\n",sum);
  if((l%2==0&&r1==1)||r1>1||(l%2==0&&sum%2==1)||r2>0){
    // condition ||l%2==0&&sum%2==1 may be unnecessary
    printf("NO SOLUTION\n");
    canPal = false;
  } else{
    //printf("SOLUTION EXISTS!\n");
    canPal = true;
  }
  */ //end of old code to be discarded
  
// end part for analysing and reporting stats

// This part for manipulation to create palindrome
// May need some of other parts to precede this
// Part for gathering stats should be before this
// Need not do this part if canPal = false
  
if(canPal) {
//printf("first char : %c\n",cp[0]);
//printf("m = %i c = %c\n",m, c);  // check m value
char leftp[m], rightp[m];
//string leftp, rightp;
//printf("%s \n %s\n",leftp[4],rightp[4]);
long long int p=0, q=0;
for(long long int i = 0; i<l; i++){
  //focus search and manipulation only on unique
  //characters
  if(r[i]==0)
     if(k[i]>0) {
  // this will start the process of distributing repeated chars to
    // left and right halves of palindrome
        p = k[i];
        for(long long int j=0;j<(p+1)/2;j++) {
          leftp[j+q]=cp[i], rightp[m-1-j-q] = cp[i];
         // printf("%i : %c, q = %i,  j+q = %i  leftp =%c, m-2-j-q = %i rightp =%c \n",i, cp[i], q, j+q,leftp[j+q],m-1-j-q,rightp[m-1-j-q]);
      }   
     q +=(p+1)/2;
  } // end of process of distributing repeated chars
}
  // cout<<"leftp :"<<leftp<<endl;
  // cout<<"rightp :"<<rightp<<endl;
  //printf("rightp =");
  //for(int i=0;i<m;i++){
  //  printf("%c",rightp[i]);
  //}
 // printf("\n");
 // printf("%c\n",rightp[5]);
  
  // To print out palindrome based on r1=0 means even number of characters in string, else odd number with centre character c which is found from k[i]==0&&r[i]==0

  // This portion is quirky because somehow extra characters were being inserted at end of string array and need to be removed when we convert char to string
/* 
  string lefts(leftp), rights(rightp);
  
    for(long long int i=0;i<(m-lefts.length());i++){
     lefts.pop_back();
  }
  for(long long int i=0;i<(m-rights.length());i++){
     rights.pop_back();
  }
*/ 
  // end of portion quirky
  
  // This portion to print out the final palindrome

  //cout<<"r1 : "<<r1<<endl;
  // Forced to use loops below to get the characters
  // as rightp[i] was giving garbage for i>=m!
  // ie. rightp contained more than necessary
  if(r1==0){
    for(long long int i=0;i<m;i++){
       printf("%c",leftp[i]); 
    }
    for(long long int i=0;i<m;i++){
       printf("%c",rightp[i]); 
    }    
    //printf("%s%c",leftp,rightp[2]);
    //cout<<lefts<<rights;   // if char is used
    //cout<<leftp<<rightp<<endl;
    //printf("even");
 } else {
     for(long long int i=0;i<m;i++){
       printf("%c",leftp[i]); 
     }
     printf("%c",c);
     for(long long int i=0;i<m;i++) {
       printf("%c",rightp[i]); 
     }
    }  
  // printf("%s%c%s",leftp,c,rightp);
  //cout<<lefts<<c<<rights;   //if char is used
   // cout<<leftp<<c<<rightp<<endl;
    //printf("odd");  
   
//  end part for manipulation to create palindrome 
//  which need to do only if canPal is true    
} // end of if(canPal)

 return 0;
}