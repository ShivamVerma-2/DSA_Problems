// 
#include <iostream>
#include <limits> // for numeric_limits
using namespace std;

int main() {
    int age;
    char name[50];

    cout << "Enter your age: ";
    cin >> age;

    // clear the leftover newline from buffer
    cin.ignore();

    cout << "Enter your full name: ";
    cin.getline(name, 50);

    cout << "Age: " << age << "\nName: " << name << endl;
    return 0;
}
