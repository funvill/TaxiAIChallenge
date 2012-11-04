#pragma once

#include <map>
#include <string>
#include <sstream>

typedef std::map<std::string, std::string> VMapRow ; 

// Names of stats 
#define TILE_ACCESSIBLE		"accessable"
#define TILE_LOCATION_X		"x"
#define TILE_LOCATION_Y		"y"

// Values of stats 
#define TILE_VALUE_TRUE		"true" 
#define TILE_VALUE_FALSE	"false" 

template<typename T> std::string toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}


class CMapTile
{
	private:
		VMapRow status;

	public:
		CMapTile(unsigned int x, unsigned int y);

		void Set( std::string name, std::string value ); 
		friend std::ostream& operator<< (std::ostream &out, CMapTile &tile);
};

std::ostream& operator<< (std::ostream &out, CMapTile &tile); 
