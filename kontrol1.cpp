#include "kontrol1.h"
#include "strategies.h"
#include <cstdlib>
#include <ctime>

void writeArray(std::vector<int>& array_in, size_t size_in) {
    array_in.resize(size_in);
    for (size_t i = 0; i < size_in; i++) {
        std::cout << "\nВведите [" << i << "] элемент массива: ";
        std::cin >> array_in[i];
    }
}

bool noRandomMass(std::vector<int>& array_in, size_t size_in) {
    std::cout << "\nЗаполнить массив автоматически? (y/n): ";
    char answer;
    std::cin >> answer;
    int a = -50;
    int b = 200;

    if (answer == 'y' || answer == 'Y') {
        srand(time(0));
        array_in.resize(size_in);
        for (size_t i = 0; i < size_in; i++) {
            array_in[i] = rand() % (b - a + 1) + a;
        }
        return false;
    }
    return true;
}

void Massive::setParams(const std::vector<int>& array_in) {
    data = array_in; // Копируем данные
}

void Massive::printArr() const {
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << "\n[" << i << "] элемент: " << data[i];
    }
}

int clientCode(){
	std::cout << "\nВведите количество элементов массива: ";
    int size = 0;
    std::cin >> size;
    if (size <= 0) return -1;

    std::vector<int> arr;
    if (noRandomMass(arr, size)) {
        writeArray(arr, size);
    }

    Massive mass;
    mass.setParams(arr);
    std::cout << "Введен следующий массив:\n";
    mass.printArr();

    
	//инициализация контекста
	Context context(std::make_unique<FindMinStrategy>());
	
	
    std::cout << "\nКакую операцию требуется выполнить:\n";
    std::cout << "1. Поиск минимального\n2. Поиск максимального\n3. Поиск суммы\n";
    std::cout << "4. Сортировать по возрастанию\n5. Сортировать по убыванию\n";
    std::cout << "6. Вывести массив\n0. Выйти\n";

    int operation;
    while (true) {
        std::cout << "\nВведите номер операции: ";
        std::cin >> operation;
		
		switch (operation) {
            case 0: return 0;
            case 1: context.set_strategy(std::make_unique<FindMinStrategy>()); context.doSomeBusinessLogic(mass.getData()); break;
            case 2: context.set_strategy(std::make_unique<FindMaxStrategy>()); context.doSomeBusinessLogic(mass.getData()); break;
            case 3: context.set_strategy(std::make_unique<FindSumStrategy>()); context.doSomeBusinessLogic(mass.getData()); break;
            case 4: context.set_strategy(std::make_unique<SortMinMaxStrategy>()); context.doSomeBusinessLogic(mass.getData()); break;
            case 5: context.set_strategy(std::make_unique<SortMaxMinStrategy>()); context.doSomeBusinessLogic(mass.getData()); break;
            case 6: mass.printArr(); break;
            default: std::cout << "Неверная операция!\n"; break;
        }
    }
}
