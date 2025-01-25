#include "Array.hpp"

int main()
{
    // ////////////////////double//////////////////////
    // {
    //     Array<double> arr;
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 0
    // }
    // std::cout << std::endl;
    // {
    //     Array<double> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 10.8;
    //     std::cout << arr[0] << std::endl; // 10

    //     try {
    //         arr[5] = 20.6; // Ошибка, выход за границы
    //     } catch (std::exception &e) {
    //         std::cout << "Exception: " << e.what() << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // {
    //     Array<double> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 10.8;
    //     Array<double> copy(arr);
    //     copy[0] = 42.42;
    //     std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
    // }
    // std::cout << std::endl;
    // {
    //     Array<double> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 10.8;
    //     Array<double> another(3);
    //     another = arr;
    //     another[0] = 50.9999;
    //     std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
    //     std::cout << another[0] << std::endl;
    // }
    // std::cout << std::endl;
    // // //////////////////////////////////////////

    // /////////////////////int///////////////////////////
    // std::cout << "INT" << std::endl;
    // {
    //     Array<int> arr;
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 0
    // }
    // std::cout << std::endl;
    // {
    //     Array<int> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 10;
    //     std::cout << arr[0] << std::endl; // 10

    //     try {
    //         arr[5] = 20; // Ошибка, выход за границы
    //     } catch (std::exception &e) {
    //         std::cout << "Exception: " << e.what() << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // {
    //     Array<int> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 10;
    //     Array<int> copy(arr);
    //     copy[0] = 42;
    //     std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
    // }
    // std::cout << std::endl;
    // {
    //     Array<int> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 10;
    //     Array<int> another(3);
    //     another = arr;
    //     another[0] = 50;
    //     std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
    //     std::cout << another[0] << std::endl;
    // }
    // cout << endl;
    // //////////////////////////////////////////////////
    // cout << "CHAR" << endl;
    //  {
    //     Array<char> arr;
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 0
    // }
    // std::cout << std::endl;
    // {
    //     Array<char> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 'e';
    //     std::cout << arr[0] << std::endl; // 10

    //     try {
    //         arr[5] = 'W'; // Ошибка, выход за границы
    //     } catch (std::exception &e) {
    //         std::cout << "Exception: " << e.what() << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // {
    //     Array<char> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 'e';
    //     Array<char> copy(arr);
    //     copy[0] = 'E';
    //     std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
    // }
    // std::cout << std::endl;
    // {
    //     Array<char> arr(5);
    //     std::cout << "Size: " << arr.size() << std::endl; // Size: 5
    //     arr[0] = 'e';
    //     Array<char> another(3);
    //     another = arr;
    //     another[0] = 'E';
    //     std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
    //     std::cout << another[0] << std::endl;
    // }
    // cout << endl;
    // ////////////////////////////////////////////////





    std::cout << std::endl;
	std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	std::cout << std::endl;

	{
		std::cout << "\033[32mCreating Array using default constructor\033[0m" << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		Array<int> emptyArray;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "Size: " << emptyArray.size() << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
	}
	std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	std::cout << std::endl;

	{
		std::cout << "\033[32mCreating Array using paramether constructor\033[0m" << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		Array<int> intArray(10);
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "Size: " << intArray.size() << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[33mFilling of array\033[0m" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = i + 1;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[34mPrinting an array\033[0m" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << ' ';
		std::cout << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "element in the range intArray[4]: " << intArray[4] << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "element out of range intArray[99]: ";
		try {
			std::cout << intArray[99] << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[0;31mException was thrown" << std::endl;
		}
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "element out of range intArray[-1]: ";
		try {
			std::cout << intArray[-1] << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[0;31mException was thrown" << std::endl;
		}
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
			{
			// COPY CONSTRUCTOR
			std::cout << std::endl;
			std::cout << "\033[32mCopy Constructor: copyArray(intArray)\033[0m" << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			Array<int> copyArray(intArray);
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;

			std::cout << "\033[34mPrinting copyArray\033[0m" << std::endl;
			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[33mChanging an copyArray\033[0m" << std::endl;
			for (unsigned int num = 10, i = 0; i < copyArray.size(); i++, num--)
				copyArray[i] = num;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting copyArray \033[33mAfter the changes\033[0m" << std::endl;
			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting intArray \033[33mAfter the changes\033[0m" << std::endl;
			for (unsigned int i = 0; i < intArray.size(); i++)
				std::cout << intArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			}
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			
			std::cout << std::endl;
			std::cout << "\033[35m***********************************************\033[0m" << std::endl;
			std::cout << std::endl;
			{
			// COPY ASSIGNMENT OPERATOR
			std::cout << "\033[32mCopy assignment operator: copyArray(intArray)\033[0m" << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			Array<int> copyArray;
			copyArray = intArray;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting copyArray\033[0m" << std::endl;

			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[33mChanging an copyArray\033[0m" << std::endl;
			for (unsigned int num = 10, i = 0; i < copyArray.size(); i++, num--)
				copyArray[i] = num;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting copyArray \033[33mAfter the changes\033[0m" << std::endl;

			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting intArray \033[33mAfter the changes\033[0m" << std::endl;

			for (unsigned int i = 0; i < intArray.size(); i++)
				std::cout << intArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			}
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		
			std::cout << std::endl;
			std::cout << "\033[35m***********************************************\033[0m" << std::endl;
			std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	std::cout << std::endl;


}