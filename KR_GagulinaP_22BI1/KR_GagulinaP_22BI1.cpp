// KR_GagulinaP_22BI1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <array>
#include <cstdlib> 
#include <ctime>
#include "math.h"
#include <fstream>
#include <string>

/*Task3*/
void delete_arraydn1(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) //очистка памяти
	{
		delete[] arr[i];
	}
	arr = 0;
}


int** create(int rows, int cols)
{
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++) //создание массива
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void input(int** arr, int rows, int cols)
{
	srand(time(0));
	for (int i = 0; i < rows; i++) //заполнение массива
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = 1 + rand() % 61; //генерируем случайные числа в каждый элемент массива
		}
	}
}

void print(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++) //вывод массива в консоль
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

// Функция для вычисления суммы элементов на побочной диагонали матрицы
int SumOfSecondaryDiagonal(int** arr, int rows, int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += arr[i][cols - i - 1];  // получаем элементы на побочной диагонали
	}
	return sum;
}


/*Task4*/
struct Account {
	std::string name;
	int id;
	std::string position;
};

const int maxAccount = 100;
Account accounts[maxAccount];
int accountCount = 0;

void addAccount() {
	if (accountCount < maxAccount) {
		std::cout << "Enter name: ";
		std::cin >> accounts[accountCount].name;
		std::cout << "Enter ID: ";
		std::cin >> accounts[accountCount].id;
		std::cout << "Enter position: ";
		std::cin >> accounts[accountCount].position;
		accountCount++;
	}
	else {
		std::cout << "Cannot add more accounts, maximum reached." << std::endl;
	}
}

void removeAccount() {
	int targetId;
	std::cout << "Enter the ID of the employee to remove: ";
	std::cin >> targetId;
	for (int i = 0; i < accountCount; i++) {
		if (accounts[i].id == targetId) {
			for (int j = i; j < accountCount - 1; j++) {
				accounts[j] = accounts[j + 1];
			}
			accountCount--;
			return;
		}
	}
	std::cout << "Employee with ID " << targetId << " not found." << std::endl;
}

void updateAccountInfo() {
	int targetId;
	std::cout << "Enter the ID of the employee to update: ";
	std::cin >> targetId;
	for (int i = 0; i < accountCount; i++) {
		if (accounts[i].id == targetId) {
			std::cout << "Enter new name: ";
			std::cin >> accounts[i].name;
			std::cout << "Enter new position: ";
			std::cin >> accounts[i].position;
			return;
		}
	}
	std::cout << "Employee with ID " << targetId << " not found." << std::endl;
}

void printAllAccount() {
	std::cout << "accounts in the company:" << std::endl;
	for (int i = 0; i < accountCount; i++) {
		std::cout << "Name: " << accounts[i].name << ", ID: " << accounts[i].id << ", Position: " << accounts[i].position << std::endl;
	}
}

int main()
{

	/*Task3*/
	std::cout << "/*Task3*/" << std::endl;
	int rows = 0;
	int cols = 0;
	std::cout << " enter rows count " << std::endl;
	std::cin >> rows;
	std::cout << " enter cols count " << std::endl;
	std::cin >> cols;
	int** arr = create(rows, cols);
	input(arr, rows, cols);
	print(arr, rows, cols);


	// Вычисление суммы элементов на побочной диагонали матрицы
	int sum = SumOfSecondaryDiagonal(arr, rows, cols);
	std::cout << "Summ of elements on pobochnoi diagonal:  " << sum << std::endl;

	delete_arraydn1(arr, rows, cols);


	/*Task4*/
	std::cout << "/*Task4*/" << std::endl;
	
	void (*functionPtr[])() = { addAccount, removeAccount, updateAccountInfo, printAllAccount };

	while (true) {
		std::cout << "Choose an action:" << std::endl;
		std::cout << "1. Add user" << std::endl;
		std::cout << "2. Remove user" << std::endl;
		std::cout << "3. Update account info" << std::endl;
		std::cout << "4. Print all accounts" << std::endl;
		std::cout << "5. Exit" << std::endl;

		int choice;
		std::cin >> choice;

		if (choice == 5) {
			break;
		}
		else if (choice > 0 && choice < 5) {
			(*functionPtr[choice - 1])();
		}
		else {
			std::cout << "Invalid choice, please try again." << std::endl;
		}
	}
	return 0;
}



