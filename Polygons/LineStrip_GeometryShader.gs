#version 330 core
layout (points) in;
layout (line_strip, max_vertices = 200) out;

uniform float sides;

void main() {    
	vec4 position = gl_in[0].gl_Position;
	const float PI = 3.1415926;	
	float angle;

	for(int i = 0; i < sides + 1; i++)
	{
		angle = 2 * PI / sides * i;
		gl_Position = position + vec4(cos(angle) * 0.5, sin(angle) * 0.5, 0.0, 1.0);
		EmitVertex();
	}

	EndPrimitive();
}