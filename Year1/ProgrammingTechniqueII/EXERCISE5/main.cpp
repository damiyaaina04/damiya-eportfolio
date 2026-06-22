// ? EXERCISE 5: POLYMORPHISM

// Programming Technique II
// Semester 2, 2021/2022

// Section: 01
// Member 1's Name: Nurul Adriana binti Kamal Jefri   Location: UTM Johor(i.e. where are you currently located)
// Member 2's Name: Damiya Aina binti Basir Abd Shammad  Location: Kota Bharu , Kelantan

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  21/6/24        8.00 pm      10.00 pm            120 minutes
//  22/6/24        8.00 pm      10.00 pm           120 minutes

// Video link:
//  https://drive.google.com/drive/folders/1laUEwVP3dOTogahNuBY0ru_HcZK9OX_x?usp=sharing



#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "shape.hpp"
#include "circle.hpp"
#include "rect.hpp"

using namespace std;

// Max size of the list
#define COUNT 5

int main()
{
    int width = getmaxwidth();
    int height = getmaxheight();
    initwindow(width, height, "Exercise 5");

    // Initialize random seed
    srand(time(NULL));

    Shape* shapes[COUNT];
    for (int i = 0; i < COUNT; ++i) {
        int type = rand() % 2; // 0 for Circle, 1 for Rect
        int x = rand() % width;
        int y = rand() % height;
        if (type == 0) {
            shapes[i] = new Circle(x, y, rand() % 50 + 10);
        } else {
            shapes[i] = new Rect(x, y, rand() % 100 + 20, rand() % 100 + 20);
        }
    }

    Shape* selectedShape = nullptr;
    char ch = 0;

    while (ch != 27) // 27 is ESC key
    {
        if (kbhit()) {
            ch = getch();
            switch (toupper(ch)) {
            case '+':
                if (selectedShape) selectedShape->resize(5);
                break;
            case '-':
                if (selectedShape) selectedShape->resize(-5);
                break;
            case KEY_LEFT:
                if (selectedShape) selectedShape->setLocation(selectedShape->getX() - 10, selectedShape->getY());
                break;
            case KEY_RIGHT:
                if (selectedShape) selectedShape->setLocation(selectedShape->getX() + 10, selectedShape->getY());
                break;
            case KEY_UP:
                if (selectedShape) selectedShape->setLocation(selectedShape->getX(), selectedShape->getY() - 10);
                break;
            case KEY_DOWN:
                if (selectedShape) selectedShape->setLocation(selectedShape->getX(), selectedShape->getY() + 10);
                break;
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            for (int i = 0; i < COUNT; ++i) {
                if (dynamic_cast<Circle*>(shapes[i])) {
                    Circle* c = dynamic_cast<Circle*>(shapes[i]);
                    if (sqrt(pow(mx - c->getX(), 2) + pow(my - c->getY(), 2)) <= c->getRadius()) {
                        if (selectedShape == c) {
                            selectedShape->setSelected(false);
                            selectedShape = nullptr;
                        } else {
                            if (selectedShape) selectedShape->setSelected(false);
                            selectedShape = c;
                            selectedShape->setSelected(true);
                        }
                        break;
                    }
                } else if (dynamic_cast<Rect*>(shapes[i])) {
                    Rect* r = dynamic_cast<Rect*>(shapes[i]);
                    if (mx >= r->getX() - r->getWidth() / 2 && mx <= r->getX() + r->getWidth() / 2 &&
                        my >= r->getY() - r->getHeight() / 2 && my <= r->getY() + r->getHeight() / 2) {
                        if (selectedShape == r) {
                            selectedShape->setSelected(false);
                            selectedShape = nullptr;
                        } else {
                            if (selectedShape) selectedShape->setSelected(false);
                            selectedShape = r;
                            selectedShape->setSelected(true);
                        }
                        break;
                    }
                }
            }
        }

        cleardevice();
        for (int i = 0; i < COUNT; ++i) {
            if (shapes[i]->isSelected()) {
                setcolor(YELLOW);
            } else {
                setcolor(WHITE);
            }
            shapes[i]->draw();
        }
        delay(30);
    }

    for (int i = 0; i < COUNT; ++i) {
        delete shapes[i];
    }

    closegraph();
    return 0;
}

