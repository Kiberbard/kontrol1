#include "kontrol1.h"


int main(){
	std::cout<< "\nВведите количество элементов массива: ";
	int size = 0;
	std::cin >> size;
	if(size <= 0){
		return -1;
			//continue;
	}
	int *arr = new int[size];

	
	
	
	if(noRandomMass(&arr[0], size))
		writeArray(&arr[0], size);
	
	Massive mass;
	mass.setParams(&arr[0], size);
	std::cout<<"Введен следующий:\n";
	mass.printArr();

	//операции над массивом
	std::cout<< "\nКакую операцию требуется выполнить:\n";
	std::cout<< "Поиск минимального 1\nПоиск максимального 2\n";
	std::cout<< "Поиск суммы всех элементов 3\nСортировать в порядке возрастания 4\n";
	std::cout<< "Сортировать в порядке убывания 5\nВывести результирующий массив 6\n";
	std::cout<< "Выйти 0\n";
	
	int operation;
	while(true){
		std::cout<< "\nВводить номер операции сюда: ";
		std::cin>>operation;
		if( operation <  0 || operation > 6){
			std::cout<<"\nВы вышли за диапазон. Программа завершена\n";
			return 0;
			//continue;
		}
	
		switch(operation){
			case 0:
				return 0;
				break;
			case 1:
				std::cout<<"минимальное = "<<mass.minArray()<<"\n";
				break;
			case 2:
				std::cout<<"максимальное = "<<mass.maxArray()<<"\n";
				break;
			case 3:
				std::cout<<"сумма = "<<mass.sumArray()<<"\n";
				break;
			case 4:
				mass.sortMinMax();
				mass.printArr();
				break;
			case 5:
				mass.sortMaxMin();
				mass.printArr();
				break;
			case 6:
				
				mass.printArr();
				break;
			default:
				return 0;
				break;
		}
	}	
		
	delete [] arr;
	mass.delMass();
	
	

	
	
	return 0;
}
