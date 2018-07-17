
#include <vector>
#include "asteroids.h"

using namespace oids;

int main()
{
    Asteroid* asteroid = new Asteroid;
    Ship* ship = new Ship;
    Bullet* bullet = new Bullet;

    std::vector<Object*> objects;

    objects.push_back(asteroid);
    objects.push_back(ship);
    objects.push_back(bullet);

    for (std::vector<Object*>::iterator A = objects.begin(); A < objects.end(); A++)
    for (std::vector<Object*>::iterator B = objects.begin(); B < objects.end(); B++)
    {
        (*A)->handleCollision(*B);
    }

    delete asteroid;
    delete ship;
    delete bullet;

    return 0;
}
