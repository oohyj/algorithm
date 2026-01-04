#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    vector<vector<int>> board;


    for (int i = r1; i <= r2; ++i)
    {
        vector<int> row;
        for (int j = c1; j <= c2; ++j)
        {
            int layer = max(abs(i), abs(j));
            int base = (2 * layer + 1) * (2 * layer + 1);
            int value;

            if (i == layer) // 아래쪽 변
            {
                value = base - (layer - j);
            }
            else if (j == -layer) // 왼쪽 변
            {
                value = base - 2 * layer - (layer - i);
            }
            else if (i == -layer) // 위쪽 변
            {
                value = base - 4 * layer - (layer + j);
            }
            else // 오른쪽 변 
            {
                value = base - 6 * layer - (layer + i);
            }

            row.push_back(value);
        }
        board.push_back(row);
    }

    int width = 0;
    for (auto &row : board)
    {
        for (int v : row)
        {
            width = max(width, (int)to_string(v).length());
        }
    }

    for (auto &row : board)
    {
        for (int j = 0; j < row.size(); ++j)
        {
            if (j > 0) cout << " ";
            cout << setw(width) << row[j];
        }
        cout << '\n';
    }

    return 0;
}