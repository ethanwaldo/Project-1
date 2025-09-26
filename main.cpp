/*
    Student: Ethan Waldo
    EMPLID: 23274836
    Project 1
    main.cpp
*/

#include <iostream>
#include <vector>
#include <chrono>

#include "Player.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

// Helper function to create a large inventory
Inventory create_inventory(size_t rows, size_t cols) {
    std::vector<std::vector<Item>> items(rows, std::vector<Item>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if ((i + j) % 2 == 0) {
                items[i][j] = Item(ItemType::POTION, 1.5f);
            }
        }
    }
    return Inventory(items, new Item(ItemType::WEAPON, 10.0f));
}

void run_performance_tests() {
    std::cout << "--- Performance Tests ---" << std::endl;

    // --- Small Inventory (10x10) ---
    std::cout << "\n--- Small Inventory (10x10) ---" << std::endl;
    Player p_small("Small_Inv_Player", create_inventory(10, 10));

    // Time Copy
    auto start_copy_small = std::chrono::high_resolution_clock::now();
    Player p_small_copy = p_small;
    auto end_copy_small = std::chrono::high_resolution_clock::now();
    auto duration_copy_small = std::chrono::duration_cast<std::chrono::microseconds>(end_copy_small - start_copy_small);
    std::cout << "Small inventory copy time: " << duration_copy_small.count() << " microseconds." << std::endl;

    // Time Move
    auto start_move_small = std::chrono::high_resolution_clock::now();
    Player p_small_move = std::move(p_small);
    auto end_move_small = std::chrono::high_resolution_clock::now();
    auto duration_move_small = std::chrono::duration_cast<std::chrono::microseconds>(end_move_small - start_move_small);
    std::cout << "Small inventory move time: " << duration_move_small.count() << " microseconds." << std::endl;


    // --- Large Inventory (2000x2000) ---
    std::cout << "\n--- Large Inventory (2000x2000) ---" << std::endl;
    Player p_large("Large_Inv_Player", create_inventory(2000, 2000));

    // Time Copy
    auto start_copy_large = std::chrono::high_resolution_clock::now();
    Player p_large_copy = p_large;
    auto end_copy_large = std::chrono::high_resolution_clock::now();
    auto duration_copy_large = std::chrono::duration_cast<std::chrono::microseconds>(end_copy_large - start_copy_large);
    std::cout << "Large inventory copy time: " << duration_copy_large.count() << " microseconds." << std::endl;

    // Time Move
    auto start_move_large = std::chrono::high_resolution_clock::now();
    Player p_large_move = std::move(p_large);
    auto end_move_large = std::chrono::high_resolution_clock::now();
    auto duration_move_large = std::chrono::duration_cast<std::chrono::microseconds>(end_move_large - start_move_large);
    std::cout << "Large inventory move time: " << duration_move_large.count() << " microseconds." << std::endl;
}

void run_functionality_tests() {
    std::cout << "\n--- Functionality Tests ---" << std::endl;

    // Create an inventory
    Inventory inv;
    inv.store(0, 0, Item(ItemType::ARMOR, 25.0f));
    inv.equip(new Item(ItemType::WEAPON, 12.5f));

    std::cout << "Initial inventory count: " << inv.getCount() << ", weight: " << inv.getWeight() << std::endl;
    if (inv.getEquipped()) {
        std::cout << "Equipped item weight: " << inv.getEquipped()->getWeight() << std::endl;
    }

    // Create a player
    Player p1("Allen", inv);
    std::cout << "Player " << p1.getName() << " created." << std::endl;

    // Test Copy Constructor
    Player p2 = p1; // Copy
    std::cout << "Player " << p2.getName() << " created via copy." << std::endl;
    std::cout << "p1 inv count: " << p1.getInventoryRef().getCount() << std::endl;
    std::cout << "p2 inv count: " << p2.getInventoryRef().getCount() << std::endl;
    // Modify p2's inventory to see if it affects p1
    p2.getInventoryRef().store(1, 1, Item(ItemType::POTION, 1.0f));
    std::cout << "p1 inv count after p2 modification: " << p1.getInventoryRef().getCount() << std::endl;
    std::cout << "p2 inv count after p2 modification: " << p2.getInventoryRef().getCount() << std::endl;
    // Check equipped item deep copy
    if (p1.getInventoryRef().getEquipped() && p2.getInventoryRef().getEquipped()) {
        std::cout << "p1 equipped address: " << p1.getInventoryRef().getEquipped() << std::endl;
        std::cout << "p2 equipped address: " << p2.getInventoryRef().getEquipped() << std::endl;
        if (p1.getInventoryRef().getEquipped() != p2.getInventoryRef().getEquipped()) {
            std::cout << "Deep copy of equipped item successful." << std::endl;
        }
    }


    // Test Move Constructor
    Player p3 = std::move(p1);
    std::cout << "Player " << p3.getName() << " created via move." << std::endl;
    // p1 should be in a valid but empty state
    std::cout << "Original player (p1) name after move: " << p1.getName() << std::endl;
    std::cout << "Original player (p1) inv count after move: " << p1.getInventoryRef().getCount() << std::endl;
    std::cout << "Moved-to player (p3) inv count: " << p3.getInventoryRef().getCount() << std::endl;

    // Test Assignment operators
    Player p4("Joe");
    p4 = p2; // Copy assignment
    std::cout << "p4 assigned from p2. p4 inv count: " << p4.getInventoryRef().getCount() << std::endl;

    Player p5("Bob");
    p5 = std::move(p3); // Move assignment
    std::cout << "p5 assigned from p3. p5 inv count: " << p5.getInventoryRef().getCount() << std::endl;
    std::cout << "Original player (p3) inv count after move assignment: " << p3.getInventoryRef().getCount() << std::endl;
}


int main() {
    run_functionality_tests();
    run_performance_tests();
    return 0;
}
