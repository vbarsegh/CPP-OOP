#include "Serializer.hpp"
using std::cout;
using std::endl;
int main()
{
    Data data;
    data.num = 42;
    data.c = 'v';

    uintptr_t   data_in_uintptr;
    Data        *newData;
    // newData->num = 442;
    // newData->c = 'c';
    cout << "doooooooooooooo\n";
    cout << "this is data address->" << &data << endl;
    cout << "this is newData address->" << newData << endl;
    cout << "this is data_in_uintptr address->" << &data_in_uintptr << endl;

    data_in_uintptr = Serializer::serialize(&data);
    newData = Serializer::deserialize(data_in_uintptr);
    cout << "posleeeeeeeeeeee\n";
    cout << "this is data_in_uintptr value->" << data_in_uintptr << endl;
    cout << "this is data_in_uintptr address->" << &data_in_uintptr << endl;

    if (&data == newData)
    {
        cout << "this is data address->" << &data << endl;
        cout << "this is newData address->" << newData << endl;
        cout << "newData.num = " << newData->num << endl;
        cout << "newData.c = " << newData->c << endl;
    }
    else
        cout << "The Addresses don't match" << endl;
    return (1);
}
