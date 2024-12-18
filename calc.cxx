#include <iostream>
#include <cmath>

void Plus(int firstNumber, int secondNumber)
{
	std::cout << "\n"
			  << firstNumber << " + " << secondNumber << " = " << firstNumber + secondNumber << "\n";
}

void Minus(int firstNumber, int secondNumber)
{
	std::cout << "\n"
			  << firstNumber << " - " << secondNumber << " = " << firstNumber - secondNumber << "\n";
}

void Multiply(int firstNumber, int secondNumber)
{
	std::cout << "\n"
			  << firstNumber << " × " << secondNumber << " = " << firstNumber * secondNumber << "\n";
}

void Division(int firstNumber, int secondNumber)
{
	if (secondNumber == 0)
	{
		std::cout << "Sorry, you can't divide by 0.\n";
	}
	else
	{
		std::cout << "\n"
				  << firstNumber << " ÷ " << secondNumber << " = " << firstNumber / secondNumber << "\n";
	}
}

void Power(int firstNumber, int secondNumber)
{
	std::cout << "\n"
			  << firstNumber << " ^ " << secondNumber << " = " << pow(firstNumber, secondNumber) << "\n";
}

int main()
{
	int op = 0;
	int firstNumber, secondNumber;

	std::cout << "\t\t\tA Simple Calculator"
			  << "\n";
	std::cout << "\nEnter two numbers and choose the operation type to perform:" << "\n";

	std::cout << "First Number: ";
	std::cin >> firstNumber;

	std::cout << "Second Number: ";
	std::cin >> secondNumber;

	std::cout << "\nChoose The Operation Type To Perform: "
			  << "\n\n";
	std::cout << "[1]  +"
			  << "\n";
	std::cout << "[2]  -"
			  << "\n";
	std::cout << "[3]  ×"
			  << "\n";
	std::cout << "[4]  ÷"
			  << "\n";
	std::cout << "[5]  ^"
			  << "\n";

	std::cout << "\nOperation Type: ";
	std::cin >> op;

	switch (op)
	{
	case 1:
		Plus(firstNumber, secondNumber);
		break;
	case 2:
		Minus(firstNumber, secondNumber);
		break;
	case 3:
		Multiply(firstNumber, secondNumber);
		break;
	case 4:
		Division(firstNumber, secondNumber);
		break;
	case 5:
		Power(firstNumber, secondNumber);
		break;
	default:
		std::cerr << "\nInvalid Operation Selected!" << std::endl;
		break;
	}

	return 0;
}