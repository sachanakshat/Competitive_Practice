/*

A subarray is a contiguous portion of an array. Given an array of integers numbers and an integer k, your task is to determine the number of distinct subarrays of numbers with at most k odd elements. Two subarrays are considered distinct if their contents differ in at least one position.

Example

    For numbers = [1, 2, 3, 4] and k = 1, the output should be evenSubarray(numbers, k) = 8.

    Here is the list of all 8 distinct subarrays with at most 1 odd element:

    [[1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [2, 3, 4]]

    For numbers = [11, 11, 11, 11, 11] and k = 2, the output should be evenSubarray(numbers, k) = 2.

    There are only 2 distinct subarrays with at most 2 odd elements:

    [[11], [11, 11]]

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer numbers

    An array of integers.

    Guaranteed constraints:
    1 ≤ numbers.length ≤ 1000,
    1 ≤ numbers[i] ≤ 250.

    [input] integer k

    The maximum number of odd elements the subarray can contain.

    Guaranteed constraints:
    1 ≤ k ≤ numbers.length.

    [output] integer
        The number of distinct subarrays that can be formed with at most k odd elements.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
std::string helloWorld(std::string name) {
    std::cout << "This prints to the console when you Run Tests" << std::endl;
    return "Hello, " + name;
}

*/

bool kOdd(int arr[], int k)
{
    int c =0;
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n; i++)
    {
        if(arr[i]%2!=0)
            c++;
    }
    if(c<=k)
        return true;
    else
        return false;
}

int evenSubarray(std::vector<int> numbers, int k) {
    int i,j,l,count=0;
    int n = numbers.size();
    for(i=1; i<n; i++)
    {
        int arr[i];
        for(j=0; j<n-i+1; j++)
        {
            for(l=0; l<i; l++)
            {
                arr[l] = numbers[j+l];
            }
            if(kOdd(arr,k))
                count++;
        }
    }
    return count;
}


/*
Q2
Given a graph of friends who have different interests, you'd like to know which groups of friends have the most interests in common. You will then use a little math to determine a value to return.

You are given integers friends_nodes and friends_edges, representing the number of nodes and edges in the graph respectively. You are also given three arrays of integers, friends_from, friends_to, and friends_weight, which describe the edges between friends.

The graph consists of nodes numbered consecutively from 1 to friends_nodes. Any members or groups of members who share the same interest are said to be connected by that interest (note that two group members can be connected by some interest even if they are not directly connected by the corresponding edge).

Once you have determined the node pairs with the maximum number of shared interests, return the product of the node pairs' labels. If there are multiple pairs with the maximum number of shared interests, return the maximum product among them.

For example, you are given a graph with friends_nodes = 4 and friends_edges = 5:
From 	To 	Weight
1 	2 	2
1 	2 	3
2 	3 	1
2 	3 	3
2 	4 	4

If we look at each interest, we have the following connections:
Interest 	Connectons
1 	2, 3
2 	1, 2
3 	1, 2, 3
4 	2, 4

In this case, we see the pairs (1, 2) (interests 2 and 3) and (2, 3) (interests 1 and 3) each share two interests which is maximal. We take the products of the node numbers: 1 × 2 = 2 and 2 × 3 = 6. The maximal value 6 is returned.

Example

    For friends_nodes = 4, friends_edges = 5, friends_from = [1, 1, 2, 2, 2], friends_to = [2, 2, 3, 3, 4], and friends_weight = [1, 2, 1, 3, 3], the output should be sharedInterests(friends_nodes, friends_edges, friends_from, friends_to, friends_weight) = 6.

    Each pair among the 4 friends is connected by the following interests:
        Pair (1, 2) shares 2 interests (interests 1 and 2)
        Pair (1, 3) shares 1 interest (interest 1)
        Pair (1, 4) shares 0 interests
        Pair (2, 3) shares 2 interests (interests 1 and 3)
        Pair (2, 4) shares 1 interest (interest 3)
        Pair (3, 4) shares 1 interest (interest 3). Note that even though these two friends are not directly connected by an edge, they still share a common interest.

    The pairs with the maximal number of shared interests are (1, 2) and (2, 3). Their respective products are 1 × 2 = 2 and 2 × 3 = 6. We then return the largest of these values as our answer, which is 6.

    For friends_nodes = 4, friends_edges = 4, friends_from = [1, 1, 2, 2], friends_to = [3, 3, 4, 4], and friends_weight = [1, 2, 1, 2], the output should be sharedInterests(friends_nodes, friends_edges, friends_from, friends_to, friends_weight) = 12.

    Interests 1 and 2 are both shared between friends (1, 3) and between friends (2, 4). Thus, both of these two interests are shared between all friends and each pair of friends has both of these interests shared in common.
    The maximal product of friends node numbers is 3 × 4 = 12.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] integer friends_nodes

    The number of nodes.

    Guaranteed constraints:
    2 ≤ friends_nodes ≤ 100.

    [input] integer friends_edges

    The number of edges between nodes.

    Guaranteed constraints:
    1 ≤ friends_nodes ≤ min(200, (friends_nodes × (friends_nodes - 1)) / 2).

    [input] array.integer friends_from

    An array of one of the endpoints of each edge, meaning that (friends_from[i], friends_to[i]) is an edge of the graph. All edges are bidirectional (therefore (friends_to[i], friends_from[i]) is also an edge).

    Guaranteed constraints:
    friends_from.length = friends_edges,
    1 ≤ friends_from[i] ≤ friends_nodes.

    [input] array.integer friends_to

    An array of one of the endpoints of each edge, meaning that (friends_from[i], friends_to[i]) is an edge of the graph.

    Guaranteed constraints:
    friends_to.length = friends_edges,
    1 ≤ friends_to[i] ≤ friends_nodes,
    friends_to[i] ≠ friends_from[i].

    [input] array.integer friends_weight

    An array of indices for each interest, meaning that the edge (friends_from[i], friends_to[i]) has a label of friends_weight[i].

    Guaranteed constraints:
    friends_weight.length = friends_edges,
    1 ≤ friends_weight[i] ≤ 100.

    [output] integer
        The maximal product of the node pairs' labels among the node pairs with the maximum number of shared interests.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
std::string helloWorld(std::string name) {
    std::cout << "This prints to the console when you Run Tests" << std::endl;
    return "Hello, " + name;
}

*/

