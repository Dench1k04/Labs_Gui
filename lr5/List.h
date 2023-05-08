#pragma once
#include "Mass.h"
class List
	// Односвязный список (он же List)
{
private:
	Mass *HEAD; // указатель на начало списка
	int size; // размер массива
public:
	List():HEAD(NULL){};
	~List();

	void add(Mass &mass); // функция добавления элемента
	void show(); // функция распечатки списка
	void del(int n); // функци удаления элемента из списка; n = номер элемента
	void pop(int n); // получаем элемент из списка; n = номер элемента
};
