/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file ai_airporttypelist.hpp List all airport types. */

#ifndef AI_AIRPORTTYPELIST_HPP
#define AI_AIRPORTTYPELIST_HPP

#include "ai_list.hpp"

/**
 * Creates a list of industries that are currently on the map.
 * @ingroup AIList
 */
class AIAirportTypeList : public AIList {
public:
	/** Get the name of this class to identify it towards squirrel. */
	static const char *GetClassName() { return "AIAirportTypeList"; }
	AIAirportTypeList();
};

#endif /* AI_AIRPORTTYPELIST_HPP */
