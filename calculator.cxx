#include <iostream>
#include <cmath>
#include <limits> // For input validation

// Templated function to display results
template <typename T>
void DisplayResult(const std::string &operation, int firstNumber, int secondNumber, T result)
{
	std::cout << "\n"
			  << firstNumber << " " << operation << " " << secondNumber << " = " << result << "\n";
}

// Operation Functions
void Plus(int firstNumber, int secondNumber)
{
	DisplayResult("+", firstNumber, secondNumber, firstNumber + secondNumber);
}

void Minus(int firstNumber, int secondNumber)
{
	DisplayResult("-", firstNumber, secondNumber, firstNumber - secondNumber);
}

void Multiply(int firstNumber, int secondNumber)
{
	DisplayResult("×", firstNumber, secondNumber, firstNumber * secondNumber);
}

void Division(int firstNumber, int secondNumber)
{
	if (secondNumber == 0)
	{
		std::cerr << "\nError: Division by zero is undefined.\n";
	}
	else
	{
		DisplayResult("÷", firstNumber, secondNumber, static_cast<double>(firstNumber) / secondNumber);
	}
}

void Power(int firstNumber, int secondNumber)
{
	DisplayResult("^", firstNumber, secondNumber, pow(firstNumber, secondNumber));
}

// Function to get validated integer input
int GetValidatedInput(const std::string &prompt)
{
	int value;
	while (true)
	{
		std::cout << prompt;
		std::cin >> value;

		if (std::cin.fail())
		{
			std::cin.clear();													// Clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cerr << "Invalid input. Please enter a valid number.\n";
		}
		else
		{
			return value;
		}
	}
}

// Function to display menu and get a valid operation choice
int GetOperationChoice()
{
	int choice;
	std::cout << "\nChoose the operation type to perform:\n";
	std::cout << "[1]  + (Addition)\n";
	std::cout << "[2]  - (Subtraction)\n";
	std::cout << "[3]  × (Multiplication)\n";
	std::cout << "[4]  ÷ (Division)\n";
	std::cout << "[5]  ^ (Power)\n";

	while (true)
	{
		std::cout << "\nOperation Type: ";
		std::cin >> choice;

		if (std::cin.fail() || choice < 1 || choice > 5)
		{
			std::cin.clear();													// Clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cerr << "Invalid choice. Please select a valid operation (1-5).\n";
		}
		else
		{
			return choice;
		}
	}
}

int main()
{
	std::cout << "\t\t\tSimple Calculator\n";

	// Get numbers from the user
	int firstNumber = GetValidatedInput("Enter the first number: ");
	int secondNumber = GetValidatedInput("Enter the second number: ");

	// Get operation choice
	int operation = GetOperationChoice();

	// Perform the chosen operation
	switch (operation)
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
		std::cerr << "An unexpected error occurred.\n";
		break;
	}

	return 0;
}