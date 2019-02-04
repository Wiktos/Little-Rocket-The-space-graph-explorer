#pragma once
#include <paths.h>

#include "../../map/undirected_map.h"
#include "complex_scene_object.h"
#include "graph_node_view.h"
#include "graph_edge_view.h"


class UndirectedMapView final : public ComplexSceneObject
{

	static const int Y = 0;
	static const int DISTANCE_BETWEEN_LAYERS = 4;
	static const int DISTANCE_BETWEEN_NODES = 4;

	std::vector<glm::vec3> positions;

	void setUpStartNode();
	void setUpInnerLayers(const UndirectedMap& G);
	void setUpEndNode(int layersNum);

public:

	UndirectedMapView(const UndirectedMap& G);
	UndirectedMapView(const UndirectedMapView&) = default;
	UndirectedMapView(UndirectedMapView&&) = default;

	UndirectedMapView& operator=(const UndirectedMapView&) = default;
	UndirectedMapView& operator=(UndirectedMapView&&) = default;

	~UndirectedMapView() = default;
};