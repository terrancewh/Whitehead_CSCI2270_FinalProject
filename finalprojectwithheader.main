#include <iostream>
#include <vector>
#include <climits>

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


// Start implementation of member objects
template<class T>
Graph<T>::Graph()
{
}

template<class T>
Graph<T>::~Graph()
{
}

template<class T>
void Graph<T>::addEdge(T loca1, T loca2, int weight1, int weight2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].location == loca1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].location == loca2 && i != j){
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.time = weight1;
                    av.price=weight2;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

template<class T>
void Graph<T>::addVertex(T loca, T name){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].location == loca){
            found = true;
            break;
        }
    }
    if(found == false){
        vertex<T> v;
        v.location = loca;
        v.theCity.citytitle=name;
        v.theCity.next=nullptr;
        v.theCity.previous=nullptr;
        vertices.push_back(v);

    }
}

template<class T>
int Graph<T>::search(T loca){
    for (int i=0; i<vertices.size(); i++){
        vertices[i].solved=false;
        vertices[i].distance=INT_MAX;
        vertices[i].parent=nullptr;
        if (vertices[i].location==loca){
            return i;
        }
    }
    cout << "Airport " << loca << " was not found." << endl;
    cout << "Instead, further searching will continue from DEN" << endl;
    return 0;
}

template<class T>
void Graph<T>::printCities(T loca){
    City *temp=&vertices[search(loca)].theCity;
    string outMessage="nullptr <- ";
    while(temp->next!=nullptr){
        outMessage=outMessage+temp->citytitle+" <-> ";
        temp=temp->next;
    }
    outMessage=outMessage+temp->citytitle+" -> nullptr";
    cout << outMessage << endl;
    return;
}

template<class T>
void Graph<T>::traverseCity(string loca, string destination){
    City *temp=&vertices[search(loca)].theCity;
    int timeCounter=numMins;
    while(temp->next!=nullptr){
        timeCounter+=temp->taxiTime;
        if(temp->citytitle==destination){
            int dispHr=timeCounter/60;
            int dispMin=timeCounter%60;
            cout<<"Travel Time: "<< dispHr << "h " << dispMin << "m" << endl;
            return;
        }
        temp=temp->next;
    }
    if(temp->citytitle!=destination){
        cout << "Destination was not found." << endl;
        return;
    }
    timeCounter+=temp->taxiTime;
    int dispHr=timeCounter/60;
    int dispMin=timeCounter%60;
    cout<<"Travel Time: "<< dispHr << "h " << dispMin << "m" << endl;
}

template<class T>
void Graph<T>::deleteCity(string loca, string delCity){
    City *temp=&vertices[search(loca)].theCity;
    if(temp->citytitle==delCity){
        cout << "Main city of " << loca << " should not be deleted." << endl;
        return;
    }
    while(temp->next!=nullptr){
        if(temp->citytitle==delCity){
            temp->previous->next=temp->next;
            temp->next->previous=temp->previous;
            delete temp;
            return;
        }
        temp=temp->next;
    }
    if(temp->citytitle==delCity){
        temp->previous->next=nullptr;
        delete temp;
        return;
    }
    else{
        cout << "Destination was not found." << endl;
    }
}

template<class T>
void Graph<T>::addCity(string loca, string newCity, string prevCity, int addTime){
    City *addingCity=new City;
    addingCity->citytitle=newCity;
    addingCity->taxiTime=addTime;
    City *temp=&vertices[search(loca)].theCity;
    if(temp->previous==nullptr&&temp->next==nullptr){
        temp->next=addingCity;
        addingCity->previous=temp;
        addingCity->next=nullptr;
    }
    else{
        while(temp->next!=nullptr){
            temp=temp->next;
            if(temp->citytitle==prevCity && temp->next==nullptr){
                addingCity->previous=temp;
                addingCity->next=nullptr;
                temp->next=addingCity;
            }
            else if (temp->citytitle==prevCity && temp->next!=nullptr){
                addingCity->previous=temp;
                addingCity->next=temp->next;
                temp->next=addingCity;
                temp->next->previous=addingCity;
            }
        }
    }
}

