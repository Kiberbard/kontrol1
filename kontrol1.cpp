#include "kontrol1.h"


void writeArray(int *array_in, size_t size_in){
	for(size_t i = 0; i < size_in; i++){
		std::cout<< "\nВведите ["<<i<<"] элемент массива: ";
		std::cin>>array_in[i];
	}
}

bool noRandomMass(int *array_in, size_t size_in){
	std::cout<< "\nЗаполнить массив автоматически? (y/n): ";
	char answer;
	std::cin>>answer;
	int a = -50;
	int b = 200;
	if(answer == 'y' || answer == 'Y'){
		srand(time(0));
		for(size_t i = 0; i < size_in; i++){
			
			array_in[i] = rand() % (b - a + 1) + a;
		}
		
		return false;
		
	}
	return true;		
		
}

void Massive::setParams(int *array_in, size_t size_in){
	int *arr2 = new int[size_in];
	for(size_t i = 0; i < size_in; i++){
		arr2[i] = array_in[i];
	}
	delete[] array;
	array = arr2;
	size = size_in;
}

int Massive::sumArray(){
	int temp_sum = 0;
	for(size_t i = 0; i < size; i++){
		temp_sum += array[i];
		
	}
	return temp_sum;
}

int Massive::maxArray(){
	int temp_max = array[0];
	for(size_t i = 1; i < size; i++){
		if(array[i] >= temp_max){
			temp_max = array[i];
		}
		
	}
	return temp_max;
}

int Massive::minArray(){
	int temp_min = array[0];
	for(size_t i = 1; i < size; i++){
		if(array[i] <= temp_min){
			temp_min = array[i];
		}
	}
	return temp_min;
}

int Massive::sortMinMax(){//сортировка возрастания
	int temp;
	for(size_t i =0; i < size -1; i++){
		for(size_t j = 0; j < size - i - 1; j++){
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return 0;
}

int Massive::sortMaxMin(){//сортировка убывания
	int temp;
	for(size_t i =0; i < size -1; i++){
		for(size_t j = 0; j < size - i - 1; j++){
			if(array[j] < array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return 0;
}

void Massive::printArr(){
	for(size_t i = 0; i < size; i++){
		std::cout<<"\n["<<i<<"] элемент: "<<array[i];
	}
}


	





