/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_airport.cpp Implementation of AIAirport. */

#include "../../stdafx.h"
#include "ai_airport.hpp"
#include "ai_station.hpp"
#include "../../station_base.h"
#include "../../company_func.h"
#include "../../town.h"

/* static */ bool AIAirport::IsHangarTile(TileIndex tile)
{
	if (!::IsValidTile(tile)) return false;

	return ::IsTileType(tile, MP_STATION) && ::IsHangar(tile);
}

/* static */ bool AIAirport::IsAirportTile(TileIndex tile)
{
	if (!::IsValidTile(tile)) return false;

	return ::IsTileType(tile, MP_STATION) && ::IsAirport(tile);
}

/* static */ bool AIAirport::BuildAirport(TileIndex tile, AirportType type, StationID station_id)
{
	EnforcePrecondition(false, ::IsValidTile(tile));
	EnforcePrecondition(false, AIAirportType::IsBuildableAirportType(type));
	EnforcePrecondition(false, station_id == AIStation::STATION_NEW || station_id == AIStation::STATION_JOIN_ADJACENT || AIStation::IsValidStation(station_id));

	uint p2 = station_id == AIStation::STATION_JOIN_ADJACENT ? 0 : 1;
	p2 |= (AIStation::IsValidStation(station_id) ? station_id : INVALID_STATION) << 16;
	return AIObject::DoCommand(tile, type, p2, CMD_BUILD_AIRPORT);
}

/* static */ bool AIAirport::RemoveAirport(TileIndex tile)
{
	EnforcePrecondition(false, ::IsValidTile(tile))
	EnforcePrecondition(false, IsAirportTile(tile) || IsHangarTile(tile));

	return AIObject::DoCommand(tile, 0, 0, CMD_LANDSCAPE_CLEAR);
}

/* static */ int32 AIAirport::GetNumHangars(TileIndex tile)
{
	if (!::IsValidTile(tile)) return -1;
	if (!::IsTileType(tile, MP_STATION)) return -1;

	const Station *st = ::Station::GetByTile(tile);
	if (st->owner != _current_company) return -1;
	if ((st->facilities & FACIL_AIRPORT) == 0) return -1;

	return st->airport.GetNumHangars();
}

/* static */ TileIndex AIAirport::GetHangarOfAirport(TileIndex tile)
{
	if (!::IsValidTile(tile)) return INVALID_TILE;
	if (!::IsTileType(tile, MP_STATION)) return INVALID_TILE;
	if (GetNumHangars(tile) < 1) return INVALID_TILE;

	const Station *st = ::Station::GetByTile(tile);
	if (st->owner != _current_company) return INVALID_TILE;
	if ((st->facilities & FACIL_AIRPORT) == 0) return INVALID_TILE;

	return st->airport.GetHangarTile(0);
}

/* static */ AirportType AIAirport::GetAirportType(TileIndex tile)
{
	if (!AITile::IsStationTile(tile)) return AT_INVALID;

	StationID station_id = ::GetStationIndex(tile);

	if (!AIStation::HasStationType(station_id, AIStation::STATION_AIRPORT)) return AT_INVALID;

	return (AirportType)::Station::Get(station_id)->airport.type;
}
