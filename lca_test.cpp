#define BOOST_TEST_MODULE Simple testlca
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(simple_test) 
{
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 2); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 

    BOOST_CHECK_EQUAL(g.LCA(4, 5), 4);
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 2); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 

    BOOST_CHECK_EQUAL(g.LCA(4, 6), 3);
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 2); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 

    BOOST_CHECK_EQUAL(g.LCA(4, 1), 1);
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 2); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 

    BOOST_CHECK_EQUAL(g.LCA(8, 9), 3);
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 2); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 

    BOOST_CHECK_EQUAL(g.LCA(4, 8), 3);
}