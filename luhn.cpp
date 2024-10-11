#include "luhn.h"

// Luhn Algorithm
// 1. Start from the rightmost digit, which is the check digit, and drop it to form the "payload".
// 2. Moving left, double the value of every second digit, starting from the "payload"'s rightmost digit;
// if the product of this doubling operation is greater than 9 (e.g., 7 * 2 = 14), then sum the digits of the products (e.g., 10: 1 + 0 = 1, 14: 1 + 4 = 5).
// 3. Take the sum of all the digits.
// 3. If (10 - (total modulo 10)) is equal to the check digit, then the number is valid.
// Example: 17893729974
// 1. 7*2=14 -> 1+4 = 5, 9, 9*2=18 -> 1+8 = 9, 2, 7*2=14 -> 5, 3, 9*2=18 -> 9, 8, 7*2=14 -> 5, 1
// 2. 1+5+8+9+3+5+2+9+9+5 = 56
// 3. 56%10=6, 10-6=4
// 4. 4 == 4, valid
bool luhn::luhnAlgorithm(std::string number) {
    int checkDigit = number[number.size()-1] - '0';
    bool isEven = false;
    int total = 0;
    for(int i = number.size()-2; i >= 0; i--) {
        int currentNum = number[i] - '0';
        isEven = !isEven;
        if(isEven) {
            currentNum *= 2;
            if(currentNum > 9) {
                int tensDigit = currentNum / 10;
                int onesDigit = currentNum % 10;
                currentNum = tensDigit + onesDigit;
            }
        }
        total += currentNum;
    }
    total = 10 - (total % 10);
    return total == checkDigit;
}
