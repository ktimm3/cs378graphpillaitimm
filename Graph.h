// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2010
// Glenn P. Downing
// Edited By: Ajay Pillai
//		 and: Kimberly Timm Bassett
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector
#include <list> //List


// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;          // fix!
        typedef int edge_descriptor;            // fix!
		

        typedef int* vertex_iterator;           // fix!
        typedef int* edge_iterator;             // fix!
        typedef int* adjacency_iterator;        // fix!

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param Vertex_descriptors are the node pair to be an on the graph
         * @param Graph is the graph we are working with using a list.
		 * @return pair of the edge descriptor or the direction of the new pair
		 * and to make sure that it is not a duplicate
		 */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor, vertex_descriptor, Graph&) {
            // <your code>
            edge_descriptor ed;
            bool            b;
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
         * @param Add a node to our Graph
		 * @return a new vertex descriptor or a node.
         */
        friend vertex_descriptor add_vertex (Graph&) {
           
            vertex_descriptor v;
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param take in a node and 
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor, const Graph&) {
            // <your code>
            adjacency_iterator b = adjacency_iterator();
            adjacency_iterator e = adjacency_iterator();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * <your documentation>
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor, vertex_descriptor, const Graph&) {
            // <your code>
            edge_descriptor ed;
            bool            b;
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * O(1) in space
         * O(1) in time
         * <your documentation>
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph&) {
            // <your code>
            edge_iterator b;
            edge_iterator e;
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * <your documentation>
         */
        friend edges_size_type num_edges (const Graph&) {
            // <your code>
            edges_size_type s = 0;
            std::vector< std::vector <edge_descriptor> >::iterator beg = g.begin();
            std::vector< std::vector <edge_descriptor> >::iterator end = g.end();
            while(beg != end)
            {
            	s += (*beg).size();
            	++beg;

            }
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph&) {
            // <your code>
            vertices_size_type s = g.size();
            return s;}

        // ------
        // source
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor source (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // target
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // vertex
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor vertex (vertices_size_type, const Graph&) {
            // <your code>
            vertex_descriptor vd;
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * <your documentation>
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph&) {
            // <your code>
            vertex_iterator b = vertex_iterator();
            vertex_iterator e = vertex_iterator();
            return std::make_pair(b, e);}

    private:
        // ----
        // data
        // ----

        std::vector< std::vector<vertex_descriptor> > g; // To make an adjacency Matrix
		std::list<std::list<vertex_descriptor>> gl //for when we want to make an Adjacency List

        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            // where we want to make sure we don't have duplicates and at least one node
			if(gl.size() == 0)
				return false;
			else if( gl.size() > 1){
				iterator b = gl.begin();
				iterator e = gl.end();
				while(b < e){
					if(b ==e-1){
						//If the b's node equals e's node, then it is a duplicate node
						return false;}
					++b;
					--e;}}
			else{ //No null first node and no duplicates
				return true;}}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Creates a Graph which will be mapped using a list
		 * Starts by making an empty list
         */
        Graph () {
			list<T> gl; //Creates an empty list
			
			//Create Vertex Iterators to point at the first node 
			//ie the root of the list. Should be pointing at the same place
			// Note the returning iterators are Bidirectional by the List stl
			vertex_iterator b = gl.begin();
			vertex_iterator e = gl.end();
			
			
            
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h