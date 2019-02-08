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

public:

	AlgorithmMovement(SearchAlgorithm* alg) : engine(alg)
	{};

	void operator()(const UndirectedMapView& mapView, LittleRocket& rocket, std::shared_ptr<Camera> cam, const OpenGLApplication& app, int endNode) const;

};