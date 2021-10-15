#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{   //(a) t^2 * dot(B, B) + 
    //(b) 2t * dot(B, A - C) + 
    //(c) dot(A - C, A - C) - r^2
    //Where A = vec endpoint
    //      B = direction vector
    //      C = center of sphere

    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, (ray.endpoint - center));
    double c = dot((ray.endpoint - center), (ray.endpoint - center)) - (radius * radius);
    Hit h;

    double t0 = -1;
    double t1 = -1;

    double discriminant = ((b * b) - (4 * (a * c)));
    if(discriminant >= 0 && a > 0){ //There is an intersection with the sphere
        t0 = (sqrt(discriminant) - b) / (2 * a); //Calculate the (potentially) 2 intersection points w the sphere
        t1 = ((0 - b) - sqrt(discriminant)) / (2 * a);
    }

    if(t0 < small_t){ //Check if either intersection is < small_t
        t0 = -1;
    }

    if(t1 < small_t){
        t1 = -1;
    }

    if((t0 > 0) || (t1 > 0)){ //Check that either of the intersection points are > small_t
        h.object = this;
    }

    if(t0 > 0 && t1 > 0){ //Intersection through the sphere
        h.dist = std::min(t0, t1); //Distance is the closer intersection point of the two
    }else if(t0 > 0){
        h.dist = t0;
    }else{
        h.dist = t1;
    }

    
    return h;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; // compute the normal direction
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}

