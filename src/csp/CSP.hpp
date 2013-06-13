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
 * Contributors:
 *  -> Konrad Talik <konradtalik@gmail.com>
 *
 */

/**
 * @file 	csp/CSP.hpp
 * @brief	Constraint satisfaction problem(s) solving algorithm class
 * @date	2013-06-13
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __CSP_HPP__
#define __CSP_HPP__

#include "CSPVariable.hpp"
#include "CSPConstraint.hpp"
#include "Graph.hpp"

namespace slimak {

	/**
	 * @brief	Constraint satisfaction problem(s) solving class
 	 * @author	Konrad Talik <konradtalik@gmail.com>
	 * 
	 * Basically, a CSP solving class algorithm tries to colour a graph of **variables**,
	 * which are connected by edges -- in this problem called **constraints**.
	 * The output graph must be colored in such a way that every defined **constraint**
	 * will be satisfied (retained).
	 *
	 * More precisely, a CSP (problem) can be defined in various ways and in many different ways solved.
	 * Our implementation allows to solve the following problem:
	 *
	 * We define a @f$ CSP @f$ as a triple of folowing objects:
	 *
	 * @f$ CSP = (V,D,C) @f$,
	 *
	 * where:
	 *
	 * @f$ V @f$ is a finite set of **variables**
	 *
	 * @f$ D @f$ is a finite **domain** of above variables
	 *
	 * @f$ C @f$ is a finite set of defined **constraints**
	 *
	 * As you should have known, we are trying to assign a values from @f$ D @f$ to every **variable**
	 * in a way, that will satisfy every **constraint**. But how are constraints defined?
	 *
	 * We must start from the **attributes**. Every color (variable) consist of attributes.
	 * For example, we can have @f$ (schoolsubject, teacher, classroom) @f$ **colors** which are composed
	 * of three attributes.
	 *
	 * The **constraints** are simple n-ary relations between every **variable**.
	 * The constraints are connecting n variables in a relation and, additionaly
	 * they're having some sort of logical or direct **rule**.
	 * The rule can be related with one or more **attributes** of every variables connected with the constraint,
	 * or it can rely on some computation (or simple counter [usually for unary constraints] etc.).
	 *
	 * #### For example:
	 * 
	 * A constraint between variables
	 * @f$ v_1 = (group1A, monday, 8:00) @f$ and @f$ v_2 = (group1B, monday, 8:00) @f$
	 * is between attribute
	 * * @f$ classroom @f$
	 * 
	 * and tells:
	 * * If, for currently computed color for @f$ v_j @f$, there in @f$ v_k @f$ is assigned a classroom @f$ c_0 @f$
	 * then we can not assign a classroom @f$ c_0 @f$ to @f$ v_j @f$.
	 *
	 * #### Another example:
	 * 
	 * An unary (direct) constraint on every variable in a timetable.
	 * The constraint isn't related to any attribute, but says:
	 * * If, for currently computed color (value) for @f$ v_j @f$,
	 * and for every @f$ v_i @f$ having same day and group as @f$ v_j @f$
	 * there is more assigned variables than acceptable, do not assign any value to anymore variable.
	 * (acceptable amount of schoolsubjects per day are e.g. defined somewhere in the lesson plan project)"
	 *
	 */
	class CSP {

		public:
			/* CONSTRUCTOR */

			/// Construct CSP solving class with given variables, constraints and attributes
			/**
			 * @param attributes_dimensions
			 * 	A number of dimensions of **attributes** of **colors**.
			 *
			 * @param given_attributes
			 *	We are giving a map of attributes, from which a **domain** will be created.
			 *	The key in the map is a concrete **attribute**.
			 *	The value is a dimension number (these numbers must start from 0).
			 *
			 * @param given_variables
			 *	This is a vector of variables which we want assign a specific values.
			 *
			 * @param given_constraints
			 * 	These are constraints which we want to satisfy throughout the algorithm process.
			 *
			 * For more information about algorithm proccess, please read the class detailed description.
			 *
			 */
			CSP (
				int attributes_dimensions,
				std::map< slimak::CSPAttribute, int > given_attributes,
				std::vector< slimak::CSPVariable > given_variables,
				std::vector< slimak::CSPConstraint > given_constraints
			);

			void init();

		protected:

			std::vector< slimak::CSPColor > domain;
			std::vector< slimak::CSPVariable > variables;
			std::vector< slimak::CSPConstraint > constraints;
			slimak::Graph< slimak::CSPVariable > constraints_graph;
			void constructConstraintsGraph();
	};

}

#endif
