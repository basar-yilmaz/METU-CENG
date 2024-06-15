#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
// do not add extra libraries here

using namespace std;

#include <iostream>

int extract_min(vector<int> &keys, vector<bool> &visited)
{
    int min_key = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < keys.size(); ++i)
    {
        if (!visited[i] && keys[i] < min_key)
        {
            min_key = keys[i];
            min_index = i;
        }
    }

    return min_index;
}

void process_vertex(int u, vector<int> &keys, vector<int> &parent, vector<vector<pair<int, int>>> &lowest_energy_structure)
{
    if (parent[u] != -1)
    {
        lowest_energy_structure[u].push_back({parent[u], keys[u]});
        lowest_energy_structure[parent[u]].push_back({u, keys[u]});
    }
}

void relax_edges(int u, vector<int> &keys, vector<int> &parent, vector<vector<pair<int, int>>> &bond_energies)
{

    for (const auto &edge : bond_energies[u])
    {
        int v = edge.first;
        int weight = edge.second;

        if (weight < keys[v])
        {
            keys[v] = weight;
            parent[v] = u;
        }
    }
}

int find_structure_loop(vector<vector<pair<int, int>>> &bond_energies,
                        vector<vector<pair<int, int>>> &lowest_energy_structure,
                        vector<bool> &visited,
                        vector<int> &parent,
                        vector<int> &keys)
{
    int numVertices = bond_energies.size();
    int total_energy = 0;

    // prim's algorithm from slides
    keys[0] = 0;

    while (true)
    {
        // Find the vertex with the minimum key among the unvisited vertices.
        int u = extract_min(keys, visited);

        // If no unvisited vertices are left, break from the loop.
        if (u == -1)
            break;

        visited[u] = true;
        total_energy += keys[u];

        process_vertex(u, keys, parent, lowest_energy_structure);
        relax_edges(u, keys, parent, bond_energies);
    }

    return total_energy;
}

int find_structure(vector<vector<pair<int, int>>> &bond_energies,
                   vector<vector<pair<int, int>>> &lowest_energy_structure)
{
    int numVertices = bond_energies.size();
    int total_energy = 0;

    vector<bool> visited(numVertices, false); // A boolean vector to mark visited vertices.

    vector<int> parent(numVertices, -1); // A vector to store the parent of each vertex in the MST.

    vector<int> keys(numVertices, INT_MAX); // A vector to store the minimum weight to connect each vertex to the MST.

    total_energy = find_structure_loop(bond_energies, lowest_energy_structure, visited, parent, keys);

    return total_energy;
}

int bfs(const vector<vector<pair<int, int>>> &molecule_structure, vector<int> &parent, int start_node, int &max_distance, int &lastIndex)
{
    vector<int> distance(molecule_structure.size(), -1);

    queue<int> q;
    q.push(start_node);

    distance[start_node] = 0;
    while (!q.empty())
    {
        lastIndex = q.front();
        q.pop();

        for (const auto &edge : molecule_structure[lastIndex] /* adj list*/)
        {
            int v = edge.first;

            if (distance[v] == -1)
            {
                q.push(v);
                parent[v] = lastIndex;
                distance[v] = distance[lastIndex] + 1;
            }
        }
    }

    int node;

    for (int i = 0; i < distance.size(); ++i)
    {
        if (distance[i] > max_distance)
        {
            max_distance = distance[i];
            node = i;
        }
    }

    return node;
}

int find_longest_chain(vector<vector<pair<int, int>>> &molecule_structure, vector<int> &chain)
{
    int longest_chain_size = 0;
    int lastIndex = -1;
    vector<int> parent(molecule_structure.size(), -1);
    
    int start_node = bfs(molecule_structure, parent, 0, longest_chain_size, lastIndex);

    parent.clear();
    parent.resize(molecule_structure.size(), -1);

    int end_node = bfs(molecule_structure, parent, start_node, longest_chain_size, lastIndex);

    for (int i = lastIndex; i != -1; i = parent[i])
    {
        chain.push_back(i);
    }

    reverse(chain.begin(), chain.end());
    return longest_chain_size + 1;
}

int main()
{
    // Example molecular structure represented as an adjacency list
    std::vector<std::vector<std::pair<int, int>>> molecule_structure = {
        {{4, 4}},                 // Node 0 is connected to nodes 1 and 2 with weights 1 and 2
        {{2, 3}},                 // Node 1 is connected to nodes 0 and 3 with weights 1 and 3
        {{1, 3}, {3, 2}, {4, 1}}, // Node 2 is connected to nodes 0 and 4 with weights 2 and 4
        {{2, 2}},                 // Node 3 is connected to node 1 with weight 3
        {{0, 4}, {2, 1}},         // Node 4 is connected to node 2 with weight 4
    };

    std::vector<int> chain;
    int longest_chain_size = find_longest_chain(molecule_structure, chain);

    std::cout << "Longest Chain Size: " << longest_chain_size << std::endl;
    std::cout << "Nodes in the Longest Chain: ";
    for (int node : chain)
    {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}
