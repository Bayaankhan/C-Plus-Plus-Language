/*
============================================================
    SMART TRAFFIC CONTROL SYSTEM FOR PESHAWAR
    University CEP (Complex Engineering Project)
============================================================
    Areas Covered:
    1. University Road
    2. Saddar
    3. Ring Road
    4. Hashtnagri

    C++ Concepts Used:
    - Data types, Memory size & address
    - Comparison & Logical operators
    - Conditional (ternary) operator
    - switch statement
    - while loop & for loop
    - 1D and 2D arrays
    - Functions
    - Strings
    - Pointers
    - Structures
============================================================
*/

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// STRUCTURE: Stores info for each road/area
// ============================================================
struct TrafficArea {
    string areaName;           // Name of the road/area
    int vehicleCount;          // Number of vehicles at that area
    string signalStatus;       // "RED", "GREEN", or "YELLOW"
    bool emergencyActive;      // Is emergency mode ON?
    string emergencyVehicle;   // Which emergency vehicle is active
    string previousSignal;     // Signal before emergency was activated
};

// ============================================================
// GLOBAL CONSTANTS AND ARRAYS
// ============================================================

const int TOTAL_AREAS = 4;        // Total number of areas

// 1D Array: Stores area names
string areaNames[TOTAL_AREAS] = {
    "University Road",
    "Saddar",
    "Ring Road",
    "Hashtnagri"
};

// 1D Array: Stores vehicle counts for each area
int vehicleCounts[TOTAL_AREAS] = {0, 0, 0, 0};

