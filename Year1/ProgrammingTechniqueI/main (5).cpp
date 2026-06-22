////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 2
//// Name:Damiya Aina binti Basir Abd Shammad
//// Matric No: A23CS0220
//// Date / Day: 4/1/2024 (Thursday)
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
//task 6// 
//function prototype//
float calculateLateFees(int , float);
void displayMenu(int);
void displayLibraryInfo();
void getUserInput(int);


//task 1//
float calculateLateFees( int numDays , float lateFee){
    if (numDays > 0 && numDays < 8){
         lateFee = 0.5 * numDays;
    } else if(numDays > 7 && numDays < 15){
         lateFee = 1.0 * numDays;
    } else{
         lateFee = 2.00 * numDays;
    }
return lateFee;
}

//task 2//
void displayMenu(){
  cout <<"1. Calculate Late Fees\n";
  cout <<"2. Library Information\n";
  cout <<"3. quit\n";
}

//task 3//
void displayLibraryInfo(){
    cout <<"*************LIBRARY INFORMTAION**************\n";
    cout <<"Library Name : UTM Library\n";
    cout <<"Address : Skudai , Johor\n";
    cout <<"Contact : (123) 456 7890";
}

//task 4//
void getUserInput (int numDays){
    float lateFee;
    cout <<"Please enter the number of days the book is overdue : ";
    cin >> numDays;
    lateFee = calculateLateFees(numDays, lateFee);
    cout << "Late fees : "<<lateFee<<endl;
}

//task 5//
int main (){
    int i=0, counter = 0, menu, numDays;
    char sentinel;

    do{
        cout <<"\n*********LIBRARY BOOK CHECKOUT SYSTEM*********\n";
        displayMenu();
        cout <<"Please enter your choice (1-3) :";
        cin >> menu;
        
        if (menu == 1){
            getUserInput(numDays);
        } else if ( menu == 2){
            displayLibraryInfo();
        } else if (menu == 3){
            cout <<endl<<"quit"; break;
        }
     i++;
    }  while(menu < 4);
 return 0;
 }
 


