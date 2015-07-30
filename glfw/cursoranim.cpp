#include "cursoranim.hpp"

#include <cmath>
#include <algorithm>

static float max(float a, float b) { return a > b ? a : b; }
static float min(float a, float b) { return a < b ? a : b; }

cursoranim::~cursoranim() {
    delete(mFrames);
    delete(mBuffer);
}

float cursoranim::star(int x, int y, float t) {
    float c = mSize / 2.0f;
    
    float i = (0.25f * (float)sin(2.0f * 3.1415926f * t) + 0.75f);
    float k = mSize * 0.046875f * i;
    
    float dist = (float)sqrt((x - c) * (x - c) + (y - c) * (y - c));
    
    float salpha = 1.0f - dist / c;
    float xalpha = (float)x == c ? c : k / (float)fabs(x - c);
    float yalpha = (float)y == c ? c : k / (float)fabs(y - c);
    
    return max(0.0f, min(1.0f, i * salpha * 0.2f + salpha * xalpha * yalpha));
}

GLFWcursor* cursoranim::loadFrame(float t) {
    int i = 0, x, y;
    const GLFWimage image = { (int)mSize, (int)mSize, mBuffer };

    for (y = 0;  y < image.width;  y++) {
        for (x = 0;  x < image.height;  x++) {
            mBuffer[i++] = 255;
            mBuffer[i++] = 255;
            mBuffer[i++] = 255;
            mBuffer[i++] = (unsigned char)(255 * star(x, y, t));
        }
    }

    printf("Frame: %.4f\n", t);
    for(y = 0; y < image.width; y++) {
        for(x = 0; x < image.height; x++) {
            //Just print the alpha to the screen
            if((unsigned int)(star(x, y, t) * 9) != 0)
                printf("%d", (unsigned int)(star(x, y, t) * 9));
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n\n");
    
    return(glfwCreateCursor(&image, image.width / 2, image.height / 2));
}

void cursoranim::glloop() {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSetCursor(window(), mFrames[mI]);
    
    mt1 = glfwGetTime();
    mFrameTime += mt1 - mt0;
    mt0 = mt1;
    
    while (mFrameTime > 1.0 / (double)mN) {
        mI = (mI + 1) % mN;
        mFrameTime -= 1.0 / (double)mN;
    }
}


