#include <iostream>
#include <limits>
#include <string>
#include <numbers>
// #include "src/gpio/gpio.h"
// #include <format> // not available
#include <pigpio.h>


// testing c++20 compilation
consteval int sqr(int n) {
  return n*n;
}
constexpr int r = sqr(100); // OK
int counter {0};
long long distance {15'000'000LL};

const wchar_t *txt = L"Hello World";
std::wstring s = std::wstring(txt);

auto pi(std::numbers::pi);

int main() { 
    std::cout << "yo, cross compiled and btw, the sqr of 100 is " << r << std::endl;
    std::wcout << "yes this is a  wstring : "  << s << std::endl;
    //std::cout << std::numeric_limits<short>::min();
    std::cout << "Hello Pi (" << pi << ")" << std::endl;

    // try out the gpio class
    // gpio::GPIO input26 = gpio::GPIO(26);

    if (gpioInitialise() < 0) {
    return 1; // Failed to initialize.
  }
}