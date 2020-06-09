#include "PixelR.h"
Sprite2D sprite[1000];
Texture2D tx;
void update();
int main()
{
	PixelWindow pixelGamewindow;//init window
	pixelGamewindow.init_GameWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE.c_str());//<--init
	glfwSetFramebufferSizeCallback(pixelGamewindow.GameWindow,OnWindowResize);//sets window resize cb
	Shapes rect;
	rect.Rect2D();
	unsigned int testshader = Shader::CreateShader("C:\\PixelRenderer\\Shaders\\defaultvertexshader.txt", "C:\\PixelRenderer\\Shaders\\defaultfragmentshader.txt");
    
	tx.loadtexture("C:\\PixelRenderer\\res\\male.png");
	//Texture2D tx2; tx2.loadtexture("C:\\PixelRenderer\\res\\pb.png");

   int x = 0;
   for (int i = 0; i < 1000; i++)
   {
	   sprite[i].init(testshader);
   }
   
   //timer
   auto const start_time = std::chrono::steady_clock::now();
   auto const wait_time = std::chrono::milliseconds{ 17 };
   auto next_time = start_time + wait_time;
	while (!glfwWindowShouldClose(pixelGamewindow.GameWindow))
	{
		x++;
		
		std::this_thread::sleep_until(next_time);	
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(testshader);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
	
		glBindTexture(GL_TEXTURE_2D, tx.textureid);
		for (int i = 0; i < 1000; i++)
		{
			sprite[i].Draw();
		}
		glfwSwapBuffers(pixelGamewindow.GameWindow);
		glfwPollEvents();
		next_time += wait_time;
		update();
	}
	
	return 0;
}
int x = 0;
void update()
{
	x++;
	for (int i = 0; i < 1000; i++)
	{
		sprite[i].Scale = { 32.0f / SCREEN_WIDTH,32.0f / SCREEN_HEIGHT,1.0f };
		sprite[i].Position = { x * 0.01f,32 / SCREEN_HEIGHT,0.0f };
		sprite[i].Update(32, 32, tx.w, tx.h, x, 1);
	}
	}
void OnWindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
