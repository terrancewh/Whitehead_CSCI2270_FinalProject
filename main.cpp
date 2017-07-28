#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
    bool exitCondition=false;
    int menuValue=0;
    Graph<string>g;
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
