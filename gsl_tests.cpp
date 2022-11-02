#include <iostream>
#include "gsl_tests.h"

int* GetPointer(int* ptr) {
  return ptr;
}

// try some GSL
void not_null_test()
{
    int i = 10;
    gsl::not_null<int*> p_int = &i;

    // this should generate a compile error
    // p_int = nullptr;

    std::cout << "p_int points to value: " << *p_int << std::endl;

    // this will terminate the application - so a runtime error as we cannot assign a nullptr to the gsl::not_null<...>
    p_int = GetPointer(nullptr);
    std::cout << "we should get terminated before we are seeing this..." << std::endl;
}

