#version 330 core
layout (location = 0) in vec2 aPos1;
layout (location = 1) in vec2 aPos2;

out vec4 pos;

void main()
{
	pos = vec4(aPos2.x, aPos2.y, 0.0, 1.0);
    gl_Position = vec4(aPos1.x, aPos1.y, 0.0, 1.0); 
}