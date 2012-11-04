#pragma once

#include "WorldMap.h"



class CTaxiAIServer
{
private:
	CWorldMap m_world ; 
	
	bool Load( ); 

	void Error( unsigned int errorCode, char * errorMessage ); 

	void DumpGameState(); 

public:
	CTaxiAIServer(void);
	~CTaxiAIServer(void);

	void Run() ; 
};

