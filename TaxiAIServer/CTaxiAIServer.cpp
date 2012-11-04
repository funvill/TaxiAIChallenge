#include "CTaxiAIServer.h"
#include <iostream>


CTaxiAIServer::CTaxiAIServer(void)
{
}


CTaxiAIServer::~CTaxiAIServer(void)
{
}

void CTaxiAIServer::Error( unsigned int errorCode, char * errorMessage ) {
	printf( "Error (%d): %s\n", errorCode, errorMessage );
}

void CTaxiAIServer::Run() {

	// Load the game map 
	if( ! this->Load() ) {
		this->Error( 1, "Can not load map" ); 
		return ; 
	}

	// Print the game state.
	this->DumpGameState(); 

}

bool CTaxiAIServer::Load( ) {
	
	this->m_world.Resize( 5, 5 ); 
	
	this->m_world.SetAttribute( 3, 4, TILE_ACCESSIBLE, TILE_VALUE_FALSE ) ; 
	this->m_world.SetAttribute( 2, 4, TILE_ACCESSIBLE, TILE_VALUE_FALSE ) ; 


	return true; 
}

void CTaxiAIServer::DumpGameState() {
	std::cout << "[start]";  
	std::cout << this->m_world ; 

}