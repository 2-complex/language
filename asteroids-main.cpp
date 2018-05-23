
#include <stdio.h>

#include "asteroids.h"

using namespace oids;

int main()
{
    Asteroid* asteroid = new Asteroid;
    Ship* ship = new Ship;
    Bullet* bullet = new Bullet;

    asteroid->collide(asteroid);

    delete asteroid;
    delete ship;
    delete bullet;

    return 0;
}
