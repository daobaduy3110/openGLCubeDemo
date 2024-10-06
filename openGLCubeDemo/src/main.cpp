#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "core/Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void setupVertexData();
void render(GLFWwindow* window);
void cleanUp();

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";

uint32_t _shaderProgram = NULL;
uint32_t _VAO, _VBO, _EBO;
Shader _shader;

int main()
{
	// init glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// create window
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

	// compile shaders
	_shader = Shader("resource/shader/Cube.vs", "resource/shader/Cube.fs");

	// setup vertex data
	setupVertexData();

	// render loop
	while (!glfwWindowShouldClose(window))
	{
		render(window);
	}

	// clean/delete resources
	cleanUp();
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

void setupVertexData()
{
	float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
	};
	uint32_t indices[] = {
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glGenBuffers(1, &_EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// unbind vbo
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// keep ebo bounded here, as it is stored in the vao

	// unbind vao
	glBindVertexArray(0);
}

void render(GLFWwindow* window)
{
	processInput(window);

	glClearColor(0.f, 0.f, 0.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//glUseProgram(_shaderProgram);
	_shader.use();
	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, /*indices num*/6, GL_UNSIGNED_INT, 0);

	// swap buffers
	glfwSwapBuffers(window);
	// poll IO events
	glfwPollEvents();
}

void cleanUp()
{
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
	glDeleteBuffers(1, &_EBO);
	glDeleteProgram(_shaderProgram);
	_shader.cleanUp();
}