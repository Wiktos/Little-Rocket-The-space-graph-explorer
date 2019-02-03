#pragma once
#include <string>
#include <vector>

#include "scene_object.h"
#include "point3D.h"

/*
	GraphNodeView class represents view of one node in OpenGL application.

	by Wiktor £azarski
*/
class GraphNodeView final : public SceneObject
{
	mutable std::vector<Point3D> vertices;

	void computeVertecies() const;
	void setDrawingDependencies() const;
	void drawObject() const;
	
public:

	GraphNodeView(const std::string& vertexPath, const std::string& fragmentPath);
	GraphNodeView(const GraphNodeView&) = default;
	GraphNodeView(GraphNodeView&&) = default;

	GraphNodeView& operator=(const GraphNodeView&) = default;
	GraphNodeView& operator=(GraphNodeView&&) = default;

	~GraphNodeView() = default;
};