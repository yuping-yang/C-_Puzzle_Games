# Maze_v2
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols,  int startX,int startY, int endX, int endY,vector<int>& Path)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || startX<0||startY<0||endX<0||endY<0||(startX==endX&&startY==endY))
			return false;
		bool* visited = new bool[rows*cols] // Define a matrix to mark whether the path has entered each grid		
memset(visited, 0, rows*cols);
		int pathLength = 0;
		if (hasPathCore(matrix, rows, cols, startX, startY, endX, endY, visited, Path))
		{
			return true;
		}
		delete[] visited;
		return false;
	}

	/* This function is used to determine whether there is a grid in the adjacent grid that meets the conditions when the current path meets the conditions. */
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, int endX, int endY, bool* visited, vector<int>& Path)
	{
		if ((row == endX) && (col == endY)&&(matrix[row*cols+col]=='1'))
		{
			Path.push_back(endY);
    		Path.push_back(endX);
			return true;
		}
		bool hasPath = false;
		if (row >= 0 && row < rows&&col >= 0 && col < cols&&matrix[row*cols + col] == '1' && !visited[row*cols + col])
		{
//			++pathLength;
			visited[row*cols + col] = true;
			Path.push_back(col);
			Path.push_back(row);
			/* If the character of the matrix grid (row, col) is 1, find the next grid with the character 1 from its 4 adjacent grids */
			hasPath = hasPathCore(matrix, rows, cols, row, col - 1, endX, endY, visited,Path) ||
				hasPathCore(matrix, rows, cols, row - 1, col, endX, endY, visited,Path) ||
				hasPathCore(matrix, rows, cols, row, col + 1, endX, endY, visited,Path) ||
				hasPathCore(matrix, rows, cols, row + 1, col, endX, endY, visited,Path);
			if (!hasPath)                             // If not found, it means that the current nth grid is positioned incorrectly, return to the previous position and reposition it
			{
				visited[row*cols + col] = false;
				Path.pop_back();
				Path.pop_back();
			}
		}
		return hasPath;
	}
};

int main()
{
	//	char* matrix = "abcesfcsadee";
	char* matrix = "1000000110110001101000010111011110100000010000001";        // Setting up the maze
	int startX, startY, endX, endY;
	cin >> startX >> startY >> endX >> endY;                                   // Enter the start and end coordinates
	Solution s;
	vector<int> Path;
	bool re = s.hasPath(matrix, 7, 7, startX,startY,endX,endY,Path);
	cout << re << endl;
	for (int i = 0; i < Path.size();)
		cout << "(" << Path[i++] << ',' << Path[i++] << ")" << " ";
	cout << endl;
	return 0;
}
