/*
  Isil Vardarli
  main menu' first four options are about to organize lists.
  *If you you want to see your items inside of every each one of your lists, you need to choose first option.
  *If you you want to see items inside of a certain list, you need to choose second option and you will enter the certain list' name.
  *If you want to need a new list, you need to choose third option and for give a name the new list, you will write a name.
  *If you want to delete a list, you need to choose fourth option. List will delete which you write it' name.
  *If you want to organize items, you need to choose fifth option. After that you need to write list' name that you want to organize items inside of it.
	You will see 6 different options:
	-If you you want to add a new item to the list, you need to choose first option.
   After you choose you will write item' name, amount and select.
   If you have already bought the item you need to enter "1" to select (0/1).So it will give a mark to the item.
   If you have not already bought the item you need to enter "0" to select (0/1).So it will not give a mark the item, but you can give a mark later with third option.
	-If you you want to delete an item from the list, you need to choose second option
	-If you you want to mark an item you have already bought, you need to choose third option
	-If you you want to delete mark from an item, you need to choose fourth option
	-If you you want to see items inside of the list, you need to choose fifth option
	-If you you want to go back to the main menu, you need to choose last option
  *If you want to exit shopping list application, you need to choose "6".
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Item structure
struct Item {
	std::string title;
	int amount;
	bool isSelected;
};

// Shopping list class which holds items
class ShoppingList {
public:
	// Constructor
	ShoppingList();
	// Destructor
	~ShoppingList();
	// Add new item to the shopping list
	void addNewItem(std::string& title, int amount, bool isSelected = false);
	// Delete an item from the shopping list with the given title
	bool deleteItem(std::string& title);
	// Select / deselect an item in the shopping list with the given title
	bool selectItem(std::string& title, bool is_selected = true);

	// Get the name of the shopping list
	const std::string& getName() const;
	// Set the name of the shopping list
	void setName(const std::string& name);
	// Get item vector of the shopping list
	const std::vector<Item>& getItems() const;
private:
	// Unique shopping list name
	std::string name;
	// Items in the shopping list
	std::vector<Item> items;
};

// Constructor
ShoppingList::ShoppingList()
{
	this->name = "";
}

// Destructor
ShoppingList::~ShoppingList()
{
}

// Add new item to the shopping list
void ShoppingList::addNewItem(std::string& title, int amount, bool isSelected)
{
	bool hasItem = false;

	for (int i = 0; i < this->items.size(); i++) {
		if (this->items[i].title == title) {
			hasItem = true;
			this->items[i].amount += amount;
			this->items[i].isSelected = isSelected;
			break;
		}
	}

	if (!hasItem) {
		Item item;

		item.title = title;
		item.amount = amount;
		item.isSelected = isSelected;

		this->items.push_back(item);
	}
}

// Delete an item from the shopping list with the given title
bool ShoppingList::deleteItem(std::string& title)
{
	for (int i = 0; i < this->items.size(); i++) {
		if (this->items[i].title == title) {
			this->items.erase(this->items.begin() + i);
			return true;
		}
	}

	return false;
}

// Select / deselect an item in the shopping list with the given title
bool ShoppingList::selectItem(std::string& title, bool is_selected)
{
	for (int i = 0; i < this->items.size(); i++) {
		if (this->items[i].title == title) {
			this->items[i].isSelected = is_selected;
			return true;
		}
	}

	return false;
}

// Get the name of the shopping list
const std::string& ShoppingList::getName() const
{
	return this->name;
}

// Set the name of the shopping list
void ShoppingList::setName(const std::string& name)
{
	this->name = name;
}

// Get item vector of the shopping list
const std::vector<Item>& ShoppingList::getItems() const
{
	return this->items;
}

// Add new shopping list to the shopping list vector with the given name
bool addNewShoppingList(std::vector<ShoppingList>& shoppingLists, std::string& name)
{
	for (int i = 0; i < shoppingLists.size(); i++) {
		if (shoppingLists[i].getName() == name)
			return false;
	}

	ShoppingList shoppinglist;
	shoppinglist.setName(name);

	shoppingLists.push_back(shoppinglist);

	return true;
}

// Delete the shopping list from the shopping list vector with the given name
bool deleteShoppingList(std::vector<ShoppingList>& shoppingLists, std::string& name)
{
	for (int i = 0; i < shoppingLists.size(); i++) {
		if (shoppingLists[i].getName() == name) {
			shoppingLists.erase(shoppingLists.begin() + i);
			return true;
		}
	}

	return false;
}

// Print the shopping list int the shopping list vector with the given name
void printShoppingList(std::vector<ShoppingList>& shoppingLists, std::string& name)
{
	std::cout << "Shopping List: " << name << std::endl;

	for (int i = 0; i < shoppingLists.size(); i++) {
		if (shoppingLists[i].getName() == name) {
			std::cout << "  Items: " << std::endl;

			for (int k = 0; k < shoppingLists[i].getItems().size(); k++) {
				const Item& item = shoppingLists[i].getItems()[k];
				std::cout << "\t- " << item.title << ", "  << item.amount << "  " << (item.isSelected ? "+" : "") << std::endl;
			}

			return;
		}
	}

	std::cout << "No such list exists!!!" << std::endl;
}

// Print all shopping lists int the shopping list vector
void printAllShoppingLists(std::vector<ShoppingList>& shoppingLists)
{
	for (int i = 0; i < shoppingLists.size(); i++) {
		std::cout << "Shopping List: " << shoppingLists[i].getName() << std::endl;

		std::cout << "  Items: " << std::endl;

		for (int k = 0; k < shoppingLists[i].getItems().size(); k++) {
			const Item& item = shoppingLists[i].getItems()[k];
			std::cout << "\t- " << item.title << ", "  << item.amount << "  " << (item.isSelected ? "+" : "") << std::endl;
		}

		std::cout << std::endl;
	}
}

// Is the shopping list exist in the shopping list vector with the given name
bool isShoppingListExist(std::vector<ShoppingList>& shoppingLists, std::string& name)
{
	for (int i = 0; i < shoppingLists.size(); i++) {
		if (shoppingLists[i].getName() == name) {
			return true;
		}
	}

	return false;
}

// Get the shopping list in the shopping list vector with the given name
ShoppingList& getShoppingList(std::vector<ShoppingList>& shoppingLists, std::string& name)
{
	for (int i = 0; i < shoppingLists.size(); i++) {
		if (shoppingLists[i].getName() == name) {
			return shoppingLists[i];
		}
	}
}

// Show main menu
void showMainMenu()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "1. Show All Shopping Lists" << std::endl;
	std::cout << "2. Show Shopping List" << std::endl;
	std::cout << "3. Add New Shopping List" << std::endl;
	std::cout << "4. Delete Shopping List" << std::endl;
	std::cout << "5. Shopping List Item Menu" << std::endl;
	std::cout << "6. Exit" << std::endl;
}

// Show item menu
void showItemMenu()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "1. Add New Item To The Shopping List" << std::endl;
	std::cout << "2. Delete Item From The Shopping List" << std::endl;
	std::cout << "3. Select Item In The Shopping List" << std::endl;
	std::cout << "4. Deselect Item In The Shopping List" << std::endl;
	std::cout << "5. Show Shopping List" << std::endl;
	std::cout << "6. Back" << std::endl;
}

// Check if console input fails
bool checkFailed()
{
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}

	return false;
}

// Main function
int main()
{
	bool result;
	std::string name;
	std::vector<ShoppingList> shoppingList;

	while (true) {
		int option = 0;
		bool is_exist;

		showMainMenu();

		std::cout << std::endl << "Select Option: ";
		std::cin >> option;

		checkFailed();

		std::cout << std::endl;

		switch (option) {
			case 1:
				printAllShoppingLists(shoppingList);
				break;
			case 2:
				std::cout << std::endl << "Enter the name of the Shopping List: ";
				std::cin >> name;
				printShoppingList(shoppingList, name);
				break;
			case 3:
				std::cout << std::endl << "Enter the name of the Shopping List to add: ";
				std::cin >> name;
				result = addNewShoppingList(shoppingList, name);

				if (result) {
					std::cout << "Shopping List added succesfully" << std::endl;
				} else {
					std::cout << "Shopping List cannot be added, name already exists" << std::endl;
				}
				break;
			case 4:
				std::cout << std::endl << "Enter the name of the Shopping List to delete: ";
				std::cin >> name;
				result = deleteShoppingList(shoppingList, name);

				if (result) {
					std::cout << "Shopping List deleted succesfully" << std::endl;
				} else {
					std::cout << "Shopping List cannot be deleted, name is not exists" << std::endl;
				}
				break;
			case 5:
				std::cout << std::endl << "Enter the name of the Shopping List: ";
				std::cin >> name;
				is_exist = isShoppingListExist(shoppingList, name);

				if (!is_exist) {
					std::cout << "Shopping List cannot be found" << std::endl;
					break;
				}

				{
					ShoppingList& slist = getShoppingList(shoppingList, name);

					while (true) {
						bool is_back = false;

						std::string title;
						int amount;
						int selected;

						showItemMenu();

						std::cout << std::endl << "Select Option: ";
						std::cin >> option;

						checkFailed();

						std::cout << std::endl;

						switch (option) {
							case 1:
								std::cout << "Title        : ";
								std::cin >> title;
								std::cout << "Amount       : ";
								std::cin >> amount;
								std::cout << "Select (0/1) : ";
								std::cin >> selected;

								if (!checkFailed())
									slist.addNewItem(title, amount, selected == 1 ? true : false);
								break;
							case 2:
								std::cout << "Title : ";
								std::cin >> title;

								result = slist.deleteItem(title);

								if (result) {
									std::cout << "Item has deleted" << std::endl;
								} else {
									std::cout << "Item cannot be found!" << std::endl;
								}
								break;
							case 3:
								std::cout << "Title : ";
								std::cin >> title;

								result = slist.selectItem(title, true);

								if (result) {
									std::cout << "Item has selected" << std::endl;
								} else {
									std::cout << "Item cannot be found!" << std::endl;
								}
								break;
							case 4:
								std::cout << "Title : ";
								std::cin >> title;

								result = slist.selectItem(title, false);

								if (result) {
									std::cout << "Item has deselected" << std::endl;
								} else {
									std::cout << "Item cannot be found!" << std::endl;
								}
								break;
							case 5:
								printShoppingList(shoppingList, name);
								break;
							case 6:
								is_back = true;
								break;
							default:
								std::cout << "Invalid input!" << std::endl;
								break;
						}

						if (is_back)
							break;

						std::cout << std::endl;
					}
				}
				break;
			case 6:
				return 0;
			default:
				std::cout << "Invalid input!" << std::endl;
				break;
		}

		std::cout << std::endl;
	}

	return 0;
}

