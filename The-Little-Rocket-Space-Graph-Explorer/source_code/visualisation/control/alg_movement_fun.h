#pragma once
#include <glm/gtc/type_ptr.hpp>

#include "../render/opengl_application.h"
#include "../../algorithms/search_algorithm.h"
#include "../models/undirected_map_view.h"
#include "../models/little_rocket.h"

/*
	AlgorithmMovement class is a functor that coordinates moves of LittleRocket so that it moves according to the trace of search algorithm.

	by Wiktor £azarski
*/
class AlgorithmMovement
{
	std::shared_ptr<SearchAlgorithm> engine;
	Color visited = { .3f, 1.f, .3f }; 
	Color belongs = { 1.f, .2f, .3f };

	void visualiseAlgorithm(UndirectedMapView& mapView, LittleRocket& rocket, std::shared_ptr<Camera> cam, const OpenGLApplication& app, int endNode) const;
	void updatePathNodesColors(UndirectedMapView& mapView, const OpenGLApplication& app, int endNode) const;
	void markNodeAsVisited(UndirectedMapView& mapView, int v) const;
	void markNodeAsPathNode(UndirectedMapView& mapView, int v) const;

public:

	AlgorithmMovement(SearchAlgorithm* alg) : engine(alg)
	{};

	void operator()(UndirectedMapView& mapView, LittleRocket& rocket, std::shared_ptr<Camera> cam, const OpenGLApplication& app, int endNode) const;

	void setVisitedColor(Color visited) { this->visited = visited; }
	void setBelongsColor(Color belongs) { this->belongs = belongs; }

};