#include <iostream> 
#include <mlpack/core.hpp> 
#include <armadillo>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp> 
#include <mlpack/methods/kmeans/kmeans.hpp>
using namespace mlpack;
using namespace mlpack::neighbor; 
using namespace mlpack::metric; 
using namespace std;
using namespace mlpack::kmeans;
int main()
{
int neighbors = 10; //number of neighbours to test for knn 
int clusters = 2; //number of clusters to get for kmeans
//declaration of index for incrementing values in the counter matrix 
int increment_index;

arma::mat referenceData, queryData;
//loading the reference and query datasets 
data::Load("../data/reference.csv", referenceData, true); 
data::Load("../data/query.csv", queryData, true);
arma::Row<size_t> assignments;
//will contain the assignments of clusters after kmeans 
arma::mat centroids;
//will contain the centroids of the clusters after kmeans 
KMeans<> k; //uses default settings for kmeans
k.Cluster(referenceData, clusters, assignments, centroids);
//does kmeans on reference data and stores values in their respective matrices
KNN a(referenceData);
//creates a model using reference data 
arma::Mat<size_t> resultingNeighbors;
//will contain the indices of the nearest neighbours of the query data 
arma::mat resultingDistances;
//will contain the distances of the nearest points from the query data 
a.Search(queryData, neighbors, resultingNeighbors,resultingDistances);
//does knn to get and store the nearest points in their respective matrices
arma::mat counter(clusters,1,arma::fill::zeros);
//keeps track of the number of occurences of each cluster of the nearest neighbours
//checks the clusters of the nearest neighbours, finds the most occurring cluster and predicts the cluster of the query data
for(long long column = 0; column < queryData.n_cols; column++) {
//checks for multiple query data points, each data reading being a column
for(int row = 0; row < neighbors; row++) {
//iterates over all nearest neighbours
increment_index = assignments(resultingNeighbors(row, column));
//checks and stores the cluster the nearest neighbour belongs to 
counter(increment_index) = counter(increment_index) + 1;
//increments the number of occurrences of the cluster by one
}
cout << "Cluster of point " << column << " is Cluster " << 
counter.index_max()+1 << endl;
//displays the cluster query data belongs to 
counter.zeros(); //resets the counter
}
return 0;
}