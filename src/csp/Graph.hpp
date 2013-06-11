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

/**
 * @file 	csp/Graph.hpp
 * @brief	Implementation of an undirected graph.
 * @date	2013-06-11
 * @authors	Konrad Talik <konradtalik@gmail.com>
 * @copyright	GNU General Public License v3.
 */

#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>
#include <map>

namespace slimak {

	// Graph template class
	/**
	 * @brief	Implementation of an undirected graph.
 	 * @author	Konrad Talik <konradtalik@gmail.com>
	 *
	 * Current implementation of this graph is an undirected graph without multiple edges
	 * (no multiple edges from some vertex *x* to some vertex *y*).
	 *
	 * @note
	 * There is no difference between edge from *x* to *y* and edge from *y* to *x* -- this
	 * implementation treats it as the same edge. However, if using
	 * a (**given_vertices**, **given_edges**) constructor you must remember to include
	 * both "sides" of the edge.
	 *
	 */
	template <class T>
	class Graph {
		
		public:

			/* CONSTRUCTORS */

			/// Construct an empty Graph.
			Graph() {}

			/// Construct Graph from given vertices.
			Graph(std::vector< T > given_vertices) {
				vertices = given_vertices;
			}

			/// Construct Graph from given vertices and edges.
			/**
			 * @param given_vertices
			 *	Source vertices. They will be copied to the Graph object.
			 *
			 * @param given_edges
			 * 	Source edges.
			 *
			 * 	Edges must be located in the map, which has pointers to the vertices as a key value
			 * 	and vectors (of pointers to other vertices) as a mapped value. Pointers should point
			 * 	to corresponding objects from **given_vertices** vector.
			 *	
			 * @note
			 * The Graph is constructed by copying the content of **given_vertices** to the new object.
			 * New data about edges is being created inside the object based on relations between pointers
			 * in the **given_edges**. Hence there is no usage of external objects (from **given_vertices**)
			 * through the pointers from **given_edges**.
			 *
			 */
			// TODO: Test this constructor.
			Graph(std::vector< T > given_vertices, std::map< T *, std::vector< T * > > given_edges) {
				
				vertices = given_vertices;

				/* Connect new vertices adresses (pointers) with corresponding source objects adresses. */
				std::map< T * , T * > given_to_current;
				for (	typename std::vector< T >::iterator 
						g_i = given_vertices.cbegin(), v_i = vertices.cbegin();
					g_i != given_vertices.cend();
					++g_i, ++v_i ) {
						given_to_current[ &(*g_i) ] = &(*v_i);
				}

				edges = std::map< T *, std::vector< T * > >();

				/* Distribute given_edges in a new object. */
				for (typename std::vector< T >::iterator g_i = given_vertices.begin();
					g_i != given_vertices.end(); ++g_i) {
					
					for(typename std::vector< T * >::iterator n_i = given_edges[ &(*g_i) ].begin();
						n_i != given_edges[ &(*g_i) ].end(); ++n_i ) {

							edges[ given_to_current[ &(*g_i) ] ].push_back( given_to_current[ &(*n_i) ] );

					}
				}
				
			}

			/// Destructor.
			~Graph() {}

			/** @name Access methods */
			///@{
			/** *Access method* */

			/// Determine if this Graph has a specified edge.
			bool hasEdge(T *first_vertex, T *second_vertex) {
				if ( hasNeighbor( first_vertex, second_vertex) && hasNeighor( second_vertex, first_vertex ) )
					return true;
				return false;
			}

			/// Return a vector of pointers to neighbors of **given_vertex**.
			/**
			 * If there are no neighbors, an empty vector is returned.
			 */
			// TODO: Check it.
			std::vector< T * > neighbors(T *given_vertex ) {
				return edges[ given_vertex ];
			}

			/// 

			///@}

			/** @name Modifiers */
			///@{
			/** *Modifying method* */

			/// Add edge between two vertices.
			/**
			 * @param first_vertex	First vertex of an edge.
			 * @param second_vertex	Second vertex of an edge.
			 * 
			 * Throughout this method, technically, a two edges will be creted:
			 * (**first_vertex**, **second_vertex**) and (**second_vertex**, **first_vertex**).
			 *
			 */
			void addEdge(T *first_vertex, T *second_vertex) {
				constructEdge( first_vertex, second_vertex );
				constructEdge( second_vertex, first_vertex );
			}

			/// Remove edge between two vertices.
			/**
			 * If there is no edge between **first_vertex** and **second_vertex**
			 * then nothing happens.
			 */
			void removeEdge(T *first_vertex, T *second_vertex) {
				destructEdge( first_vertex, second_vertex);
				destructEdge( second_vertex, first_vertex);
			}
			
			/// Add new vertex into collection.
			void addVertex(T given_vertex) {
				vertices.push_back( given_vertex );
			}

			///@}

		protected:

			std::vector< T > vertices;
			std::map< T *, std::vector< T * > > edges;

			typename std::vector< T * >::const_iterator
			findNeighbor(T *given_vertex, T *neighbor_vertex) {
				for(typename std::vector< T * >::const_iterator n_i = edges[ &(*given_vertex) ].cbegin();
					n_i != edges[ given_vertex ].cend(); ++n_i ) {
						if ( &(*n_i) == neighbor_vertex ) {
							return n_i;
						}
				}
				return 0;
			}
			
			bool hasNeighbor(T *given_vertex, T *neighbor_vertex) {
				if ( findNeighbor( given_vertex, neighbor_vertex) != 0 ) {
					return true;
				} else {
					return false;
				}
			}
			
			void constructEdge(T *first_vertex, T *second_vertex) {
				if ( !hasNeighbor( first_vertex, second_vertex ) )
					edges[ first_vertex ].push_back( second_vertex );
			}

			void destructEdge(T *first_vertex, T *second_vertex) {
				typename std::vector< T * >::const_iterator neighbor_search;
				neighbor_search = findNeighbor( first_vertex, second_vertex);
				if (neighbor_search != 0) {
					edges[ first_vertex ].erase( neighbor_search );
				}
			}

	};

}

#endif
