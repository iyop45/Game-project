#include "World.h"

// To generate the unique entity keys
#include "Utility/Random.h"

namespace game {

using namespace utilities;

World::World()
{
}


World::~World()
{
}

entityPointer World::getEntity(std::string key)
{
	return entityContainer[key];
}

std::string World::createEntity(entityPointer entity)
{
	// Add to container and then return entity
	
	// Create a random key, this will be the unique key for this entitity
	// - May need to check this key does not already exist first!
	std::string randomKey = randomString(5);

	entityContainer[entity->getName() + "_" + randomKey] = entity;

	return randomKey;
}

void World::removeEntity(int id)
{

}

void World::setup()
{
	// -------------- Temporary ---------------
	// Create entities for level
	std::shared_ptr<Character> character(new Character());
	createEntity(character);
	// ----------------------------------------

	// Loop through all the created entities and call setup
	for (auto &entity : entityContainer)
	{
		// Calling setup on each entity will also internally call
		// setup on each of their components
		entity.second->setup();
	}
}

void World::update()
{
	// Loop through all entities and call update
	for (auto &entity : entityContainer)
	{
		entity.second->update();
	}
}

}

