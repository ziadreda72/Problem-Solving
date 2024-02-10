class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool checkBig() {
        if (big >= 1) {
            --big;
            return true;
        }
        return false;
    }

    bool checkMedium() {
        if (medium >= 1) {
            --medium;
            return true;
        }
        return false;
    }

    bool checkSmall() {
        if (small >= 1) {
            --small;
            return true;
        }
        return false;
    }

    bool addCar(int carType) {
        if (carType == 1)
            return checkBig();

        if (carType == 2)
            return checkMedium();

        if (carType == 3)
            return checkSmall();
        
        return true;
    }

private:
    int big , medium , small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