template<class T>
void Graph<T>::createGraph(){
    addVertex("DEN","Denver, Colorado");
    addVertex("ORD", "Chicago, Illinois");
    addVertex("MSP", "Minneapolis, Minnesota");
    addVertex("ATL", "Atlanta, Georgia");
    addVertex("SFO", "San Francisco, California");
    addVertex("LAX", "Los Angeles, California");
    addVertex("JFK", "New York City, New York");
    addVertex("LHR", "London, United Kingdom");
    addVertex("ARN", "Stockholm, Sweden");
    addVertex("CDG", "Paris, France");
    addVertex("FRA", "Frankfurt, Germany");
    addVertex("PRG", "Prague, Czech Republic");
    addVertex("IST", "Istanbul, Turkey");
    addVertex("TPE", "Taipei, Taiwan");
    addVertex("DPS", "Bali, Indonesia");
    addVertex("ICN", "Incheon, South Korea");
    addVertex("HAN", "Hanoi, Vietnam");
    addVertex("CAN", "Guangzhou, China");
    addVertex("MEX", "Mexico City, Mexico");
    addVertex("BOG", "Bogota, Colombia");
    addVertex("REP", "Siem Reap, Cambodia");
    addVertex("KTM", "Kathmandu, Nepal");
    addVertex("HKT", "Phuket, Thailand");
    addVertex("GIG", "Rio de Janeiro, Brazil");
    addVertex("DEL", "New Delhi, India");
    addVertex("SVO", "Moscow, Russia");
    addVertex("HER", "Crete, Greece");
    addVertex("CMN", "Casablanca, Morocco");
    addVertex("FCO", "Fiumicino, Rome");
    addVertex("KIN", "Kingston, Jamaica");
    addEdge("DEN", "ORD", 156, 222);
    addEdge("DEN", "MSP", 129, 159);
    addEdge("DEN", "ATL", 184, 187);
    addEdge("DEN", "SFO", 167, 163);
    addEdge("DEN", "LAX", 150, 193);
    addEdge("DEN", "JFK", 225, 342);
    addEdge("ORD", "LHR", 526, 1455);
    addEdge("ORD", "ARN", 640, 1418);
    addEdge("ARN", "LHR", 360, 45);
    addEdge("ARN", "CDG", 370, 84);
    addEdge("ORD", "FRA", 700, 1226);
    addEdge("FRA", "PRG", 174, 30);
    addEdge("FRA", "IST", 127, 70);
    addEdge("MSP", "FRA", 530, 1097);
    addEdge("SFO", "TPE", 2108, 1194);
    addEdge("TPE", "DPS", 1050, 109);
    addEdge("SFO", "ICN", 2873, 2052);
    addEdge("ICN", "HAN", 685, 1033);
    addEdge("SFO", "CAN", 1153, 1081);
    addEdge("SFO", "MEX", 255, 461);
    addEdge("SFO", "BOG", 639, 574);
    addEdge("LAX", "TPE", 1800, 891);
    addEdge("LAX", "ICN", 1181, 1297);
    addEdge("LAX", "BOG", 582, 704);
    addEdge("LAX", "MEX", 579, 414);
    addEdge("BOG", "GIG", 1215, 1728);
    addEdge("LAX", "CAN", 1900, 854);
    addEdge("CAN", "REP", 165, 244);
    addEdge("CAN", "KTM", 425, 449);
    addEdge("CAN", "HKT", 585, 297);
    addEdge("ATL", "KIN", 484, 854);
    addEdge("JFK", "DEL", 1335, 1151);
    addEdge("JFK", "SVO", 685, 1003);
    addEdge("JFK", "CMN", 589, 1053);
    addEdge("CMN", "FCO", 435, 360);
    addEdge("SVO", "HER", 1126, 605);
    addCity("DEN", "Aurora, Colorado", "Denver, Colorado", 22);
    addCity("DEN", "Northglenn, Colorado", "Aurora, Colorado", 22);
    addCity("ORD", "Bensenville, Illinois", "Chicago, Illinois", 12);
    addCity("ORD", "Schiller Park, Illinois", "Bensenville, Illinois", 10);
    addCity("MSP", "Richfield, Minnesota", "Minneapolis, Minnesota", 9);
    addCity("MSP", "Edina, Minnesota", "Richfield, Minnesota", 10);
    addCity("ATL", "College Park, Georgia", "Atlanta, Georgia", 13);
    addCity("ATL", "Gresham, Georgia", "College Park, Georgia", 10);
    addCity("SFO", "Millbrae, California", "San Francisco, California", 10);
    addCity("SFO", "San Mateo, California", "Millbrae, California", 15);
    addCity("LAX", "El Segundo, California", "Los Angeles, California", 12);
    addCity("LAX", "Lawndale, California", "El Segundo, California", 12);
    addCity("JFK", "Woodmere, New York", "New York City, New York", 14);
    addCity("JFK", "East Rockaway, New York", "Woodmere, New York", 6);
    addCity("LHR", "Staines, United Kingdom", "London, United Kingdom", 9);
    addCity("LHR", "Kingston Upon Thames, United Kingdom", "Staines, United Kingdom", 32);
    addCity("ARN", "Marsta, Sweden", "Stockholm, Sweden", 9);
    addCity("ARN", "Balsta, Sweden", "Marsta, Sweden", 32);
    addCity("CDG", "Villepinte, France", "Paris, France", 12);
    addCity("CDG", "Sevran, France", "Villepinte, France", 11);
    addCity("FRA", "Kelsterbach, Germany", "Frankfurt, Germany", 11);
    addCity("FRA", "Langen, Germany", "Kelsterbach, Germany", 21);
    addCity("PRG", "Hostivice, Czech Republic", "Prague, Czech Republic", 27);
    addCity("PRG", "Horomerice, Czech Republic", "Hostivice, Czech Republic", 14);
    addCity("IST", "Esenyurt, Turkey", "Istanbul, Turkey", 20);
    addCity("IST", "Tepecik, Turkey", "Esenyurt, Turkey", 24);
    addCity("TPE", "Taoyuan, Taiwan", "Taipei, Taiwan", 23);
    addCity("TPE", "Pingzhen, Taiwan", "Taoyun, Taiwan", 28);
    addCity("DPS", "Kuta, Indonesia", "Bali, Indonesia", 15);
    addCity("DPS", "Karangasem, Indonesia", "Kuta, Indonesia", 40);
    addCity("ICN", "Seoul, South Korea", "Incheon, South Korea", 23);
    addCity("ICN", "Ansan, South Korea", "Seoul, South Korea", 19);
    addCity("HAN", "Bac Giang, Vietnam", "Hanoi, Vietnam", 84);
    addCity("HAN", "Tuyen, Vietnam", "Bac Giang, Vietnam", 24);
    addCity("CAN", "Dongguan, China", "Guangzhou, China", 64);
    addCity("CAN", "Xiaolan, China", "Dongguan, China", 108);
    addCity("MEX", "Venustiano Carranza, Mexico", "Mexico City, Mexico", 20);
    addCity("MEX", "San Bernardino, Mexico", "Venustiano Carranza, Mexico", 20);
    addCity("BOG", "Funza, Colombia", "Bogota, Colombia", 19);
    addCity("BOG", "Bojaca, Colombia", "Funza, Colombia", 53);
    addCity("REP", "Poipet, Cambodia", "Siem Reap, Cambodia", 120);
    addCity("REP", "Surin, Cambodia", "Poipet, Cambodia", 210);
    addCity("HKT", "Kathu, Thailand", "Phuket, Thailand", 31);
    addCity("HKT", "Wiang Sa, Thailand", "Kathu, Thailand", 22);
    addCity("GIG", "Duque de Caxias, Brazil", "Rio de Janeiro, Brazil", 13);
    addCity("GIG", "Niteroi, Brazil", "Duque de Caxias, Brazil", 32);
    addCity("DEL", "Gurgaon, India", "New Delhi, India", 19);
    addCity("DEL", "Faridabad, India", "Gurgaon, India", 72);
    addCity("SVO", "Dolgoprudnyy, Russia", "Moscow, Russia", 29);
    addCity("SVO", "Nekrasovskiy, Russia", "Dolgoprudnyy, Russia", 22);
    addCity("HER", "Nea Alikarnassos, Greece", "Crete, Greece", 6);
    addCity("HER", "Vasiliai, Greece", "Nea Alikarnassos, Greece", 19);
    addCity("CMN", "Nouaceur, Morocco", "Casablanca, Morocco", 10);
    addCity("CMN", "Tit Mellil, Morocco", "Nouaceur, Morocco", 38);
    addCity("FCO", "Ciampino, Italy", "Fiumicino, Italy", 29);
    addCity("FCO", "Bracciano, Italy", "Ciampino, Italy", 64);
    addCity("KIN", "Half Way Tree, Jamaica", "Kingston, Jamaica", 5);
    addCity("KIN", "Mavis Bank, Jamaica", "Half Way Tree, Jamaica", 62);
}

