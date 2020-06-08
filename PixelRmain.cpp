#include "PixelR.h"

int main()
{
	PixelWindow pixelGamewindow;//init window
	pixelGamewindow.init_GameWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE.c_str());//<--init
	glfwSetFramebufferSizeCallback(pixelGamewindow.GameWindow,OnWindowResize);//sets window resize cb
	Shapes rect;
	rect.Rect2D();
	unsigned int testshader = Shader::CreateShader("C:\\PixelRenderer\\Shaders\\defaultvertexshader.txt", "C:\\PixelRenderer\\Shaders\\defaultfragmentshader.txt");
    
	Texture2D tx;tx.loadtexture("C:\\PixelRenderer\\res\\male.png");
 
   int x = 0;
   Sprite2D sprite;
   sprite.Scale = { 0.32f,0.32f,0.0f };
   sprite.Position = { -0.5f,0.0f,0.0f };
   Sprite2D sprite1;
   sprite1.Scale = { 0.5f,0.5f,0.0f };
   sprite1.Position = { -1.0f,0.0f,0.0f };
   sprite1.color = { 1.0f,0.0f,0.0f };
	//game loop
  
   

	while (!glfwWindowShouldClose(pixelGamewindow.GameWindow))
	{
		x = x + 1;
		
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, tx.textureid);
		glUseProgram(testshader);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
	
		sprite.Draw(testshader,32,32,tx.w,tx.h,x,2);
		
		glfwSwapBuffers(pixelGamewindow.GameWindow);
		glfwPollEvents();
	}
	
	return 0;
}
void OnWindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
