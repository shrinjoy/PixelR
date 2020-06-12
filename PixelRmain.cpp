#include "PixelR.h"

Texture2D tx;
Sprite2D Player;
Camera2D camera;
unsigned int testshader;
void update();
int main()
{
	PixelWindow pixelGamewindow;//init gamw window class
	pixelGamewindow.init_GameWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE.c_str());//<--init
	//call gl functions after init game window ^^^^
	glfwSetFramebufferSizeCallback(pixelGamewindow.GameWindow,OnWindowResize);//sets window resize cb
	
	Shapes rect;
	rect.Rect2D();
	testshader = Shader::CreateShader("C:\\PixelRenderer\\Shaders\\defaultvertexshader.vert", "C:\\PixelRenderer\\Shaders\\defaultfragmentshader.frag");
    tx.loadtexture("C:\\PixelRenderer\\res\\male.png");
	Player.init(testshader);
	Player.Scale = { 128.0f/SCREEN_WIDTH,128.0f/SCREEN_HEIGHT,1.0f };
	Player.Position = { -1.0f,-1,1.0f };
	Player.UpdateRectPosition();
	//camera
	
	
	glm::mat4 project = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
	camera.init(testshader, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT);
	
	float x = 0;
	while (!glfwWindowShouldClose(pixelGamewindow.GameWindow))
	{
		x += 0.005f;
		update();
		std::this_thread::sleep_for(std::chrono::milliseconds(17));	
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(testshader);
		
		camera.Update();
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glDisable(GL_CULL_FACE);
		

		glBindTexture(GL_TEXTURE_2D, tx.textureid);
		Player.Draw();
		glfwSwapBuffers(pixelGamewindow.GameWindow);
		glfwPollEvents();
		
		
	}
	
	return 0;
}

void update()
{
	
	
	
	Player.UpdateSpriteTexture(32, 32, tx.w, tx.h, 1, 1);
	
}
void OnWindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
