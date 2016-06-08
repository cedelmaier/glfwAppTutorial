#include <GLFW/glfw3.h>
#include "glfwApp.hpp"
#include "gears.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdexcept>

#if defined(_OPENMP)
#define ENABLE_OPENMP
#include <omp.h>
#endif

int main() {
    int nthreads = 1;

    #ifdef ENABLE_OPENMP
    #pragma omp parallel
    {
        if (omp_get_thread_num() == 0) {
            nthreads = omp_get_num_threads();
        }
    }
    #endif

    std::cout << "Running gears with " << nthreads << " threads\n";

    auto app = makeApp<gears>("gears", 300, 300);

    app->start();
}
