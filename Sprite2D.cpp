#include "PixelR.h"
void Sprite2D::Draw(unsigned int shaderid,float frame_w,float frame_h,float txw,float txh,int col,int row)
{
	x = x + 0.01f;
	unsigned int txlocc = glGetUniformLocation(shaderid, "tx_cord");
	glm::mat4 txtran = glm::mat4(1.0f);
	txtran = glm::scale(txtran, glm::vec3(frame_w/txw,frame_h/txh, 0.0f));
	txtran = glm::translate(txtran, glm::vec3(frame_w*col,(row*frame_h)/frame_h,32));
	glUniformMatrix4fv(txlocc, 1, GL_FALSE, glm::value_ptr(txtran));

	transformloc = glGetUniformLocation(shaderid,"transform");//mat4
	colorloc = glGetUniformLocation(shaderid,"mcolor");//vec3
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::scale(trans, glm::vec3(Scale.x,Scale.y,1.0f));
	trans = glm::translate(trans, glm::vec3(Position.x, Position.y, 0.0f));
	glUniformMatrix4fv(transformloc, 1, GL_FALSE, glm::value_ptr(trans));
	glUniform3f(colorloc, color.x, color.y, color.z);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}