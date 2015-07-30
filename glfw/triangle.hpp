#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "glfwApp.hpp"

class triangle : public glfwApp {
    public:
        template<typename... ARGS>
        triangle(ARGS&&... args) : glfwApp{ std::forward<ARGS>(args)... }
        {}

        virtual void onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) override;

        virtual void glloop() override;
};

#endif
