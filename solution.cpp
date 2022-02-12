#include "solution.h"
#include <map>
#include <cstdlib>
using namespace sol1057;
using namespace std;

/*takeaways
  - if the max distance between a worker and a bike
    is known that we can create a vector of buckets
    to hold every possible distance
    - it's already sorted by distance as the
      distance is the key of the
    - we don't need to use map or min-heap to
      maintain the order
    - inside each bucket is a list of worker-bike
      pair which is already in ascending order
      due to how we build it

  - alternatively we can use map or min-heap
    if number of workers and bikes are not too
    big


*/

vector<int> Solution::assign(vector<vector<int>> &ws, vector<vector<int>> &bs)
{
  /*
    - index is the worker;
    - value is the bike assigned
  */
  auto assigned = vector<int>(ws.size(), -1);

  /*
    - index is the distance
    - value is a list of worker-bike pair
      in ascending order by worker index
      and bike index
      - this is achieved by how we scan
        the ws and bs lists
  */
  auto distMap = vector<vector<pair<int, int>>>(2001, vector<pair<int, int>>());
  for (auto i = 0; i < ws.size(); i++)
    for (auto j = 0; j < bs.size(); j++)
    {
      auto dist = abs(ws[i][0] - bs[j][0]) +
                  abs(ws[i][1] - bs[j][1]);
      distMap[dist].push_back(make_pair(i, j));
    }
  auto bAssigned = vector<bool>(bs.size() - 1, false);

  /* assign the bikes; shorter distance first */
  for (auto d : distMap)
    for (auto p : d)
      if (!bAssigned[p.second] && assigned[p.first] == -1)
      {
        /* mark bike as assigned */
        bAssigned[p.second] = true;
        /* assign bike to worker */
        assigned[p.first] = p.second;
      }

  return assigned;
}