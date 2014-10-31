varying vec3 varyColor;
varying vec2 textureCoords;
uniform sampler2D sampleri;

void main (void)
{
	gl_FragColor = texture(sampleri, textureCoords) + vec4(varyColor, 0.0);
}