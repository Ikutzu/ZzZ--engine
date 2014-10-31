attribute vec2 attrPosition;
attribute vec3 attrColor;
attribute vec2 attrTexture;

uniform mat4 unifProjection;

varying vec3 varyColor;
varying vec2 textureCoords;

void main(void)
{
	textureCoords = attrTexture;
	varyColor = attrColor;
	gl_Position = unifProjection * vec4(attrPosition, 0.0, 1.0);
}