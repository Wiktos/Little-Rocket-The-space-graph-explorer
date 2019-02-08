#include "alg_movement_fun.h"

void AlgorithmMovement::operator()(const UndirectedMapView& mapView, LittleRocket& rocket, std::shared_ptr<Camera> cam, const OpenGLApplication& app, int endNode) const {

	engine->performSearching();
	if (!engine->hasPathTo(endNode)) {
		return;
	}

	std::vector<int> path = engine->traceTo(endNode);

	//delete start node from path
	for (auto iter = path.begin() + 1; iter != path.end(); iter++) {
		glm::vec3 direction = mapView.getVertexPosition(*iter) - rocket.position();

		//splits the path into small pieces to makes animation like behavior
		int pathSpliter = 50000;
		for (int i = 0; i < pathSpliter; i++) {
			glm::vec3 newPos = glm::vec3(direction.x / pathSpliter, direction.y / pathSpliter, direction.z / pathSpliter);

			rocket.translate(newPos);

			//update camera position
			cam->setPosition(newPos + cam->currentPostion());

			if (app.shouldAppBeClosed()) {
				break;
			}
		}
	}
}