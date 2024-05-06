# Eulerian Graph Checker

## Overview

This project is a graph analysis tool that checks whether a given directed or undirected graph is Eulerian. An Eulerian graph contains a closed path that visits every edge exactly once (known as an Eulerian circuit).

## Features

- Supports both directed and undirected graphs.
- User input for graph direction, number of nodes, and number of edges.
- User input for the edges of the graph.
- Checks if the graph is Eulerian.

## Prerequisites

To compile and run this project, you need:

- A C++ compiler that supports C++11 or later.
- A terminal or command prompt to compile and run the program.

## Usage

1. **Clone the repository**:

    ```bash
    git clone <repository URL>
    cd <repository directory>
    ```

2. **Compile the code**:

    You can use your preferred compiler. For example, using `g++`:

    ```bash
    g++ main.cpp Graph.cpp -o graph_eulerian_checker
    ```

3. **Run the program**:

    ```bash
    ./graph_eulerian_checker
    ```

4. **Follow the prompts**:

    The program will guide you through the input process to specify whether the graph is directed or undirected, the number of nodes, the number of edges, and the edges of the graph. The program will then check whether the graph is Eulerian and provide the result.
