#include "alg_movement_fun.h"

void AlgorithmMovement::operator()(const UndirectedMapView& mapView, LittleRocket& rocket, const OpenGLApplication& app, int endNode) const {

	engine->performSearching();
	if (!engine->hasPathTo(endNode)) {
		return;
	}

	std::vector<int> path = engine->traceTo(endNode);

	//delete start node from path
	for (auto iter = path.begin() + 1; iter != path.end(); iter++) {
		glm::vec3 direction = mapView.getVertexPosition(*iter) - rocket.position();

		//splits the path into small pieces to makes animation like feeling
		int pathSpliter = 70000;
		for (int i = 0; i < pathSpliter; i++) {
			rocket.translate(glm::vec3(direction.x / pathSpliter, direction.y / pathSpliter, direction.z / pathSpliter));

			if (app.shouldAppBeClosed()) {
				break;
			}
		}
	}
}