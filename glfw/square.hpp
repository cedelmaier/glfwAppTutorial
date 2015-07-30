#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "glfwApp.hpp"

class square : public glfwApp {
    public:
        template<typename... ARGS>
        square(ARGS&&... args) : glfwApp{ std::forward<ARGS>(args)... }
        {}

        virtual void onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) override;

        virtual void glloop() override;
};

#endif
