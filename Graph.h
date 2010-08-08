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

        typedef int vertex_descriptor;
        typedef std::pair<vertex_descriptor, vertex_descriptor> edge_descriptor;
		

        typedef std::vector<vertex_descriptor>::iterator vertex_iterator;
        typedef std::vector<edge_descriptor>::iterator edge_iterator;
        typedef std::list<vertex_descriptor>::iterator adjacency_iterator;

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param source vertex of the edge
         * @param target vertex of the edge
         * @param g a graph containing vertices and edges
		 * @return pair of the edge descriptor and a boolean
		 * boolean is true if the edge was successfully added,
		 * false otherwise (the edge already existed)
		 */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor source, vertex_descriptor target, Graph& g) {
            // <your code>
            edge_descriptor ed (source, target);
            bool b = true;
            if(source == target)
            	return make_pair(ed, false);
            int num = 0;
            vertex_iterator t = g.vertices.begin();
            while(t != g.vertices.end())
            {
            	if(*t == source)//
            		break;
            	++t;
            	++num;
            }
            std::list<vertex_descriptor> current = g.adjacency_list[num];
            std::list<vertex_descriptor>::iterator beg = current.begin();
            std::list<vertex_descriptor>::iterator end = current.end();
            while(beg != end && b)
            {
            	vertex_descriptor temp = *beg;
            	if(temp == target)
            		b = false;
            	++beg;
            }
            if(b)//if the edge does not already exist
            {
            	beg = current.begin();
            	g.adjacency_list[num].push_back(target);
            	std::vector<edge_descriptor>::iterator edgebeg = g.edges.begin();
            	std::vector<edge_descriptor>::iterator edgeend = g.edges.end();
            	while(edgebeg != edgeend)
            	{
            		if(ed > *edgebeg)
            			break;
            		++edgebeg;
            	}
            	g.edges.insert(edgebeg, ed);
            }
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
         * @param g		the Graph being operated upon
		 * @return a copy of the new vertex.
         */
        friend vertex_descriptor add_vertex (Graph& g) {
        	g.vertices.push_back(vertex_descriptor(g.count));
        	++g.count;
        	g.adjacency_list.push_back(std::list<vertex_descriptor>());
            vertex_descriptor v = g.vertices.back();
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param source 	an individual vertex
         * @param g			a graph
		 * @return a pair of iterators pointing to all nodes that the provided vertex points to.
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor source, const Graph& g) {
            // <your code>
        	std::vector<vertex_descriptor>::const_iterator temp = g.vertices.begin();
        	int num = 0;
        	//while loop finds the specific vertex, which can be used with the adjacency_list
        	//to find all adjacent nodes
        	while(temp != g.vertices.end())
        	{
        		if(*temp == source)//
        			break;
        		++temp;
        		++num;
        	}
        	std::list<vertex_descriptor> current = g.adjacency_list.at(num);
            adjacency_iterator b = current.begin();
            adjacency_iterator e = current.end();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * @param source
         * @param target		source and target of the edge which may or may not exist
         * @param g				graph that might have the edge
		 * @return a pair containing the edge between the two vertices and a boolean which is
		 * true if the edge already exists in the graph and false otherwise.
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor source, vertex_descriptor target, const Graph& g) {
            // <your code>
            edge_descriptor ed = std::make_pair(source, target);
            bool            b = false;
            std::vector<edge_descriptor>::const_iterator beg = g.edges.begin();
            std::vector<edge_descriptor>::const_iterator end = g.edges.end();
            while(beg != end && !b)
            {
            	std::pair<vertex_descriptor, vertex_descriptor> temp = *beg;
            	if(temp == ed)
            		b = true;
            	++beg;
            }
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * @param g		 a Graph
		 * @return all edges in the graph
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& g) {
        	std::vector<edge_descriptor>::const_reverse_iterator b = g.edges.rbegin();
        	std::vector<edge_descriptor>::const_reverse_iterator e = g.edges.rend();
        	std::vector<edge_descriptor> result;
        	while(b != e)
        	{
        		result.push_back(*b);
        		++b;
        	}
            return std::make_pair(result.begin(), result.end());
        }

        // ---------
        // num_edges
        // ---------

        /**
         * @param g		 a Graph
		 * @returns the number of edges in the graph
         */
        friend edges_size_type num_edges (const Graph& g) {
            
            return g.edges.size();
        }

        // ------------
        // num_vertices
        // ------------

        /**
         * @param g		 a Graph
		 * @return the number of vertices in the graph
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            // <your code>
            vertices_size_type s = g.vertices.size();
            return s;}

        // ------
        // source
        // ------

        /**
         * @param ed		edge_descriptor pointing to the edge whose source is to be identified
         * @param g			a Graph
		 * @return The root node of the edge
         */
        friend vertex_descriptor source (edge_descriptor ed , const Graph& g) {
            vertex_descriptor v = ed.first;
            return v;
        }

        // ------
        // target
        // ------

        /**
         * @param ed		edge_descriptor pointing to the edge whose target is to be identified
         * @param g			a Graph
		 * @return the target vertex
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {
            // <your code>
            vertex_descriptor v = ed.second;
            return v;
        }

        // ------
        // vertex
        // ------

        /**
         * @param n		index of a vertex
         * @param g		a graph
		 * @return the vertex at the index provided
         */
        friend vertex_descriptor vertex (vertices_size_type n, const Graph& g) {
            // <your code>
            vertex_descriptor vd = g.vertices.at(n);
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * @param g		a graph
		 * @return all vertices in the graph
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {
            // <your code>
        	std::vector<vertex_descriptor>::const_iterator b = g.vertices.begin();
        	std::vector<vertex_descriptor>::const_iterator e = g.vertices.end();
        	std::vector<vertex_descriptor> result;
        	while(b != e)
        	{
        		result.push_back(*b);
        		++b;
        	}
            return std::make_pair(result.begin(), result.end());}

    private:
        // ----
        // data
        // ----

		std::vector< std::list<vertex_descriptor> > adjacency_list;
		std::vector<vertex_descriptor> vertices;
		std::vector<edge_descriptor> edges;
		int count;

        // -----
        // valid
        // -----

        /**
         * @return true if the graph is a valid graph
		 * Validity denotes that it does not have duplicate nodes or edges
         */
        bool valid () const {
        	using namespace std;
           if(count == 0)
        	   return true;
           else
           {
        	   vector<vertex_descriptor>::const_iterator bv = vertices.begin();
        	   vertex_descriptor current = *bv;
        	   ++bv;
        	   //checks for duplicate vertices
        	   while(bv != vertices.end())
        	   {
        		   if(*bv == current)
        			   return false;
        		   current = *bv;
        		   ++bv;
        	   }
        	   vector<edge_descriptor>::const_iterator ev = edges.begin();
        	   edge_descriptor cur = *ev;
        	   ++ev;
        	   //check for duplicate edges
        	   while(ev != edges.end())
        	   {
        		   if(*ev == cur)
        			   return false;
        		   cur = *ev;
        		   ++ev;
        	   }
        	   return true;
           }
        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Creates a Graph which will be mapped using a list
		 * Starts by making an empty list
         */
        Graph () {
			adjacency_list = std::vector< std::list<vertex_descriptor> >();
			vertices = std::vector<vertex_descriptor>();
			edges = std::vector<edge_descriptor>();
			count = 0;
			
			
            
            assert(valid());
        }

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h
