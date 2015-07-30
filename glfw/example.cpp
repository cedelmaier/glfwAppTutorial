#include <GLFW/glfw3.h>
#include "glfwApp.hpp"
#include "triangle.hpp"
#include "ball.hpp"
#include "square.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdexcept>

int main() {
    auto app = makeApp<ball>("ball", 800, 600);

    app->start();
}
