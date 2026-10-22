#include <iostream>
#include <string.h>

//PROBLEM 1
class Fruit{
    private:
        std::string itemName;
        double itemPrice;
        int itemQuantity;
    public:
        //constructor
        Fruit(std::string newName = "Unknown Fruit", double newPrice = 0.0, int newQuantity = 0){
            itemName = (newName);
            itemPrice = newPrice;
            itemQuantity = newQuantity;
            std::cout << "Fruit Constructor Called." << std::endl;
        };

        //deconstructor
        ~Fruit(){
            std::cout << "Fruit Destructor Called." << std::endl;
        }

        //Copy constructor
        Fruit(const Fruit &copyFruit){
            std::cout << "Fruit Copy Constructor Called." << std::endl;
            itemName = copyFruit.itemName;
            itemPrice = copyFruit.itemPrice;
            itemQuantity = copyFruit.itemQuantity;
        }

        //Copy Assignment Operator
        Fruit& operator=(const Fruit &copyFruit){
            std::cout << "Fruit Copy Assignment Operator Called." << std::endl;
            if(this != &copyFruit){
                itemName = copyFruit.itemName;
                itemPrice = copyFruit.itemPrice;
                itemQuantity = copyFruit.itemQuantity;
            }
            return *this;
        }

        //Calculate Sum
        double calculateSum(){
            return itemPrice * itemQuantity;
        }

        //Display Attributes
        void printDetails(){
            std::cout << this->itemName << " - PHP " << this->itemPrice << " x " << this->itemQuantity
                       << " = PHP " << this->calculateSum() << std::endl;
        }
};

class Vegetable{
    private:
        std::string itemName;
        double itemPrice;
        int itemQuantity;
    public:
        //constructor
        Vegetable(std::string newName = "Unknown Vegetable", double newPrice = 0.0, int newQuantity = 0){
            itemName = (newName);
            itemPrice = newPrice;
            itemQuantity = newQuantity;
            std::cout << "Vegetable Constructor Called." << std::endl;
        };

        //deconstructor
        ~Vegetable(){
            std::cout << "Vegetable Destructor Called." << std::endl;
        }

        //Copy constructor
        Vegetable(const Vegetable &copyVegetable){
            std::cout << "Vegetable Copy Constructor Called." << std::endl;
            itemName = copyVegetable.itemName;
            itemPrice = copyVegetable.itemPrice;
            itemQuantity = copyVegetable.itemQuantity;
        }

        //Copy Assignment Operator
        Vegetable& operator=(const Vegetable &copyVegetable){
            std::cout << "Vegetable Copy Assignment Operator Called." << std::endl;
            if(this != &copyVegetable){
                itemName = copyVegetable.itemName;
                itemPrice = copyVegetable.itemPrice;
                itemQuantity = copyVegetable.itemQuantity;
            }
            return *this;
        }

        //Calculate Sum
        double calculateSum(){
            return itemPrice * itemQuantity;
        }

        //Display Attributes
        void printDetails(){
            std::cout << this->itemName << " - PHP " << this->itemPrice << " x " << this->itemQuantity
                       << " = PHP " << this->calculateSum() << std::endl;
        }
};

//PROBLEM 3
double TotalSum(Fruit *fruitList[], int fruitCount, Vegetable *vegList[], int vegCount){
    double total = 0.0;
    for(int i = 0; i < fruitCount; i++){ //loop A
        if(fruitList[i] != NULL){
            total += fruitList[i]->calculateSum();
        }
    }
    for(int i = 0; i < vegCount; i++){ //loop B
        if(vegList[i] != NULL){
            total += vegList[i]->calculateSum();
        }
    }
    return total;
}

//DRIVER PROGRAM
int main(){
    const size_t fruitCount = 2;
    const size_t vegCount = 2;

//PROBLEM 2    
	Fruit *fruitList[fruitCount];
    fruitList[0] = new Fruit("Apple", 10, 7);
    fruitList[1] = new Fruit("Banana", 10, 8);

    Vegetable *vegList[vegCount];
    vegList[0] = new Vegetable("Broccoli", 60, 12);
    vegList[1] = new Vegetable("Lettuce", 50, 10);

    std::cout << "\n--- Jenna's Grocery List ---" << std::endl;
    for(int i = 0; i < fruitCount; i++){
        fruitList[i]->printDetails();
    }
    for(int i = 0; i < vegCount; i++){
        vegList[i]->printDetails();
    }

    std::cout << "\nTotal (before removing Lettuce): PHP "
               << TotalSum(fruitList, fruitCount, vegList, vegCount) << std::endl;

    //PROBLEM 4
    std::cout << "\n--- Removing Lettuce ---" << std::endl;
    delete vegList[1];
    vegList[1] = NULL;

    std::cout << "\nTotal (after removing Lettuce): PHP "
               << TotalSum(fruitList, fruitCount, vegList, vegCount) << std::endl;

    //Clean up all remaining dynamically allocated memory
    for(int i = 0; i < fruitCount; i++){
        delete fruitList[i];
        fruitList[i] = NULL;
    }
    for(int i = 0; i < vegCount; i++){
        if(vegList[i] != NULL){
            delete vegList[i];
            vegList[i] = NULL;
        }
    }

    return 0;
}
