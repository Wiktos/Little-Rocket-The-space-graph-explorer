#pragma once
#include <array>
#include "scene_object.h"
#include "point3d.h"

/*
	GraphEdgeView class represents view of one edge that connects nodes of graph in OpenGL application.

	by Wiktor £azarski
*/
class GraphEdgeView final : public SceneObject
{
	static const short START_POINT_IDX = 0;
	static const short END_POINT_IDX = 1;
	std::array<Point3D, 2> points;

	void setDrawingDependencies();

	void drawObject() const;

public :

	GraphEdgeView(Point3D start, Point3D end, const std::string& vertexPath, const std::string& fragmentPath);
	GraphEdgeView(const GraphEdgeView&) = default;
	GraphEdgeView(GraphEdgeView&&) = default;

	GraphEdgeView& operator=(const GraphEdgeView&) = default;
	GraphEdgeView& operator=(GraphEdgeView&&) = default;

	~GraphEdgeView() = default;
};