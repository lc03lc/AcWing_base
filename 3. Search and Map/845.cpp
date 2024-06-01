#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node
{
    char map[3][3];
    int sum;
};

char map[3][3];
char target[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', 'x'}};
int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }

    queue<Node> q;
    Node node;
    memcpy(node.map, map, sizeof(map));
    node.sum = 0;
    q.push(node);

    while (!q.empty())
    {
        auto pMap = q.front();
        q.pop();
        pair<int, int> xx;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (pMap.map[i][j] == 'x')
                {
                    xx = {i, j};
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int x_ = xx.first + x[i];
            int y_ = xx.second + y[i];
            if (x_ >= 0 && x_ < 3 && y_ >= 0 && y_ < 3)
            {
                char pMapCopy[3][3];
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        pMapCopy[i][j] = pMap.map[i][j];
                    }
                }
                swap(pMapCopy[x_][y_], pMapCopy[xx.first][xx.second]);
                int s = pMap.sum + 1;
                Node nn;
                memcpy(nn.map, pMapCopy, sizeof(pMapCopy));
                nn.sum = s;

                int flag = 0;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if(target[i][j]!=pMapCopy[i][j])
                        {
                            flag = 1;
                        }
                    }
                }
                if(flag == 0)
                {
                    cout << s;
                    exit(0);
                }

                q.push(nn);
            }
        }
    }
}