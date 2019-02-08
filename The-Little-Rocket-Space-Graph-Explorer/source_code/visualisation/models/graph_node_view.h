#pragma once
#include <string>
#include <vector>

#include "../render/color.h"
#include "scene_object.h"
#include "point3d.h"

/*
	GraphNodeView class represents view of one node in OpenGL application.

	by Wiktor £azarski
*/
class GraphNodeView final : public SceneObject
{
	std::vector<Point3D> vertices;
	Color color = { 1.f, 1.f, 1.f };

	void computeVertecies();
	void setDrawingDependencies();
	void drawObject() const override;
	
public:

	GraphNodeView(const std::string& vertexPath, const std::string& fragmentPath);
	GraphNodeView(const GraphNodeView&) = default;
	GraphNodeView(GraphNodeView&&) = default;

	GraphNodeView& operator=(const GraphNodeView&) = default;
	GraphNodeView& operator=(GraphNodeView&&) = default;

	void changeColor(Color newColor) { color = newColor; }

	~GraphNodeView() = default;
};