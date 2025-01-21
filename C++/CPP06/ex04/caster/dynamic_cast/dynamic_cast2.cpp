#include <iostream>
using namespace std;

// // Base Class
// class Animal {
// public:
//     virtual void speak() {
//         cout << "Animal speaks." << endl;
//     }
// };

// // Derived Class
// class Dog : public Animal {
// public:
//     void speak() override  {
//         cout << "Dog barks." << endl;
//     }
// };

// // Derived Class
// class Cat : public Animal {
// public:
//     void speak() override {
//         cout << "Cat meows." << endl;
//     }
// };

// int main() {
  
//     // Base class pointer to derived class object
//     Animal* animalPtr = new Dog();

//     // Downcasting
//     Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
// // dynamic_cast проверяет во время выполнения, является ли объект, на который указывает animalPtr, действительно типа Dog (или наследует от него).
// // В данном случае объект реально типа Dog, поэтому приведение успешно, и dogPtr становится ненулевым.//66rd toxic nerqev orinakum ciuce tvac или наследует от него -i tarberakovy!
   
//     // Checking if the typecasting is successfull
//     if (dogPtr) {
//         dogPtr->speak();
//     }
//     else {
//         cout << "Failed to cast to Dog." << endl;
//     }

//     // Typecasting to other dervied class
//     Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
//     if (catPtr) {
//         catPtr->speak();
//     }
//     else {
//         cout << "Failed to cast to Cat." << endl;
//     }

//     delete animalPtr;
//     return 0;
// }
//  The first line of output is printed because the animalPtr of the Animal type is successfully cast to the Dog type and speak() function of the Dog class is invoked but the casting of the Animal type to ‘Cat’ type is failed because animalPtr points to a Dog object thus, the dynamic cast fails because the typecasting is not safe.

// Upcasting. ցուցիչը կամ հղումը ստացված դասից վերափոխում է բազային դասի: Այն միշտ անվտանգ է և չի պահանջում ստուգում:
// Downcasting. ցուցիչը կամ հղումը հիմնական դասից ածանցյալ դասի վերածելը: Սա պահանջում է գործարկման տիպի ստուգում((runtime type checking), որպեսզի ապահովվի փոխակերպումը:




////////////////////////////////////////////
#include <iostream>
using namespace std;

// Базовый класс
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks." << endl;
    }
    virtual ~Animal() {}
};

// Производный класс
class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks." << endl;
    }
};

// Класс, наследующий от Dog
class Labrador : public Dog {
public:
    void speak() override {
        cout << "Labrador barks loudly." << endl;
    }
};

int main() {
    // Создаём объект типа Labrador, но указываем на него через указатель Animal
    Animal* animalPtr = new Labrador();

    // Пробуем привести к Dog
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

    if (dogPtr) {
        dogPtr->speak(); // Это сработает, так как Labrador наследует от Dog
    } else {
        cout << "Failed to cast to Dog." << endl;
    }

    // Пробуем привести к Cat (другому типу)
    class Cat : public Animal {
    public:
        void speak() override {
            cout << "Cat meows." << endl;
        }
    };
    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);

    if (catPtr) {
        catPtr->speak();
    } else {
        cout << "Failed to cast to Cat." << endl;
    }

    delete animalPtr; // Удаляем объект
    return 0;
}
