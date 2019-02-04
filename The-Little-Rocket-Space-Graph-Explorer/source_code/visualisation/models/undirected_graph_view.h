#pragma once
#include "../../map/undirected_map.h"
#include "complex_scene_object.h"
#include "graph_node_view.h"
#include "graph_edge_view.h"

/*
	TODO : 
	1) ComplexSceneObject interface
*/
class UndirectedMapView final : public ComplexSceneObject
{

public:

	UndirectedMapView(const UndirectedMap& G) {
		std::shared_ptr<GraphNodeView> node(new GraphNodeView("source_code/visualisation/shaders/node_vertex.vert", "source_code/visualisation/shaders/node_fragment.frag"));
		node->rotate(-55.f, glm::vec3(1.f, 0.f, 0.f));
		
		float leftBorderNodePos = (G.nodesPerLayer() / 2.f) * 5 - 2.5f;
		std::cout << leftBorderNodePos;
		
		pushBackObject(node);
	}


};