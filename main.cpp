#include <iostream>
#include <memory>
#include <limits>
using namespace std;

// Function to get a valid integer from the user
int getValidInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    // Get three valid integers
    int a = getValidInteger("Enter first integer: ");
    int b = getValidInteger("Enter second integer: ");
    int c = getValidInteger("Enter third integer: ");

    // Use unique_ptr for dynamic allocation (modern approach)
    unique_ptr<int> ptrA = make_unique<int>(a);
    unique_ptr<int> ptrB = make_unique<int>(b);
    unique_ptr<int> ptrC = make_unique<int>(c);

    // Display values of variables
    cout << "\nValues of variables:\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Display values using pointers
    cout << "\nValues from dynamic memory using smart pointers:\n";
    cout << "*ptrA = " << *ptrA << ", *ptrB = " << *ptrB << ", *ptrC = " << *ptrC << endl;

    // Display memory addresses
    cout << "\nMemory addresses:\n";
    cout << "Address of a: " << &a << ", ptrA points to: " << ptrA.get() << endl;
    cout << "Address of b: " << &b << ", ptrB points to: " << ptrB.get() << endl;
    cout << "Address of c: " << &c << ", ptrC points to: " << ptrC.get() << endl;

    // No need to manually delete, unique_ptr automatically frees memory
    cout << "\nSmart pointers automatically handle memory cleanup." << endl;

    return 0;
}
