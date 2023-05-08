#include "stdafx.h"
#include "List.h"


List::~List()
{
	while (HEAD != NULL) // Пока по адресу хоть что-то есть
	{
		Mass *temp = HEAD -> Next; // Запишем указатель на адрес следующего элемента структуры
		delete HEAD; // Освобождаем память по месту начала списка
		HEAD = temp; // Меняем адрес начала списка
	}
}

void List::add(Mass &mass)
{
	Mass *temp = new Mass(); // Выделяем память под новую структуру
	temp->Next = HEAD; // меняем адрес начала списка 
	size++; // увеличиваем переменную хранящую размер на 1

	temp->sz = mass.sz; // копируем размер массива в созданную переменную
	for (int i = 0; i < mass.sz; i++) // копируем элементы массива
		temp->buf[i] = mass.buf[i];

	HEAD = temp; // меняем адрес начала списка
}

void List::show()
{
	Mass *temp = HEAD; // объявляем указатель и пусть он указывает на начало списка
	int i = 0;

	while (temp != NULL) // пока есть на что указывать
	{
		cout << i << " массив: ";
		for (int i = 0; i < temp->sz; i++)
		{
			cout << temp->buf[i] << " ";
		}
		cout << endl;
		temp = temp->Next;
		i++;
	}
}

void List::pop(int n)
{
	Mass *temp = HEAD; // обращаемся к началу списка

	if ((HEAD != NULL) && (n <= size) && (n>=0)) // если по этому номеру что-то лежит и этот элемент внутри списка
	{
		for (int i = 0; i < n; i++)
			temp = temp->Next;
		cout << *temp;
	}
}

void List::del(int n)
{
	Mass *temp = NULL, *b; 
	int i = 0; // ??
	if ((n > size) || (n < 0))
	{
		cout << "Такого элемента нет";
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
			temp = temp->Next;
	}

}