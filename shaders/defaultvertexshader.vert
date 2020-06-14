#version 330 core
layout (location = 0) in vec3 Lpos;//local position of the model verts
layout (location = 1) in vec3 Lcolor;//color of each vert
layout (location = 0) in vec3 LtexCords;//texture cordinates of each vert
out vec4 SColor;//color output data for fragment shader
out vec2 STexCoord;//color output data for fragment shader
uniform mat4 transform;//model matrix localspace to world space
uniform vec3 mcolor;//color data 
uniform mat4 tx_cord;//texture cordinates
vec4 _txtrans;//texture transform temporary storage data 
uniform mat4 projection; // projection matrix 
uniform mat4 view;//view matrix
uniform bool enablecamera=false;
void main()
{
 if(enablecamera == false)
 {
     //if the projection or view is an empty matrix then 
     //run without them 
     SColor = vec4(1.0f,0.0f,0.0f,1.0f);
     
      gl_Position = transform*vec4(Lpos.x,Lpos.y,Lpos.z, 1.0f);
 }
else if(enablecamera == true)
{
    //run with projection and view matrix
     SColor = vec4(mcolor,1.0f);
    gl_Position = projection*view*transform*vec4(Lpos.x,Lpos.y,Lpos.z, 1.0f);
}
   
    _txtrans=tx_cord*vec4(LtexCords.x,LtexCords.y,0,1.0f);
    STexCoord = vec2(_txtrans.x,_txtrans.y);
}