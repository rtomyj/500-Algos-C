/*
	The situation is similar to problem 2. However, now we have to keep track of all occurences.

	Thinking again about a graph, we see that there will be different local graphs - I'll call them graphs.

	Eg) [3, -3, 2, -2]
	We can see that there will be 3 sub arrays that produce a zero sum: [3, -3], [3, -3, 2, -2], [2, -2].

	If we do the problem the same way as problem two, we will miss some zero graphs since our graph kept track of only one
	zero sum occurence that produced the same y value. In other words: since the graph starts at 0, and all our sub arrays
	go back to 0, we will override previous values since we only keep track of one occurence, we will ignore other
	occurences or we will miss occurences. In the example above all three can happen. See below.

	First occurence: [3, -3] @ indexes [0, 2)
	Override: Once we see [2, -2] our indexes can shift to indexes [2, 4)
	Ignore: If we don't allow overriding we will miss the above occurence
	Missed: What about [3, -3, 2, -2] @ indexes [0, 4)?  How can we account for it.

	To solve this problem it is better to think of every element as spawning a new graph. If we take the above sequence
	again:
	Ind: 0
	Elements added: [3]
	Graph(s):
		Graph 1
	#
	#
	#
	--------
	1

	Ind: 1
	Elements added: [3, -3]
	Graph(s):
		Graph 1					Graph 2
	#
	#
	#									1
	--------					-------
	1	2								#
										#
										#

	Ind: 2
	Elements added: [3, -3, 2]
	Graph(s):
		Graph 1						Graph 2						Graph 3
	#
	#		#																		#
	#		#								1	2									#
	----------					----------					----------
	1	2	3								#	#									1
											#
											#

	Ind: 3
	Elements added: [3, -3, 2. -2]
	Graph(s):
		Graph 1						Graph 2						Graph 3						Graph 4
	#
	#		#																		#
	#		#								1	2	3								#								1
	----------					----------					----------			----------
	1	2	3	4							#	#	#								1	2							#
											#		#																#
											#		#

	With the above graphs, we can see that zero graphs occur when the y-ind of each graph is 0.
	This happnes twice in graph 1, and once in graph 3.
	Using the x values we see this happens with indexes [0, 2) and [0, 4) in graph 1 and [0, 2) in graph 2.

	Since Graph 1 encompasses all original indexes we see that [0, 2) = [3, -3] and [0, 4) = [3, -3, 2, -2].
	However, Graph 2 only considers the sub array [2 -2], so [0, 2) for Graph 2 is equal to [2, -2]
*/

#include <stdio.h>
#include "libs/algorithm.h"
#include "libs/print.h"
#include "libs/cust_structs.h"

/*
	Finds all sub array with zero sum for a given sequence and returns an array of arrays with all sub arrays.
*/
void getZeroSums(int *items, unsigned size)
{
	int graphs[size];	// each index will be graph X and each value will be sum at given index for graph X (see above)
	unsigned currentNumGraphs = 0;	// current number of graphs - at most it will be = len(items)

	struct dynamicArrMeta dynArr = newDynamicArrMeta(1, 1, sizeof(subArr));	// holds data about zeroSums dyn array
	struct subArr *zeroSums = malloc(sizeof(subArr) * dynArr.maxCap);	// dyn array holding all sub arrays with 0 graphs

	for (unsigned ind = 0; ind < size; ind++)
	{
		int item = items[ind];
		graphs[currentNumGraphs] = item;

		/*
			By default, a value of 0 is a zero sum.
		*/
		if (item == 0)
		{
				zeroSums[dynArr.nextUnused] = splice(items, size, ind, ind + 1);

				dynArr.nextUnused++;
				zeroSums = (subArr *) resizeDynArray(zeroSums, &dynArr);
		}

		/*
			Increases sum for each graph except the last one.
		*/
		for (unsigned jnd = 0; jnd < currentNumGraphs; jnd++)
		{
			graphs[jnd] += item;

			/*
				If after adding the current element to the graph sum we get a 0, then we found a zero sum sub array from -
				[graph X, currentInd]
			*/
			if (graphs[jnd] == 0)
			{
				zeroSums[dynArr.nextUnused] = splice(items, size, jnd, ind + 1);

				dynArr.nextUnused++;
				zeroSums = (subArr *)resizeDynArray(zeroSums, &dynArr);
			}
		}
		currentNumGraphs++;
	}

	printSubArrs(zeroSums, dynArr.nextUnused);
}

int main()
{
	int items[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
	unsigned size = sizeof(items) / sizeof(int);

	getZeroSums(items, size);
	return 0;
}