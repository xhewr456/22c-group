#include<iostream>
#include<string>
#include<fstream>
//#include<memory>
#include<Windows.h>
#include"Globals.h"
#include"Scanner.h"
#include"Pokemon.h"
//#include"LinkedList.h"
#include"LeoLinkedList.h"
#include"BinarySearchTree.h"
#include"HashTable.h"

using namespace std;
//Pokemon *getDataMemoryAddress(ifstream);
int getIntegerInput();

Pokemon *getDataMemoryAddress(ifstream &file)
//unique_ptr<Pokemon> getDataMemoryAddress(ifstream &file)
{
	Pokemon *newPokemon = nullptr;
	newPokemon = new Pokemon;
	file >> newPokemon;
	//cout << newPokemon->getPokemonName() << endl;
	return newPokemon;

	//unique_ptr<Pokemon> ptr(new Pokemon);
	//file >> ptr;
	//return ptr;
}


int main()
{

	// this makes the console window bigger
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1000, 600, TRUE);


	// before any choices are give, load the data file and build the hash table and binary search tree
	// none of this is set in stone, but for now gives us something to work on
	// if you need to work on some file, just tag it with a "-A" or "-L" or "-H" and upload the file
	ifstream dataRecordsFile;
	dataRecordsFile.open("PokeStats.txt");


	BinarySearchTree<Pokemon*> pokemonBST;
	LinkedList<Pokemon*> pokemonLinkedList;
	//HashTable<Pokemon*> pokemonHashedTable(ARRAY_SIZE);
	HashTable pokemonHashedTable(ARRAY_SIZE);


	Pokemon *tempPokemon = nullptr;
	for (int count = 0; count < ARRAY_SIZE; count++)
	{
		tempPokemon = getDataMemoryAddress(dataRecordsFile);
		//pokemonLinkedList.push_end(tempPokemon);
		pokemonBST.addValue(tempPokemon);
		pokemonHashedTable.add(tempPokemon);
	}
	dataRecordsFile.close();

	//dataRecordsFile.open("PokeStats.txt");
	//Pokemon pokemonArray[ARRAY_SIZE];
	//for (int count = 0; count < ARRAY_SIZE; count++)
	//{
	//	dataRecordsFile >> pokemonArray[count];
	//}

	int creatureIndexNumber;
	string name;
	string elements;
	int offense;
	int defense;
	bool status;

	int choice = 0;
	while (choice != 9)
	{
		system("cls");
		cout << "1: add new data\n";
		cout << "2: remove data\n";
		cout << "3: find and display data\n";
		cout << "4: list data in the hash table\n";
		cout << "5: list data in key sequence (inorder traverse)\n";
		cout << "6: print indented tree\n";
		cout << "7: effiency\n";
		cout << "8: team choice (scanner)\n";
		cout << "9: exit program\n";
		cout << "Enter the choice: ";
		choice = getMenuInput(9);

		switch (choice)
		{
		case 1:
		{
			// call to add data function
			// both the hash table and binary search tree need add functions
			// use this case to call those add functions
			// leo and alex will make the add functions in the their class files
			system("cls");
			cout << "this is the add data choice\n";
			cout << "enter in pokemon's name: ";
			getline(cin, name);
			cout << "enter in pokemon's pokedex number: ";
			creatureIndexNumber = getIntegerInput();
			cout << "enter in pokemon's elements: ";
			getline(cin, elements);
			cout << "enter in pokemon's offense stat: ";
			offense = getIntegerInput();
			cout << "enter in pokemon's defense stat: ";
			defense = getIntegerInput();
			Pokemon *addThisPokemon = nullptr;
			addThisPokemon = new Pokemon(name, creatureIndexNumber, elements, offense, defense);
			pokemonBST.addValue(addThisPokemon);
			pokemonHashedTable.add(addThisPokemon);
			cout << "\npress <Enter> to return to main menu...";
			cin.get();
			break;
		}
		case 2:
		{
			// call to remove data function
			// both the hash table and binary search tree need remove functions
			// use this case to call those remove functions
			// leo and alex will make the remove functions in the their class files
			system("cls");
			cout << "this is the remove data choice\n";
			cout << "enter the pokedex number of the pokemon you wish to remove: ";
			int removeNumber = getIntegerInput();
			Pokemon *removeThisPokemon = nullptr;
			removeThisPokemon = new Pokemon();
			removeThisPokemon->setSerialNumber(removeNumber);
			bool status = pokemonBST.deleteValue(removeThisPokemon);
			bool status2 = pokemonHashedTable.removebyData(removeThisPokemon);

			cout << status << " " << status2 << endl;
			//cout << status << endl;
			cout << "\npress <Enter> to return to main menu...";
			cin.get();
			delete removeThisPokemon;
			break;
		}
		case 3:
		{
			// call to find and display data function
			// this function will use the binary search tree to find and display the creature based on the number entered
			// clifford will write this function
			cout << "this is the find and display data choice\n";

			cout << "enter in creature number to search for: ";
			creatureIndexNumber = getIntegerInput();
			// send the number to the binary search tree module and print out the results of the search
			Pokemon *tempPokemon = nullptr;
			tempPokemon = new Pokemon;
			tempPokemon->setSerialNumber(creatureIndexNumber);
			//status = pokemonBST.searchForValue(tempPokemon);
			status = pokemonBST.searchForValue(creatureIndexNumber);
			//status = true;
			if (status == true)
			{
				cout << "creature number: " << creatureIndexNumber << " has been found\n";
			}
			else
			{
				cout << "creature number: " << creatureIndexNumber << " was NOT been found\n";
			}
			cout << "\npress <Enter> to return to main menu...";
			cin.get();

			break;
		}
		case 4:
		{
			// call to list data in hash table
			// list all the data stored in the hashed table based on the order in the array
			// leo will write this function
			system("cls");
			cout << "this is the list data in hash table choice\n";
			pokemonHashedTable.hashDisplayAll();

			//pokemonLinkedList.displayList();
			cout << "\npress <Enter> to return to main menu...";
			cin.get();


			break;
		}
		case 5:
		{
			// call to list data in key sequence (sorted)
			// list all data using the creature number as the sort method
			// I think you can use either the hashed table or the binary search tree for the data
			// but lets go with the hashed table for now
			// leo will work on this
			system("cls");
			cout << "this is the list data in key sequence (inorder traverse) choice\n";
			pokemonBST.printBreadthFirstTraverse();
			cout << "\npress <Enter> to return to main menu...";
			cin.get();
			break;
		}
		case 6:
		{
			// call to print indented tree function
			// cout the binary tree horizontally, alex and hammud will collaborate as needed on this
			system("cls");
			cout << "this is the printed indented tree choice\n";
			pokemonBST.callPrintIndentedTree();
			cout << "\npress <Enter> to return to main menu...";
			cin.get();
			break;
		}
		case 7:
		{
			// call to effiency
			// display the effiency of our hashed table and binary search tree
			int hashedTableFillRate = ((static_cast<double>(pokemonHashedTable.getItemCount()) / static_cast<double>(pokemonHashedTable.getLength())) * 100);
			system("cls");
			cout << "this is the effiency choice\n";
			cout << "Hashed Table fill rate is: " << hashedTableFillRate << "%";
			cout << "\npress <Enter> to return to main menu...";
			cin.get();
			break;
		}
		case 8:
		{
			// call to scanner function
			// this is our team choice and for now the idea is to display a message that a wild pokemon has appeared
			// display an out line of the creature, flash the words scanning on the the screen
			// then after the 3 seconds display the full picture and some stats about the creature
			// it will only display one creature for now, and in the future it may display a random pokemon
			cout << "this is the scanner choice\n";
			startScanner();
			break;
		}
		case 9:
		{
			// exit program 
			break;
		}
		default:
		{
			// this is here for safety
			break;
		}

		}
	}

	cout << "\npress <Enter> to exit...";
	cin.get();
	return 0;
}