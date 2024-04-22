#pragma once
#include <iostream>
#include <string>
using namespace std;


class ALU {

private:
	int noOfAdders;
	int noOfSubtractor;
	int noOfRegisters;
	int sizeOfRegisters;

public:
	ALU(int add = 1, int sub = 1, int reg = 1, int regSize = 1) : noOfAdders(add), noOfSubtractor(sub), noOfRegisters(reg), sizeOfRegisters(regSize) {
		if (add < 1 || sub < 1 || reg < 1 || regSize < 1)
			input(add, sub, reg, regSize);
	}			// constructor (default and paramterised)

	void input(int add, int sub, int reg, int regSize) {
		while (add < 1) {
			cout << "Adders must not be less than 1." << endl << "Re-enter: ";
			cin >> add;
			cout << endl;
		}
		setAdders(add);

		while (sub < 1) {
			cout << "Subtractors must not be less than 1." << endl << "Re-enter: ";
			cin >> sub;
			cout << endl;
		}
		setSubtractors(sub);

		while (reg < 1) {
			cout << "Registers must be not be less than 1." << endl << "Re-enter: ";
			cin >> reg;
			cout << endl;
		}
		setRegisters(reg);

		while (regSize < 1) {
			cout << "Register size must be more than 1 byte." << endl << "Re-enter: ";
			cin >> regSize;
			cout << endl;
		}
		setSize(regSize);
	}

	void setAdders(int add) {
		while (add < 1) {
			cout << "Adders must not be less than 1." << endl << "Re-enter: ";
			cin >> add;
			cout << endl;
		}
		this->noOfAdders = add;
	}

	int getAdders() {
		return this->noOfAdders;
	}

	void setSubtractors(int sub) {
		while (sub < 1) {
			cout << "Subtractors must not be less than 1." << endl << "Re-enter: ";
			cin >> sub;
			cout << endl;
		}
		this->noOfSubtractor = sub;
	}

	int getSubtractors() {
		return this->noOfSubtractor;
	}

	void setRegisters(int reg) {
		while (reg < 1) {
			cout << "Registers must be not be less than 1." << endl << "Re-enter: ";
			cin >> reg;
			cout << endl;
		}
		this->noOfRegisters = reg;
	}

	int getRegisters() {
		return this->noOfRegisters;
	}

	void setSize(int regSize) {
		while (regSize < 1) {
			cout << "Register size must be more than 1 byte." << endl << "Re-enter: ";
			cin >> regSize;
			cout << endl;
		}
		this->sizeOfRegisters = regSize;
	}

	int getRegSize() {
		return this->sizeOfRegisters;
	}
	
};



class ControlUnit {

private:
	float clock;

public:
	ControlUnit(int clock = 0) : clock(clock) {}

	float getClock() {
		return this->clock;
	}

	void setClock(int clock) {
		this->clock = clock;
	}

};



class CPU {

private:
	ALU *alu = new ALU;
	ControlUnit *cu = new ControlUnit;
	//composition relation

public:

	ALU* getAlu() {
		return this->alu;
	}

	ControlUnit* getCu() {
		return this->cu;
	}

	void setAlu(int *ALU) {
		
	}

	CPU() {};
	~CPU() {
		delete alu, cu;
	}
};



class MainMemory {

private: 
	int capacity;
	string technologyType;

public:
	MainMemory(int capa = 0, string type = "\0") : capacity(capa), technologyType(type) {}

	void setCapacity(int capa) {
		this->capacity = capa;
	}

	int getCapacity() {
		return this->capacity;
	}

	void setType(string type) {
		this->technologyType = type;
	}

	string getType() {
		return this->technologyType;
	}
};



class Port {

private:
	string type;
	int baud_rate;

public:
	Port(string type = "\0", int rate = 0) : type(type), baud_rate(rate) {}

	void setType(string type) {
		this->type = type;
	}

	string getType() {
		return this->type;
	}

	void setRate(int rate) {
		this->baud_rate = rate;
	}

	int getRate() {
		return this->baud_rate;
	}
};



class MotherBoard {

private:
	Port *ports;
	MainMemory* mm;

public:
	MotherBoard(Port* ports, MainMemory* mm, int size = 0) {
		this->ports = ports;
		this->mm = mm;
	}

