#include <iostream>
#include <string>
//#include <windows.h> //для проверки решения в ОС Windows

class Counter {

public:
	Counter(int x) {counter = x;}
	Counter() {counter = 1;}

	void print_result() {std::cout << counter << std::endl;}

	bool operations_counter(std::string str) {

		if(str == "+") {
			increase_counter();
			return true;
		}
		else if(str == "-") {
			decrease_counter(str);
			return true;
		}
		else if(str == "=") {
			print_result();
			return true;
		}
		else if(str == "x" || str == "х") {
			std::cout << "До свидания!" << std::endl;
			return false;
		}
		else {
			std::cout << "Введено неверное значение!" << std::endl;
			return false;
		}
	}

private:
	int counter;

	int increase_counter() {
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
	std::string str;
	bool b = true;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> str;

		if (str == "да") {
			Counter counter(x);

		    std::cout << "Введите начальное значение счётчика: ";
		    std::cin >> x;

			while (b == true) {
				std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
				std::cin >> str;
				b = counter.operations_counter(str);
			}
		}
		else if (str == "нет") {
		    Counter counter;

		    std::cout << "Начальное значение счётчика равно: ";
			counter.print_result();

			while (b == true) {
				std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
				std::cin >> str;

				b = counter.operations_counter(str);
			}
	    }
		else {
		    std::cout << "Введено неверное значение!" << std::endl;

		}
	return 0;
}