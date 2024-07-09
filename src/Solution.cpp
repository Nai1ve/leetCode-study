#include "Solution.h"
#include "unordered_map"
#include "string"
#include <iostream>
int Solution:: minimumDistance(vector<vector<int>>& points) {
	// 两个单元格 (xi, yi) 和 (xj, yj) 之间的曼哈顿距离为 |xi - xj| + |yi - yj|。
	// 暴力算法 但会存在重复的数据计算，可以构建一个缓存，（1到2的距离和2到1的距离是一样的）
	unordered_map<string, int> distinceMap;

	int minDistince = INT8_MAX;
	int size = points.size();

	for (int i = 0; i <size; i++)
	{
		int maxDistince = 0;
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				continue;
			}
			//计算除i以外的两点距离
			for (int k = j; k < size; k++)
			{
				if (k==i)
				{
					continue;
				}

				if (distinceMap.find(to_string(j).append(to_string(k))) != distinceMap.end())
				{
					maxDistince = maxDistince > distinceMap[to_string(j).append(to_string(k))] ? maxDistince : distinceMap[to_string(j).append(to_string(k))];
				}
				else
				{
					int distince = abs(points[j][0] - points[k][0]) + abs(points[j][1] - points[k][1]);
					distinceMap[to_string(j).append(to_string(k))] = distince;
					maxDistince = maxDistince > distince ? maxDistince : distince;
				}
			}
			
		}
		cout << maxDistince<<endl;
		minDistince = minDistince < maxDistince ? minDistince : maxDistince;
	}
	return minDistince;
}


