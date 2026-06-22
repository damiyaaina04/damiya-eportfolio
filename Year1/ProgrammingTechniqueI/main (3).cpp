////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 1
//// Name:Damiya Aina binti Basir Abd Shammad
//// Matric No: A23CS0220
//// Date / Day:4/1/2024 (Thursday)
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// function prototypes
void price_original(float);
void choose_Option(char);
void price_afterTax(float, char); 

// start main function
int main() 
{
    char category;
    float bookPrice;
    float price = 0; // should > 0
    char option; // A -> Encyclopedia
                  // B -> Textbook
                  // C -> Novel
                  // D -> Magazine
    choose_Option(category); 
    price_original(bookPrice);
    cout << "Original book price before tax = RM " << price << "\n\n";
    price_afterTax(price, option);
    cout << "Total book price after tax = RM " << price << '\n';
    return 0;
}

// start new user-defined functions
void price_original(float bookPrice) 
{ 
    cout << "Please insert the book price (RM): ";
    cin >> bookPrice;
    }
}


void choose_Option(char category) 
{ 
   cout << "Please choose the book category: \n";
   cout << "A -> Encyclopedia\n";
   cout << "B -> Textbook\n";
   cout << "C -> Novel\n";
   cout << "D -> Magazine\n";
   cout << "Book category (A,B,C,D): ";
   cin >> category;
   cout << "\n";

}

// tax is based on book categories as follows:
// A -> Encyclopedia => 3%
// B -> Textbook => 2%
// C -> Novel => 1%
// D -> Magazine => 0.5%
void price_afterTax(float bookPrice, char category) 
{ 
    float tax;
    switch (category) 
	{
        case 'A': tax = bookPrice *  0.03 ; 
           break; 
        case 'B': tax = bookPrice * 0.02 ; 
           break; 
        case 'C': tax = bookPrice * 0.01 ; 
           break;
		case 'D': tax = bookPrice * 0.005;
		   break;
		default : "Error";
    }
    cout << "Tax price = RM " << tax << "\n";
}

