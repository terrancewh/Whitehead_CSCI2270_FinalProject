#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>

using namespace std;

struct City{
    string citytitle;
    City *next;
    City *previous;
    int taxiTime;
};

template<class T>
struct vertex;

template<class T>
struct adjVertex{
    vertex<T> *v;
    int time;
    int price;
};

template<class T>
struct vertex{
    string location;
    City theCity;
    vector<adjVertex<T> > adj;
    bool solved;
    int distance;
    vertex *parent;
};


template<class T>
class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(T loca1, T loca2, int weight1, int weight2);
        void addVertex(T loca, T name);
        void createGraph();
        void displayGraph();
        int search (T loca);
        void DijkstraPrice(string start, string end);
        void DijkstraTime(string start, string end);
        void printCities(T loca);
        void addCity(string loca, string newCity, string prevCity, int addTime);
        void deleteCity(string loca, string delCity);
        void traverseCity(string loca, string destination);
        int numMins;

    protected:
    private:
        vector<vertex<T> > vertices;

};

#endif // GRAPH_H
