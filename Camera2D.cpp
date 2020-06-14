#include "PixelR.h"
void Camera2D::init(unsigned int shaderid, float screen_width, float screen_height, float fov)
{
	projection_shader_location = glGetUniformLocation(shaderid, "projection");
	view_shader_location = glGetUniformLocation(shaderid, "view");
	enablecamera = glGetUniformLocation(shaderid, "enablecamera");
	projection = glm::perspective(glm::radians(fov), screen_width / screen_height, camera_near_clip, camera_far_clip);
	view = glm::lookAt(
		glm::vec3(0, 0, 3),//eye
		camera_position,//center <-- move this
		glm::vec3(0, 1, 0)//up
	);
	glUseProgram(shaderid);
	glUniformMatrix4fv(projection_shader_location, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(view_shader_location, 1, GL_FALSE, glm::value_ptr(view));
	glUniform1i(enablecamera, true);
}
void Camera2D::Update()
{
	view = glm::lookAt(
		glm::vec3(0, 0, 3),//eye
		camera_position,//center <-- move this
		glm::vec3(0, 1, 0)//up
	);
	glUniformMatrix4fv(projection_shader_location, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(view_shader_location, 1, GL_FALSE, glm::value_ptr(view));
	glUniform1i(enablecamera, true);
}