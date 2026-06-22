//Name : Damiya Aina binti Basir Abd Shammad//
//Matric Number : A23CS0220//
//Due Date : 21/12/2023//


#include <iostream>
using namespace std;

//task 1//
 void dispStatus(int NumActCase){
     if (NumActCase > 40){
         cout <<"Status : Red zone"<<endl;
     } else if (NumActCase >= 21 && NumActCase <= 40){
         cout <<"Status : Orange zone"<<endl;
     } else if (NumActCase >= 1 && NumActCase <= 20){
         cout <<"Status : Yellow zone"<<endl;
     } else {
         cout <<"Status : Green zone"<<endl;
     }
     
 }
 
//task 2//
  void getInput(int &NumTotCases, int &NumNewCase, int &NumTotDeath, int &NumTotRecovered){
      cout <<"Please enter the number of total cases : ";
      cin >>NumTotCases;
      cout <<"Please enter the number of new cases : ";
      cin >>NumNewCase;
      cout <<"Please enter the number of total death : ";
      cin >>NumTotDeath;
      cout <<"Please enter the number of total recovered : ";
      cin >>NumTotRecovered;
  }
  
//task 3//
 void dispOutput(int NumActCase){
     dispStatus(NumActCase);
 }
  
//task 4//
 float calcAverage(int &numStates, int &TotNumActCases){
     
     return static_cast<float>(TotNumActCases) / numStates;
     
 }
 
 //task 5//
 int main (){
     string stateName;
     int NumActCase, NumTotRecovered, NumTotCases, NumNewCase, NumTotDeath , TotActCases, TotNumActCases = 0;
     char sentinel;
     int numStates = 0, highNum = 0;
     float average;
     
     sentinel = 'y';
     
     while (sentinel == 'y'){
         cout <<"\n--------------MINISTRY OF HEALTH---------------"<<endl;
         cout <<"------Number of Active Cases of COVID 19-------\n"<<endl;
         cout <<"Please enter the state name : ";
         cin >> stateName;
         numStates = numStates + 1;

         getInput( NumTotCases, NumNewCase, NumTotDeath, NumTotRecovered);
        
         NumActCase = NumTotCases + NumNewCase - NumTotDeath - NumTotRecovered;
         TotNumActCases = TotNumActCases + NumActCase; 
         if (NumActCase > highNum){
             highNum = NumActCase;
         }
        
         cout <<"Active cases : "<<NumActCase <<endl;;
         dispOutput( NumActCase);
         cout <<"\nDo you want to continue? (y/n) : ";
         cin >>sentinel;
         
     }
     
    average = calcAverage(numStates,TotNumActCases);
    cout <<"\n--------------ACTIVE CASES---------------"<<endl;
    cout <<"Total Active Cases : "<<TotNumActCases<<endl;
    cout <<"Highest number of active cases : "<<highNum<<endl;
    cout <<"Average for "<<numStates<<" states : "<<average ;
 }
 

