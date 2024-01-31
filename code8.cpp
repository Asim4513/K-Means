void getKNN()
{
KNN a(referenceData);
// creates model using reference data 
a.Search(queryData, neighbors, resultingNeighbors, resultingDistances); // implements KNN 
resultingNeighbors.print("The indices of the nearest neighboursare: ");
resultingDistances.print("he distances of the nearest neighbours from the query data are: ");
}