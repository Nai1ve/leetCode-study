#include<iostream>
#include"Solution.h"
int main() {
	

	vector<vector<int>> points(4,vector<int>(2));
	
	points[0][0] = 3;
	points[0][1] = 10;
	points[1][0] = 5;
	points[1][1] = 15;
	points[2][0] = 10;
	points[2][1] = 2;
	points[3][0] = 4;
	points[3][1] = 4;

	Solution solution;

	solution.minimumDistance(points);
}