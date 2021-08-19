#include <bits/stdc++.h>

using namespace std;
int vertex = 7;
int parent[10000] = {-1};
int rankk[10000] = {0};

int findParent(int node)
{
  if (parent[node] == -1)
    return node;
  return parent[node] = findParent(parent[node]);
}

void unionn(int u, int v)
{
  int u = findParent(u);
  int v = findParent(v);
  if (rankk[u] > rankk[v])
  {
    parent[v] = u;
  }
  else if (rankk[u] < rankk[v])
  {
    parent[u] = v;
  }
  else
  {
    parent[v] = u;
    rankk[v]++;
  }
}
int main()
{
}