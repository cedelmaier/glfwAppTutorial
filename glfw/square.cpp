#include "square.hpp"

void square::onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void square::glloop() {
    float ratio = framebufferWidth() / (float)framebufferHeight();

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    //glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

    glBegin(GL_QUADS);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.5f, -0.5f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.5f, 0.5f, 0.f);
    glColor3f(1.f, 1.f, 1.f);
    glVertex3f(-0.5f, 0.5f, 0.f);
    glEnd();
}
