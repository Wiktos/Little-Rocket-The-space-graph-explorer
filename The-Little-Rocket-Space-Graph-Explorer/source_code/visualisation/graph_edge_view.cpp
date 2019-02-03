#include "graph_edge_view.h"

GraphEdgeView::GraphEdgeView(Point3D start, Point3D end, const std::string& vertexPath, const std::string& fragmentPath) : SceneObject(vertexPath, fragmentPath) {
	points[START_POINT_IDX] = start;
	points[END_POINT_IDX] = end;
	setDrawingDependencies();
}

void GraphEdgeView::setDrawingDependencies() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(Point3D), &points[START_POINT_IDX], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Point3D), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void GraphEdgeView::drawObject() const {
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINE_STRIP, 0, 2);
	glBindVertexArray(0);
}