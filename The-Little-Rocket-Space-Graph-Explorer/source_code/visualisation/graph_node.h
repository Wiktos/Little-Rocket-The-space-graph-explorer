#pragma once
#include <string>
#include <vector>
#include <math.h>

#include "scene_object.h"
#include "point3D.h"

class GraphNode final : public SceneObject
{
	mutable std::vector<Point3D> vertices;

	void computeVertecies() const;
	void setDrawingDependencies() const;
	void drawObject() const;
	
public:

	GraphNode(const std::string& vertexPath, const std::string& fragmentPath);

};