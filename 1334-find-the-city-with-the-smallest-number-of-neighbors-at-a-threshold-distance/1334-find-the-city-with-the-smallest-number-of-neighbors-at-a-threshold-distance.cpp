 
class Solution {
public:
    int findTheCity(int numOfCities, vector<vector<int>>& cityConnections, int distanceThreshold) {
        // Initialize a 2D matrix of distances between all cities, with a large value as default.
        vector<vector<int>>cityDistances(numOfCities, vector<int>(numOfCities, 1e9));
        
        // Fill in the distance matrix with the distances between cities from the input edges.
        for(auto connection: cityConnections)
        {
            cityDistances[connection[0]][connection[1]] = connection[2];
            cityDistances[connection[1]][connection[0]] = connection[2];
        }

        // Set the distance between a city and itself as 0.
        for(int i=0; i<numOfCities; i++) cityDistances[i][i] = 0;

        // Use Floyd-Warshall algorithm to update the distance matrix with the shortest path between cities.
        for(int k=0; k<numOfCities; k++)
        {
            for(int i=0; i<numOfCities; i++)
            {
                for(int j=0; j<numOfCities; j++)
                {
                    cityDistances[i][j] = min(cityDistances[i][j], cityDistances[i][k]+cityDistances[k][j]);
                }
            }
        }
        
        // Initialize the number of cities within distance threshold and the city number.
        int cntWithinThreshold = numOfCities;
        int cityNo = -1;
        
        // Iterate over all cities to find the one with the least number of other cities within distance threshold.
        for(int i=0; i<numOfCities; i++)
        {
            int cnt = 0;
            for(int j=0; j<numOfCities; j++)
            {
                if(cityDistances[i][j] <= distanceThreshold)
                cnt++;
            }
            if(cnt <= cntWithinThreshold)
            {
                cntWithinThreshold = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};
