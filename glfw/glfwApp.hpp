#ifndef GLFW_APP_HPP
#define GLFW_APP_HPP

#include <string>
#include <memory>

#include <GLFW/glfw3.h>

/* glfwApp
 * Base class for glfwApp-s to inherit from
*/
class glfwApp {
    public:
        glfwApp(const std::string& windowTitle, int windowWidth, int windowHeight);
        virtual ~glfwApp();

        void start();

        virtual void onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods);
        virtual void onError(int error, const char* desc);
        virtual void onResize(GLFWwindow* window, int width, int height);
        virtual void glloop() = 0;

        std::pair<int, int> framebufferSize() const;
        int framebufferWidth() const;
        int framebufferHeight() const;

        GLFWwindow* window() const;

    private:
        GLFWwindow* _window;

        void glfwloop();
};

/* glfwAppManager
 * App manager that sets callbacks appropriately
*/
class glfwAppManager {
    static glfwApp* _app;

    static void onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if(_app) _app->onKeydown(window, key, scancode, action, mods);
    }

    static void onError(int error, const char* desc) {
        if(_app) _app->onError(error, desc);
    }

    static void onResize(GLFWwindow* window, int width, int height) {
        if(_app) _app->onResize(window, width, height);
    }

    public:
    //startApp
    // This is where all of the callbacks are assigned.  Very important
    // as we can't directly assign them in the base function glfwApp
    static void startApp(glfwApp* app) {
        _app = app;

        glfwSetKeyCallback(app->window(), onKeydown);
        glfwSetFramebufferSizeCallback(app->window(), onResize);
        glfwSetErrorCallback(onError);
    }
};

/* makeApp
 * creates the App
 */

template<typename T, typename...ARGS, typename = typename std::enable_if<std::is_base_of<glfwApp, T>::value>::type>
std::unique_ptr<T> makeApp(ARGS&&... args) {
    std::unique_ptr<T> app{ new T{ std::forward<ARGS>(args)...} };

    glfwAppManager::startApp(app.get());

    return app;
}

#endif
