#ifndef KONTROL1_H
#define KONTROL1_H
 
#include <iostream>
#include <cstdlib>
#include <ctime>
bool noRandomMass(int *array_in, size_t size_in);
void writeArray(int *array_in, size_t size_in);


class Massive{
	public:
		void delMass(){delete [] array;}
		void setParams(int *array_in, size_t size_in);//сохранение параметров в приватные поля
		int sumArray();//сумма значений элементов массива
		int maxArray();//максимальный элемент массива
		int minArray();//минимальный элемент массива
		int sortMinMax();//сортировка возрастания 
		int sortMaxMin();//сортировка убывания
		void printArr();//вывод массива
		
		
	private:
	
	int *array = new int[10];
	
	size_t size;
};
	
 
 #endif /* KONTROL1_H */

