void getKMeans()
{
KMeans<> k; //uses default settings for kmeans 
k.Cluster(referenceData, clusters, assignments, centroids);
//does kmeans on reference data and stores values in their respective matrices
}
