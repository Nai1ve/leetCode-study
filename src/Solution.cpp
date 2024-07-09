#include "Solution.h"
#include "unordered_map"
#include "string"
#include <iostream>
int Solution:: minimumDistance(vector<vector<int>>& points) {
	// ������Ԫ�� (xi, yi) �� (xj, yj) ֮��������پ���Ϊ |xi - xj| + |yi - yj|��
	// �����㷨 ��������ظ������ݼ��㣬���Թ���һ�����棬��1��2�ľ����2��1�ľ�����һ���ģ�
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
			//�����i������������
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


