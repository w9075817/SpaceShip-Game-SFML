//Andrew Morgan Hartley
//W9075817

//Include the World Header File
#include "World.h"

//The main program loop
void HAPI_Main()
{
	//Create an instance of the world
	World World;
	//Run the load level function which Loads Sprites, set variables, etc.
	World.LoadLevel();
	//Run the main loop of the game.
	World.Run();
}