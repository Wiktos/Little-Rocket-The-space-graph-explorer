#pragma once
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader_program.h" 

/*
	SceneObject class provides an interface for every object that would like to be drawn in Scene.
	The method design pattern is used to release object from managing such things like using shader and applying transformations.

	by Wiktor £azarski
*/
class SceneObject
{
	//initialy model mat is identity mat 
	glm::mat4 model = glm::mat4(1.f);

	virtual void drawObject() const = 0;

protected:

	GLuint VAO, VBO;
	ShaderProgram shader;

public :
	
	SceneObject(const std::string& vertexPath, const std::string& fragmentPath);

	void draw() const;
	void rotate(float angle, glm::vec3 axis) {
		model = glm::rotate(model, glm::radians(angle), axis);
	}
	void translate(glm::vec3 vec) {
		model = glm::translate(model, vec);
	}
	void scale(glm::vec3 vec) {
		model = glm::scale(model, vec);
	}

	virtual ~SceneObject();
};