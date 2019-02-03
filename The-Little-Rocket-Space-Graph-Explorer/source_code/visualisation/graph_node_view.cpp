#include <math.h>
#include "graph_node_view.h"

GraphNodeView::GraphNodeView(const std::string& vertexPath, const std::string& fragmentPath) : SceneObject(vertexPath, fragmentPath) {
	computeVertecies();
	setDrawingDependencies();
}

void GraphNodeView::computeVertecies() {
	float radius = 0.5f;

	for (int i = 0; i < 360; i++) {
		float x = static_cast<float>(radius * cos(i * acos(-1) / 180.f));
		float y = static_cast<float>(radius * sin(i * acos(-1) / 180.f));
		float z = 0.f;
		vertices.push_back({ x, y, z });
	}
}

void GraphNodeView::setDrawingDependencies() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Point3D) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Point3D), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void GraphNodeView::drawObject() const {
	glBindVertexArray(VAO);
	glDrawArrays(GL_POLYGON, 0, vertices.size());
	glBindVertexArray(0);
}