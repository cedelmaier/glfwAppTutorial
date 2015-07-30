#ifndef CURSORANIM_HPP
#define CURSORANIM_HPP

#include "glfwApp.hpp"

class cursoranim : public glfwApp {
    public:
        template<typename... ARGS>
        cursoranim(ARGS&&... args) : glfwApp{ std::forward<ARGS>(args)... } ,
            mI{ 0 },
            mt0{ 0.0f },
            mt1{ 0.0f },
            mFrameTime{ 0.0f }
        { 
            //Here goes everything the glfwApp constructor doesn't handle
            mBuffer = new unsigned char[4 * mSize * mSize];
            mFrames = new GLFWcursor*[mN];
            
            for (mI = 0; mI < (int)mN; mI++) {
                mFrames[mI] = loadFrame(mI / (float)mN);
            }

            mI = 0;
            
            mt0 = glfwGetTime();
        }
        ~cursoranim();

        virtual void glloop() override;

    private:
        const unsigned int mSize = 64;
        const unsigned int mN    = 60;

        int mI;
        double mt0, mt1, mFrameTime;
        unsigned char* mBuffer;

        GLFWcursor** mFrames;

        float star(int x, int y, float t);
        GLFWcursor* loadFrame(float t);
};

#endif
