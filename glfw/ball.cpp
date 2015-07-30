#include "ball.hpp"

#include <cmath>
#include <array>
#include <iostream>

void ball::onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void ball::draw_ball() {
    const float full_angle = 2.0f*M_PI;
    float x, y;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);

    for(std::size_t i = 0; i < 20; ++i) {
        x = x_ball + radius*(std::cos(i*full_angle / 20.0f));
        y = y_ball + radius*(std::sin(i*full_angle / 20.0f));

        glVertex2f(x, y);
    }

    glEnd();
}

void ball::glloop() {
    float ratio = framebufferWidth() / (float)framebufferHeight();

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);

    //Bounce on window bottom
    if(y_ball - radius <= -1)
        vy_ball = std::abs(vy_ball);
    else
        vy_ball -= gravity;

    //Update ball coordinates
    x_ball += vx_ball;
    y_ball += vy_ball;

    std::cout << y_ball + radius << std::endl;

    draw_ball();
}
