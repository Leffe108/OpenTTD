/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

AILog.Info("1.1 API compatability in effect.");

AICompany.GetCompanyValue <- function(company)
{
	return AICompany.GetQuarterlyCompanyValue(company, AICompany.CURRENT_QUARTER);
}

// AirportType enum
AIAirport.AT_SMALL         <-   0; // The small airport.
AIAirport.AT_LARGE         <-   1; // The large airport.
AIAirport.AT_METROPOLITAN  <-   3; // The metropolitan airport.
AIAirport.AT_INTERNATIONAL <-   4; // The international airport.
AIAirport.AT_COMMUTER      <-   5; // The commuter airport.
AIAirport.AT_INTERCON      <-   7; // The intercontinental airport.

AIAirport.AT_HELIPORT      <-   2; // The heliport.
AIAirport.AT_HELISTATION   <-   8; // The helistation.
AIAirport.AT_HELIDEPOT     <-   6; // The helidepot.
AIAirport.AT_INVALID       <- 255; // Invalid airport.
