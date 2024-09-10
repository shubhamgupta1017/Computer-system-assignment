# Geometry Library and Convex Hull Application

## Overview

This project consists of a library and application for coordinate geometry. The library includes functions for handling points, lines, and polygons, while the application demonstrates the use of these functions to perform various geometric computations.

## Github Link

https://github.com/shubhamgupta1017/CS207

## File Structure

- **include/geometry.h**: Contains the declarations of functions and structures used in the geometry library.
- **src/geometry.c**: Contains the definitions of functions declared in `geometry.h`.
- **test/test.c**: Contains unit tests for the geometry library.
- **test/test_app.c**: Contains tests for the application that uses the geometry library.
- **app/app.c**: Contains the source code for the application that utilizes the geometry library.
- **lib/**: Stores the compiled shared library `libgeo.so`.
- **bin/**: Contains the final executables: `test`, `test_app`, and `app`.
- **Makefile**: Used to build the library and the final application.
- **README.md**: Overview of the project, including file information, compilation instructions, and running steps.


## Requirements

Before running this project, ensure you have the following installed:

- **GCC Compiler**: Required for compiling the code.
- **Standard C Libraries**: Includes `<stdio.h>`, `<stdlib.h>`, and `<math.h>`.
- **Make**: Required for build automation.

## Library Overview

The `geometry` library provides functions for:

- **Points**
  - `Point pointInit(float x, float y);`

- **Lines**
  - `Line lineInit(float slope, float intercept);`

- **Polygons**
  - `Polygon polyInit(Point p[], int num_points);`
  - `void polyAddPoints(Polygon *poly, Point p[], int size);`
  - `Point polyGetPoint(Polygon *poly, int idx);`
  - `void polySortPoint(Polygon *poly);`
  - `void polyPrint(Polygon *library);`
  - `float polyPeri(Polygon *poly);`
  - `Point polyCentroid(Polygon *poly);`

- **Geometric Computations**
  - `float angleBwLines(Line l1, Line l2);`
  - `float distance(Point p1, Point p2);`
  - `Point reflectionAboutLine(Point p, Line l);`
  - `Line ptsToLine(Point p1, Point p2);`
  - `Point intersectionOfLine(Line l1, Line l2);`

## Application Overview

The application demonstrates the use of the geometry library by initializing a set of points and creating a polygon. It then prints the vertices of the polygon's convex hull.

- `Polygon polyInit(Point p[], int num_points);` - Initializes a polygon with a given set of points.
- `void polySortPoint(Polygon *poly);` - Sorts the points of the polygon.
- `Point pointInit(float x, float y);` - Initializes a point with specified coordinates.
- `void polyAddPoints(Polygon *poly, Point p[], int size);` - Adds additional points to the polygon.
- `Point polyGetPoint(Polygon *poly, int idx);` - Retrieves a specific point from the polygon.
- `void polyPrint(Polygon *library);` - Prints the details of the polygon.


## Makefile Commands

- `make all`          : Builds all components (library, application, and tests).
- `make app`          : Builds the application.
- `make test`         : Builds the unit tests.
- `make test_app`     : Builds the application tests.
- `make lib`          : Builds the geometry library (`libgeo.so`).
- `make run_app`      : Runs the application.
- `make run_test`     : Runs the unit tests.
- `make run_test_app` : Runs the application tests.
- `make clean`        : Deletes all executables.

## Compilation and Running

1. **Build Everything:**
   ```bash
   make all
   ```

2. **Run Application:**
   ```bash
   make run_app
   ```

3. **Run Tests:**
   ```bash
   make run_test
   ```

4. **Run Application Tests:**
   ```bash
   make run_test_app
   ```

5. **Clean Up:**
   ```bash
   make clean
   ```

## Team Members

- Kumar Vedant (2023AIB1009)
- Meet Gupta (2023AIB1011)
- Shubham Gupta (2023AIB1017)

## Contributions

- **Task 0:** Identified the list of functions required and the targeted application. (Vedant, Meet, Shubham)
- **Task 1:** Created a library of coordinate geometry. (Shubham)
- **Task 2:** Tested individual functions for correctness and functionality. (Meet)
- **Task 3:** Used library functions to develop meaningful applications. (Vedant)
- **Task 4:** Created test cases for the main application. (Meet)
- **Task 5:** Used the Makefile to build the complete system. (Shubham)
