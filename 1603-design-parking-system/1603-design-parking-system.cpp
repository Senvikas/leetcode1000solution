class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        _parkingPlace[1] = big;
        _parkingPlace[2] = medium;
        _parkingPlace[3] = small;
     }
    
    bool addCar(int carType) {
        return _parkingPlace[carType]-- > 0;
    }

private:
unordered_map<int, int> _parkingPlace;
};