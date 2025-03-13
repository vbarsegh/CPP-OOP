#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Driver code

	int main()
{
    // Declare value_type for priority queue
    priority_queue<string>::value_type AString;

    // Declares priority_queue
    priority_queue<string> q2;

    // Here AString acts as a variable of string data type
    AString = "geeks for geeks";
    cout << "The value_type is AString = " << AString << endl;

    AString = "abc";
    q2.push(AString);
    AString = "ghi";
    q2.push(AString);
 q2.push(AString);
    AString = "def";
    cout << "Value stored in priority queue are:" << endl;
    while (!q2.empty()) {
        cout << '\t' << q2.top();
        q2.pop();
    }

    return 0;
}


// This code is modified by Susobhan Akhuli
