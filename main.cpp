#include <iostream>
#include "luhn.h"

int main(){
    std::string isValidNumberA = luhn::luhnAlgorithm("17893729974") ? "true" : "false";
    std::string isValidNumberB = luhn::luhnAlgorithm("17893729979") ? "true" : "false";
    std::cout << isValidNumberA << std::endl;
    std::cout << isValidNumberB << std::endl;
    return 0;
}