#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N , M;
    cin >> N  >> M;

    vector<vector<int>> light(N+1); // 특정 노드보다 가벼운 것들
    vector<vector<int>> heavy(N+1); // 특정 노드보다 무거운 것들


    for (int i =0; i<M; ++i)
    {
        int big , small;
        cin >> big >> small;
        light[big].push_back(small);
        heavy[small].push_back(big);
    }

    vector<int> possibleLightNode(N+1 , 0);
    vector<int> possibleHeavyNode(N+1 , 0);

     int mid = (N-1)/2;

    for (int i = 1; i <= N; ++i)
    {
        queue<int> q;
        q.push(i);
        vector<int> visited(N+1 , false);
        visited[i] = true;
        int arrive = 0;
        while (!q.empty())
        {
            int cur = q.front();q.pop();

            for (int next : light[cur])
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                    arrive+=1;
                }
            }
        }

        possibleLightNode[i] = arrive;
        // 자기보다 무거운 노드들 순서대로 방문하기

        fill(visited.begin(), visited.end(), false);
        visited[i] = true;
        arrive = 0;
        q.push(i);

        while (!q.empty())
        {
            int cur = q.front();q.pop();

            for (int next : heavy[cur])
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                    arrive+=1;
                }
            }
        }

        possibleHeavyNode[i] = arrive;
    }
    int answer = 0;
    for (int i = 1; i<= N; ++i)
    {
        if (possibleHeavyNode[i] > mid || possibleLightNode[i] > mid)
        {
            answer += 1;
        }
    }

     cout << answer << '\n';

}
