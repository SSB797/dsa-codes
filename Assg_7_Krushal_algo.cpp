#include <bits\stdc++.h>
using namespace std;

#define MAX 10
vector<int> parent(MAX);
vector<int> size(MAX);

void make_set(int v)
{
  parent[v] = v;
  size[v] = 1;
}

int find_set(int v)
{
  if (v == parent[v])
  {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
  a = find_set(a);
  b = find_set(b);

  if (a != b)
  {
    if (size[a] < size[b])
    {
      swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
  }
}

int main()
{
  for (int i = 0; i < MAX; i++)
  {
    make_set(i);
  }

  int n, m;
  cout << "Enter the number of node: ";
  cin >> n;
  cout << "Enter the number of edges: ";
  cin >> m;

  vector<vector<int>> edges;
  cout << "Source --> Destination: Weight " << endl;
  for (int i = 0; i < m; i++)
  {
    int source, destination, weight;
    cin >> source >> destination >> weight;
    edges.push_back({weight, source, destination});
  }

  sort(edges.begin(), edges.end());

  int cost = 0;

  for (auto i : edges)
  {
    /*
    X --> SOURCE
    Y --> DESTINATION
    W --> WEIGHT
  */
    int w = i[0];
    int x = i[1];
    int y = i[2];

    int p = find_set(x);
    int q = find_set(y);

    if (p == q)
    {
      continue;
    }
    else
    {
      cout << "Source vertex: " << x << " Destination vertex: " << y << endl;
      cost += w;
      union_set(x, y);
    }
  }
  cout << "The final  cost is: " << cost << endl;
}