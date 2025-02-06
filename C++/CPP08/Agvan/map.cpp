#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<int, std::vector<std::string> > myMap;

    myMap[1].push_back("Apple");
    myMap[1].push_back("Cherry");
    myMap[2].push_back("Banana");

    for (const auto& pair : myMap) {
        std::cout << pair.first << " -> ";
        for (const auto& val : pair.second) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}


// #include <iostream>
// #include <map>

// int main() {
//     std::map<int, std::string> myMap;

//     myMap[1] = "Apple";  
//     myMap[2] = "Banana";
//     myMap[1] = "Cherry";  // Перезаписывает значение ключа 1

//     for (const auto& pair : myMap) {
//         std::cout << pair.first << " -> " << pair.second << std::endl;
//     }
// }
