// The problem consists in determining the minimun energy a drone would need to have
// at the start position to complete its route. Each position of the route is caracterized
// by a 3D point of coords x, y, z. The drone spend 1 unity of energy to ascend 1 unit of
// space, and gains 1 unity of energe to descends 1 unit of space. There is no cost to
// traveling sideways.

// The approach is keep track of all the changes in drone energy, and finding the
// point where it has the greatest value, in module, below 0. That is the energy
// needed at the start of the flight.

#include <iostream>
#include <vector>
using namespace std;


int calcDroneMinEnergy( const vector<vector<int>>& route ){ // time O(n), space O(1)
  int energyCount = 0;
  int minEnergy = 0;
    
  //route[i][2] == z axis
  for(int i = 1; i < route.size(); i++){
    int diff = route[i-1][2] - route[i][2];
    energyCount += diff;
    
    minEnergy = min(minEnergy, energyCount);
  }
  
  if(minEnergy < 0) return abs(minEnergy);
                    return 0;
}

int main() {
  
  return 0;
}