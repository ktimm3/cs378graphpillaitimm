// ----------------------------
// projects/graph/TestGraph.c++
// Copyright (C) 2010
// Glenn P. Downing
// ----------------------------

/*
To test the program:
    % g++ -ansi -pedantic -I/public/linux/include/boost-1_38 -lcppunit -ldl -Wall TestGraph.c++ -o TestGraph.app
    % valgrind TestGraph.app >& TestGraph.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp" // adjacency_list

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Graph.h"
#include "GraphAlgorithms.h"

// ---------
// TestGraph
// ---------

template <typename T>
struct TestGraph : CppUnit::TestFixture {
    // --------
    // typedefs
    // --------

    typedef T                                       graph_type;

    typedef typename graph_type::vertex_descriptor  vertex_descriptor;
    typedef typename graph_type::edge_descriptor    edge_descriptor;

    typedef typename graph_type::vertex_iterator    vertex_iterator;
    typedef typename graph_type::edge_iterator      edge_iterator;
    typedef typename graph_type::adjacency_iterator adjacency_iterator;

    typedef typename graph_type::vertices_size_type vertices_size_type;
    typedef typename graph_type::edges_size_type    edges_size_type;

    // -----
    // tests
    // -----

    graph_type g;

    vertex_descriptor vdA;
    vertex_descriptor vdB;
    vertex_descriptor vdC;
    vertex_descriptor vdD;
    vertex_descriptor vdE;
    vertex_descriptor vdF;
    vertex_descriptor vdG;
    vertex_descriptor vdH;

    edge_descriptor edAB;
    edge_descriptor edAC;
    edge_descriptor edAE;
    edge_descriptor edBD;
    edge_descriptor edBE;
    edge_descriptor edCD;
    edge_descriptor edDE;
    edge_descriptor edDF;
    edge_descriptor edFD;
    edge_descriptor edFH;
    edge_descriptor edGH;

    graph_type g1;

    vertex_descriptor vA;
    vertex_descriptor vB;
    vertex_descriptor vC;
    vertex_descriptor vD;
    vertex_descriptor vE;
    vertex_descriptor vF;
    vertex_descriptor vG;
    vertex_descriptor vH;
    vertex_descriptor vI;
    vertex_descriptor vJ;
    vertex_descriptor vK;
    vertex_descriptor vL;
    vertex_descriptor vM;

    edge_descriptor eAB;
    edge_descriptor eAC;
    edge_descriptor eAF;
    edge_descriptor eBC;
    edge_descriptor eCD;
    edge_descriptor eDE;
    edge_descriptor eEF;
    edge_descriptor eFG;
    edge_descriptor eGH;
    edge_descriptor eHI;
    edge_descriptor eIJ;
    edge_descriptor eJK;
    edge_descriptor eKL;
    edge_descriptor eLM;



    // -----
    // setUp
    // -----

    // directed, sparse, unweighted
    // possibly connected
    // possibly cyclic
    // Collins, 2nd, pg. 653
    void setUp () {
        vdA  = add_vertex(g);
        vdB  = add_vertex(g);
        vdC  = add_vertex(g);
        vdD  = add_vertex(g);
        vdE  = add_vertex(g);
        vdF  = add_vertex(g);
        vdG  = add_vertex(g);
        vdH  = add_vertex(g);
        edAB = add_edge(vdA, vdB, g).first;
        edAC = add_edge(vdA, vdC, g).first;
        edAE = add_edge(vdA, vdE, g).first;
        edBD = add_edge(vdB, vdD, g).first;
        edBE = add_edge(vdB, vdE, g).first;
        edCD = add_edge(vdC, vdD, g).first;
        edDE = add_edge(vdD, vdE, g).first;
        edDF = add_edge(vdD, vdF, g).first;
        edFD = add_edge(vdF, vdD, g).first;
        edFH = add_edge(vdF, vdH, g).first;
        edGH = add_edge(vdG, vdH, g).first;

        vA = add_vertex(g1);
        vB = add_vertex(g1);
        vC = add_vertex(g1);
        vD = add_vertex(g1);
        vE = add_vertex(g1);
        vF = add_vertex(g1);
        vG = add_vertex(g1);
        vH = add_vertex(g1);
        vI = add_vertex(g1);
        vJ = add_vertex(g1);
        vK = add_vertex(g1);
        vL = add_vertex(g1);
        vM = add_vertex(g1);
        eAB = add_edge(vA, vB, g1).first;
        eAC = add_edge(vA, vC, g1).first;
        eAF = add_edge(vA, vF, g1).first;
        eBC = add_edge(vB, vC, g1).first;
        eCD = add_edge(vC, vD, g1).first;
        eDE = add_edge(vD, vE, g1).first;
        eEF = add_edge(vE, vF, g1).first;
        eFG = add_edge(vF, vG, g1).first;
        eGH = add_edge(vG, vH, g1).first;
        eHI = add_edge(vH, vI, g1).first;
        eIJ = add_edge(vI, vJ, g1).first;
        eJK = add_edge(vJ, vK, g1).first;
        eKL = add_edge(vK, vL, g1).first;
        eLM = add_edge(vL, vM, g1).first;

    }

    // -------------
    // test_add_edge
    // -------------

    void test_add_edge () {
        std::pair<edge_descriptor, bool> p = add_edge(vdA, vdB, g);
        CPPUNIT_ASSERT(p.first  == edAB);
        CPPUNIT_ASSERT(p.second == false);}

    void test_add_edge2() {
    	std::pair<edge_descriptor, bool> p = add_edge(vdA, vdH, g);
    	edge_descriptor edAH = add_edge(vdA, vdH, g).first;
    	CPPUNIT_ASSERT(p.first == edAH);
    	CPPUNIT_ASSERT(p.second == true);
    }


    // ----------------------
    // test_adjacent_vertices
    // ----------------------

    void test_adjacent_vertices () {
        std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
        adjacency_iterator b = p.first;
        adjacency_iterator e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdB);}
        ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdC);}
        ++b;
        if(b != e){
        	vertex_descriptor vd = *b;
        	CPPUNIT_ASSERT(vd == vdE);
        }
        ++b;
        CPPUNIT_ASSERT(b == e);
    }

    void test_adjacent_vertices2(){
    	std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdB, g);
    	adjacency_iterator b = p.first;
    	adjacency_iterator e = p.second;
    	CPPUNIT_ASSERT(b != e);
    	if(b != e){
    		vertex_descriptor vd = *b;
    		CPPUNIT_ASSERT(vd == vdD);
    	}
    	++b;
    	if(b != e){
    		vertex_descriptor vd = *b;
			CPPUNIT_ASSERT(vd == vdE);
    	}
    	++b;
    	CPPUNIT_ASSERT(b == e);
    }

    void test_adjacent_vertices3(){
    	std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdG, g);
    	adjacency_iterator b = p.first;
    	adjacency_iterator e = p.second;
    	CPPUNIT_ASSERT(b != e);
    	if(b != e){
    		vertex_descriptor vd = *b;
    		CPPUNIT_ASSERT(vd == vdH);
    	}
    	++b;
    	CPPUNIT_ASSERT(b == e);
    }

    // ---------
    // test_edge
    // ---------

    void test_edge () {
        std::pair<edge_descriptor, bool> p = edge(vdA, vdB, g);
        CPPUNIT_ASSERT(p.first  == edAB);
        CPPUNIT_ASSERT(p.second == true);}

    void test_edge2(){
    	std::pair<edge_descriptor, bool> p = edge(vdF, vdD, g);
    	CPPUNIT_ASSERT(p.first  == edFD);
    	CPPUNIT_ASSERT(p.second == true);
    }

    void test_edge3(){
    	std::pair<edge_descriptor, bool> p = edge(vdA, vdG, g);
    	CPPUNIT_ASSERT(p.second == false);
    }

    // ----------
    // test_edges
    // ----------

    void test_edges () {
        std::pair<edge_iterator, edge_iterator> p = edges(g);
        edge_iterator                           b = p.first;
        edge_iterator                           e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edAB);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edAC);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edAE);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edBD);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edBE);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edCD);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edDE);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edDF);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edFD);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edFH);}
        ++b;
        if (b != e) {
            edge_descriptor ed = *b;
            CPPUNIT_ASSERT(ed == edGH);}
        ++b;
        CPPUNIT_ASSERT(b == e);
    }

    // --------------
    // test_num_edges
    // --------------

    void test_num_edges () {
        edges_size_type es = num_edges(g);
        CPPUNIT_ASSERT(es == 11);}

    void test_num_edges2 () {
    	edges_size_type es = num_edges(g1);
    	CPPUNIT_ASSERT(es == 14);
    }

    // -----------------
    // test_num_vertices
    // -----------------

    void test_num_vertices () {
        vertices_size_type vs = num_vertices(g);
        CPPUNIT_ASSERT(vs == 8);}

    void test_num_vertices2() {
    	vertices_size_type vs = num_vertices(g1);
    	CPPUNIT_ASSERT(vs == 13);
    }

    // -----------
    // test_source
    // -----------

    void test_source () {
        vertex_descriptor vd = source(edAB, g);
        CPPUNIT_ASSERT(vd == vdA);}

    void test_source2()
    {
    	vertex_descriptor vd = source(eGH, g1);
    	CPPUNIT_ASSERT(vd == vG);
    }

    void test_source3()
    {
    	vertex_descriptor vd = source(edFD, g);
    	CPPUNIT_ASSERT(vd == vdF);
    }

    // -----------
    // test_target
    // -----------

    void test_target () {
        vertex_descriptor vd = target(edAB, g);
        CPPUNIT_ASSERT(vd == vdB);}

    void test_target2 () {
    	vertex_descriptor vd = target(eAF, g1);
    	CPPUNIT_ASSERT(vd == vF);
    }

    void test_target3 () {
    	vertex_descriptor vd = target(edBE, g);
    	CPPUNIT_ASSERT(vd == vdE);
    }

    // -----------
    // test_vertex
    // -----------

    void test_vertex () {
        vertex_descriptor vd = vertex(0, g);
        CPPUNIT_ASSERT(vd == vdA);}

    void test_vertex2 () {
    	vertex_descriptor vd = vertex(3, g1);
    	CPPUNIT_ASSERT(vd == vD);
    }

    void test_vertex3 () {
    	vertex_descriptor vd = vertex(5, g);
    	CPPUNIT_ASSERT(vd == vdF);
    }

    // -------------
    // test_vertices
    // -------------

    void test_vertices () {
        std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
        vertex_iterator                             b = p.first;
        vertex_iterator                             e = p.second;
        CPPUNIT_ASSERT(b != e);
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdA);}
        ++b;
        if (b != e) {
            vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdB);}
        ++b;
        if (b != e) {
        	vertex_descriptor vd = *b;
            CPPUNIT_ASSERT(vd == vdC);}
        ++b;
        if (b != e) {
        	vertex_descriptor vd = *b;
        	CPPUNIT_ASSERT(vd == vdD);}
        ++b;
        if (b != e) {
        	vertex_descriptor vd = *b;
        	CPPUNIT_ASSERT(vd == vdE);}
        ++b;
        if (b != e) {
        	vertex_descriptor vd = *b;
        	CPPUNIT_ASSERT(vd == vdF);}
        ++b;
        if (b != e) {
        	vertex_descriptor vd = *b;
        	CPPUNIT_ASSERT(vd == vdG);}
        ++b;
        if (b != e) {
        	vertex_descriptor vd = *b;
        	CPPUNIT_ASSERT(vd == vdH);}
        ++b;
        CPPUNIT_ASSERT(b == e);
    }

    // --------------
    // test_has_cycle
    // --------------

    void test_has_cycle () {
        CPPUNIT_ASSERT(has_cycle(g));}

    void test_has_cycle2 () {
        CPPUNIT_ASSERT(!has_cycle(g1));}

    // ---------------------
    // test_topological_sort
    // ---------------------

    void test_topological_sort () {
        std::ostringstream out;
        topological_sort(g, std::ostream_iterator<vertex_descriptor>(out, " "));
        CPPUNIT_ASSERT(out.str() == "2 0 1 ");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestGraph);
    CPPUNIT_TEST(test_add_edge);
    CPPUNIT_TEST(test_add_edge2);
    CPPUNIT_TEST(test_adjacent_vertices);
    CPPUNIT_TEST(test_adjacent_vertices2);
    CPPUNIT_TEST(test_adjacent_vertices3);
    CPPUNIT_TEST(test_edge);
    CPPUNIT_TEST(test_edge2);
    CPPUNIT_TEST(test_edge3);
    CPPUNIT_TEST(test_edges);
    CPPUNIT_TEST(test_num_edges);
    CPPUNIT_TEST(test_num_edges2);
    CPPUNIT_TEST(test_num_vertices);
    CPPUNIT_TEST(test_num_vertices2);
    CPPUNIT_TEST(test_source);
    CPPUNIT_TEST(test_source2);
    CPPUNIT_TEST(test_source3);
    CPPUNIT_TEST(test_target);
    CPPUNIT_TEST(test_target2);
    CPPUNIT_TEST(test_target3);
    CPPUNIT_TEST(test_vertex);
    CPPUNIT_TEST(test_vertex2);
    CPPUNIT_TEST(test_vertex3);
    CPPUNIT_TEST(test_vertices);
    CPPUNIT_TEST_SUITE_END();};


// ----
// main
// ----

int main () {
    using namespace std;
    using namespace boost;

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestGraph.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestGraph< adjacency_list<setS, vecS, directedS> >::suite());
    tr.addTest(TestGraph<Graph>::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
