#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1057;

/*
Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: [1,0]
*/
tuple<vector<vector<int>>, vector<vector<int>>, vector<int>>
testFixture1()
{
  auto ws = vector<vector<int>>{
      {0, 0}, {2, 1}};
  auto bs = vector<vector<int>>{
      {1, 2}, {3, 3}};
  auto output = vector<int>{1, 0};
  return make_tuple(ws, bs, output);
}

/*
Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: [0,2,1]
*/
tuple<vector<vector<int>>, vector<vector<int>>, vector<int>>
testFixture2()
{
  auto ws = vector<vector<int>>{
      {0, 0}, {1, 1}, {2, 0}};
  auto bs = vector<vector<int>>{
      {1, 0}, {2, 2}, {2, 1}};
  auto output = vector<int>{0, 2, 1};
  return make_tuple(ws, bs, output);
}

string toString(vector<int> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += to_string(e);
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see: "
       << toString(get<2>(f)) << endl;
  Solution sol;
  auto result = sol.assign(get<0>(f), get<1>(f));
  cout << "result: " << toString(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see: "
       << toString(get<2>(f)) << endl;
  Solution sol;
  auto result = sol.assign(get<0>(f), get<1>(f));
  cout << "result: " << toString(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}