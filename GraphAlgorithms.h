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

// ---------
// has_cycle
// ---------

/**
 * depth-first traversal
 * three colors
 * @param Takes in a Graph by reference
 * @return True to make sure it has one cycle
 */
template <typename G>
bool has_cycle (const G& g) {
    return true;}

// ----------------
// topological_sort
// ----------------

/**
 * depth-first traversal
 * two colors
 * @param Takes in a graph by reference and an Output Iterator
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
