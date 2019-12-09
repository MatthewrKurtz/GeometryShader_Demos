#version 330 core
layout (points) in;
layout (line_strip, max_vertices = 64) out;

in vec4 pos[];

uniform float numOfLines;

void main() {    
	vec4 position = gl_in[0].gl_Position;
	vec4 position2 = pos[0];

	gl_Position = position;
	gl_PointSize = 10.0;
	EmitVertex();

	// float numOfLines = 3;

	float stepFactor = (position2.x - position.x) / numOfLines;
	float currentStep = stepFactor;
	float y;


	// Right hand side
	for(int i = 0; i < numOfLines; i++)
	{
		y = pow(currentStep + position.x, 2);

		gl_Position = vec4(position.x + currentStep, y + position.y, position.z, position.w);
		gl_PointSize = 5.0;
		EmitVertex();

		currentStep += stepFactor;
	}

	EndPrimitive();
}