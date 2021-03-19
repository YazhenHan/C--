class ParkingSystem {
private:
    int b, m, s;
public:
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        int *ans = &b;
        switch (carType)
        {
        case 1:
            ans = &b;
            break;
        case 2:
            ans = &m;
            break;
        default:
            ans = &s;
            break;
        }
        if (*ans > 0)
        {
            (*ans)--;
            return true;
        }
        return false;
    }
};