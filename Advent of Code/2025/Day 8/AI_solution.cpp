#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Point3D {
    double x, y, z;
};

struct Edge {
    int u, v;
    double weight;
};

// Disjoint Set Union (DSU) for Kruskal's
struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

double calculateDistance(Point3D a, Point3D b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2) + std::pow(a.z - b.z, 2));
}

int main() {
    std::string filename = "Input.txt";
    std::ifstream infile(filename);

    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::vector<Point3D> points;
    double x, y, z;
    char comma;
    while (infile >> x >> comma >> y >> comma >> z) {
        points.push_back({x, y, z});
    }
    infile.close();

    int n = points.size();
    if (n < 2) {
        std::cout << "Not enough points to form an MST." << std::endl;
        return 0;
    }

    // 1. Generate all possible edges (N^2 approach)
    std::vector<Edge> all_edges;
    all_edges.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            all_edges.push_back({i, j, calculateDistance(points[i], points[j])});
        }
    }

    // 2. Sort edges by weight (Shortest first)
    std::sort(all_edges.begin(), all_edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    // 3. Build MST using Union-Find
    DSU dsu(n);
    std::vector<Edge> mst;
    for (const auto& edge : all_edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
        }
        if (mst.size() == n - 1) break;
    }

    // 4. Output results
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "MST generated with " << mst.size() << " edges." << std::endl;

    if (!mst.empty()) {
        Edge lastEdge = mst.back();
        std::cout << "\n--- THE LAST EDGE ---" << std::endl;
        std::cout << "Connects Index [" << lastEdge.u << "] and [" << lastEdge.v << "]" << std::endl;
        std::cout << "Distance (Weight): " << lastEdge.weight << std::endl;
        std::cout << "Coordinates: (" << points[lastEdge.u].x << "," << points[lastEdge.u].y << "," << points[lastEdge.u].z << ") to ("
                  << points[lastEdge.v].x << "," << points[lastEdge.v].y << "," << points[lastEdge.v].z << ")" << std::endl;

        std::cout << std::endl << "Solution: " << points[lastEdge.u].x*points[lastEdge.v].x << std::endl;
    }

    return 0;
}