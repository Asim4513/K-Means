#include <mlpack/methods/kmeans/kmeans.hpp> 
using namespace mlpack::kmeans;
// The dataset we are clustering. 
extern arma::mat data;
// The number of clusters we are getting.
18
extern size_t clusters;
// The assignments will be stored in this vector. 
arma::Row<size_t> assignments;
// The centroids will be stored in this matrix. 
arma::mat centroids;
// Initialize with the default arguments. 
KMeans<> k;
k.Cluster(data, clusters, assignments, centroids);