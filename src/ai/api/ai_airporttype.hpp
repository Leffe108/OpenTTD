/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_airporttype.hpp Everything to query information about airport types. */

#ifndef AI_AIRPORTTYPE_HPP
#define AI_AIRPORTTYPE_HPP

#include "ai_object.hpp"
#include "ai_types.hpp"

/**
 * Class that handles all airport type related functions.
 */
class AIAirportType : public AIObject {
public:
	/** Get the name of this class to identify it towards squirrel. */
	static const char *GetClassName() { return "AIAirportType"; }

	/**
	 * All plane types available.
	 */
	enum PlaneType {
		/* Note: the values _are_ important as they represent an in-game value */
		PT_HELICOPTER    =   0, ///< A helicopter.
		PT_SMALL_PLANE   =   1, ///< A small plane.
		PT_BIG_PLANE     =   3, ///< A big plane.

		PT_INVALID       =  -1, ///< An invalid PlaneType
	};

	/**
	 * Checks whether the given AirportType is valid and available.
	 * @param type The AirportType to check.
	 * @return True if and only if the AirportType is valid and available.
	 * @post return value == true -> IsAirportTypeInformationAvailable returns true.
	 */
	static bool IsBuildableAirportType(AirportType type);

	/**
	 * Can you get information on this airport type? As opposed to
	 * IsBuildable this will return also return true when
	 * an airport type is no longer buildable.
	 * @param type The AirportType to check.
	 * @return True if and only if the AirportType is valid.
	 * @post return value == false -> IsBuildableAirportType returns false.
	 */
	static bool IsAirportTypeInformationAvailable(AirportType type);

	/**
	 * Check if a view is valid for a given airport type.
	 * @param airport_view The view to check
	 * @param airport_type The airport type for which to check if the view exist
	 * @return True if and only if the AirportView is valid for the give AirportType
	 */
	static bool IsValidAirportView(AirportView airport_view, AirportType airport_type);

	/**
	 * Checks wheather the given PlaneType is valid
	 * @param plane_type The PlaneType to check.
	 * @return True if and only if the PlaneType is valid
	 */
	static bool IsValidPlaneType(PlaneType plane_type);

	/**
	 * Get the cost to build this AirportType.
	 * @param type The AirportType to check.
	 * @pre IsBuildableAirportType(type).
	 * @return The cost of building this AirportType.
	 */
	static Money GetPrice(AirportType type);

	/**
	 * Get the width of of the given airport type.
	 * @param type The type of airport.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The width in tiles.
	 */
	static int32 GetAirportWidth(AirportType type);

	/**
	 * Get the height of of the given airport type.
	 * @param type The type of airport.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The height in tiles.
	 */
	static int32 GetAirportHeight(AirportType type);

	/**
	 * Get the number of hangars of the given airport type.
	 * @param type The type of airport.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The number of hangars.
	 */
	static int32 GetNumHangars(AirportType type);

	/**
	 * Get the number of helipads of the given airport type.
	 * @param type The type of airport.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The number of helipads.
	 */
	static int32 GetNumHelipads(AirportType type);

	/**
	 * Get the number of terminals of the given airport type.
	 * @param type The type of airport.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The number of terminals.
	 */
	static int32 GetNumTerminals(AirportType type);

	/**
	 * Check if a plane type can land on a airport type
	 * @param type The type of airport.
	 * @param plane_type The plane type.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @pre IsValidPlaneType(plane_type).
	 * @return True if and only if the given plane type can land on the given airport type.
	 */
	static bool CanPlaneTypeLand(AirportType type, PlaneType plane_type);

	/**
	 * Check if landing on the given airport type is extra dangerous for a given plane type.
	 * Extra dangerous airport and plane type combinations increase the chance that the
	 * airplane will crash on landing.
	 * @param type The type of airport.
	 * @param plane_type The plane type.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @pre IsValidPlaneType(plane_type).
	 * @pre CanPlaneTypeLand(type, plane_type)
	 * @return True if and only if the given plane type has a higher crash chance than usual when landing on the given airport type.
	 */
	static bool IsLandingExtraDangerous(AirportType type, PlaneType plane_type);

	/**
	 * Get the coverage radius of this type of airport.
	 * @param type The type of airport.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The radius in tiles.
	 */
	static int32 GetAirportCoverageRadius(AirportType type);

	/**
	 * Get the noise that will be added to the nearest town if an airport was
	 *  built at this tile.
	 * @param tile The tile to check.
	 * @param type The AirportType to check.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The amount of noise added to the nearest town.
	 * @note The noise will be added to the town with TownID GetNearestTown(tile, type).
	 */
	static int GetNoiseLevelIncrease(TileIndex tile, AirportType type);

	/**
	 * Get the TownID of the town whose local authority will influence
	 *  an airport at some tile.
	 * @param tile The tile to check.
	 * @param type The AirportType to check.
	 * @pre IsAirportTypeInformationAvailable(type).
	 * @return The TownID of the town closest to the tile.
	 */
	static TownID GetNearestTown(TileIndex tile, AirportType type);
};

#endif /* AI_AIRPORTTYPE_HPP */
