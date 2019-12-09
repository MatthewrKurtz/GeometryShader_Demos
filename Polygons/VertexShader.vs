#version 330 core
layout (location = 0) in vec2 aPos1;

void main()
{
	gl_Position = vec4(aPos1.x, aPos1.y, 0.0, 1.0); 
}