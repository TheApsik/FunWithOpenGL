#version 150 core

uniform vec3 objectPosition;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

in vec3 position;
in vec3 color;
in vec2 texCoord;

out vec3 Color;
out vec2 TexCoord;
void main() {
	Color = color;
	TexCoord = texCoord;
	gl_Position = projection * view * model * vec4(position+objectPosition, 1.0);
	//gl_Position = vec4(position, 1.0);
}