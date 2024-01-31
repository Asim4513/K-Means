# K-Means
This repo contins code files for a simple implementation of Kmeans in C++ using MLPack

K-means clustering is one of the simplest and popular unsupervised machine learning algorithms.

Typically, unsupervised algorithms make inferences from datasets using only input vectors without referring to known, or labelled, outcomes.

AndreyBu, who has more than 5 years of machine learning experience and currently teaches people his skills, says that “the objective of K-means is simple: group similar data points together and discover underlying patterns. To achieve this objective, K-means looks for a fixed number (k) of clusters in a dataset.”

A cluster refers to a collection of data points aggregated together because of certain similarities.

You’ll define a target number k, which refers to the number of centroids you need in the dataset. A centroid is the imaginary or real location representing the center of the cluster.

Every data point is allocated to each of the clusters through reducing the in-cluster sum of squares.

In other words, the K-means algorithm identifies k number of centroids, and then allocates every data point to the nearest cluster, while keeping the centroids as small as possible.

The ‘means’ in the K-means refers to averaging of the data; that is, finding the centroid.

# Tools
C++
MLPack: https://github.com/mlpack/mlpack
Ubuntu

# Compile
Install MLpack successfully and dont forget to install dpendencies: This line will do the trick sudo apt-get install libboost-math-dev libboost-program-options-dev libboost-test-dev libboost-serialization-dev libarmadillo-dev binutils-dev

If you are using gcc you need to do this to complie the code successfully: g++ kmeans.cpp -o Foo -lmlpack -larmadillo -lboost_serialization -lboost_program_options


