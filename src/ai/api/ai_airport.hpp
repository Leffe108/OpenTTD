/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_airport.hpp Everything to query and build airports. */

#ifndef AI_AIRPORT_HPP
#define AI_AIRPORT_HPP

#include "ai_object.hpp"
#include "ai_airporttype.hpp"

/**
 * Class that handles all airport related functions.
 */
class AIAirport : public AIObject {
public:
	/** Get the name of this class to identify it towards squirrel. */
	static const char *GetClassName() { return "AIAirport"; }

	/**
	 * Checks whether the given tile is actually a tile with a hangar.
	 * @param tile The tile to check.
	 * @pre AIMap::IsValidTile(tile).
	 * @return True if and only if the tile has a hangar.
	 */
	static bool IsHangarTile(TileIndex tile);

	/**
	 * Checks whether the given tile is actually a tile with an airport.
	 * @param tile The tile to check.
	 * @pre AIMap::IsValidTile(tile).
	 * @return True if and only if the tile has an airport.
	 */
	static bool IsAirportTile(TileIndex tile);

	/**
	 * Get the number of hangars of the airport.
	 * @param tile Any tile of the airport.
	 * @pre AIMap::IsValidTile(tile).
	 * @return The number of hangars of the airport.
	 */
	static int32 GetNumHangars(TileIndex tile);

	/**
	 * Get the first hanger tile of the airport.
	 * @param tile Any tile of the airport.
	 * @pre AIMap::IsValidTile(tile).
	 * @pre GetNumHangars(tile) > 0.
	 * @return The first hanger tile of the airport.
	 * @note Possible there are more hangars, but you won't be able to find them
	 *  without walking over all the tiles of the airport and using
	 *  IsHangarTile() on them.
	 */
	static TileIndex GetHangarOfAirport(TileIndex tile);

	/**
	 * Builds a airport with tile at the topleft corner.
	 * @param tile The topleft corner of the airport.
	 * @param type The type of airport to build.
	 * @param view The view of given airport type to build
	 * @param station_id The station to join, AIStation::STATION_NEW or AIStation::STATION_JOIN_ADJACENT.
	 * @pre AIMap::IsValidTile(tile).
	 * @pre AIAirportType::IsBuildableAirportType(type).
	 * @pre AIAirportType::IsValidAirportView(type, view).
	 * @pre station_id == AIStation::STATION_NEW || station_id == AIStation::STATION_JOIN_ADJACENT || AIStation::IsValidStation(station_id).
	 * @exception AIError::ERR_AREA_NOT_CLEAR
	 * @exception AIError::ERR_FLAT_LAND_REQUIRED
	 * @exception AIError::ERR_LOCAL_AUTHORITY_REFUSES
	 * @exception AIStation::ERR_STATION_TOO_LARGE
	 * @exception AIStation::ERR_STATION_TOO_CLOSE_TO_ANOTHER_STATION
	 * @return Whether the airport has been/can be build or not.
	 */
	static bool BuildAirport(TileIndex tile, AirportType type, AirportView view, StationID station_id);

	/**
	 * Removes an airport.
	 * @param tile Any tile of the airport.
	 * @pre AIMap::IsValidTile(tile).
	 * @exception AIError::ERR_OWNED_BY_ANOTHER_COMPANY
	 * @return Whether the airport has been/can be removed or not.
	 */
	static bool RemoveAirport(TileIndex tile);

	/**
	 * Get the AirportType of an existing airport.
	 * @param tile Any tile of the airport.
	 * @pre AITile::IsStationTile(tile).
	 * @pre AIStation::HasStationType(AIStation.GetStationID(tile), AIStation::STATION_AIRPORT).
	 * @return The AirportType of the airport.
	 */
	static AirportType GetAirportType(TileIndex tile);

	/**
	 * Get the AirportView of an existing airport
	 * @param tile Any tile of the airport.
	 * @pre AITile::IsStationTile(tile)
	 * @pre AIStation::HasStationType(AIStation.GetStationID(tile), AIStation::STATION_AIRPORT).
	 * @return The AirportView of the airport.
	 */
	static AirportView GetAirportView(TileIndex tile);
};

#endif /* AI_AIRPORT_HPP */
