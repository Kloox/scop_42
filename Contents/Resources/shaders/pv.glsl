#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 ourColor;
out vec3 pos;
out vec2 vID;

uniform mat4 mvp;

uniform int d;
uniform int c;

uniform float time;

void main()
{
	// textureMapping = texMap;

	vID = vec2(gl_VertexID, 0.0f);
	TexCoord = aTexCoord;
	ourColor = vec3((cos(aColor.x + aPos.x) * 255 ) / 1000.0f, (sin(aColor.y + aPos.y) * 255 ) / 1000.0f, aColor.z);
	pos = aPos;
	if (d == 0) {
		gl_Position = mvp * vec4(aPos, 1.0f);
	} else {
		gl_Position = vec4(vec3(aPos.x, aPos.y, aPos.z), 1.0f);
	}

}