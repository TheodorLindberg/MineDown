#version 400 core
layout (location = 0) in vec2 aPos;

out vec4 fragColor;

uniform int tile;
uniform vec2 offset;

uniform vec2 camoffset;

void main()
{
	if(tile == 0) {
		fragColor = vec4(1, 1, 0, 0);
	} else if(tile == 1) {
		fragColor = vec4(0, 1, 0, 0);		
	} else {
		fragColor = vec4(1, 0, 0, 0);		
	}
	
	vec4 worldPosition = vec4(aPos, 0, 1);
	worldPosition.y = -worldPosition.y;

	worldPosition.x += offset.x;
	worldPosition.y += -offset.y;

	worldPosition.xy += camoffset;

   gl_Position =  vec4(worldPosition.x,worldPosition.y,0, 1);
}