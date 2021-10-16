#include "light.h"
#include "object.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    vec3 ambient;
    vec3 diffuse;

    //Ambient
    ambient = color_ambient;

    TODO; //determine the color
    for(unsigned i = 0; i < world.lights.size(); i++){ //For every color in the world space
        vec3 l = world.lights[i]->position - intersection_point; //Calculate l for each light 

    //Diffuse Id = (Rd)(Ld)(max(dot(n ,l), 0))
    diffuse = color_diffuse * world.lights[i]->Emitted_Light(l) * std::max(dot(normal, l.normalized()), 0.00);

    //Specular TODO


    }
    color = ambient + diffuse;
    return color;
}
