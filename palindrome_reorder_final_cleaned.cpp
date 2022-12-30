#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstring>
//#include <cmath>
//#include <bits/stdc++.h> 
using namespace std;
int main() {
  char c;
  char cp[1000000]; //try scanf
  scanf("%s",cp);   //try scanf
  //string cp;   //  comment out if reading file or scanf
  //cin>>cp;     //  comment out if reading file or scanf
  //string cp ="AAAAAAAAAA"; //test_input1
  //string cp ="ABABABABAB"; //test_input2
  //string cp ="CBPPBFCFAA"; //test_input3
  //string cp ="SQAADSDTQ"; //test_input4
  //string cp ="MWNYFUIRUX"; //test_input5
  //string cp ="BBCCCCAAA";
  //string cp ="BBCCAAA";
  //string cp ="BBCCAA";
  int l, h, m;
  //printf("%s \n",cp);
  //l = cp.length();
  l = strlen(cp); //use this if cp is char array and scanf used
  //printf("%i\n",l);
   if(l%2==0){
     h = l/2;
     m = h;
   }else {
     h = (l+1)/2;
     m = h - 1;
   }
// Code for gathering statistics really starts here
  int k[l],r[l];
  for(int i=0;i<l;i++){
    r[i]=0, k[i] =0; //initialize array for detecting duplicates 
  }
    for(int i=0; i<l; i++) {
      if(r[i]==0) {
           for(int j=i+1;j<l;j++){
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
// refer notes.txt
bool canPal = false;
int r1=0, rc=0;
// gather information on how many unique 
// characters have odd occurences
for(int i=0;i<l;i++) {
  //print out stats  
  /*
  if(k[i]>0||(k[i]==0&&r[i]==0)){
      printf("char %c : No of reps :%lli  r value : %lli\n",cp[i],k[i],r[i]);
  }
  */
  // search only unique characters
  if(r[i]==0){
    if(k[i]%2==0) {
      r1 +=1;
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
// end part for analysing and reporting stats

if(canPal) {
//printf("first char : %c\n",cp[0]);
//printf("m = %i c = %c\n",m, c);  // check m value
char leftp[m], rightp[m];
//string leftp, rightp;
//printf("%s \n %s\n",leftp[4],rightp[4]);
int p=0, q=0;
for(int i = 0; i<l; i++){
  //focus search and manipulation only on unique
  //characters
  if(r[i]==0)
     if(k[i]>0) {
  // this will start the process of distributing repeated chars to
    // left and right halves of palindrome
        p = k[i];
        for(int j=0;j<(p+1)/2;j++) {
          leftp[j+q]=cp[i], rightp[m-1-j-q] = cp[i];
         // printf("%i : %c, q = %i,  j+q = %i  leftp =%c, m-2-j-q = %i rightp =%c \n",i, cp[i], q, j+q,leftp[j+q],m-1-j-q,rightp[m-1-j-q]);
      }   
     q +=(p+1)/2;
  } 
}
  string lefts(leftp), rights(rightp);
  
    for(int i=0;i<(m-lefts.length());i++){
     lefts.pop_back();
  }
  for(int i=0;i<(m-rights.length());i++){
     rights.pop_back();
  }
  if(r1==0){
    for(int i=0;i<m;i++){
       printf("%c",leftp[i]); 
    }
    for(int i=0;i<m;i++){
       printf("%c",rightp[i]); 
    }    
 } else {
     for(int i=0;i<m;i++){
       printf("%c",leftp[i]); 
     }
     printf("%c",c);
     for(int i=0;i<m;i++) {
       printf("%c",rightp[i]); 
     }
    }  
} // end of if(canPal)

 return 0;
}