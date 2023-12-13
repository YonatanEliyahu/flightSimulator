# Flight Simulator

Welcome to the Flight Simulator, an OpenGL-based program that creates a dynamic 3D environment featuring a controllable F-35 plane,
various viewing perspectives, and upcoming exciting features.
Explore the skies, experience different views, and stay tuned for upcoming enhancements!
## Upcoming Features

- Flying in the  Y-axis: flying up and down.
- Speedometer: The speedometer will provide real-time feedback on the speed of the F-35 plane, allowing for better control and awareness during gameplay.
- Plane Angle Indicator: This feature will visually display the current angle of the F-35 plane, providing valuable information to the user about the orientation of the aircraft.

## Files

- **main.cpp**: Contains the main logic of the program, including the initialization, event handling, and rendering functions.
- **plane.h, plane.cpp**: Define and implement the `Plane` class, which represents the F-35 plane. It includes functions for updating the plane's position, orientation, and dropping speeds.
- **viewPorts.h, viewPorts.cpp**: Implements different viewing perspectives, including regular, top, cockpit, and combined views.
- **terrain.h, terrain.cpp**: Manages the terrain generation and rendering, including the ground and water.
- **shapes.h, shapes.cpp**: Contains functions for drawing geometric shapes like cylinders and spheres.
- **vector3D.h**: Defines the `Vector3D` class, used for representing 3D vectors.
- **pov.h**: Defines the Pov class, responsible for managing the point of view within the scene.
  It controls the position of the camera (eye) and the direction in which it is looking (dir).
  The default configuration places the camera behind and above the F-35 plane.

## Project Setup

### Dependencies

The program relies on the following external libraries:

- **OpenGL**: The primary graphics library used for rendering.
- **GLUT (OpenGL Utility Toolkit)**: A library for handling windows, user input, and events.

### Prerequisites

- Visual Studio 2019 or later: Ensure you have Visual Studio installed on your system.
- x86 Configuration: Make sure your Visual Studio project is configured for x86 architecture.
- Git: You need Git installed to clone this repository.

### C++ Version

The program is designed to run on C++17 or later versions. Please ensure that your development environment supports C++17 features or later.

### Compilation and Execution
Clone the Repository: Open a terminal and run the following command to clone the repository:

```
git clone https://github.com/YonatanEliyahu/flightSimulator.git
```

Open in Visual Studio: Open Visual Studio and navigate to File > Open > Project/Solution.

Change Configuration: Change the build configurations to x86 architecture.

Build the Project: Build the project by selecting Build > Build Solution in Visual Studio.

Run the Program: Execute the program by pressing F5 or selecting Debug > Start Debugging in Visual Studio.

## Usage

- **Controls**: The F-35 plane can be controlled using the 'W', 'A', 'S', and 'D' keys for forward, left, backward, and right movements, respectively.
- **Views**: Right-clicking opens a context menu to switch between regular, top, cockpit, and combined views.

## Viewing Perspectives

- **Regular View**: Default perspective with the plane following the user's control.
- **Top View**: Overhead view looking down at the terrain and plane.
- **Cockpit View**: View from the cockpit of the F-35.
- **Combined View**: Split-screen combining regular, top, and cockpit views.
<img width="200" alt="1" src="https://github.com/YonatanEliyahu/flightSimulator/assets/106242827/7f49bdfc-259f-4d65-a3c3-29283d491742" title="Regular View"> 
<img width="200" alt="1" src="https://github.com/YonatanEliyahu/flightSimulator/assets/106242827/14977763-1b33-49e3-bd89-401ba1acfac1" title="Top View"> <br>
<img width="200" alt="1" src="https://github.com/YonatanEliyahu/flightSimulator/assets/106242827/2c4b5553-0ee1-47c4-872d-42f6ef5bc1ec" title="Cockpit View"> 
<img width="200" alt="1" src="https://github.com/YonatanEliyahu/flightSimulator/assets/106242827/3a3b74cb-13e1-431c-972f-c2d6450964e6" title="Combined View">

## Terrain Generation

The terrain is generated dynamically, with different heights representing sand, grass, stones, and snow. The water is transparent and animated.

## Additional Information

This program was developed using C++ and OpenGL for educational and entertainment purposes.
Feel free to explore, modify, and enhance the code to suit your needs.
If you encounter any issues or have suggestions, please feel free to contribute or open an issue.
