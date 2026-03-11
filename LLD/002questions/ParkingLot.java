import java.util.List;

abstract class Vehicle {
    String type;
    String number;
};

class Spot {
    int spotid;
    boolean isOccupied;
    Vehicle vehicle;

    boolean assigningVehicle() {
        return false;
    }

    void removeVehicle() {
        // remove the vehicle
    }
}

class ParkingFloor {
    int floorNumber;
    List<Spot> spots;

    Spot findAvailableSpot() { // strategy design patten
    }    
}

class Ticket {
    int id;
    long entrytime;
    long exittime;
    Spot spot;
}

class ParkingLot {
    List<ParkingFloor> floors;

    Spot parkVehicle(Vehicle vehicle) {}
}
