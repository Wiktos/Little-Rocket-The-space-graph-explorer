#include "alg_movement_fun.h"

void AlgorithmMovement::operator()(UndirectedMapView& mapView, LittleRocket& rocket, std::shared_ptr<Camera> cam, const OpenGLApplication& app, int endNode) const {

	visualiseAlgorithm(mapView, rocket, cam, app, endNode);
	updatePathNodesColors(mapView, app, endNode);

}

void AlgorithmMovement::visualiseAlgorithm(UndirectedMapView& mapView, LittleRocket& rocket, std::shared_ptr<Camera> cam, const OpenGLApplication& app, int endNode) const {
	engine->performSearching();
	if (!engine->hasPathTo(endNode)) {
		return;
	}

	std::vector<int> trace = engine->traceTo(endNode);
	markNodeAsVisited(mapView, UndirectedMap::START_NODE_IDX);

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

		markNodeAsVisited(mapView, *iter);
	}
}

void AlgorithmMovement::updatePathNodesColors(UndirectedMapView& mapView, const OpenGLApplication& app, int endNode)  const {
	std::stack<int> path = engine->pathTo(endNode);
	
	while (!path.empty()) {
		int v = path.top();
		path.pop();

		markNodeAsPathNode(mapView, v);

		if (app.shouldAppBeClosed()) {
			break;
		}
	}
} 

void AlgorithmMovement::markNodeAsVisited(UndirectedMapView& mapView, int v) const {
	std::shared_ptr<GraphNodeView> currVertexView = std::dynamic_pointer_cast<GraphNodeView>(mapView.getObject(v));
	currVertexView->changeColor(visited);
}

void AlgorithmMovement::markNodeAsPathNode(UndirectedMapView& mapView, int v) const {
	std::shared_ptr<GraphNodeView> currVertexView = std::dynamic_pointer_cast<GraphNodeView>(mapView.getObject(v));
	currVertexView->changeColor(belongs);
}