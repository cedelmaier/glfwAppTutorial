#include <GLFW/glfw3.h>
#include "glfwApp.hpp"
#include "gears.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdexcept>

int main() {
    auto app = makeApp<gears>("gears", 300, 300);

    app->start();
}
