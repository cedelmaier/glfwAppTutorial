#ifndef BALL_HPP
#define BALL_HPP

#include "glfwApp.hpp"

#include <utility>
#include <iostream>

class ball : public glfwApp {
    public:
        template<typename... ARGS>
        ball(ARGS&&... args) : glfwApp{ std::forward<ARGS>(args)... } ,
            x_ball{ 0.0f },
            y_ball{ 0.8f},
            vx_ball{ 0.0f },
            vy_ball {0.0f }
        { 
            for(int i = 0; i < 10; i++) {
                std::cout << "ball constructor called!\n";
            }
        }

        virtual void onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) override;

        virtual void glloop() override;

    private:
        float x_ball, y_ball;
        float vx_ball, vy_ball;
        const float gravity = 0.0001;
        const float radius = 0.1f;

        void draw_ball();
};

#endif
