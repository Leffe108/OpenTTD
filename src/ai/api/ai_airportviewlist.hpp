/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_airportviewlist.hpp List all airport views. */

#ifndef AI_AIRPORTVIEWLIST_HPP
#define AI_AIRPORTVIEWLIST_HPP

#include "ai_list.hpp"
#include "ai_types.hpp"

/**
 * Creates a list of airport views that are available for the given
 * airport type. An airport view is basically a rotation of the airport.
 * @ingroup AIList
 */
class AIAirportViewList : public AIList {
public:
	/** Get the name of this class to identify it towards squirrel. */
	static const char *GetClassName() { return "AIAirportViewList"; }

	/**
	 * @param type The airport type to get a list of views for.
	 * @pre AIAirportType::IsAirportTypeInformationAvailable
	 */
	AIAirportViewList(AirportType type);
};

#endif /* AI_AIRPORTVIEWLIST_HPP */
