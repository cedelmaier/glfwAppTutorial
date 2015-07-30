#ifndef GEARS_HPP
#define GEARS_HPP

#include "glfwApp.hpp"

class gears : public glfwApp {
    public:
        template<typename... ARGS>
        gears(ARGS&&... args) : glfwApp{ std::forward<ARGS>(args)... } {
            onResize(window(), 300, 300);
            // XXX: Change this to accept actual command line args
            init(0, nullptr);
        }

        virtual void onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) override;
        virtual void onResize(GLFWwindow* window, int width, int height) override;

        virtual void glloop() override;

    private:
        //Rotation parameters
        GLfloat view_rotx = 20.f;
        GLfloat view_roty = 30.f;
        GLfloat view_rotz = 0.f;

        GLint gear1, gear2, gear3;
        GLfloat angle = 0.0f;

        int autoexit = 0;

        //gear creation
        void gear(GLfloat inner_radius, GLfloat outer_radius, GLfloat width,
               GLint teeth, GLfloat tooth_depth);
        void draw(void);
        void animate(void);
        void init(int argc, char* argv[]);
};

#endif
