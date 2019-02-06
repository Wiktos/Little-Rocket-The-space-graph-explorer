#include "undirected_graph_view.h"

UndirectedMapView::UndirectedMapView(const UndirectedMap& G) {
	setStartNode();
	setInnerLayersNodes(G);
	setEndNode(G.layersNum());

	setEdges(G);
}

void UndirectedMapView::setStartNode() {
	std::shared_ptr<GraphNodeView> startNode(new GraphNodeView(GRAPH_NODE_VERTEX_SHADER_PATH, GRAPH_NODE_FRAGMENT_SHADER_PATH));

	startNode->rotate(-90.f, glm::vec3(1.f, 0.f, 0.f));
	startNode->scale(glm::vec3(2.f, 2.f, 2.f));

	pushBackObject(startNode);
	positions.push_back(glm::vec3(0.f, 0.f, 0.f));
}

void UndirectedMapView::setInnerLayersNodes(const UndirectedMap& G) {
	float graphPosX = (G.nodesPerLayer() / 2.f) * DISTANCE_BETWEEN_NODES - DISTANCE_BETWEEN_NODES / 2.f;

	for (int i = 0; i < G.layersNum(); i++) {
		float z = static_cast<float>(-(DISTANCE_BETWEEN_LAYERS + DISTANCE_BETWEEN_LAYERS * i));
		
		for (int j = 0; j < G.nodesPerLayer(); j++) {
			std::shared_ptr<GraphNodeView> node(new GraphNodeView(GRAPH_NODE_VERTEX_SHADER_PATH, GRAPH_NODE_FRAGMENT_SHADER_PATH));

			float x = -graphPosX + DISTANCE_BETWEEN_NODES * j;

			node->translate(glm::vec3(x, Y, z));
			node->rotate(-90.f, glm::vec3(1.f, 0.f, 0.f));
			node->scale(glm::vec3(2.f, 2.f, 2.f));

			pushBackObject(node);
			positions.push_back(glm::vec3(x, Y, z));
		}
	}
}

void UndirectedMapView::setEndNode(int layersNum) {
	std::shared_ptr<GraphNodeView> endNode(new GraphNodeView(GRAPH_NODE_VERTEX_SHADER_PATH, GRAPH_NODE_FRAGMENT_SHADER_PATH));

	float endX = 0;
	float endZ = static_cast<float>(-(DISTANCE_BETWEEN_LAYERS + DISTANCE_BETWEEN_LAYERS * layersNum));

	endNode->translate(glm::vec3(endX, Y, endZ));
	endNode->rotate(-90.f, glm::vec3(1.f, 0.f, 0.f));
	endNode->scale(glm::vec3(2.f, 2.f, 2.f));

	pushBackObject(endNode);
	positions.push_back(glm::vec3(endX, Y, endZ));
}

void UndirectedMapView::setEdges(const UndirectedMap& G) {
	for (int i = 0; i < G.V(); i++) {
		for (auto v : G.adj(i)) {
			//avoids double draw of the same edge
			if (v < i) {
				continue;
			}
			Point3D start = { positions[i].x, positions[i].y, positions[i].z };
			Point3D end = { positions[v].x, positions[v].y, positions[v].z };

			std::shared_ptr<GraphEdgeView> edge(new GraphEdgeView(start, end, GRAPH_EDGE_VERTEX_SHADER_PATH, GRAPH_EDGE_FRAGMENT_SHADER_PATH));
			pushBackObject(edge);
		}
	}
}