	Port* getPort() {
		return this->ports;
	}

	MainMemory* getMemory() {
		return this->mm;
	}

	void setMemory(MainMemory* mm) {
		this->mm = mm;
	}

	void setPorts(Port* ports) {
		this->ports = ports;
	}

	~MotherBoard() {
		delete[] this->ports;
	}
};



class PhysicalMemory {
	
private:
	int capacity;

public:
	PhysicalMemory(int capa) : capacity(capa) {}

	void setCapacity(int capacity) {
		this->capacity = capacity;
	}

	int getCapacity() {
		return this->capacity;
	}
};



class Computer {

private:
	PhysicalMemory* pm;
	MotherBoard* mb;
	CPU* cpu;

public:
	Computer(PhysicalMemory* pm, MotherBoard* mb, CPU* cpu) : pm(pm), mb(mb), cpu(cpu) {}

	PhysicalMemory* getMemory() {
		return this->pm;
	}

	MotherBoard* getMB() {
		return this->mb;
	}

	CPU* getCPU() {
		return this->cpu;
	}

	void setCPU(CPU* cpu) {
		this->cpu = cpu;
	}

	void setMB(MotherBoard* mb) {
		this->mb = mb;
	}

	void setMemory(PhysicalMemory* pm) {
		this->pm = pm;
	}
};



class GraphicsCard {

private:
	string brand;
	int memorySize;
	double price;

public:
	GraphicsCard(string brand = "\0", int size = 0, double price = 0) : brand(brand), memorySize(size), price(price) {}

	string getBrand() {
		return this->brand;
	}

	int getSize() {
		return this->memorySize;
	}

	double price() {
		return this->price;
	}

	void setBrand(string brand) {
		this->brand = brand;
	}

	void setSize(int size) {
		this->memorySize = size;
	}

	void setPrice(double price) {
		this->price = price;
	}
};



class StorageDevice {

private:
	string type;
	int capacity;
	double price;

public:
	StorageDevice(string type = "\0", int capacity = 0, double price = 0) : type(type), capacity(capacity), price(price) {}

	string getType() {
		return this->type;
	}

	int getCapacity() {
		return this->capacity;
	}

	double price() {
		return this->price;
	}

	void setType(string type) {
		this->type = type;
	}

	void setCapacity(int capacity) {
		this->capacity = capacity;
	}

	void setPrice(double price) {
		this->price = price;
	}
};



class NetworkClass {

private:
	string type;
	int speed;
	double price;

public:
	NetworkClass(string type = "\0", int speed = 0, double price = 0) : type(type), speed(speed), price(price) {}

	string getType() {
		return this->type;
	}

	int getSpeed() {
		return this->speed;
	}

	double price() {
		return this->price;
	}

	void setType(string type) {
		this->type = type;
	}

	void setSpeed(int speed) {
		this->speed = speed;
	}

	void setPrice(double price) {
		this->price = price;
	}
};



class PowerSupply {

private:
	string efficiencyRating;
	int wattage;
	double price;

public:
	PowerSupply (string efficiencyRating = "\0", int wattage = 0, double price = 0) : efficiencyRating(efficiencyRating), wattage(wattage), price(price) {}

	string getefficiencyRating() {
		return this->efficiencyRating;
	}

	int getwattage() {
		return this->wattage;
	}

	double price() {
		return this->price;
	}

	void setefficiencyRating(string efficiencyRating) {
		this->efficiencyRating = efficiencyRating;
	}

	void setwattage(int wattage) {
		this->wattage = wattage;
	}

	void setPrice(double price) {
		this->price = price;
	}
};



class Battery {

private:
	int capacity;

public:
	Battery(int capa) : capacity(capa) {}

	void setCapacity(int capacity) {
		this->capacity = capacity;
	}

	int getCapacity() {
		return this->capacity;
	}
};



class Case {

private:
	string formFactor;
	string color;

public:
	Case(string formFactor = "\0", string color = "\0") : formFactor(formFactor), color(color) {}

	void setFormFactor(string formFactor) {
		this->formFactor = formFactor;
	}

	string getFormFactor() {
		return this->formFactor;
	}

	void setColor(string color) {
		this->color = color;
	}

	string getColor() {
		return this->color;
	}
};



class ComputerAssembly {

};