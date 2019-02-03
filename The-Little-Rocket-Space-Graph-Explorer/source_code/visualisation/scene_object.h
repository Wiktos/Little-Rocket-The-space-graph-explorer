#pragma once


class SceneObject
{
public :
	
	SceneObject() {}

	void draw() const {
		/*
			TODO:
			- IF SHADERS OR TRANSFORMATION SPECIFIED PERFORM
		*/

		drawObject();
	}

	virtual ~SceneObject() = default;

private :

	GLuint VAO, VBO;

	virtual void drawObject() const = 0;

};