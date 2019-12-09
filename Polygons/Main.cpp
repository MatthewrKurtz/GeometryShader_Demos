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
float numberOfSides = 4.0f;

double currentTime;
double timeOfLastInput;

enum EShaderToUse {triangleStrip, lineStrip};
EShaderToUse shaderCurrentlyInUse = lineStrip;

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
	Shader TriangleStripShader("VertexShader.vs", "FragmentShader.fs", "TriangleStrip_GeometryShader.gs");
	Shader LineStripShader("VertexShader.vs", "FragmentShader.fs", "LineStrip_GeometryShader.gs");

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
		0.0f, 0.0f
	};

	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), &points, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

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

		TriangleStripShader.setFloat("sides", numberOfSides);

		// render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw points
		if(shaderCurrentlyInUse == triangleStrip)
			TriangleStripShader.use();
		if (shaderCurrentlyInUse == lineStrip)
			LineStripShader.use();
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
	if (currentTime - timeOfLastInput >= 0.1)
	{
		timeOfLastInput = currentTime;
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
			numberOfSides = 1.0f;
		if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
			numberOfSides = 2.0f;
		if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
			numberOfSides = 3.0f;
		if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
			numberOfSides = 4.0f;
		if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
			numberOfSides = 5.0f;
		if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
			numberOfSides = 6.0f;
		if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
			numberOfSides = 7.0f;
		if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
			numberOfSides = 8.0f;
		if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
			numberOfSides = 9.0f;
		if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
			numberOfSides = 10.0f;
		if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
			numberOfSides = 100.0f;
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
			numberOfSides += 1.0f;

		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
			shaderCurrentlyInUse = lineStrip;
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
			shaderCurrentlyInUse = triangleStrip;
	}
}
