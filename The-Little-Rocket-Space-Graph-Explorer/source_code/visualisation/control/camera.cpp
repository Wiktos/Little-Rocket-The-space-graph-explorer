#include "camera.h"

const float Camera::SPEED_MIN = 0.5f;

void Camera::increaseSpeed() {
	speed += 1.f;
}

void Camera::decreaseSpeed() {
	if (speed <= SPEED_MIN) {
		return;
	}
	speed -= 1.f;
}

void Camera::moveForward(float delta) {
	viewVectors.cameraPos += delta * speed * viewVectors.cameraFront;
}

void Camera::moveBackward(float delta) {
	viewVectors.cameraPos -= delta * speed * viewVectors.cameraFront;
}

void Camera::moveLeft(float delta) {
	viewVectors.cameraPos -= glm::normalize(glm::cross(viewVectors.cameraFront, viewVectors.cameraUp)) * delta * speed;
}

void Camera::moveRight(float delta) {
	viewVectors.cameraPos += glm::normalize(glm::cross(viewVectors.cameraFront, viewVectors.cameraUp)) * delta * speed;
}