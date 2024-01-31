#include <mlpack/methods/neighbor_search/neighbor_search.hpp> 
using namespace mlpack::neighbor;
// Our dataset matrices, which are column-major. 
extern arma::mat queryData, referenceData;
KNN a(referenceData);
// The matrices we will store output in. 
arma::Mat<size_t> resultingNeighbors; 
arma::mat resultingDistances;
// Finds the 10 nearest neighbours of the query data in the 
training dataset
a.Search(queryData, 10, resultingNeighbors, resultingDistances);