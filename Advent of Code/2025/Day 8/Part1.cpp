#include <bits/stdc++.h>
typedef long long ull;

std::string source = "Input.txt";
int count;
int solution = 1;

struct Point {
    int x,y,z;

    Point(const int _x, const int _y, const int _z) : x(_x), y(_y), z(_z) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        os << "(" << obj.x << ", " << obj.y << ", " << obj.z << ")";
        return os;
    }
};

struct Distance {
    ull distance; int first, second;

    Distance(const ull d, const int f, const int s): distance(d), first(f), second(s) {}

    bool operator<(const Distance& other) const {
        if (distance != other.distance) {
            return distance < other.distance;
        }
        if (first != other.first) {
            return first < other.first;
        }
        return second < other.second;
    }
};

std::vector<Point> Points;
std::set<Distance> Order;
std::unordered_map<int,int>Belongs;
std::unordered_map<int,int>Count_Vertices;
std::multiset<int> Sizes;

inline ull distance(const Point& P1, const Point& P2) {
    ull dx = P1.x - P2.x;
    ull dy = P1.y - P2.y;
    ull dz = P1.z - P2.z;
    return dx*dx + dy*dy + dz*dz;
}

void ingest(std::ifstream& fin) {
    fin >> count;

    unsigned int x,y,z;
    char comma;

    while (fin >> x >> comma >> y >> comma >> z)
        Points.emplace_back(x,y,z);
}

void populate() {
    for (int i = 0; i < Points.size(); i++) {
        for (int j = i+1; j < Points.size(); j++) {
            const ull dist = distance(Points[i],Points[j]);
            Order.emplace(dist,i,j);
        }
    }
}

void trim() {
    const auto it = std::next(Order.begin(), count);
    Order.erase(it, Order.end());
}

void conjoin() {
    int id = 1;
    int counter = count;
    for (auto [distance, first, second] : Order) {
        if (counter <= 0) break;
        //We first find the locations of the elements in the map
        auto f = Belongs.find(first);
        auto s = Belongs.find(second);

        //Cases for joining

        //1. Both of them are connected to other vertices
        if (f != Belongs.end() && s != Belongs.end()) {
            if (f->second == s->second) {
                counter--;
                std::cout << "Points " << Points[first] << " and " << Points[second] <<
                    " belong to the same subgraph. \tEdge not needed."
                    << std::endl;
                continue;
            }

            //We will be overwriting the second's chain's id to the first's chain's id.
            const auto old_v = s->second;
            const auto new_v = f->second;
            for (auto& [key, value] : Belongs)
                if (value == old_v)
                    value = new_v;

            //Edge is created
            counter--;
            std::cout << "Points " << Points[first] << " and " << Points[second] <<
                " belong to the different subgraphs. \tEdge No. " << count-counter << " created."
                << std::endl;


            continue;
        }

        //2. Both of them are connected only to each other.
        if (f == Belongs.end() and s == Belongs.end()) {
            Belongs[first] = id;
            Belongs[second] = id;
            id++; counter--;
            std::cout << "Points " << Points[first] << " and " << Points[second] <<
                " only connect to themselves. \t\tEdge No. " << count-counter << " created."
                << std::endl;
            continue;
        }

        //3. One of them is connected. The other isn't.
        auto active = (f != Belongs.end())?first:second;
        auto empty = (f == Belongs.end())?first:second;
        Belongs[empty] = Belongs[active];
        counter--;
        std::cout << "One Point between " << Points[first] << " and " << Points[second] <<
            " is isolated. \t\tEdge No. " << count-counter << " created."
            << std::endl;
    }
}

void print_Order() {
    int i = 1;
    for (auto [distance, first, second] : Order) {
        std::cout << i++ << ". Squared distance of " << distance <<
            " between [" << first+1 << "]: " << Points[first] << " and [" << second+1 << "]: " << Points[second] << "."
            << std::endl;
    }
    std::cout << std::endl;
}

void print_Belongs() {
    std::cout <<std::endl;
    for (auto& [key, value] : Belongs) {
        // std::cout << "Point " << Points[key] << "\tbelongs to group: " << value << std::endl;
        Count_Vertices[value]++;
    }
}

void print_edges_in_groups() {
    int sum = 0;
    for (auto& [key, value] : Count_Vertices) {
        // std::cout << "Group " << key << " has these many vertices: " << value << std::endl;
        sum += value-1;
        Sizes.insert(value);
    }
    std::cout << std::endl;
    std::cout << "Total number of edges: "<< sum << std::endl;

    std::cout << "The three largest subgraphs: ";
    int limit = 3;
    for (auto it = Sizes.rbegin(); it != Sizes.rend() and limit; limit--, ++it) {
        std::cout << *it << " ";
        solution *= *it;
    }
    std::cout << std::endl;
    std::cout << "Solution: " << solution << std::endl;

}

int main() {
    std::ifstream fin (source);

    ingest(fin);
    populate();
    // trim();
    conjoin();
    // print_Order();
    print_Belongs();
    print_edges_in_groups();

    // std::cout << Order.size() << std::endl;
    return 0;
}


// struct Graph {
//     int id;
//     std::unordered_set<int> vertices;
//
//     bool operator>(const Graph& other) const {
//         if (vertices.size() != other.vertices.size()) {
//             return vertices.size() > other.vertices.size();
//         }
//         return id > other.id;
//     }
// };
//
// void mergeGraphs(Graph& a, Graph& b) {
//     if (a.vertices.size() < b.vertices.size()) {
//         b.vertices.insert(a.vertices.begin(), a.vertices.end());
//     } else {
//         a.vertices.insert(b.vertices.begin(), b.vertices.end());
//     }