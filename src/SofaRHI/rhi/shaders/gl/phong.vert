#version 440

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

layout(location = 0) out vec3 out_world_position;
layout(location = 1) out vec3 out_normal;
layout(location = 2) out vec2 out_uv;

layout(std140, binding = 0) uniform CameraUniform 
{
    mat4 mvp_matrix;
    vec3 camera_position;
} u_camerabuf;

out gl_PerVertex 
{ 
	vec4 gl_Position;
};

void main()
{
    gl_Position = u_camerabuf.mvp_matrix * position;
    out_world_position = position.xyz;
    out_normal = normal;
    out_uv = uv;
}