int sharedInterests(int friends_nodes, int friends_edges, std::vector<int> friends_from, std::vector<int> friends_to, std::vector<int> friends_weight) {

}

/*
Q3

You're given a log of daily readings of mercury levels in a river. In each test case, there are missing mercury values for several of the days. Your task is to analyze the data and try to identify all of the missing values.

Each row of data contains three whitespace-separated values: date, time and the highest reading for that day.

There are exactly twenty rows with missing values in each input file. The missing values are marked as "Missing_1", "Missing_2", ..., "Missing_20". These missing records have been randomly dispersed in the rows of data.

Return a list of all the missing values in order.

Note: All mercury levels are below 400.

Scoring

We will compute the mean of the magnitude of the percentage difference by comparing your expected answers with the actual mercury level for each of the missing records (in all test cases - samples included).

We start by calculating the total sum of percentage differences between the actual and estimated values:

t=∑iabs(expectedValuei−computedValuei)expectedValuei×100t = \sum_i \frac{abs(expectedValue_i - computedValue_i)}{expectedValue_i} \times 100 t=​i​∑​​​expectedValue​i​​​​abs(expectedValue​i​​−computedValue​i​​)​​×100

Then we calculate the average difference by dividing the sum by the number of missing values: d = t / 20.

Your final score on a scale from 0 to 1 will be: max(2 - d, 0) / 2.

That is, if the mean value d exceeds 2% (your predictions are off by 2% or more on average), you will score a zero. If your predictions are all right on target, you will score 1 (and get the maximal score for this test).

If your program throws an error (or produces an incorrect output format) for a single test case, the overall score assigned will be zero.

Example

Example of input file:

250
1/3/2012 16:00:00 Missing_1
1/4/2012 16:00:00 27.47
1/5/2012 16:00:00 27.728
1/6/2012 16:00:00 28.19
1/9/2012 16:00:00 28.1
1/10/2012 16:00:00 28.15
....
....
....
12/13/2012 16:00:00 27.52
12/14/2012 16:00:00 Missing_19
12/17/2012 16:00:00 27.215
12/18/2012 16:00:00 27.63
12/19/2012 16:00:00 27.73
12/20/2012 16:00:00 Missing_20
12/21/2012 16:00:00 27.49
12/24/2012 13:00:00 27.25
12/26/2012 16:00:00 27.2
12/27/2012 16:00:00 27.09
12/28/2012 16:00:00 26.9
12/31/2012 16:00:00 26.77

Example of output file:

26.96
31.98
32.69
32.41
32.32
30.5
29.18
30.8
30.46
30.63
30.96
30.4
28.2
28.2
27.3
27.1666
27.58
26.82
27.13
27.68

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.string levels

    Each string contains whitespace-separated date, time and mercury_level.

    [output] array.float
        An array of length 20 with missing mercury levels.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
std::string helloWorld(std::string name) {
    std::cout << "This prints to the console when you Run Tests" << std::endl;
    return "Hello, " + name;
}

*/

std::vector<double> fillingInData(std::vector<std::string> levels) {

}