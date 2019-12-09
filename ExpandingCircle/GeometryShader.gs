#version 330 core
layout (points) in;
layout (line_strip, max_vertices = 200) out;

uniform float sides;
uniform float time;

out vec4 vColor;

void main() {    
	vec4 position = gl_in[0].gl_Position;
	const float PI = 3.1415926;	
	float angle;
	float t_Position = abs(sin(time));
	float t_Color = abs(cos(time));

	for(int i = 0; i < sides + 1; i++)
	{
		if(mod(i, 2) == 0)
		{
			gl_PointSize = 5.0;
			angle = 2 * PI / sides * i;
			gl_Position = position + vec4(cos(angle) * t_Position, sin(angle) * t_Position, 0.0, 1.0);
		}
		else
		{
			angle = 2 * PI / sides * i;
			gl_Position = position + vec4(cos(angle) * t_Position, sin(angle) * t_Position, 0.0, 1.0);
		}
		

		vColor =  vec4(1.0 * pow(t_Color, 2), 1.0 * (t_Color / 2),sqrt(t_Color), 1.0);

		EmitVertex();
	}

	EndPrimitive();
}