// 2D Array: Traffic history log [area][last 3 readings]
int trafficHistory[TOTAL_AREAS][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

// Array of structures for each traffic area
TrafficArea areas[TOTAL_AREAS];

// ============================================================
// FUNCTION PROTOTYPES (declarations)
// ============================================================
void displayHeader();
int  selectArea();
void inputVehicles(int areaIndex);
string analyzeTraffic(int vehicleCount);
void controlSignal(int areaIndex);
void emergencyON(int areaIndex);
void emergencyOFF(int areaIndex);
void emergencyMenu(int areaIndex);
void displayStatus(int areaIndex);
void displayAllStatus();
void showMemoryInfo();
void showTrafficHistory(int areaIndex);
void runMainMenu();

// ============================================================
// MODULE 1: HEADER DISPLAY MODULE
// ============================================================
void displayHeader() {
    cout << "\n";
    cout << "============================================================\n";
    cout << "   SMART TRAFFIC CONTROL SYSTEM - PESHAWAR CITY            \n";
    cout << "   Complex Engineering Problem (CEP)                        \n";
    cout << "============================================================\n";
    cout << "   Roads: University Road | Saddar | Ring Road | Hashtnagri \n";
    cout << "============================================================\n";
}

// ============================================================
// MODULE 2: AREA SELECTION MODULE
// Function: selectArea()
// Uses: switch statement, while loop
// Returns: index of selected area (0-3), or -1 for all areas
// ============================================================
int selectArea() {
    int choice = 0;
    bool validInput = false;

    cout << "\n--- AREA SELECTION ---\n";
    cout << "Select a Traffic Area:\n";
    cout << "  1. University Road\n";
    cout << "  2. Saddar\n";
    cout << "  3. Ring Road\n";
    cout << "  4. Hashtnagri\n";
    cout << "  5. All Areas\n";
    cout << "Enter your choice (1-5): ";

    // while loop: keeps asking until valid input is given
    while (!validInput) {
        cin >> choice;

        // switch statement: handles each menu option
        switch (choice) {
            case 1:
                cout << ">> Selected: University Road\n";
                validInput = true;
                return 0;

            case 2:
                cout << ">> Selected: Saddar\n";
                validInput = true;
                return 1;

            case 3:
                cout << ">> Selected: Ring Road\n";
                validInput = true;
                return 2;

            case 4:
                cout << ">> Selected: Hashtnagri\n";
                validInput = true;
                return 3;

            case 5:
                cout << ">> All Areas Selected\n";
                validInput = true;
                return -1;

            default:
                cout << "Invalid choice! Please enter 1-5: ";
        }
    }
    return 0;
}

// ============================================================
// MODULE 3: VEHICLE INPUT MODULE
// Function: inputVehicles()
// Uses: pointer, data types
// ============================================================
void inputVehicles(int areaIndex) {
    int count = 0;

    cout << "\n--- VEHICLE INPUT: " << areaNames[areaIndex] << " ---\n";
    cout << "Enter number of vehicles currently at "
         << areaNames[areaIndex] << ": ";
    cin >> count;

    // POINTER EXAMPLE: pointer to vehicleCounts array element
    int *ptr = &vehicleCounts[areaIndex];
    *ptr = count;    // store value through pointer

    // Show memory address (pointer concept demo)
    cout << "Vehicle count stored at memory address: " << ptr << "\n";
    cout << "Value stored via pointer: " << *ptr << " vehicles\n";

    // Update the structure
    areas[areaIndex].vehicleCount  = count;
    areas[areaIndex].areaName      = areaNames[areaIndex];

    // Update 2D traffic history (shift old readings left, add new)
    trafficHistory[areaIndex][0] = trafficHistory[areaIndex][1];
    trafficHistory[areaIndex][1] = trafficHistory[areaIndex][2];
    trafficHistory[areaIndex][2] = count;

    cout << "Vehicle count recorded successfully!\n";
}

// ============================================================
// MODULE 4: TRAFFIC ANALYSIS MODULE
// Function: analyzeTraffic()
// Uses: comparison operators, logical operators
// Returns: density level as string
// ============================================================
string analyzeTraffic(int vehicleCount) {
    if (vehicleCount >= 0 && vehicleCount <= 20) {
        return "LOW";
    }
    else if (vehicleCount > 20 && vehicleCount <= 50) {
        return "MODERATE";
    }
    else if (vehicleCount > 50 && vehicleCount <= 100) {
        return "HIGH";
    }
    else {
        return "CRITICAL";
    }
}

// ============================================================
// MODULE 5: SIGNAL CONTROL MODULE
// Function: controlSignal()
// Uses: if-else, comparison operators, conditional (ternary) operator
// ============================================================
void controlSignal(int areaIndex) {
    // Block signal change if emergency is active for this area
    if (areas[areaIndex].emergencyActive) {
        cout << "\n[WARNING] Emergency is ACTIVE at "
             << areaNames[areaIndex]
             << ". Turn off emergency first before changing signal.\n";
        return;
    }

    int count    = vehicleCounts[areaIndex];
    string density = analyzeTraffic(count);
    string signal;

    cout << "\n--- SIGNAL CONTROL: " << areaNames[areaIndex] << " ---\n";
    cout << "Vehicle Count  : " << count    << "\n";
    cout << "Traffic Density: " << density  << "\n";

    if (density == "LOW") {
        signal = "GREEN";
        cout << "Signal Decision: Traffic is low -> GREEN signal\n";
        cout << "Signal Duration: 60 seconds GREEN\n";
    }
    else if (density == "MODERATE") {
        signal = "GREEN";
        cout << "Signal Decision: Moderate traffic -> GREEN with caution\n";
        cout << "Signal Duration: 45 seconds GREEN, 15 seconds YELLOW\n";
    }
    else if (density == "HIGH") {
        signal = "YELLOW";
        cout << "Signal Decision: High traffic -> YELLOW (slow down)\n";
        cout << "Signal Duration: 30 seconds YELLOW, 30 seconds RED\n";
    }
    else {
        signal = "RED";
        cout << "Signal Decision: CRITICAL traffic -> RED (STOP!)\n";
        cout << "Signal Duration: 60 seconds RED, traffic control needed!\n";
    }

    // Conditional (ternary) operator: quick alert
    string alert = (count > 100) ? "!!! SEND TRAFFIC POLICE !!!" : "Normal operations";
    cout << "Alert Status   : " << alert << "\n";

    // Save signal in structure and remember it (used by emergency restore)
    areas[areaIndex].signalStatus   = signal;
    areas[areaIndex].previousSignal = signal;
}

// ============================================================
// MODULE 6a: EMERGENCY ON
// Function: emergencyON()
// Activates emergency mode: overrides all signals to RED and
// sets the emergency area signal to GREEN.
// Uses: switch, string, structure, for loop
// ============================================================
void emergencyON(int areaIndex) {
    // Check if already active
    if (areas[areaIndex].emergencyActive) {
        cout << "\n[INFO] Emergency is already ACTIVE at "
             << areaNames[areaIndex] << ".\n";
        cout << "Active vehicle: " << areas[areaIndex].emergencyVehicle << "\n";
        return;
    }

    int vehicleType = 0;
    cout << "\n--- EMERGENCY ON: " << areaNames[areaIndex] << " ---\n";
    cout << "Select Emergency Vehicle Type:\n";
    cout << "  1. Ambulance\n";
    cout << "  2. Fire Brigade\n";
    cout << "  3. Police\n";
    cout << "  4. VIP Convoy\n";
    cout << "Enter choice (1-4): ";
    cin >> vehicleType;

    string vehicleName;

    switch (vehicleType) {
        case 1:  vehicleName = "Ambulance";    break;
        case 2:  vehicleName = "Fire Brigade"; break;
        case 3:  vehicleName = "Police";       break;
        case 4:  vehicleName = "VIP Convoy";   break;
        default: vehicleName = "Unknown";      break;
    }

    // Save the current signal before overriding it
    areas[areaIndex].previousSignal = areas[areaIndex].signalStatus;

    // Set all OTHER areas to RED to clear the route
    cout << "\n>>> EMERGENCY ACTIVATED <<<\n";
    for (int i = 0; i < TOTAL_AREAS; i++) {
        if (i != areaIndex) {
            areas[i].signalStatus = "RED (Emergency Hold)";
            cout << "  " << areaNames[i] << " -> RED (Emergency Hold)\n";
        }
    }

    // Emergency area gets GREEN
    areas[areaIndex].signalStatus    = "GREEN (EMERGENCY)";
    areas[areaIndex].emergencyActive = true;
    areas[areaIndex].emergencyVehicle = vehicleName;

    cout << "\n  " << areaNames[areaIndex]
         << " -> GREEN (EMERGENCY ROUTE)\n";
    cout << "\nVehicle  : " << vehicleName << "\n";
    cout << "Route    : " << areaNames[areaIndex] << " cleared!\n";
    cout << "Status   : Traffic police notified!\n";
    cout << "Emergency mode is now ON.\n";
}

// ============================================================
// MODULE 6b: EMERGENCY OFF
// Function: emergencyOFF()
// Deactivates emergency mode and restores normal signals.
// Uses: if-else, for loop, string, structure
// ============================================================
void emergencyOFF(int areaIndex) {
    // Check if emergency is actually active
    if (!areas[areaIndex].emergencyActive) {
        cout << "\n[INFO] No active emergency at "
             << areaNames[areaIndex] << ". Nothing to turn off.\n";
        return;
    }

    cout << "\n--- EMERGENCY OFF: " << areaNames[areaIndex] << " ---\n";
    cout << "Deactivating emergency for: "
         << areas[areaIndex].emergencyVehicle << "\n";

    // Restore all areas to their normal computed signal
    for (int i = 0; i < TOTAL_AREAS; i++) {
        // Recompute the correct signal from current vehicle count
        string density = analyzeTraffic(vehicleCounts[i]);
        string restoredSignal;

        if (density == "LOW" || density == "MODERATE") {
            restoredSignal = "GREEN";
        }
        else if (density == "HIGH") {
            restoredSignal = "YELLOW";
        }
        else {
            restoredSignal = "RED";
        }

        areas[i].signalStatus = restoredSignal;
        cout << "  " << areaNames[i]
             << " -> Restored to " << restoredSignal << "\n";
    }

    // Clear emergency flags
    areas[areaIndex].emergencyActive  = false;
    areas[areaIndex].emergencyVehicle = "None";

    cout << "\nEmergency mode is now OFF.\n";
    cout << "All signals restored to normal operation.\n";
}

// ============================================================
// MODULE 6: EMERGENCY MENU
// Function: emergencyMenu()
// Lets user choose to turn emergency ON or OFF
// Uses: switch, while loop
// ============================================================
void emergencyMenu(int areaIndex) {
    int emChoice = 0;
    bool validInput = false;

    cout << "\n--- EMERGENCY VEHICLE MENU: "
         << areaNames[areaIndex] << " ---\n";

    // Show current emergency status
    cout << "Current Emergency Status: ";
    if (areas[areaIndex].emergencyActive) {
        cout << "ON  (Vehicle: " << areas[areaIndex].emergencyVehicle << ")\n";
    } else {
        cout << "OFF\n";
    }

    cout << "\n  1. Turn Emergency ON  (Activate)\n";
    cout << "  2. Turn Emergency OFF (Deactivate)\n";
    cout << "  3. Back to Main Menu\n";
    cout << "Enter choice (1-3): ";

    while (!validInput) {
        cin >> emChoice;

        switch (emChoice) {
            case 1:
                emergencyON(areaIndex);
                validInput = true;
                break;

            case 2:
                emergencyOFF(areaIndex);
                validInput = true;
                break;

            case 3:
                cout << "Returning to main menu...\n";
                validInput = true;
                break;

            default:
                cout << "Invalid choice! Enter 1-3: ";
        }
    }
}

// ============================================================
// MODULE 7: DISPLAY MODULE
// Function: displayStatus()
// Uses: structure, arrays, for loop
// ============================================================
void displayStatus(int areaIndex) {
    cout << "\n--- TRAFFIC STATUS REPORT: "
         << areas[areaIndex].areaName << " ---\n";
    cout << "Vehicle Count  : " << areas[areaIndex].vehicleCount  << "\n";
    cout << "Signal Status  : " << areas[areaIndex].signalStatus  << "\n";
    cout << "Density Level  : " << analyzeTraffic(areas[areaIndex].vehicleCount) << "\n";

    // Conditional (ternary) operator for emergency display
    cout << "Emergency Mode : "
         << (areas[areaIndex].emergencyActive ? "ON" : "OFF") << "\n";

    if (areas[areaIndex].emergencyActive) {
        cout << "Emergency Veh  : " << areas[areaIndex].emergencyVehicle << "\n";
    }

    // 2D array: show traffic history with for loop
    cout << "\nLast 3 Traffic Readings:\n";
    for (int i = 0; i < 3; i++) {
        cout << "  Reading " << (i + 1) << ": "
             << trafficHistory[areaIndex][i] << " vehicles\n";
    }
}

// ============================================================
// Function: displayAllStatus()
// Shows status of all 4 areas using for loop
// ============================================================
void displayAllStatus() {
    cout << "\n============================================================\n";
    cout << "           ALL AREAS - TRAFFIC STATUS SUMMARY               \n";
    cout << "============================================================\n";

    for (int i = 0; i < TOTAL_AREAS; i++) {
        cout << "\n[" << (i + 1) << "] " << areaNames[i] << "\n";
        cout << "    Vehicles  : " << vehicleCounts[i] << "\n";
        cout << "    Density   : " << analyzeTraffic(vehicleCounts[i]) << "\n";
        cout << "    Signal    : " << areas[i].signalStatus << "\n";

        // Comparison operator to show recommendation
        if (vehicleCounts[i] > 100) {
            cout << "    *** CRITICAL - Traffic Police Required! ***\n";
        }
        else if (vehicleCounts[i] > 50) {
            cout << "    ** HIGH - Monitor closely\n";
        }
        else {
            cout << "    OK - Normal flow\n";
        }

        // Show emergency status per area
        if (areas[i].emergencyActive) {
            cout << "    [EMERGENCY ON] Vehicle: "
                 << areas[i].emergencyVehicle << "\n";
        }
    }
    cout << "\n============================================================\n";
}

// ============================================================
// Function: showMemoryInfo()
// Demonstrates memory size and memory address concepts
// ============================================================
void showMemoryInfo() {
    cout << "\n--- MEMORY INFORMATION (C++ Concept Demo) ---\n";

    cout << "Size of int    : " << sizeof(int)    << " bytes\n";
    cout << "Size of float  : " << sizeof(float)  << " bytes\n";
    cout << "Size of double : " << sizeof(double) << " bytes\n";
    cout << "Size of char   : " << sizeof(char)   << " bytes\n";
    cout << "Size of bool   : " << sizeof(bool)   << " bytes\n";
    cout << "Size of string : " << sizeof(string) << " bytes\n";

    cout << "\nMemory Addresses of vehicleCounts array:\n";

    // Pointer to array - show address of each element
    int *p = vehicleCounts;
    for (int i = 0; i < TOTAL_AREAS; i++) {
        cout << "  " << areaNames[i]
             << " -> Address: " << (p + i)
             << " | Value: "   << *(p + i) << " vehicles\n";
    }
}

// ============================================================
// MAIN MENU RUNNER
// Function: runMainMenu()
// Uses: while loop, switch statement
// ============================================================
void runMainMenu() {
    int mainChoice = 0;
    bool running   = true;

    // Initialise all areas with default values
    for (int i = 0; i < TOTAL_AREAS; i++) {
        areas[i].areaName         = areaNames[i];
        areas[i].vehicleCount     = 0;
        areas[i].signalStatus     = "RED";
        areas[i].previousSignal   = "RED";
        areas[i].emergencyActive  = false;
        areas[i].emergencyVehicle = "None";
    }

    // while loop: main program loop
    while (running) {
        displayHeader();

        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Select Area & Input Vehicles\n";
        cout << "2. Analyze & Control Signal\n";
        cout << "3. Emergency Vehicle Mode (ON / OFF)\n";
        cout << "4. Display Area Status\n";
        cout << "5. Display All Areas Status\n";
        cout << "6. Show Memory & Pointer Info\n";
        cout << "7. Exit System\n";
        cout << "Enter choice (1-7): ";
        cin >> mainChoice;

        int areaIndex = 0;

        switch (mainChoice) {

            case 1:   // Vehicle input
                areaIndex = selectArea();
                if (areaIndex >= 0) {
                    inputVehicles(areaIndex);
                } else {
                    for (int i = 0; i < TOTAL_AREAS; i++) {
                        inputVehicles(i);
                    }
                }
                break;

            case 2:   // Signal control
                areaIndex = selectArea();
                if (areaIndex >= 0) {
                    controlSignal(areaIndex);
                } else {
                    for (int i = 0; i < TOTAL_AREAS; i++) {
                        controlSignal(i);
                    }
                }
                break;

            case 3:   // Emergency ON / OFF menu
                areaIndex = selectArea();
                if (areaIndex >= 0) {
                    emergencyMenu(areaIndex);
                } else {
                    cout << "\n[INFO] Please select a specific area for emergency control.\n";
                }
                break;

            case 4:   // Display single area status
                areaIndex = selectArea();
                if (areaIndex >= 0) {
                    displayStatus(areaIndex);
                }
                break;

            case 5:   // Display all areas
                displayAllStatus();
                break;

            case 6:   // Memory info
                showMemoryInfo();
                break;

            case 7:   // Exit
                cout << "\nExiting Smart Traffic Control System...\n";
                cout << "Thank you! Stay safe on Peshawar roads!\n";
                running = false;
                break;

            default:
                cout << "\nInvalid option! Please choose 1-7.\n";
        }

        if (running && mainChoice != 7) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
}

// ============================================================
// MAIN FUNCTION - Entry point of program
// ============================================================
int main() {
    runMainMenu();
    return 0;
}

/*
============================================================
END OF SMART TRAFFIC CONTROL SYSTEM - PESHAWAR
============================================================
*/
