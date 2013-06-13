/*
 * Copyright (C) Software Liberation Maniacs Cracow
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "CSP.hpp"

slimak::CSP::CSP (
	int attributes_dimensions,
	std::map< slimak::CSPAttribute, int > given_attributes,
	std::vector< slimak::CSPVariable > given_variables,
	std::vector< slimak::CSPConstraint > given_constraints
	) {
		/* Store data inside object. */
		variables = given_variables;
		constraints = given_constraints;

		/* Generate a domain from given_attributes. */
		domain = std::vector< slimak::CSPColor > ();
		// Divide attributes into dimensions: attribute[ dimension ][ id ].
		std::vector< std::vector< slimak::CSPAttribute > > attributes;
		// Prepare data storage.
		for (int i = 0; i < attributes_dimensions; ++i) {
			std::vector< slimak::CSPAttribute > new_dimension;
			attributes.push_back( new_dimension );
		}
		// Store attributes.
		for (std::map< slimak::CSPAttribute, int >::iterator it = given_attributes.begin();
			it != given_attributes.end(); ++it) {
				attributes[ (*it).second ].push_back( (*it).first );
		}
		// Generate......
		for (std::vector< std::vector< slimak::CSPAttribute > >::iterator it = attributes.begin();
			it != attributes.end(); ++it) {
			/* TODO */
		}

}

void slimak::CSP::init() {
	//constructConstraintsGraph();
}
