#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <vector>
#include <algorithm>



// Базовый интерфейс стратегии
class ArrayStrategy {
public:
    virtual ~ArrayStrategy() = default;
    virtual void execute(std::vector<int>& arr) = 0;
};

class Context
{
	private:
		std::unique_ptr<ArrayStrategy> ArrayStrategy_;
	public:
		explicit Context(std::unique_ptr<ArrayStrategy> &&strategy = {})
			: ArrayStrategy_(std::move(strategy)) {}
		void set_strategy(std::unique_ptr<ArrayStrategy> &&strategy) {
			ArrayStrategy_ = std::move(strategy);
		}
		
		void doSomeBusinessLogic(std::vector<int>& arr) const {
			if (ArrayStrategy_) {
				ArrayStrategy_->execute(arr);
			}
			else std::cout << "Context: Стратегия не определена\n";
		}
};

// Стратегии операций над массивом

class FindSumStrategy : public ArrayStrategy {
public:
	void execute(std::vector<int>& arr) override {
		int temp_sum = 0;
		for(size_t i = 0; i < arr.size(); i++){
			temp_sum += arr[i];
			
		}
		std::cout<<"Сумма элементов равна: "<<temp_sum<<"\n";
	}
};

class FindMinStrategy : public ArrayStrategy {
public:
    void execute(std::vector<int>& arr) override {
        if (arr.empty()) {
            std::cout << "Массив пуст!\n";
            return;
        }
        int min = *std::min_element(arr.begin(), arr.end());
        std::cout << "Минимальное значение: " << min << "\n";
    }
};

class FindMaxStrategy : public ArrayStrategy {
public:
    void execute(std::vector<int>& arr) override {
        if (arr.empty()) {
            std::cout << "Массив пуст!\n";
            return;
        }
        int max = *std::max_element(arr.begin(), arr.end());
        std::cout << "Максимальное значение: " << max << "\n";
    }
};

class SortMinMaxStrategy : public ArrayStrategy {
public:
    void execute(std::vector<int>& arr) override {  // Не const, так как модифицирует массив
        std::sort(arr.begin(), arr.end());
        std::cout << "Отсортировано по возрастанию.\n";
    }
};

class SortMaxMinStrategy : public ArrayStrategy {
public:
    void execute(std::vector<int>& arr) override {
        std::sort(arr.begin(), arr.end(), std::greater<int>());
        std::cout << "Отсортировано по убыванию.\n";
    }
};

#endif // STRATEGIES_H
