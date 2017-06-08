#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <fstream>

class pokemon
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
	pokemon()
	{
		creatureName = "default name";
		serialNumber = 999;
		elementalTypes = "unknown";
		//type2 = "";
		offense = 0;
		defense = 0;
	}
	pokemon(std::string name, int idNumber, std::string emelents, int offenseNumber, int defenseNumber)
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
	int setOffenseStat(int offenseNumber)
	{
		offense = offenseNumber;
	}
	int setDefenseStat(int defenseNumber)
	{
		defense = defenseNumber;
	}
	//Overloading >> operator to read in data from file
	friend std::ifstream& operator >>(std::ifstream& file, pokemon p)
	{
		std::string tempStr;
		getline(file, tempStr, '|');
		p.serialNumber(std::stoi(tempStr));
		getline(file, tempStr, '|');
		p.creatureName(tempStr);
		getline(file, tempStr, '|');
		p.elementalTypes(tempStr);
		//getline(file, tempStr, '|');
		//p.setType2(tempStr);
		getline(file, tempStr, '|');
		p.offense(std::stoi(tempStr));
		getline(file, tempStr, '\n');
		p.defense(std::stoi(tempStr));
		return file;
	}
};
#endif