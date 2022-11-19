#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <vector<int>> trees;
    if (trees.size() == 1 || trees.size() == 2)
    {
        //return trees;
    }
    vector<int> a, b;
    vector<vector<int>> ans;
    int ind_temp;
    vector<int> temp, point;
    vector<int> left_p = { 1000, 1000 };
    for (int i = 0; i < trees.size(); i++)
    {
        point = trees[i];
        if (point[0] < left_p[0])
        {
            left_p = point;
            ind_temp = i;
        }
        else
        {
            if (point[0] == left_p[0] && point[1] < left_p[1])
            {
                left_p = point;
                ind_temp = i;
            }
        }
    }
    swap(trees[0], trees[ind_temp]);
    vector<int> prev = left_p;
    int min_ind = 1;
    int n = trees.size();
    do
    {
        temp = trees[min_ind];
        ind_temp = min_ind;
        ans.push_back(prev);
        a = { temp[0] - prev[0], temp[1] - prev[1] };
        for (int i = min_ind + 1; i < n; i++)
        {
            point = trees[i];
            b = { point[0] - prev[0], point[1] - prev[1] };
            if (a[0] * b[1] - a[1] * b[0] < 0)
            {
                temp = point;
                ind_temp = i;
                a = { temp[0] - prev[0], temp[1] - prev[1] };
            }
            else
            {
                if (a[0] * b[1] - a[1] * b[0] == 0)
                {
                    if (b[0] * b[0] + b[1] * b[1] < a[0] * a[0] + a[1] * a[1])
                    {
                        temp = point;
                        ind_temp = i;
                        a = { temp[0] - prev[0], temp[1] - prev[1] };
                    }
                }
            }
        }
        point = trees[0];
        b = { point[0] - prev[0], point[1] - prev[1] };
        if (a[0] * b[1] - a[1] * b[0] < 0)
        {
            temp = point;
            ind_temp = 0;
        }
        else
        {
            if (a[0] * b[1] - a[1] * b[0] == 0 && a[0] * b[0] + a[1] * b[1] > 0)
            {
                if (b[0] * b[0] + b[1] * b[1] < a[0] * a[0] + a[1] * a[1] && b[0] * b[0] + b[1] * b[1] != 0)
                {
                    temp = point;
                    ind_temp = 0;
                }
            }
        }
        prev = temp;
        swap(trees[min_ind], trees[ind_temp]);
        min_ind += 1;
    } while ((prev[0] != left_p[0] || prev[1] != left_p[1]) && min_ind != n);
    if (prev[0] != left_p[0] || prev[1] != left_p[1])
    {
        ans.push_back(prev);
    }
    //return ans;
    return 0;
}
