#include "GameWorld.hpp"

#include <iostream>
#include "GraphicsUtils.hpp"

#include "Props/Fire.hpp"
#include "Props/Guts.hpp"

GameWorld::GameWorld() :
    _dt(0.016),
    _level(MAP_SIZE, MAP_SIZE),
    _phyManager(_dt, CELL_SIZE, Vec2(MAP_SIZE, MAP_SIZE), this)
{
    _phyManager.setGravity(Vec2(0.0f, 0.0f));
    _phyManager.setPrecision(2);

    Guts::init();
    Hunter::init();
    Bullet::init();
    BulletShell::init();
    AK::init();
    Shotgun::init();
    Pistol::init();
    Smoke::init();
    Fire::init();
    Zombie::init();
    Explosion::init();

    _level.render();
}

void GameWorld::initEventHandler(sf::RenderWindow& window)
{
    _eventManager.init(&window);
}

void GameWorld::addEntity(WorldEntity* entity)
{
    _entities.push_back(entity);

    entity->initPhysics(this);
}

void GameWorld::update()
{
    _entities.remove_if([=](const WorldEntity* e){return e->isDone();});

    //sf::Clock clock;
    _phyManager.update();
    //float time = clock.restart().asMilliseconds();

    for (WorldEntity* entity : _entities)
    {
        entity->update(*this);
    }

    std::cout << "Entities : " << _entities.size() << std::endl;
}

GridCell* GameWorld::getBodiesAt(Vec2 coord)
{
    return _phyManager.getBodyAt(coord);
}

void GameWorld::render()
{
    for (WorldEntity* entity : _entities)
    {
        entity->render();
    }
}

void GameWorld::removeBody(U_2DBody* body)
{
    _phyManager.killBody(body);
}

U_2DConstraint* GameWorld::addConstraint(U_2DBody* body1, U_2DBody* body2, float length)
{
    return _phyManager.addConstraint(body1, body2, length);
}

void GameWorld::addBody(U_2DBody* body)
{
    _phyManager.addBody(body);
}

void GameWorld::removeConstraint(U_2DConstraint* constraint)
{
    _phyManager.killConstraint(constraint);
}



