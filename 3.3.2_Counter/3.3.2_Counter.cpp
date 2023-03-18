#include <iostream>
#include <string>
//#include <windows.h> //для проверки решения в ОС Windows

class Counter {

public:
	Counter(int x) { counter = x; }
	Counter() { counter = 1; }

	void print_result() {std::cout << counter << std::endl;}

	void operations_counter(Counter counter, bool *b) {
		std::string str;
		while(*b == true) {
			std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
			std::cin >> str;

			if(str == "+") {
				counter.increase_counter(str);
				*b = true;
			}
			else if(str == "-") {
				counter.decrease_counter(str);
				*b = true;
			}
			else if(str == "=") {
				counter.print_result();
			}
			else if(str == "x" || str == "х") {
				std::cout << "До свидания!" << std::endl;
				*b = false;
			}
			else {
				std::cout << "Введено неверное значение!" << std::endl;
				*b = false;
			}
		}
	}

private:
	int counter;

	int increase_counter(std::string str) {
		++counter;
		return counter;
	}

	int decrease_counter(std::string str) {
		--counter;
		return counter;
	}
};

int main(int arrgc, char** argv) {
	//SetConsoleCP(1251); // для проверки решения в ОС Windows
	//SetConsoleOutputCP(1251); // для проверки решения в ОС Windows
	setlocale(LC_ALL, "RUSSIAN");

	int x = 0;
	bool b = true;
	std::string str;

	while (b == true) {
		std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
		std::cin >> str;

		if (str == "да") {

			std::cout << "Введите начальное значение счётчика: ";
			std::cin >> x;
			Counter counter(x);

			counter.operations_counter(counter, &b);
		}
		else if (str == "нет") {
			Counter counter;
			std::cout << "Начальное значение счётчика равно: ";
			counter.print_result();

			counter.operations_counter(counter, &b);
		}
		else {
			std::cout << "Введено неверное значение!" << std::endl;
		}
	}
	return 0;
}