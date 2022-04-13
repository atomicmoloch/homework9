Adam Snelling
Kavi Wilson

Here are some of our thought processes on the different parts of the project:

operator << and >> override todo

total_path_distance just sums up the distances between each city in the order
it's given. I made a helper function, distance(), that returned the distance
betweeen two points, and used that in total_path_distance.

reorder creates a new Cities object, then manually sets the citylist_ with the
new order it was given.

I chose to make random_permutation a class method instead of a free function
because then it could access the length of the citylist_, which is a private
member. If I had made it a free function taking a length as input, I would have
needed a get_length() method later, which makes it more complicated. It uses
the standard library's random_device for randomness, so it can produce different
output each time.

tsp.cc:
We had to make several helper functions for this bit. First was the
aforementioned get_length() method, but that was removed once I made
random_permutation a class method instead of a free function. Also, to calculate
the distance of the first route chosen, a non-random ordered_permutation method
was required. This is probably unnecessary, as it's not more likely that the
permutation the city is intialized in is the fastest, but it makes it feel more
complete.

part 8 todo
