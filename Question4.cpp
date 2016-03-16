///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name: Praneel Misthry
// Student No: 202515355
// Date: 16 March 2016
///////////////////////////////////////////////////////////////////////////////////////////////////

// ***** QUESTION 4 ****
// Question 4 has 3 parts (you do NOT need to include each class in a separate file!)
// 4.1 Create a virtual base class "Animal" which has two methods, name() and does(). 
// 4.2 From class "Animal", derive a concrete class "Bird" and "Dog".  Print appropriate message for
//     each method.
// 4.3 Write a driver program which creates an object of each type and demonstrates POLYMORPHISM. 

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

//Creating abtract class Animal with pure virtual functions

class Animal{
protected: string animalName, action;
public: Animal(){
			animalName = "no name";
			action = "whatever";
}
		Animal(string iname, string iaction){
			animalName = iname;
			action = iaction;
		}

		~Animal(){

		}
	
	    virtual void name() = 0;   
		virtual void does() = 0;
};

class Bird : public Animal{
public:
	Bird(){
		animalName = "Bird";
		action = "Tweets and Flies";
	}

	Bird(string iname, string iaction){
		animalName = iname;
		action = iaction;
	}

	~Bird(){

	}

	void name(){
		cout << animalName << endl;
	}

	void does(){
		cout << action << endl;
	}
};

class Dog :public Animal{
public:
	Dog(){
		animalName = "Dog";
		action = "Barks and Woofs";
	}

	~Dog(){

	}

	void name(){
		cout << animalName << endl;
	}

	void does(){
		cout << action << endl;
	}
	
};

int main(){
	//Demonstrating polymorphism by creating pointers of the ABSTRACT CLASS Animal to dynamically create objects of the concrete
	//sub classes Bird and Dog
	//Cannot create objects of abstract classes but can create pointers of abstract classes

	Animal *p1 = new Bird();
	p1->name();
	p1->does();

	Animal *p2 = new Dog();
	p2->name();
	p2->does();

	//Demonstrating polymorphism with arrays
	Animal *pointer[2];
	
	Bird b1;  //Use default constructors
	Dog d1;

	//Fill array with sub class objects by reference
	pointer[0] = &b1;
	pointer[1] = &d1;

	cout << "Testing polymorphism with Abstract Pointer array" << endl;

	for (int i = 0; i < 10; i++)
	{
		pointer[0]->name();
		pointer[0]->does();
		pointer[1]->name();
		pointer[1]->does();
    }


	delete p1;
	delete p2;
	
	system("PAUSE");
	return 0;
}