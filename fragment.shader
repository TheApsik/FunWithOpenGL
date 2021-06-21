#version 150 core
in vec3 Color;
in vec2 TexCoord;
out vec4 outColor;
uniform sampler2D Texture;
void main()
{
	outColor = texture(Texture, TexCoord);
	//outColor = vec4(Color, 1.0);
	//outColor = vec4(vec3(gl_FragCoord.z), 1.0); // test depth
}