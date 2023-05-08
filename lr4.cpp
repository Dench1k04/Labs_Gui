#include <iostream>
 
using namespace std;
 
int main (){
int n, a, c=0;
int *mas = new int [n];
cout<<"Введите n: ";
cin >> n;
 
for(int i=0; i<n; i++){
    cout<<"Введите значение a"<< i << " :";
    cin >> a;
    mas[i] = a;
}
 
for(int i=0; i<n; i++){
    if (mas[i] < 0){
        c += mas[i];
    }
}
cout <<"Сумма отрицательных чисел: "<< c <<endl;
delete [] mas;
}
