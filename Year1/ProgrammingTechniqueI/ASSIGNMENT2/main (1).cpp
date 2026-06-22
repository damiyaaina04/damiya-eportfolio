#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main ( ) {  
    int counter, age, height, weight, bmr;
    char gender , activitylevel, sentinel;

    counter=15;
    sentinel= 'y';

    do

    {      cout <<"\n----------- BASAL METABOLIC RATE (BMR) CALCULATOR -----------";
           cout << "\n\nPlease enter your age (15-80) : ";
           cin >> age;
           cout << "Please enter your gender (m/f): ";
           cin >> gender;
           cout << "Please enter your height (cm) : ";
           cin >> height;
           cout << "Please enter your weight (kg) : ";
           cin >> weight;
           
           
           if (gender == 'f' || gender == 'F') {
              bmr = (10 * weight) + (6.25 * height) - (5 * age) - 161;
           } else {
              bmr = (10 * weight) + (6.25 * height) - (5 * age) + 5;
           }
           
           cout << "\n\nBMR = " <<bmr <<" calories/day" <<endl;
           
           cout << "\n\nActivity Level\t\t\t\t\t\t\tcalorie" <<endl;
           cout << "a.Sedentary little or no exercise\t\t\t\t1926" <<endl;
           cout << "b.Exercise 1-3 times/week\t\t\t\t\t2207" <<endl;
           cout << "c.Exercise 4-5 times/week\t\t\t\t\t2351" <<endl;
           cout << "d.Daily Exercise or intense exercise 3-4 times/week\t\t2488 " <<endl;
           cout << "e.Intense Exercise 6-7 times/week\t\t\t\t2769 " <<endl;
           cout << "f.Very intense exercise daily, or physical job\t\t\t3055 " <<endl;
           
           
           cout <<"\nExercise : 15-30 minutes of elevated heart rate activity" <<endl;
           cout <<"Intense exercise : 45-120 minutes of elevated heart rate activity" <<endl;
           cout <<"VEry Intense exercise : 2+ hours of elevated heart rate activity" <<endl;
           
           
          counter = counter + 1;
          
          cout << "\n\nDo you want to continue (y/n) :";
          cin >> sentinel;
          

    }while (sentinel == 'y' || sentinel == 'Y');
  
     cout << "thank you :)";
return 0;

}




