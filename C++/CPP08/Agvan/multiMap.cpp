#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultiMap;

    myMultiMap.insert({1, "Apple"});
    myMultiMap.insert({2, "Banana"});
    myMultiMap.insert({1, "Cherry"});  // Ключ 1 теперь имеет два значения

    for (const auto& pair : myMultiMap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}
