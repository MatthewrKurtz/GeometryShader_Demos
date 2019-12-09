// Skeleton code is from LearnOpenGL.com
// Modified to demonstrate geometry shaders

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <learnopengl/filesystem.h>
#include <learnopengl/shader.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

float numberOfLines = 1.0f;

double currentTime;
double timeOfLastInput;

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// build and compile shaders
	// -------------------------
	Shader shader1("xSquared.vs", "xSquared.fs", "xSquaredLHS.gs");
	Shader shader2("xSquared.vs", "xSquared.fs", "xSquaredRHS.gs");

	//Shader shader2("9.1.geometry_shader.vs", "9.1.geometry_shader.fs", "xSquaredSecondPass.gs");
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	//float points[] = {
	//	-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // top-left
	//	 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // top-right
	//	 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // bottom-right
	//	-0.5f, -0.5f, 1.0f, 1.0f, 0.0f  // bottom-left
	//};

	float points[] = {
		0.0f, 0.0f, 1.0f, 0.25f
	};

	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), &points, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glBindVertexArray(0);

	glEnable(GL_PROGRAM_POINT_SIZE);

	currentTime = glfwGetTime();
	timeOfLastInput = currentTime;

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		currentTime = glfwGetTime();

		// input
		// ------
		processInput(window);


		// render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw points
		shader1.use();
		shader1.setFloat("numOfLines", numberOfLines);
		glBindVertexArray(VAO);
		glDrawArrays(GL_POINTS, 0, 1);

		shader2.use();
		shader2.setFloat("numOfLines", numberOfLines);
		glBindVertexArray(VAO);
		glDrawArrays(GL_POINTS, 0, 1);



		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (currentTime - timeOfLastInput >= 0.05)
	{
		timeOfLastInput = currentTime;
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
			numberOfLines = 1.0f;
		if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
			numberOfLines = 2.0f;
		if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
			numberOfLines = 3.0f;
		if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
			numberOfLines = 4.0f;
		if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
			numberOfLines = 5.0f;
		if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
			numberOfLines = 6.0f;
		if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
			numberOfLines = 7.0f;
		if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
			numberOfLines = 8.0f;
		if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
			numberOfLines = 9.0f;
		if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
			numberOfLines = 10.0f;
		if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
			numberOfLines = 100.0f;
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
			numberOfLines += 1.0f;
	}
}