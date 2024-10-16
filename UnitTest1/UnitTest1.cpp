#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include "../PDS_LAB_6/PDS_LAB_6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestReadGraph)
        {
            int n, m;
            std::vector<std::pair<int, int>> edges;
            const std::string testFilename = "test_graph.txt"; 

            
            {
                std::ofstream file(testFilename);
                file << "3 3\n"; 
                file << "1 2\n"; 
                file << "2 3\n"; 
                file << "3 1\n"; 
                file.close();
            }

            
            readGraph(testFilename, n, m, edges);

            
            Assert::AreEqual(3, n);
            Assert::AreEqual(3, m);
            Assert::AreEqual(3, (int)edges.size());
            Assert::AreEqual(1, edges[0].first);
            Assert::AreEqual(2, edges[0].second);
            Assert::AreEqual(2, edges[1].first);
            Assert::AreEqual(3, edges[1].second);
            Assert::AreEqual(3, edges[2].first);
            Assert::AreEqual(1, edges[2].second);
        }

        TEST_METHOD(TestCreateIncidenceMatrix)
        {
            int n = 3, m = 3;
            std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
            auto incidenceMatrix = createIncidenceMatrix(n, m, edges);

            
            std::vector<std::vector<int>> expectedIncidenceMatrix = {
                {1, 0, -1},
                {-1, 1, 0},
                {0, -1, 1}
            };

            for (size_t i = 0; i < expectedIncidenceMatrix.size(); ++i) {
                for (size_t j = 0; j < expectedIncidenceMatrix[i].size(); ++j) {
                    Assert::AreEqual(expectedIncidenceMatrix[i][j], incidenceMatrix[i][j]);
                }
            }
        }

        TEST_METHOD(TestCreateAdjacencyMatrix)
        {
            int n = 3;
            std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
            auto adjacencyMatrix = createAdjacencyMatrix(n, edges);

            
            std::vector<std::vector<int>> expectedAdjacencyMatrix = {
                {0, 1, 0},
                {0, 0, 1},
                {1, 0, 0}
            };

            for (size_t i = 0; i < expectedAdjacencyMatrix.size(); ++i) {
                for (size_t j = 0; j < expectedAdjacencyMatrix[i].size(); ++j) {
                    Assert::AreEqual(expectedAdjacencyMatrix[i][j], adjacencyMatrix[i][j]);
                }
            }
        }

        TEST_METHOD(TestPrintMatrix)
        {
            
        }
    };
}
