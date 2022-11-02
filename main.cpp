#include <iostream>
#include <limits>
#include <string>
#include <numbers>
// #include "src/gpio/gpio.h"
// #include <format> // not available
#include <pigpio.h>

// from c++ core guidelines - e.g. when returning a value, or multiple values below can be handy
// see also https://www.youtube.com/watch?v=XkDEzfpdcSg (Kate Gregory)
#include <optional>
#include <tuple>


// installed wiringPi on the rpi 4 from deb file:  https://project-downloads.drogon.net/wiringpi-latest.deb
// extra rsync done on /usr/include/wiringPi* and /usr/lib/libwiringPi* to sysroot
#include <wiringPi.h>

#include "gsl_tests.h"


// some c++20 to test compilation
consteval int sqr(int n) {
  return n*n;
}
constexpr int r = sqr(100);
int counter {0};
long long distance {15'000'000LL};
auto pi(std::numbers::pi);
// end compilation test

int main() { 
    std::cout << "yo, cross compiled and btw, the sqr of 100 is " << r << std::endl;
    std::cout << std::numeric_limits<short>::min();
    std::cout << "Hello Pi (" << pi << ")" << std::endl;

    // try out the gpio class
    // gpio::GPIO input26 = gpio::GPIO(26);

    // if (gpioInitialise() < 0) {
    // return 1; // Failed to initialize.
    // }

    // GSL tests
    not_null_test(); // un/comment lines in gsl_tests.cpp to tweak behavior
}