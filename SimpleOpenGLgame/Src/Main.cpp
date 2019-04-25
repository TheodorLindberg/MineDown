#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include "Shader.h"
#include <glm/gtc/matrix_transform.inl>
#include "World/Chunk/Chunk.h"

void processInput(GLFWwindow *window);

static int tiles[] = {
	1,1,1,0,0,2,2,
	1,1,0,0,1,2,2,
	1,1,0,2,2,2,1,
	0,0,0,1,2,2,2,
	1,1,1,1,2,2,0,
	1,1,2,1,5,2,0,
	1,1,2,1,5,2,0
};
int tilesWidth = 7;


int main() {
	GLFWwindow* window = nullptr;
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}

		glViewport(0, 0, 800, 600);
	}

	unsigned int VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);


	/*float verticies[] = {
		 0.5f,  0.5f,
		 0.5f, -0.5f,
		-0.5f, -0.5f,
		-0.5,   0.5f,
	};*/

	float gridScale = 1.5;
	float size = (1.f / 7.f) * gridScale;
	float verticies[] = {
		size,  size,
		size, 0,
		0, 0,
		0,  size,
	};

	unsigned int indicies[] = {
		0,1,3,
		1,2,3
	};

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	Chunk chunk(glm::vec2(0, 0));

	chunk.setBlock(10, 10, 4, 200);
	Block block(static_cast<std::uint64_t>(Block::BlockType::Liquid));

	auto test = block.getBlockType() == Block::BlockType::Liquid;


	Shader shader;
	shader.CompileFromFile("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

	float time = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		double dt = glfwGetTime() - time;
		time = glfwGetTime();
		glfwPollEvents();
		processInput(window);
		
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


		shader.Use();
		glBindVertexArray(VAO);
		shader.SetVector2f("camoffset", glm::vec2(-1, 1));
		int count = 0;
		for (auto& tile : tiles) {
			shader.SetInteger("tile", tile);

			float x = (count % tilesWidth);
			float y = (count / tilesWidth);

			
			shader.SetVector2f("offset", glm::vec2((x/7.f) * gridScale, (y/7.f) * gridScale));
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			count++;
		}

		
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;

}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}



