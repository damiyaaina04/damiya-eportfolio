// Programming Technique II (SECSJ1023)
// Semester 2, 2023/2024

// Final Exam (Practical - Question 2)

// Student's Name:Damiya Aina binti Basir Abd Shammad
// Matric Number:A23CS0220

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//i. FoodItem class
class FoodItem{
private:
      string name;
      double price;
      int quantity;

public:
FoodItem(string n = "", double p = 0.0, int q = 0){
    name = n;
    price = p;
    quantity = q;
}

virtual void dispDetails() const = 0;
virtual double calPrice() const{
    return 0;
}

double calPrice() const {
    return (price*quantity);
}
};

//ii. Pizza class inherit from FoodItem class
class Pizza : public FoodItem{
    private:
        string size;

    public:
    Pizza(string s) : FoodItem(string n, double p, int q){
    }  

void dispDetails(string n, FoodItem f1, int q, string s){
    cout <<"Pizza - " <<n <<endl;
    cout <<"Price : " <<f1.calPrice() <<endl;
    cout <<"Quantity : " <<q <<endl;
    cout <<"Size : " <<s <<endl;
}
};

//Burger class inherit from FoodItem class
class Burger : public FoodItem{
     private:
        bool isDoublePatty;

     public:
     Burger(bool i) : FoodItem(string n, double p , int q){
     }

     void dispDetails(string n, FoodItem f2,int q,  bool i ){
        cout <<"Burger - " <<n <<endl;
        cout <<"Price : " <<f2.calPrice() <<endl;
        cout <<"Quantity : " <<q <<endl;
        cout <<"Double Patty? :" <<i <<endl;
     }

     double calPrice() const{
        if (bool = 1){
            double totPrice = (price * quantity) + 3.8;
            return totPrice;
        } else {
            return f2.calPrice();
        }
     }
};

class Order{
     public:
        void addItem(FoodItem *food){
         }

        void dispOrder(Burger b1, FoodItem f3){
            b1.dispDetails();
            f3.dispDetails();
        }
};

int main(){
       Order *o;

       FoodItem *list[int n] = {};

       for (int i=0 ; i < n ; i++){
        
       }



}

