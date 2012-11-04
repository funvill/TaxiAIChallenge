#include "stdafx.h"
#include "WorldMap.h"


CWorldMap::CWorldMap(void)
{
}

CWorldMap::~CWorldMap(void)
{
}

std::ostream& operator<< (std::ostream &out, CWorldMap &worldMap){
	
	out << "<worldmap sizeX='"<< worldMap.GetSizeX() <<"' sizey='"<< worldMap.GetSizeY() <<"'>"; 
	for( size_t offsetX = 0 ; offsetX < worldMap.GetSizeX() ; offsetX++ ) {
		for( size_t offsetY = 0 ; offsetY < worldMap.GetSizeY() ; offsetY++ ) {
			out << worldMap.m_map[offsetX][offsetY] ; 
		}
	}
	out << "</worldmap>"; 

	return out ; 
}


size_t CWorldMap::GetSizeX() {
	return this->m_map.size(); 
}
size_t CWorldMap::GetSizeY() {
	if( this->GetSizeX() > 0 ) {
		return this->m_map[0].size(); 
	}
	return 0 ; 
}

bool CWorldMap::CheckSize( unsigned int x, unsigned int y ) {
	if( x >= this->GetSizeX() || y >= this->GetSizeY() ) {
		return false; 
	}
	return true; 
}

void CWorldMap::Resize( unsigned int x, unsigned int y ) {
	this->m_map = std::vector<std::vector<CMapTile> >(x, std::vector<CMapTile>(y, CMapTile(0,0)));
	for( size_t offsetX = 0 ; offsetX < x ; offsetX++ ) {
		for( size_t offsetY = 0 ; offsetY < x ; offsetY++ ) {
			this->SetAttribute( offsetX, offsetY, TILE_LOCATION_X, toString( offsetX ) );
			this->SetAttribute( offsetX, offsetY, TILE_LOCATION_Y, toString( offsetY ) );
		}
	}
}

bool CWorldMap::Set( unsigned int x, unsigned int y, CMapTile tile ) {
	if( ! this->CheckSize( x, y ) ) {
		return false; 
	}

	this->m_map[x][y] = tile ; 
	return true; 
}
bool CWorldMap::SetAttribute( unsigned int x, unsigned int y, std::string name, std::string value ) {
	if( ! this->CheckSize( x,y ) ) {
		return false; 
	}
	CMapTile tile = this->Get( x,y ); 
	tile.Set( name, value ); 
	return this->Set( x,y, tile ); 
}


CMapTile & CWorldMap::Get( unsigned int x, unsigned int y )  {
	if( ! this->CheckSize( x,y ) ) {
		// ToDo: This is an error and should throw an error message or excption. 
		return CMapTile(x,y); 
	}

	return this->m_map[x][y]; 
}

