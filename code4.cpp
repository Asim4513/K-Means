extern arma::mat data; // Dataset we want to run K-Means on. 
arma::Row<size_t> assignments; // Cluster assignments. 
arma::mat centroids; // Cluster centroids.
KMeans<> k; // Default options.
k.Cluster(data, 3, assignments, centroids); // 3 clusters.
// Cluster using the Manhattan distance, 100 iterations maximum, saving only the centroids. 
KMeans<metric::ManhattanDistance> k(100); 
k.Cluster(data, 6, centroids); // 6 clusters.