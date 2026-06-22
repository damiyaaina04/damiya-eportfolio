//Name : Damiya Aina binti Basir Abd Shammad//
//Matric Number : A23CS0220//
//Date : 6 November 2023//
//SET 1//


#include <iostream>
using namespace std;
int main (){
    int num , digit , sum=0;
    float sum2;
    
    cout << "Enter an integer number : ";
    cin >> num;
    
    do {
        digit = num % 10;
        num = num / 10;
        cout << digit;
        
        if (num != 0){
            cout << " + ";
        }
     sum = sum + digit;
    } while (num != 0);
 
  cout <<" = " <<sum;
 
   if (sum % 3 == 0 && sum % 4 == 0 && sum % 5 != 0) {
     cout <<"\n" <<sum <<" is the multiple of 3 and 4";
 } else if (sum % 3 == 0 && sum % 4 != 0 && sum % 5 == 0) {
     cout <<"\n" <<sum <<" is the multiple of 3 and 5";
 } else if (sum % 3 != 0 && sum % 4 == 0 && sum % 5 == 0) {
     cout <<"\n" <<sum <<" is the multiple of 4 and 5";
 } else if (sum % 3 == 0 && sum % 4 == 0 && sum % 5 == 0) {
     cout <<"\n" <<sum <<" is the multiple of 3 , 4 and 5";
 } else if (sum % 3 == 0 && sum % 4 != 0 && sum % 5 != 0) {
     cout << "\n" <<sum <<" is the multple of 3";
 } else if (sum % 3 != 0 && sum % 4 == 0 && sum % 5 != 0) {
     cout <<"\n" <<sum <<" is the multiple of 4";
 } else if (sum % 3 != 0 && sum % 4 != 0 && sum % 5 == 0) {
     cout <<"\n" <<sum <<" is the multiple of 5";
 } else {
     cout <<"\n" <<sum <<" is not multiple of 3 , 4 and 5";
 }
     
 
 return 0;
}





//SET 2//

#include <iostream>
using namespace std;
int main () {
    int sum , num , digit;
    
    cout <<"Enter an integer number : ";
    cin >>num;
    
    for (num == num ; num != 0 ; sum = sum + digit) {
        digit = num % 10;
        num = num / 10;
        cout << digit;
        
        if (num != 0){
            cout <<" + ";
        }
    }
    
  cout <<" = " <<sum;
  
  if (sum % 2 == 0 && sum % 4 != 0 && sum % 5 != 0 ) {
      cout <<"\n" <<sum <<" is an even number";
  } else if ( sum % 2 != 0 && sum % 4 != 0 && sum % 5 != 0) {
      cout <<"\n" <<sum <<" is an odd number";
  } else if (sum % 2 == 0 && sum % 4 == 0 && sum % 5 != 0) {
      cout <<"\n" <<sum <<" is an even number and multiple of 4";
  } else if (sum % 2 == 0 && sum % 4 != 0 && sum % 5 == 0) {
      cout <<"\n" <<sum <<" is an even number and multiple of 5";
  } else if (sum % 2 != 0 && sum % 4 == 0 && sum % 5 != 0) {
      cout <<"\n" <<sum <<" is an odd number and multiple of 4";
  } else if (sum % 2 != 0 && sum % 4 != 0 && sum % 5 == 0) {
      cout <<"\n" <<sum <<" is an odd number and multiple of 5";
  } else if (sum % 2 == 0 && sum % 4 == 0 && sum % 5 == 0) {
      cout <<"\n" <<sum <<" is an even number and multiple of 4 and 5"; 
  } else {
      cout <<"\n" <<sum <<" is not the multiple of 4 and 5";
  }
 
return 0;   
}



