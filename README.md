Inventory Management System
===========================

CSCI 33500 - Project 1
----------------------

A C++ inventory management system demonstrating move semantics, the Rule of Five, and performance optimization.

Project Overview
----------------

This project implements an inventory system for a game-like application where players can store items in a grid-based inventory and equip items. The focus is on proper memory management and demonstrating the performance benefits of move semantics.

Files
-----

*   Inventory.hpp / Inventory.cpp - Inventory class implementation
*   Player.hpp / Player.cpp - Player class implementation
*   main.cpp - Test program with functionality and performance tests
*   Item.hpp - Item class (provided)
*   Guild.hpp - Guild class (provided)
    

Key Features
------------

*   **Grid-based inventory system** (customizable size, default 10x10)
*   **Item equipping mechanism** with dynamic memory management
*   **Complete Big Five implementation** for both classes
*   **Move semantics optimization** for efficient resource transfer
*   **Performance testing** comparing copy vs move operations

How to Compile and Run
----------------------

```g++ -std=c++17 -Wall -Wextra -g -o main main.cpp Inventory.cpp Player.cpp  ./main```

What the Program Does
---------------------

1.  **Functionality Tests**: Verifies that copying, moving, and memory management work correctly
2.  **Performance Tests**: Times copy vs move operations for different inventory sizes
    

Expected Output
---------------

*   Functionality test results showing proper deep copying and move semantics
*   Performance comparison showing move operations are much faster for large inventories
    

Learning Goals
--------------

*   Understanding C++ move semantics
*   Implementing the Rule of Five correctly
*   Managing dynamic memory safely
*   Measuring and comparing algorithm performance