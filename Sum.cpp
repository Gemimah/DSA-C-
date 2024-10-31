#include <iostream>
using namespace std;

// Function to calculate the sum of digits
int sumDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;  // Get the last digit and add to sum
        number /= 10;        // Remove the last digit
    }
    return sum;
}

int main() {
    int number = 1335;
    cout << "The sum of the digits of " << number << " is " << sumDigits(number) << endl;
    return 0;
}
