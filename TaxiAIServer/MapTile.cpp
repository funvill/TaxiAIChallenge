#include "MapTile.h"





CMapTile::CMapTile(unsigned int x, unsigned int y)	
{
	// Set the location of this tile 
	this->Set( TILE_LOCATION_X, toString( x ) );  
	this->Set( TILE_LOCATION_Y, toString( x ) ); 

	// Set the default stats of this tile 
	// To save space we can asume the defaults if not declared. 
	this->Set( TILE_ACCESSIBLE, TILE_VALUE_TRUE ) ; 
}

std::ostream& operator<< (std::ostream &out, CMapTile &tile) {
	
	out << "<tile>"; 
	if( tile.status.size() > 0 ) {		
		for( VMapRow::iterator it = tile.status.begin(); it != tile.status.end() ; it++ ) {
			out << "<" << (*it).first << ">" << (*it).second << "</" << (*it).first << ">"; 
		}		
	}
	out << "</tile>\n"; 

	return out ; 
}

void CMapTile::Set( std::string name, std::string value ) {
	this->status[ name ] = value ; 
}
