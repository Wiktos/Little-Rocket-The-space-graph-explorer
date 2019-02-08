#include "alg_movement_fun.h"

void AlgorithmMovement::operator()(UndirectedMapView& mapView, LittleRocket& rocket, std::shared_ptr<Camera> cam, const OpenGLApplication& app, int endNode) const {

	engine->performSearching();
	if (!engine->hasPathTo(endNode)) {
		return;
	}

	std::vector<int> trace = engine->traceTo(endNode);

	//delete start node from path
	for (auto iter = trace.begin() + 1; iter != trace.end(); iter++) {
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

	std::stack<int> path = engine->pathTo(endNode);
	while (!path.empty()) {
		int v = path.top();
		path.pop();

		//changing color of vertices in path to pink like
		Color newCol = { 1.0f, .2f, .3f};
		std::shared_ptr<GraphNodeView> currVertexView = std::dynamic_pointer_cast<GraphNodeView>(mapView.getObject(v));
		currVertexView->changeColor(newCol);

		if (app.shouldAppBeClosed()) {
			break;
		}
	}
}