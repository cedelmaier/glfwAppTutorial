#ifndef GEARS_HPP
#define GEARS_HPP

#include <vector>
#include <iostream>

#include "glfwApp.hpp"

#if defined(_OPENMP)
#define ENABLE_OPENMP
#include <omp.h>
#endif

class gears : public glfwApp {
    public:
        template<typename... ARGS>
        gears(ARGS&&... args) : glfwApp{ std::forward<ARGS>(args)... } {
            onResize(window(), 300, 300);
            // XXX: Change this to accept actual command line args
            init(0, nullptr);
            #ifdef ENABLE_OPENMP
            nthreads = omp_get_num_threads();
            #else
            nthreads = 1;
            #endif
            frc_ = new double[3*10*nthreads];
            for (int i = 0; i < 3*10*nthreads; ++i) {
                frc_[i] = 0.0;
            }
            std::cout << "Done with gears constructor!\n";
        }

        virtual ~gears() {
            delete[] frc_;
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

        // Test stuff for openmp inclusion
        int nthreads;
        double* frc_;
};

#endif
