/* $Id: ai_airporttype.cpp 22710 2011-08-01 20:15:18Z frosch $ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_airporttype.cpp Implementation of AIAirportType. */

#include "../../stdafx.h"
#include "ai_airporttype.hpp"
#include "ai_station.hpp"
#include "../../station_base.h"
#include "../../company_func.h"
#include "../../town.h"

/* static */ bool AIAirportType::IsBuildableAirportType(AirportType type)
{
	return IsAirportTypeInformationAvailable(type) && ::AirportSpec::Get(type)->IsAvailable();
}

/* static */ bool AIAirportType::IsAirportTypeInformationAvailable(AirportType type)
{
	return type >= 0 && type < (AirportType)NUM_AIRPORTS && AirportSpec::Get(type)->enabled;
}

/* static */ bool AIAirportType::IsValidPlaneType(PlaneType plane_type)
{
	return plane_type == PT_SMALL_PLANE || plane_type == PT_BIG_PLANE || plane_type == PT_HELICOPTER;
}

/* static */ Money AIAirportType::GetPrice(AirportType type)
{
	if (!IsBuildableAirportType(type)) return -1;

	const AirportSpec *as = ::AirportSpec::Get(type);
	return _price[PR_BUILD_STATION_AIRPORT] * as->size_x * as->size_y;
}

/* static */ int32 AIAirportType::GetAirportWidth(AirportType type)
{
	if (!IsAirportTypeInformationAvailable(type)) return -1;

	return ::AirportSpec::Get(type)->size_x;
}

/* static */ int32 AIAirportType::GetAirportHeight(AirportType type)
{
	if (!IsAirportTypeInformationAvailable(type)) return -1;

	return ::AirportSpec::Get(type)->size_y;
}

/* static */ int32 AIAirportType::GetAirportCoverageRadius(AirportType type)
{
	if (!IsAirportTypeInformationAvailable(type)) return -1;

	return _settings_game.station.modified_catchment ? ::AirportSpec::Get(type)->catchment : (uint)CA_UNMODIFIED;
}

/* static */ int AIAirportType::GetNoiseLevelIncrease(TileIndex tile, AirportType type)
{
	extern Town *AirportGetNearestTown(const AirportSpec *as, TileIndex airport_tile);
	extern uint8 GetAirportNoiseLevelForTown(const AirportSpec *as, TileIndex town_tile, TileIndex tile);

	if (!::IsValidTile(tile)) return -1;
	if (!IsAirportTypeInformationAvailable(type)) return -1;

	if (_settings_game.economy.station_noise_level) {
		const AirportSpec *as = ::AirportSpec::Get(type);
		const Town *t = AirportGetNearestTown(as, tile);
		return GetAirportNoiseLevelForTown(as, t->xy, tile);
	}

	return 1;
}

/* static */ TownID AIAirportType::GetNearestTown(TileIndex tile, AirportType type)
{
	extern Town *AirportGetNearestTown(const AirportSpec *as, TileIndex airport_tile);

	if (!::IsValidTile(tile)) return INVALID_TOWN;
	if (!AIAirportType::IsAirportTypeInformationAvailable(type)) return INVALID_TOWN;

	return AirportGetNearestTown(AirportSpec::Get(type), tile)->index;
}
