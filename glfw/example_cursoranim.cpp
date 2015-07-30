#include <GLFW/glfw3.h>
#include "glfwApp.hpp"
#include "cursoranim.hpp"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdexcept>

int main() {
    auto app = makeApp<cursoranim>("cursoranim", 800, 600);

    app->start();
}
