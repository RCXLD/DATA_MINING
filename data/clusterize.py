#!/usr/bin/env python2

import sys, argparse, numpy



#-------------------------------------------------------------------------------
# Compute the Euclidean distance between 2 vectors
#-------------------------------------------------------------------------------

def dist_euclid(A, B):
	return numpy.sum((A - B) ** 2)



#-------------------------------------------------------------------------------
# Pick one element from a sequence, with probability proportional to weights
#-------------------------------------------------------------------------------

def weighted_choice(weights, sequence):
	s = numpy.sum(weights) * numpy.random.random()
	for w, item in zip(weights, sequence):
		if s < w:
			return item
		s -= w
	return None



#-------------------------------------------------------------------------------
# Clusterize data with kmeans algorithm
#   - points : a matrix of points, 1 row vector for 1 point
#   - cluster_count : number of clusters
#
#  Returns (clustersIds, clustersCenters)
#   - sequence of cluster id for each point (1st cluster got id 0)
#   - center of each cluster
#-------------------------------------------------------------------------------

def clusterize(points, cluster_count, dist_func = dist_euclid, init = 'kmeans++'):
	# Parameters
	point_count, var_count = points.shape
	
	# Initialization
	if init == 'random':
		# Random init
		clusters_ids = tuple(numpy.random.randint(cluster_count) for i in range(point_count))
		clusters_centers = numpy.zeros((cluster_count, var_count))
	elif init == 'kmeans++':
		# KMeans++ init
		clusters_centers = [points[numpy.random.randint(point_count)]]
		min_dist = numpy.array([dist_func(p, clusters_centers[-1]) for p in points])
		for n in range(cluster_count - 1):
			clusters_centers.append(weighted_choice(min_dist, points))
			min_dist = numpy.minimum(min_dist, [dist_func(p, clusters_centers[-1]) for p in points])

		clusters_centers = numpy.array(clusters_centers)
		clusters_ids = tuple(numpy.argmin([dist_func(p, c) for c in clusters_centers]) for p in points)

	# KMeans iterations
	while(True):
		# For each cluster
		for c in range(cluster_count):
			# Find all points belonging to cluster c
			members = [p for i, p in zip(clusters_ids, points) if i == c]

			# Update the clusters center
			if len(members) == 0:
				# Empty cluster, pick one point randomly as center
				clusters_centers[c] = points[numpy.random.randint(point_count)].copy()
			else:
				# Non-empty cluster, compute its center
				numpy.median(members, axis=0, out=clusters_centers[c])

		# Attribute each point to its closest cluster
		prev_clusters_ids = clusters_ids
		clusters_ids = tuple(numpy.argmin([dist_func(p, c) for c in clusters_centers]) for p in points)

		# Check if convergence is reached
		if prev_clusters_ids == clusters_ids:
			break

	# Done
	return clusters_ids, clusters_centers



# --- Main function -----------------------------------------------------------

def main():
	parser = argparse.ArgumentParser(description='Clusterize a dataset')
	parser.add_argument('input',    metavar='[IN PATH]',      type=str, nargs=1, help='input file')
	parser.add_argument('output',   metavar='[OUT PATH]',     type=str, nargs=1, help='output file')
	parser.add_argument('clusters', metavar='[NO. CLUSTERS]', type=int, nargs=1, help='number of clusters')

	args = parser.parse_args()

	# Read data
	try:
		data = numpy.loadtxt(args.input[0])
	except IOError as (errno, strerror):
		sys.stderr.write("Failed to load '%s':%s\n" % (args.input[0], strerror))
		sys.exit(0)

	# Clusterize
	clusters_ids, cluster_centers = clusterize(data, args.clusters[0])

	# Save data
	try:
		with open(args.output[0], 'w') as out_file:
			for i in xrange(data.shape[0]):
				for x in data[i]:
					print >> out_file, x, 
				print >> out_file, clusters_ids[i]
	except IOError as (errno, strerror):
		sys.stderr.write("Failed to save '%s':%s\n" % (args.output[0], strerror))
		sys.exit(0)



if __name__ == "__main__":
	main()
