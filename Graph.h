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
         * @param take in a node and our current graph
		 * @return a pair that was just mapped.
		 * Note: the Adjacency iterator is what is horizontally iterating our list
		 * Also note that vertically iterating our list means to change the root node. 
		 * Our list is working like a vector in that each row is an adjacency list with the root node being the current row element
		 * The adjacency list is the nodes being directed at.
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
         * @param take two nodes that will be mapped on our graph 
		 * @return a pair denoting the mapping and a boolean to make sure it doesn't already exist.
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
         * @param Take in our graph being worked on
		 * @return a pair with the root node and the directed node and call that path the edge
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
         * @param Takes in our current graph
		 * @returns the number of edges in our graph
         */
        friend edges_size_type num_edges (const Graph&) {
            
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
         * @param Takes in our Graph
		 * @return Returns the number of vertices in the graph
         */
        friend vertices_size_type num_vertices (const Graph&) {
            // <your code>
            vertices_size_type s = g.size();
            return s;}

        // ------
        // source
        // ------

        /**
         * @param Takes in our Graph
		 * @return The root node of the edge
         */
        friend vertex_descriptor source (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // target
        // ------

        /**
         * @param Takes in our Graph
		 * @return the targe vertex
		 * This method takes in an edge descriptor and creates a vertex descriptor so that we can make an edge later.
		 * Essentially it adds a new node to the graph.
         */
        friend vertex_descriptor target (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v;
            return v;}

        // ------
        // vertex
        // ------

        /**
         * @param Takes in our graph and a size of how big our elements are that will be mapped
		 * @return a new vertex descriptor
         */
        friend vertex_descriptor vertex (vertices_size_type, const Graph&) {
            // <your code>
            vertex_descriptor vd;
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * @param Takes in our Graph
		 * @return a pair of mapped elements
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
         * @return true if the graph is a valid graph
		 * Validity denotes that it does not have duplicate nodes or edges and at least 1 node in the Graph
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
