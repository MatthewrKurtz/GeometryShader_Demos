#version 330 core
layout (points) in;
layout (points, max_vertices = 200) out;

uniform float sides;
uniform float time;

out vec4 vColor;

void main() {    
	vec4 position = gl_in[0].gl_Position;
	const float PI = 3.1415926;	
	float angle;
	//float t_Position = 1.0;
	float t_Position = pow(mod(time, PI/2),2);
	float t_Color = -mod(time, PI/2) + PI/4;

	vec4 Color_Yellow = vec4(1.0, 1.0, 0.0, 1.0);
	vec4 Color_Red = vec4(1.0, 0.0, 0.0, 1.0);
	vec4 Color_Blue = vec4(0.0, 0.0, 1.0, 1.0);
	vec4 Color_Green = vec4(0.0, 1.0, 0.0, 1.0);
	gl_PointSize = 5.0;

	for(int i = 0; i < sides + 1 && mod(time, PI/2) <= PI/4; i++)
	{
		angle = 2 * PI / sides * i;

		gl_Position = position + vec4( 0.5 * cos(angle) * t_Position, 0.5 * sin(angle) * t_Position, 0.0, 1.0);
		vColor =  vec4(t_Color, t_Color, t_Color, 1.0) * Color_Red;
		EmitVertex();

		gl_Position = position + vec4(cos(angle) * t_Position, sin(angle) * t_Position, 0.0, 1.0);
		vColor =  vec4(t_Color, t_Color, t_Color, 1.0) * Color_Yellow;
		EmitVertex();

		gl_Position = position + vec4(1.5 * cos(angle) * t_Position, 1.5 * sin(angle) * t_Position, 0.0, 1.0);
		vColor =  vec4(t_Color, t_Color, t_Color, 1.0) * Color_Blue;
		EmitVertex();

		gl_Position = position + vec4( 2.0 * cos(angle) * t_Position, 2.0 * sin(angle) * t_Position, 0.0, 1.0);
		vColor =  vec4(t_Color, t_Color, t_Color, 1.0) * Color_Green;
		EmitVertex();
	}


	EndPrimitive();
}