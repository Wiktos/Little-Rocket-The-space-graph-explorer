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
	static const int DISTANCE_BETWEEN_LAYERS = 4;
	static const int DISTANCE_BETWEEN_NODES = 4;

	std::vector<glm::vec3> positions;

	void drawStartNode();
	void drawInnerLayersNodes(const UndirectedMap& G);
	void drawEndNode(int layersNum);
	void drawEdges(const UndirectedMap& G);

public:

	UndirectedMapView(const UndirectedMap& G);
	UndirectedMapView(const UndirectedMapView&) = default;
	UndirectedMapView(UndirectedMapView&&) = default;

	UndirectedMapView& operator=(const UndirectedMapView&) = default;
	UndirectedMapView& operator=(UndirectedMapView&&) = default;

	~UndirectedMapView() = default;
};