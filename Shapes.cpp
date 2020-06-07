#include "PixelR.h"
void Shapes::Rect2D()
{
	Pvector3f vertices[] = {
		Pvector3f{0.5f, 0.5f, 0.0f},Pvector3f{1.0f, 1.0f,0.0f},Pvector3f{1.0f,0.0f,0.0f},
		Pvector3f{ 0.5f,-0.5f, 0.0f},Pvector3f{1.0f, 0.0f,0.0f},Pvector3f{1.0f,0.0f,0.0f},
		Pvector3f{-0.5f,  0.5f, 0.0f},Pvector3f{0.0f, 1.0f,0.0f},Pvector3f{1.0f,0.0f,0.0f},
		Pvector3f{0.5f,-0.5f, 0.0f},Pvector3f{1.0f, 0.0f,0.0f},Pvector3f{1.0f,0.0f,0.0f},
		Pvector3f{-0.5f,-0.5f,0.0f},Pvector3f{0.0f, 0.0f,0.0f},Pvector3f{1.0f,0.0f,0.0f},
		Pvector3f{-0.5f,0.5f,0.0f},Pvector3f{0.0f, 1.0f,0.0f},Pvector3f{1.0f,0.0f,0.0f},
	};

	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Pvector3f), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Pvector3f), (void*)(1*sizeof(Pvector3f)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Pvector3f), (void*)(2 * sizeof(Pvector3f)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}