template<class T>
void Graph<T>::displayGraph(){
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].location<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->location<<"***";
        }
        cout << endl;
    }

}

template<class T>
void Graph<T>::DijkstraPrice(string start, string end){
vertex<T> *startV=nullptr;
vertex<T> *endV=nullptr;
startV=&vertices[search(start)];
endV=&vertices[search(end)];
    if (startV!=nullptr && endV!=nullptr){
        startV->solved = true;
        startV->distance = 0;
        vector<vertex<T> *> solved;
        vector<vertex<T> *> path;
        solved.push_back(startV);
        adjVertex<T> *sadj;
        vertex<T> *s;
        vertex<T> *solvedV;
        vertex<T> *prev;
        while (endV->solved==false) {
            int minDistance=INT_MAX;
            for (int i=0; i<solved.size(); i++) {
                s=solved[i];
                for (int j=0; j<s->adj.size(); j++) {
                    sadj=&solved[i]->adj[j];
                    if (sadj->v->solved==false) {
                        int dist=s->distance+sadj->price;
                        if (dist<minDistance){
                            minDistance=dist;
                            solvedV=sadj->v;
                            prev=s;
                        }
                    else{
                        }
                    }
                    else{
                    }
                }
            }
            solved.push_back(solvedV);
            solvedV->distance=minDistance;
            solvedV->parent=prev;
            solvedV->solved=true;
        }
        cout<<"Cheapest Path"<<endl;
        vertex<T> *analysis=endV;
        while (analysis!=nullptr) {
            path.push_back(analysis);
            analysis=analysis->parent;
        }
        for (int i=0; i<path.size(); i++) {
            if (i==path.size()-1){
                cout<<path[path.size()-1-i]->location;
            }
            else{
                cout<<path[path.size()-1-i]->location<<" -> ";
            }

        }
        cout<<endl;
        cout<<"Minimum Cost: $"<<solved[solved.size()-1]->distance<<endl;
    }
    else if (endV!=nullptr){
        return;
    }
    else{
        return;
    }
}

