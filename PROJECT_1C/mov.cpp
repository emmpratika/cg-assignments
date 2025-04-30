// Include GLFW
#include <GLFW/glfw3.h>
extern GLFWwindow* window; 

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp> //for camera rotation

using namespace glm;

#include <iostream>
#include <cstdlib>
using namespace std;

#include <Windows.h>
#include "mov.hpp"



float FoV = 45.0f;
float cameraSpeed = 1.0f;

bool isBallMoving = false;


glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;
glm::mat4 GroundModel = mat4(1.0f);  // Ground Model matrix
glm::mat4 BallModel = mat4(1.0f);

glm::vec3 groundPosition = vec3(0, 0, 0);
glm::vec4 ballPosition = vec4(0.0f, 0.0f, 0.0f, 1.0f);


// Initial camera position
glm::vec3 position = glm::vec3(10.0f, 50.0f, 0.0f);
glm::vec3 direction = glm::vec3(0, 0, 0);
glm::vec3 up = glm::vec3(0, 0, 1.0f);





glm::mat4 getViewMatrix() {
	return ViewMatrix;
}

glm::mat4 getProjectionMatrix() {
	return ProjectionMatrix;
}

glm::mat4 getGroundModel() {
	return GroundModel;
}


glm::mat4 getBallModel() {
	return BallModel;
}

bool getIsBallMoving() {
	return isBallMoving;
}


glm::vec3 getGroundPosition() {
	return groundPosition;
}

glm::vec4 getBallPosition() {
	return ballPosition;
}





void computeMatricesFromInputs() {

	// Move Camera around X axis
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		position = glm::rotateX(position, glm::radians(cameraSpeed));
	}


	// Move Camera around X axis (inversed)
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		position = glm::rotateX(position, glm::radians(-cameraSpeed));
	}



	// Move Camera around Z axis
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		position = glm::rotateZ(position, glm::radians(cameraSpeed));
	}

	// Move Camera around Z axis (inversed)
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		position = glm::rotateZ(position, glm::radians(-cameraSpeed));
	}


	// Update Camera Matrix
	ViewMatrix = glm::lookAt(
		position,
		direction,
		up
	);
}


int randomGenerator(int range) {
	srand((unsigned)time(NULL));
	int random = rand() % range;
	cout << random;
	return random;
	
	
}

