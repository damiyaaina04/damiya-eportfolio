#include <iostream>
using namespace std;

int Sifir (int num, int limit, int i){
    if (i>limit)
        return 0;
    else {
        cout << num << "x" << i << "=" << num*i << endl;
        return Sifir (num, limit, i+1);
}
}

int main (){
    int num = 2;
    int limit = 12;
    int x = Sifir (num, limit, 1);
    
    return 0;
}