template<class T>
void Graph<T>::DijkstraTime(string start, string end){
vertex<T> *startV=nullptr;
vertex<T> *endV=nullptr;
startV=&vertices[search(start)];
endV=&vertices[search(end)];
    if (startV!=nullptr && endV!=nullptr){
        startV->solved = true;
        startV->distance = 0;
        vector<vertex<T> *> solved;
        vector<vertex<T> *> path;
        solved.push_back(startV);
        adjVertex<T> *sadj;
        vertex<T> *s;
        vertex<T> *solvedV;
        vertex<T> *prev;
        while (endV->solved==false) {
            int minDistance=INT_MAX;
            for (int i=0; i<solved.size(); i++) {
                s=solved[i];
                for (int j=0; j<s->adj.size(); j++) {
                    sadj=&solved[i]->adj[j];
                    if (sadj->v->solved==false) {
                        int dist=s->distance+sadj->time;
                        if (dist<minDistance){
                            minDistance=dist;
                            solvedV=sadj->v;
                            prev=s;
                        }
                    else{
                        }
                    }
                    else{
                    }
                }
            }
            solved.push_back(solvedV);
            solvedV->distance=minDistance;
            solvedV->parent=prev;
            solvedV->solved=true;
        }
        cout<<"Fastest Path"<<endl;
        vertex<T> *analysis=endV;
        while (analysis!=nullptr) {
            path.push_back(analysis);
            analysis=analysis->parent;
        }
        for (int i=0; i<path.size(); i++) {
            if (i==path.size()-1){
                cout<<path[path.size()-1-i]->location;
            }
            else{
                cout<<path[path.size()-1-i]->location<<" -> ";
            }

        }
        cout<<endl;
        numMins=solved[solved.size()-1]->distance;
        int dispHr=numMins/60;
        int dispMin=numMins%60;
        cout<<"Minimum Flight Time: "<< dispHr << "h " << dispMin << "m" << endl;
    }
    else if (endV!=nullptr){
        return;
    }
    else{
        return;
    }
}

