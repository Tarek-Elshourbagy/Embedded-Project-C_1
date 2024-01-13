#include <stdio.h>

// Define enum for engine state
typedef enum {
    ENGINE_OFF,
    ENGINE_ON
} EngineState;

// Define struct for vehicle state
typedef struct {
    EngineState engine;
    int speed;
    int roomTemperature;
    int engineTemperature;
    int ac;
    int engineTemperatureController;
} VehicleState;

// Function to print menu and get user input
char getMenuInput() {
    char input;
    printf("a. Turn on the vehicle engine\n");
    printf("b. Turn off the vehicle engine\n");
    printf("c. Quit the system\n\n");
    scanf(" %c", &input);
    return input;
}

// Function to handle turning on the engine
void turnOnEngine(VehicleState *vehicle) {
    vehicle->engine = ENGINE_ON;
    printf("Sensors set menu\n");
    char sensorInput;
    do {
        printf("a. Turn off the engine\n");
        printf("b. Set the traffic light color\n");
        printf("c. Set the room temperature\n");
        printf("d. Set the engine temperature\n");
        scanf(" %c", &sensorInput);

        switch (sensorInput) {
            case 'b':
                setTrafficLightColor(vehicle);
                break;
            case 'c':
                setRoomTemperature(vehicle);
                break;
            case 'd':
                setEngineTemperature(vehicle);
                break;
            case 'a':
                vehicle->engine = ENGINE_OFF;
                return;
            default:
                printf("Invalid input\n");
        }

        printVehicleState(*vehicle);

    } while (sensorInput != 'a');
}

// Function to handle setting traffic light color
void setTrafficLightColor(VehicleState *vehicle) {
    char trafficLight;
    printf("Enter the traffic light color (G, O, R): ");
    scanf(" %c", &trafficLight);

    switch (trafficLight) {
        case 'G':
            vehicle->speed = 100;
            break;
        case 'O':
            vehicle->speed = 30;
            break;
        case 'R':
            vehicle->speed = 0;
            break;
        default:
            printf("Invalid traffic light color\n");
    }
}

// Function to handle setting room temperature
void setRoomTemperature(VehicleState *vehicle) {
    printf("Enter the room temperature: ");
    scanf("%d", &vehicle->roomTemperature);

    if (vehicle->roomTemperature < 10 || vehicle->roomTemperature > 30) {
        vehicle->ac = 1;
        vehicle->roomTemperature = 20;
    } else {
        vehicle->ac = 0;
    }
}

// Function to handle setting engine temperature
void setEngineTemperature(VehicleState *vehicle) {
    printf("Enter the engine temperature: ");
    scanf("%d", &vehicle->engineTemperature);

    if (vehicle->engineTemperature < 100 || vehicle->engineTemperature > 150) {
        vehicle->engineTemperatureController = 1;
        vehicle->engineTemperature = 125;
    } else {
        vehicle->engineTemperatureController = 0;
    }
}

// Function to print the current vehicle state
void printVehicleState(VehicleState vehicle) {
    printf("\nEngine state: %s\n", vehicle.engine == ENGINE_ON ? "ON" : "OFF");
    printf("AC: %s\n", vehicle.ac ? "ON" : "OFF");
    printf("Vehicle Speed: %d km/hr\n", vehicle.speed);
    printf("Room Temperature: %d\n", vehicle.roomTemperature);
    printf("Engine Temperature Controller State: %s\n", vehicle.engineTemperatureController ? "ON" : "OFF");
    printf("Engine Temperature: %d\n\n", vehicle.engineTemperature);
}

int main() {
	setbuf(stdout,NULL);
    char input;
    VehicleState vehicle;
    vehicle.engine = ENGINE_OFF;

    do {
        input = getMenuInput();

        switch (input) {
            case 'a':
                turnOnEngine(&vehicle);
                break;
            case 'b':
                // Implement turning off the engine and displaying menu
                vehicle.engine = ENGINE_OFF;
                break;
            case 'c':
                // Quit the program
                break;
            default:
                printf("Invalid input\n");
        }

        printVehicleState(vehicle);

    } while (input != 'c');

    return 0;
}
