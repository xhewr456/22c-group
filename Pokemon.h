#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <fstream>

class Pokemon
{
private:
	std::string creatureName;
	int serialNumber;
	std::string elementalTypes;
	//std::string type2;
	int offense;
	int defense;
public:
	//Constructors
	Pokemon()
	{
		creatureName = "unknown name";
		serialNumber = 999;
		elementalTypes = "unknown";
		//type2 = "";
		offense = 0;
		defense = 0;
	}
	Pokemon(std::string name, int idNumber, std::string emelents, int offenseNumber, int defenseNumber)
	{
		creatureName = name;
		serialNumber = idNumber;
		elementalTypes = emelents;
		//type2 = "";
		offense = offenseNumber;
		defense = defenseNumber;
	}

	//getters
	std::string getPokemonName()
	{
		return creatureName;
	}
	int getSerialNumber()
	{
		return serialNumber;
	}
	std::string getElementalType()
	{
		return elementalTypes;
	}
	//std::string getType2()
	//{
	//	return type2;
	//}
	int getOffenseStat()
	{
		return offense;
	}
	int getDefenseStat()
	{
		return defense;
	}

	//setters
	void setPokemonName(std::string name)
	{
		creatureName = name;
	}
	void setSerialNumber(int idNumber)
	{
		serialNumber = idNumber;
	}
	void setElementType(std::string elements)
	{
		elementalTypes = elements;
	}
	//void setType2(std::string x)
	//{
	//	type2 = x;
	//}
	void setOffenseStat(int offenseNumber)
	{
		offense = offenseNumber;
	}
	void setDefenseStat(int defenseNumber)
	{
		defense = defenseNumber;
	}
	void setAll(int number, std::string name, std::string elements, int attack, int defend)
	{
		serialNumber = number;
		creatureName = name;
		elementalTypes = elements;
		offense = attack;
		defense = defend;
	}
	//Overloading >> operator to read in data from file
	friend std::ifstream& operator >> (std::ifstream &file, Pokemon &creature)
	{
		std::string tempString;
		int tempNumber;
		getline(file, tempString, '|');
		tempNumber = std::stoi(tempString);
		creature.setSerialNumber(tempNumber);
		getline(file, tempString, '|');
		creature.setPokemonName(tempString);
		getline(file, tempString, '|');
		creature.setElementType(tempString);
		//getline(file, tempStr, '|');
		//p.setType2(tempStr);
		getline(file, tempString, '|');
		creature.setOffenseStat(std::stoi(tempString));
		getline(file, tempString, '\n');
		creature.setDefenseStat(std::stoi(tempString));
		return file;
	}


	//Overloading >> operator to read in data from file
	friend std::ifstream& operator >> (std::ifstream &file, Pokemon *&creature)
	{
		std::string tempString;
		int tempNumber;
		getline(file, tempString, '|');
		tempNumber = std::stoi(tempString);
		creature->setSerialNumber(tempNumber);
		getline(file, tempString, '|');
		creature->setPokemonName(tempString);
		getline(file, tempString, '|');
		creature->setElementType(tempString);
		//getline(file, tempStr, '|');
		//p.setType2(tempStr);
		getline(file, tempString, '|');
		creature->setOffenseStat(std::stoi(tempString));
		getline(file, tempString, '\n');
		creature->setDefenseStat(std::stoi(tempString));
		return file;
	}




	// overloaded out stream operator 
	friend std::ostream &operator << (std::ostream &outStream, Pokemon &creature)
	{
		std::cout << creature.serialNumber << " " << creature.creatureName << " " << creature.elementalTypes;
		return outStream;
	}

	friend std::ostream &operator << (std::ostream &outStream, Pokemon *&creature)
	{
		std::cout << creature->serialNumber << " " << creature->creatureName << " " << creature->elementalTypes;
		return outStream;
	}
};
#endif