int main()
{
    bool exitCondition=false;
    int menuValue=0;
    Graph<string> g;
    g.createGraph();
    while(exitCondition!=true){
        cout << "============Main Menu============" << endl;
        cout << "1. Print Flight Destinations and Connecting Flights" << endl;
        cout << "2. Find Cheapest Flight to a Destination" << endl;
        cout << "3. Find Fastest Flight to a Destination" << endl;
        cout << "4. Print After Flight Destinations" << endl;
        cout << "5. Find Travel Time to After Flight Destination" << endl;
        cout << "6. Find Total Travel Time Including Flight from DEN" << endl;
        cout << "7. Insert a Flight Destination" << endl;
        cout << "8. Insert a Flight Path" << endl;
        cout << "9. Insert an After Flight Destination" << endl;
        cout << "10. Delete an After Flight Destination" << endl;
        cout << "11. Quit" << endl;
        cin >> menuValue;
        if(menuValue==1){
            g.displayGraph();
        }
        else if(menuValue==2){
            cout << "Enter the starting airport. i.e. If you want to travel from Denver, type DEN for Denver International Airport." << endl;
            string startChoice;
            cin >> startChoice;
            cout << "Enter the destination airport. i.e. If you want to travel to Los Angeles, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            g.DijkstraPrice(startChoice, endChoice);
        }
        else if(menuValue==3){
            cout << "Enter the starting airport. i.e. If you want to travel from Denver, type DEN for Denver International Airport." << endl;
            string startChoice;
            cin >> startChoice;
            cout << "Enter the destination airport. i.e. If you want to travel to Los Angeles, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            g.DijkstraTime(startChoice, endChoice);
        }
        else if(menuValue==4){
            cout << "Enter the destination airport. i.e. If you want to travel to Los Angeles, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            cout << "From here, you can travel to the following locations via taxi:" << endl;
            g.printCities(endChoice);
        }
        else if(menuValue==5){
            g.numMins=0;
            cout << "Enter the destination airport. i.e. If you want to travel to Los Angeles, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            cout << "Enter your destination city. i.e. If you want to travel to El Segundo from Los Angeles, type El Segundo, California." << endl;
            string cityChoice;
            getline(cin.ignore(),cityChoice);
            g.traverseCity(endChoice, cityChoice);
        }
        else if (menuValue==6){
            cout << "Enter the destination airport. i.e. If you want to travel to Los Angeles, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            cout << "Enter your destination city. i.e. If you want to travel to El Segundo from Los Angeles, type El Segundo, California." << endl;
            string cityChoice;
            getline(cin.ignore(),cityChoice);
            g.DijkstraTime("DEN", endChoice);
            g.traverseCity(endChoice, cityChoice);
        }
        else if(menuValue==7){
            cout << "Enter the abbreviation for the airport you want to add. i.e. Type AUS for Austin International Airport." << endl;
            string startChoice;
            cin >> startChoice;
            cout << "Enter the destination city of the airport. i.e. Type Austin, Texas if using AUS airport." << endl;
            string cityChoice;
            getline(cin.ignore(),cityChoice);
            g.addVertex(startChoice, cityChoice);
        }
        else if(menuValue==8){
            cout << "Enter the starting airport. i.e. If you want to travel from Denver, type DEN for Denver International Airport." << endl;
            string startChoice;
            cin >> startChoice;
            cout << "Enter the destination airport. i.e. If you want to travel to Los Angeles, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            cout << "Enter the time associated with the flight to your destination." << endl;
            int ftime;
            cin>>ftime;
            cout << "Enter the price associated with the flight to your destination." << endl;
            int fprice;
            cin>>fprice;
            g.addEdge(startChoice, endChoice, ftime, fprice);
        }
        else if(menuValue==9){
            cout << "Enter the destination airport. i.e. If you want to travel to Los Angeles, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            cout << "Enter your new destination city. i.e. If you want to add West Athens in California, type West Athens, California." << endl;
            string cityChoice;
            getline(cin.ignore(),cityChoice);
            cout << "Enter the city from which you travel to your new destination. i.e. If you travel from Los Angeles to West Athens, California, type Los Angeles, California. Note if you add the city to a location that travels to another, you need to delete and update those cities." << endl;
            string prevC;
            getline(cin.ignore(),prevC);
            cout << "Add the time associated with traveling via taxi to your city." << endl;
            int ctime;
            cin >> ctime;
            g.addCity(endChoice, cityChoice, prevC, ctime);
        }
        else if(menuValue==10){
            cout << "Enter the destination airport of the city you wish to delete. i.e. If you want to delete El Segundo, California, type LAX for Los Angeles International Airport." << endl;
            string endChoice;
            cin >> endChoice;
            cout << "Enter the destination city you wish to delete. i.e. If you want to delete El Segundo from LAX, type El Segundo, California. Note, you cannot delete the main city in which the airport is located." << endl;
            string dCity;
            getline(cin.ignore(),dCity);
            g.deleteCity(endChoice, dCity);
        }
        else{
            cout << "Goodbye!" << endl;
            exitCondition=true;
        }

    }
    return 0;
}
