#include <stdlib.h> // для system("pause");
#include <locale.h> // для русской консоли
#include "List.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

cout << "Лабораторная работа №5\n\n";

List list; // объявили объект список;
int n; // размер массива
int k; // число массивов

cout << "Введите количество вводимых массивов: ";
cin >> k;

cout << "Введите размеры массивов: ";
cin >> n;
Mass massiv(n); // создаем объект массив

for (int i = 0; i < k; i++)
{
	cin >> massiv; // вводим элементы массива
	list.add(massiv); // заносим их в список
}

cout << endl;
list.show(); // выводим наш список элементов

	cout << "Введите номер элемента который нужно извлечь: \n";
	cin >> n;
	list.pop(n);

	cout << "Введите номер элемента который нужно удалить: \n";
	cin >> n;
	list.del(n);
	cout << endl;
	list.show();

	system("pause");
	return 0;
}