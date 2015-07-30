#include "glfwApp.hpp"

#include <stdexcept>

//Class constructor
glfwApp::glfwApp(const std::string& windowTitle, int windowWidth, int windowHeight) {
    if(!glfwInit()) {
        throw std::runtime_error {
            "Unable to initialize glfw runtime"
        };
    }

    _window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);

    if(!_window) {
        throw std::runtime_error {
            "Unable to initialize glfw window"
        };
    }

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);

    //Print out some versioning info
    printf("Compiled against GLFW %i.%i.%i\n",
            GLFW_VERSION_MAJOR,
            GLFW_VERSION_MINOR,
            GLFW_VERSION_REVISION);

    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Running against GLFW %i.%i.%i\n", major, minor, revision);

    const unsigned char* glversion = glGetString(GL_VERSION);
    printf("OpenGL Version: %s\n", glversion);
}

//Class destructor, yay unique_ptr
glfwApp::~glfwApp() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

//Start the app
void glfwApp::start() {
    glfwloop();
}

//The actual loop run
void glfwApp::glfwloop() {
    while(!glfwWindowShouldClose(_window)) {
        this->glloop();

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

//glfw callbacks that do nothing by default
void glfwApp::onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) {
    //Does nothing by default.  Override to customize
}

void glfwApp::onError(int error, const char* desc) {
    //Does nothing by default
}

void glfwApp::onResize(GLFWwindow* window, int width, int height) {
    //Default rearranges OpenGL viewport to current framebuffer size
    
    glViewport(0, 0, width, height);
}

//Framebuffer size stuff
std::pair<int, int> glfwApp::framebufferSize() const {
    std::pair<int, int> size;

    glfwGetFramebufferSize(_window, &size.first, &size.second);

    return size;
}

int glfwApp::framebufferWidth() const {
    return framebufferSize().first;
}

int glfwApp::framebufferHeight() const {
    return framebufferSize().second;
}

GLFWwindow* glfwApp::window() const {
    return _window;
}

glfwApp* glfwAppManager::_app = nullptr;


