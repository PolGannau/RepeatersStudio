#include "ModulePlayersManager.h"

ModulePlayersManager::ModulePlayersManager()
{}

ModulePlayersManager::~ModulePlayersManager()
{}

bool ModulePlayersManager::Start()
{


	return true;
}

bool ModulePlayersManager::CleanUp()
{


	return true;
}

ModuleHonda * ModulePlayersManager::CreatePlayer()
{
	return nullptr;
}

update_status ModulePlayersManager::Update()
{


	return update_status::UPDATE_CONTINUE;
}

