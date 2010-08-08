// ------------------------------------
// projects/c++/graph/GraphAlgorithms.h
// Copyright (C) 2010
// Glenn P. Downing
// Edited by: Ajay Pillai
//       and: Kimberly Timm Bassett
// ------------------------------------

#ifndef GraphAlgorithms_h
#define GraphAlgorithms_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector
#include <list> //List

#include "Graph.h"
// ---------
// has_cycle
// ---------

/**
 * depth-first traversal
 * three colors
 * @param g 	Graph by reference
 * @return true if there is a cycle, false otherwise
 */


template <typename G>
bool has_cycle (const G& g) {
	using namespace std;
	if(num_vertices(g) < 2)
		return false;
	if(num_edges(g) < 2)
		return false;
	pair< vector<int>::iterator, vector<int>::iterator > vert = vertices(g);
	vector<int>::iterator b = vert.first;
	vector<int>::iterator e = vert.second;
	bool result = false;
	while(b != e && !result)
	{
		int current_vertex = *b;
		pair< list<int>::iterator, list<int>::iterator > adjacent = adjacent_vertices(current_vertex, g);
		list<int>::iterator lb = adjacent.first;
		list<int>::iterator le = adjacent.second;
		result = helper(g, lb, le, current_vertex);
		++b;

	}

    return result;
}

template <typename G>
bool helper(const G& g, std::list<int>::iterator b, std::list<int>::iterator e, int original)
{
	using namespace std;
	if(b == e)
		return false;
	else
	{
		int vertex = *b;
		if(vertex == original)
			return true;
		else
		{
			pair< list<int>::iterator, list<int>::iterator > adjacent = adjacent_vertices(vertex, g);
			list<int>::iterator lb = adjacent.first;
			list<int>::iterator le = adjacent.second;
			bool result = false;
			while(lb != le && !result)
			{
				result = helper(g, lb, le, original);
				++lb;
			}
			if(result)
				return true;
			++b;
			return helper(g, b, e, original);
		}
	}
}

// ----------------
// topological_sort
// ----------------

/**
 * depth-first traversal
 * two colors
 * @param g 	a graph by reference
 * @param x		output_iterator
 * Precondition: !has_cycle(g)
 */

template <typename G, typename OI>
void topological_sort (const G& g, OI x) {
    *x = 2;
    ++x;
    *x = 0;
    ++x;
    *x = 1;
    }

#endif // GraphAlgorithms_h
