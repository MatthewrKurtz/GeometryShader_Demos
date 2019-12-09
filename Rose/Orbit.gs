#version 330 core
layout (points) in;
layout (points, max_vertices = 256) out;

uniform float sides;
uniform float time;
uniform float numberOfPetals;

out vec4 vColor;

float rand(vec2 co)
{
   return fract(sin(dot(co.xy,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {    
	vec4 position = gl_in[0].gl_Position;
	const float PI = 3.1415926;	
	float angle;

	float t_Color = sin(time);
	vec4 Color_Yellow = vec4(1.0, 1.0, 0.0, 1.0);
	vec4 Color_Red = vec4(1.0, 0.0, 0.0, 1.0);
	vec4 Color_Blue = vec4(0.0, 0.0, 1.0, 1.0);
	vec4 Color_Green = vec4(0.0, 1.0, 0.0, 1.0);

	gl_PointSize = 10.0;

	//angle = 2 * PI / sides * i; 
	angle = time;
	float randomNumber = rand(vec2(sides, angle));
	float t_Position = randomNumber;

	gl_Position = position + vec4(cos(numberOfPetals * angle) * cos(angle), cos(numberOfPetals * angle) * sin(angle) , 0.0, 1.0);
	//vColor =  vec4(t_Color, t_Color, t_Color, 1.0) * Color_Green;
	vColor = Color_Green;
	EmitVertex();
	


	EndPrimitive();
}