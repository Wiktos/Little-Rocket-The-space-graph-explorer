#pragma once
#include <paths.h>

#include "../../map/undirected_map.h"
#include "complex_scene_object.h"
#include "graph_node_view.h"
#include "graph_edge_view.h"

/*
	UndirectedMapView class represents UndirectedMap in the OpenGL render Scene.

	by Wiktor £azarski
*/
class UndirectedMapView final : public ComplexSceneObject
{
	static const int Y = 0;
	static const int DISTANCE_BETWEEN_LAYERS = 5;
	static const int DISTANCE_BETWEEN_NODES = 5;

	std::vector<glm::vec3> positions;

	void setStartNode();
	void setInnerLayersNodes(const UndirectedMap& G);
	void setEndNode(int layersNum);
	void setEdges(const UndirectedMap& G);

public:

	UndirectedMapView(const UndirectedMap& G);
	UndirectedMapView(const UndirectedMapView&) = default;
	UndirectedMapView(UndirectedMapView&&) = default;

	UndirectedMapView& operator=(const UndirectedMapView&) = default;
	UndirectedMapView& operator=(UndirectedMapView&&) = default;

	glm::vec3 getVertexPosition(int idx) { return positions[idx]; }

	~UndirectedMapView() = default;
};