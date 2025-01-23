#include "Array.hpp"

int main()
{
    {
        Array<int> arr;
        std::cout << "Size: " << arr.size() << std::endl; // Size: 0
    }
    std::cout << std::endl;
    {
        Array<int> arr(5);
        std::cout << "Size: " << arr.size() << std::endl; // Size: 5
        arr[0] = 10;
        std::cout << arr[0] << std::endl; // 10

        try {
            arr[5] = 20; // Ошибка, выход за границы
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        Array<int> arr(5);
        std::cout << "Size: " << arr.size() << std::endl; // Size: 5
        arr[0] = 10;
        Array<int> copy(arr);
        copy[0] = 42;
        std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
    }
    std::cout << std::endl;
    {
        Array<int> arr(5);
        std::cout << "Size: " << arr.size() << std::endl; // Size: 5
        arr[0] = 10;
        Array<int> another(3);
        another = arr;
        another[0] = 50;
        std::cout << arr[0] << std::endl; // 10 (оригинал не меняется)
        std::cout << another[0] << std::endl;
    }
}