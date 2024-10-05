#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void render(GLFWwindow* window);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // for Macos X

    // create windown object
    const int width = 1200, height = 800;
    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGLCubeDemo", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // setup viewport
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    framebuffer_size_callback(window, width, height);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        render(window);
    }

    // clean/delete GLFW resources
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    // close when press ESC
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void render(GLFWwindow* window)
{
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    processInput(window);

    glfwSwapBuffers(window);
    glfwPollEvents();
}