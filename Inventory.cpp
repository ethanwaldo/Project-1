#include "Inventory.hpp"

Inventory::Inventory(const std::vector<std::vector<Item>>&, Item*) {}
Inventory::~Inventory() {}
Inventory::Inventory(const Inventory&) {}
Inventory::Inventory(Inventory&&) {}
Inventory& Inventory::operator=(const Inventory&) { return *this; }
Inventory& Inventory::operator=(Inventory&&) { return *this; }

Item* Inventory::getEquipped() const { return nullptr; }
std::vector<std::vector<Item>> Inventory::getItems() const { return {}; }
float Inventory::getWeight() const { return 0.0f; }
size_t Inventory::getCount() const { return 0; }
Item Inventory::at(size_t, size_t) const { return Item(); }

void Inventory::equip(Item*) {}
void Inventory::discardEquipped() {}
bool Inventory::store(size_t, size_t, const Item&) { return true; }
