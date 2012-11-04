#pragma once

#include "MapTile.h"

#include <vector>

#ifndef SAFE_DELETE
#define SAFE_DELETE(a) { delete (a); (a) = NULL; }
#endif // SAFE_DELETE

class CWorldMap
{
private:
	bool CheckSize( unsigned int x, unsigned int y ); 

public:
	CWorldMap(void);
	~CWorldMap(void);

	std::vector<std::vector< CMapTile>> m_map ; 

	size_t			GetSizeX() ;
	size_t			GetSizeY() ;
	void			Resize	( unsigned int x, unsigned int y ); 
	CMapTile      & Get		( unsigned int x, unsigned int y ) ; 
	bool			Set		( unsigned int x, unsigned int y, CMapTile tile ) ; 
	bool			SetAttribute( unsigned int x, unsigned int y, std::string name, std::string value ) ; 
	
	friend std::ostream& operator<< (std::ostream &out, CWorldMap &worldMap);

};


std::ostream& operator<< (std::ostream &out, CWorldMap &worldMap);