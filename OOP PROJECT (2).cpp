#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <ctime>
#include <windows.h> 
using namespace std;
class Product {
public:
    string name;
    float price;
    Product(string _name, float _price)
        : name(_name), price(_price) {}
    virtual void displayDetails() const {
        cout << "Name: " << name << ", Price: $" << price << endl;
    }
    virtual void buy() const {
        cout << "You purchased: " << name << ", Price: $" << price << endl;
    }
};

class Book : public Product {
public:
    string author;
    string genre;
    Book(string _name, string _author, string _genre, float _price)
        : Product(_name, _price), author(_author), genre(_genre) {}
    void displayDetails() const override {
        cout << "Title: " << name << ", Author: " << author << ", Genre: " << genre << ", Price: $" << price << endl;
    }
};

class Music : public Product {
public:
    string artist;
    string genre;
    Music(string _name, string _artist, string _genre, float _price)
        : Product(_name, _price), artist(_artist), genre(_genre) {}
    void displayDetails() const override {
        cout << "Title: " << name << ", Artist: " << artist << ", Genre: " << genre << ", Price: $" << price << endl;
    }
};

class Movie : public Product {
public:
    string Director;
    string genre;
    Movie(string _name, string _Director, string _genre, float _price)
        : Product(_name, _price), Director(_Director), genre(_genre) {}
    void displayDetails() const override {
        cout << "Title: " << name << ", Director: " << Director << ", Genre: " << genre << ", Price: $" << price << endl;
    }
};

class Grocery : public Product {
public:
    string category;
    Grocery(string _name, string _category, float _price)
        : Product(_name, _price), category(_category) {}
    void displayDetails() const override {
        cout << "Name: " << name << ", Category: " << category << ", Price: $" << price << endl;
    }
    void addGrocery() {
    string name, company;
    float price;
    cout << "Enter grocery name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter company: ";
    getline(cin, company);
    cout << "Enter price: ";
    cin >> price;

    ofstream outFile("grocery.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'grocery.txt' for writing.\n";
        return;
    }
    outFile << name << ", " << company << ", " << price << endl;
    cout << "Grocery item added successfully.\n";
}

void addGroceryDeal() {
    string deal;
    cout << "Enter deal for grocery: ";
    cin.ignore();
    getline(cin, deal);

    ofstream outFile("groceryDeal.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'groceryDeal.txt' for writing.\n";
        return;
    }
    outFile << deal << endl;
    cout << "Deal added successfully for grocery.\n";
}

void displayGroceriesToBuy() {
    ifstream inFile("grocery.txt");
    if (!inFile) {
        cerr << "Unable to open file 'grocery.txt' for reading.\n";
        return;
    }

    cout << "Available Groceries:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

void buyGrocery() {
    displayGroceriesToBuy();
    string groceryName;
    cout << "Enter the name of the grocery you want to buy: ";
    cin.ignore();
    getline(cin, groceryName);

    ifstream inFile("grocery.txt");
    if (!inFile) {
        cerr << "Unable to open file 'grocery.txt' for reading.\n";
        return;
    }

    string line;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productName;
        float productPrice;

        getline(ss, productName, ',');
        ss >> productPrice;

        if (productName == groceryName) {
            found = true;
            price = productPrice; 
            break;
        }
    }

    if (found) {
        cout << "You purchased the grocery: " << groceryName << endl;
        srand(time(0));
        int deliveryTime = rand() % 7 + 1;
        cout << "Estimated Delivery Time: " << deliveryTime << " days\n";
    } 
    else {
        cout << "Error: Grocery not found.\n";
    }
}

void displayGroceryDealsToBuy() {
    ifstream inFile("groceryDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'groceryDeal.txt' for reading.\n";
        return;
    }

    cout << "Available Grocery Deals:\n";
    string line;
    int index = 1;
    while (getline(inFile, line)) {
        cout << index++ << ". " << line << endl;
    }
}

void buyGroceryDeal() {
    displayGroceryDealsToBuy();
    int dealNumber;
    cout << "Enter the deal number you want to buy: ";
    cin >> dealNumber;

    ifstream inFile("groceryDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'groceryDeal.txt' for reading.\n";
        return;
    }

    string line;
    int index = 1;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        if (index == dealNumber) {
            found = true;
            stringstream ss(line);
            ss >> price; 
            break;
        }
        index++;
    }

    if (found) {
        cout << "You purchased deal number: " << dealNumber << endl;
    } else {
        cout << "Error: Deal not found.\n";
    }
}
};

class OnlineStore : public Product {
public:
    string category;
    OnlineStore(string _name, string _category, float _price)
        : Product(_name, _price), category(_category) {}
    void displayDetails() const override {
        cout << "Name: " << name << ", Category: " << category << ", Price: $" << price << endl;
    }
};



void addBook() {
    string name, author, genre;
    float price;
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter price: ";
    cin >> price;

    ofstream outFile("book.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'book.txt' for writing.\n";
        return;
    }
    outFile << name << ", " << author << ", " << genre << ", " << price << endl;
    cout << "Book added successfully.\n";
}

void addBookDeal() {
    string deal;
    cout << "Enter deal for book: ";
    cin.ignore();
    getline(cin, deal);

    ofstream outFile("bookDeal.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'bookDeal.txt' for writing.\n";
        return;
    }
    outFile << deal << endl;
    cout << "Deal added successfully for book.\n";
}
void displayBooksToBuy() {
    ifstream inFile("book.txt");
    if (!inFile) {
        cerr << "Unable to open file 'book.txt' for reading.\n";
        return;
    }

    cout << "Available Books:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

void buyBook() {
    displayBooksToBuy();
    string bookName;
    cout << "Enter the name of the book you want to buy: ";
    cin.ignore();
    getline(cin, bookName);

    ifstream inFile("book.txt");
    if (!inFile) {
        cerr << "Unable to open file 'book.txt' for reading.\n";
        return;
    }

    string line;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productName;
        float productPrice;

        getline(ss, productName, ',');
        ss >> productPrice;

        if (productName == bookName) {
            found = true;
            price = productPrice; 
            break;
        }
    }

    if (found) {
        cout << "You purchased the book: " << bookName << endl;
        srand(time(0));
        int deliveryTime = rand() % 7 + 1;
        cout << "Estimated Delivery Time: " << deliveryTime << " days\n";
    } else {
        cout << "Error: Book not found.\n";
    }
}
void displayBookDealsToBuy() {
    ifstream inFile("bookDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'bookDeal.txt' for reading.\n";
        return;
    }

    cout << "Available Book Deals:\n";
    string line;
    int index = 1;
    while (getline(inFile, line)) {
        cout << index++ << ". " << line << endl;
    }
}
void buyBookDeal() {
    displayBookDealsToBuy();
    int dealNumber;
    cout << "Enter the deal number you want to buy: ";
    cin >> dealNumber;

    ifstream inFile("bookDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'bookDeal.txt' for reading.\n";
        return;
    }

    string line;
    int index = 1;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        if (index == dealNumber) {
            found = true;
            stringstream ss(line);
            ss >> price; 
            break;
        }
        index++;
    }

    if (found) {
        cout << "You purchased deal number: " << dealNumber << endl;
    } else {
        cout << "Error: Deal not found.\n";
    }
}



void addMusic() {
    string name, artist, genre;
    float price;
    cout << "Enter music name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter artist: ";
    getline(cin, artist);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter price: ";
    cin >> price;

    ofstream outFile("music.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'music.txt' for writing.\n";
        return;
    }
    outFile << name << ", " << artist << ", " << genre << ", " << price << endl;
    cout << "Music added successfully.\n";
}

void addMusicDeal() {
    string deal;
    cout << "Enter deal for music: ";
    cin.ignore();
    getline(cin, deal);

    ofstream outFile("musicDeal.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'musicDeal.txt' for writing.\n";
        return;
    }
    outFile << deal << endl;
    cout << "Deal added successfully for music.\n";
}
void displayMusicToBuy() {
    ifstream inFile("music.txt");
    if (!inFile) {
        cerr << "Unable to open file 'music.txt' for reading.\n";
        return;
    }

    cout << "Available Music:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

void displayMusicDealsToBuy() {
    ifstream inFile("musicDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'musicDeal.txt' for reading.\n";
        return;
    }

    cout << "Available Music Deals:\n";
    string line;
    int index = 1;
    while (getline(inFile, line)) {
        cout << index++ << ". " << line << endl;
    }
}

void buyMusic() {
    displayMusicToBuy();
    string musicName;
    cout << "Enter the name of the music you want to buy: ";
    cin.ignore();
    getline(cin, musicName);

    ifstream inFile("music.txt");
    if (!inFile) {
        cerr << "Unable to open file 'music.txt' for reading.\n";
        return;
    }

    string line;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productName;
        float productPrice;

        getline(ss, productName, ',');
        ss >> productPrice;

        if (productName == musicName) {
            found = true;
            price = productPrice; 
            break;
        }
    }

    if (found) {
        cout << "You purchased the music: " << musicName << endl;
    } else {
        cout << "Error: Music not found.\n";
    }
}


void buyMusicDeal() {
    displayMusicDealsToBuy();
    int dealNumber;
    cout << "Enter the deal number you want to buy: ";
    cin >> dealNumber;

    ifstream inFile("musicDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'musicDeal.txt' for reading.\n";
        return;
    }

    string line;
    int index = 1;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        if (index == dealNumber) {
            found = true;
            stringstream ss(line);
            ss >> price; 
            break;
        }
        index++;
    }

    if (found) {
        cout << "You purchased deal number: " << dealNumber << endl;
    } else {
        cout << "Error: Deal not found.\n";
    }
}

void addMovie() {
    string name, director, genre;
    float price;
    cout << "Enter movie name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter director: ";
    getline(cin, director);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter price: ";
    cin >> price;

    ofstream outFile("movies.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'movies.txt' for writing.\n";
        return;
    }
    outFile << name << ", " << director << ", " << genre << ", " << price << endl;
    cout << "Movie added successfully.\n";
}

void addMovieDeal() {
    string deal;
    cout << "Enter deal for movie: ";
    cin.ignore();
    getline(cin, deal);

    ofstream outFile("movieDeals.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'movieDeals.txt' for writing.\n";
        return;
    }
    outFile << deal << endl;
    cout << "Deal added successfully for movie.\n";
}

void displayMoviesToBuy() {
    ifstream inFile("movies.txt");
    if (!inFile) {
        cerr << "Unable to open file 'movies.txt' for reading.\n";
        return;
    }

    cout << "Available Movies:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

void displayMovieDealsToBuy() {
    ifstream inFile("movieDeals.txt");
    if (!inFile) {
        cerr << "Unable to open file 'movieDeals.txt' for reading.\n";
        return;
    }

    cout << "Available Movie Deals:\n";
    string line;
    int index = 1;
    while (getline(inFile, line)) {
        cout << index++ << ". " << line << endl;
    }
}

void buyMovie() {
    displayMoviesToBuy();
    string movieName;
    cout << "Enter the name of the movie you want to buy: ";
    cin.ignore();
    getline(cin, movieName);

    ifstream inFile("movies.txt");
    if (!inFile) {
        cerr << "Unable to open file 'movies.txt' for reading.\n";
        return;
    }

    string line;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productName;
        float productPrice;

        getline(ss, productName, ',');
        ss >> productPrice;

        if (productName == movieName) {
            found = true;
            price = productPrice; 
            break;
        }
    }

    if (found) {
        cout << "You purchased the movie: " << movieName << endl;
    } else {
        cout << "Error: Movie not found.\n";
    }
}

void buyMovieDeal() {
    displayMovieDealsToBuy();
    int dealNumber;
    cout << "Enter the deal number you want to buy: ";
    cin >> dealNumber;

    ifstream inFile("movieDeals.txt");
    if (!inFile) {
        cerr << "Unable to open file 'movieDeals.txt' for reading.\n";
        return;
    }

    string line;
    int index = 1;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        if (index == dealNumber) {
            found = true;
            stringstream ss(line);
            ss >> price; 
            break;
        }
        index++;
    }

    if (found) {
        cout << "You purchased deal number: " << dealNumber << endl;
    } else {
        cout << "Error: Deal not found.\n";
    }
}

void addGrocery() {
    string name, company;
    float price;
    cout << "Enter grocery name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter company: ";
    getline(cin, company);
    cout << "Enter price: ";
    cin >> price;

    ofstream outFile("grocery.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'grocery.txt' for writing.\n";
        return;
    }
    outFile << name << ", " << company << ", " << price << endl;
    cout << "Grocery item added successfully.\n";
}

void addGroceryDeal() {
    string deal;
    cout << "Enter deal for grocery: ";
    cin.ignore();
    getline(cin, deal);

    ofstream outFile("groceryDeal.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'groceryDeal.txt' for writing.\n";
        return;
    }
    outFile << deal << endl;
    cout << "Deal added successfully for grocery.\n";
}

void displayGroceriesToBuy() {
    ifstream inFile("grocery.txt");
    if (!inFile) {
        cerr << "Unable to open file 'grocery.txt' for reading.\n";
        return;
    }

    cout << "Available Groceries:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

void buyGrocery() {
    displayGroceriesToBuy();
    string groceryName;
    cout << "Enter the name of the grocery you want to buy: ";
    cin.ignore();
    getline(cin, groceryName);

    ifstream inFile("grocery.txt");
    if (!inFile) {
        cerr << "Unable to open file 'grocery.txt' for reading.\n";
        return;
    }

    string line;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productName;
        float productPrice;

        getline(ss, productName, ',');
        ss >> productPrice;

        if (productName == groceryName) {
            found = true;
            price = productPrice; 
            break;
        }
    }

    if (found) {
        cout << "You purchased the grocery: " << groceryName << endl;
        srand(time(0));
        int deliveryTime = rand() % 7 + 1;
        cout << "Estimated Delivery Time: " << deliveryTime << " days\n";
    } 
    else {
        cout << "Error: Grocery not found.\n";
    }
}

void displayGroceryDealsToBuy() {
    ifstream inFile("groceryDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'groceryDeal.txt' for reading.\n";
        return;
    }

    cout << "Available Grocery Deals:\n";
    string line;
    int index = 1;
    while (getline(inFile, line)) {
        cout << index++ << ". " << line << endl;
    }
}

void buyGroceryDeal() {
    displayGroceryDealsToBuy();
    int dealNumber;
    cout << "Enter the deal number you want to buy: ";
    cin >> dealNumber;

    ifstream inFile("groceryDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'groceryDeal.txt' for reading.\n";
        return;
    }

    string line;
    int index = 1;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        if (index == dealNumber) {
            found = true;
            stringstream ss(line);
            ss >> price; 
            break;
        }
        index++;
    }

    if (found) {
        cout << "You purchased deal number: " << dealNumber << endl;
    } else {
        cout << "Error: Deal not found.\n";
    }
}

void addItem() {
    string name, category,brand;
    float price;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter category: ";
    getline(cin, category);
    cout << "Enter Brand: ";
    getline(cin,brand);
    cout << "Enter price: ";
    cin >> price;

    ofstream outFile("item.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'item.txt' for writing.\n";
        return;
    }
    outFile << name << ", " << category << ", " << brand << "," << price << endl;
    cout << "Item added successfully.\n";
}

void addItemDeal() {
    string deal;
    cout << "Enter deal for item: ";
    cin.ignore();
    getline(cin, deal);

    ofstream outFile("itemDeal.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'itemDeal.txt' for writing.\n";
        return;
    }
    outFile << deal << endl;
    cout << "Deal added successfully for item.\n";
}

void displayItemsToBuy() {
    ifstream inFile("item.txt");
    if (!inFile) {
        cerr << "Unable to open file 'item.txt' for reading.\n";
        return;
    }

    cout << "Available Items:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

void buyItem() {
    displayItemsToBuy();
    string itemName;
    cout << "Enter the name of the item you want to buy: ";
    cin.ignore();
    getline(cin, itemName);

    ifstream inFile("item.txt");
    if (!inFile) {
        cerr << "Unable to open file 'item.txt' for reading.\n";
        return;
    }

    string line;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productName;
        float productPrice;

        getline(ss, productName, ',');
        ss >> productPrice;

        if (productName == itemName) {
            found = true;
            price = productPrice; 
            break;
        }
    }

    if (found) {
        cout << "You purchased the item: " << itemName << endl;
        srand(time(0));
        int deliveryTime = rand() % 7 + 1;
        cout << "Estimated Delivery Time: " << deliveryTime << " days\n";
    } 
    else {
        cout << "Error: Item not found.\n";
    }
}

void displayItemDealsToBuy() {
    ifstream inFile("itemDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'itemDeal.txt' for reading.\n";
        return;
    }

    cout << "Available Item Deals:\n";
    string line;
    int index = 1;
    while (getline(inFile, line)) {
        cout << index++ << ". " << line << endl;
    }
}

void buyItemDeal() {
    displayItemDealsToBuy();
    int dealNumber;
    cout << "Enter the deal number you want to buy: ";
    cin >> dealNumber;

    ifstream inFile("itemDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'itemDeal.txt' for reading.\n";
        return;
    }

    string line;
    int index = 1;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        if (index == dealNumber) {
            found = true;
            stringstream ss(line);
            ss >> price; 
            break;
        }
        index++;
    }

    if (found) {
        cout << "You purchased deal number: " << dealNumber << endl;
    } else {
        cout << "Error: Deal not found.\n";
    }
}


void saveUserInfo(const string& email, const string& password) {
    ofstream outFile("info.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'info.txt' for writing.\n";
        return;
    }
    outFile << email << " " << password << endl;
}

bool checkLogin(const string& email, const string& password) {
    ifstream inFile("info.txt");
    if (!inFile) {
        cerr << "Unable to open file 'info.txt' for reading.\n";
        return false;
    }

    string storedEmail, storedPassword;
    while (inFile >> storedEmail >> storedPassword) {
        if (email == storedEmail && password == storedPassword) {
            return true;
        }
    }

    return false;
}
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setBackgroundColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD attributes = consoleInfo.wAttributes;
    attributes &= 0xFFF0; 
    attributes |= color; 

    SetConsoleTextAttribute(hConsole, attributes);
    COORD bufferSize = {consoleInfo.dwSize.X, consoleInfo.dwSize.Y};
    DWORD numCells = bufferSize.X * bufferSize.Y;
    COORD topLeft = {0, 0};
    DWORD numWritten;
    FillConsoleOutputAttribute(hConsole, attributes, numCells, topLeft, &numWritten);
}


class Player {
private:
    std::string name;
    int rupees;

public:
    Player(std::string n) : name(n), rupees(0) {}

    std::string getName() const {
        return name;
    }

    int getRupees() const {
        return rupees;
    }

    void addRupees(int amount) {
        rupees += amount;
    }

    void deductRupees(int amount) {
        rupees -= amount;
    }
};

class Game {
public:
    virtual void play(Player& player) = 0;
};

class Hangman : public Game {
private:
    void display_misses(int misses) {
    if (misses == 0 || misses == 1)
    {
        std::cout << "                 .                            \n";
        std::cout << "                 |                            \n";
        std::cout << "              .-\"^\"-.                       \n";
        std::cout << "             /_....._\\                       \n";
        std::cout << "         .-\"`         `\"-.                  \n";
        std::cout << "        (  ooo  ooo  ooo  )                   \n";
        std::cout << "         '-.,_________,.-'    ,-----------.   \n";
        std::cout << "              /     \\        (  Send help! ) \n";
        std::cout << "             /   0   \\      / `-----------'  \n";
        std::cout << "            /  --|--  \\    /                 \n";
        std::cout << "           /     |     \\                     \n";
        std::cout << "          /     / \\     \\                   \n";
        std::cout << "         /               \\                   \n";
    }
    else if (misses == 2)
    {
        std::cout << "                 .                            \n";
        std::cout << "                 |                            \n";
        std::cout << "              .-\"^\"-.                       \n";
        std::cout << "             /_....._\\                       \n";
        std::cout << "         .-\"`         `\"-.                  \n";
        std::cout << "        (  ooo  ooo  ooo  )                   \n";
        std::cout << "         '-.,_________,.-'    ,-----------.   \n";
        std::cout << "              /  0  \\        (  Send help! ) \n";
        std::cout << "             / --|-- \\      / `-----------'  \n";
        std::cout << "            /    |    \\    /                 \n";
        std::cout << "           /    / \\    \\                    \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
    }
    else if (misses == 3)
    {
        std::cout << "                 .                            \n";
        std::cout << "                 |                            \n";
        std::cout << "              .-\"^\"-.                       \n";
        std::cout << "             /_....._\\                       \n";
        std::cout << "         .-\"`         `\"-.                  \n";
        std::cout << "        (  ooo  ooo  ooo  )                   \n";
        std::cout << "         '-.,_________,.-'    ,-----------.   \n";
        std::cout << "              /--|--\\        (  Send help! ) \n";
        std::cout << "             /   |   \\      / `-----------'  \n";
        std::cout << "            /   / \\   \\    /                \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
    }
    else if (misses == 4)
    {
        std::cout << "                 .                            \n";
        std::cout << "                 |                            \n";
        std::cout << "              .-\"^\"-.                       \n";
        std::cout << "             /_....._\\                       \n";
        std::cout << "         .-\"`         `\"-.                  \n";
        std::cout << "        (  ooo  ooo  ooo  )                   \n";
        std::cout << "         '-.,_________,.-'    ,-----------.   \n";
        std::cout << "              /  |  \\        (  Send help! ) \n";
        std::cout << "             /  / \\  \\      / `-----------' \n";
        std::cout << "            /         \\    /                 \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
    }
    else if (misses == 5)
    {
        std::cout << "                 .                            \n";
        std::cout << "                 |                            \n";
        std::cout << "              .-\"^\"-.                       \n";
        std::cout << "             /_....._\\                       \n";
        std::cout << "         .-\"`         `\"-.                  \n";
        std::cout << "        (  ooo  ooo  ooo  )                   \n";
        std::cout << "         '-.,_________,.-'    ,-----------.   \n";
        std::cout << "              / / \\ \\        (  Send help! )\n";
        std::cout << "             /       \\      / `-----------'  \n";
        std::cout << "            /         \\    /                 \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
    }
    else if (misses == 6)
    {
        std::cout << "                 .                            \n";
        std::cout << "                 |                            \n";
        std::cout << "              .-\"^\"-.                       \n";
        std::cout << "             /_....._\\                       \n";
        std::cout << "         .-\"`         `\"-.                  \n";
        std::cout << "        (  ooo  ooo  ooo  )                   \n";
        std::cout << "         '-.,_________,.-'    ,-----------.   \n";
        std::cout << "              /     \\        (  Send help! ) \n";
        std::cout << "             /       \\      / `-----------'  \n";
        std::cout << "            /         \\    /                 \n";
        std::cout << "           /           \\                     \n";
        std::cout << "          /             \\                    \n";
        std::cout << "         /               \\                   \n";
    }
}

    

public:
    void play(Player& player) override {
        std::string codeword = "MAAZ";
        std::string answer(codeword.length(), '-');
        std::vector<char> incorrectGuesses;
        int maxAttempts = 6;
        int attempts = 0;

        std::cout << "Welcome to Hangman!\n";
        std::cout << "Try to guess the word by entering one letter at a time.\n";

        while (attempts < maxAttempts && answer != codeword) {
            std::cout << "\nCurrent word: " << answer << "\n";
            std::cout << "Incorrect guesses: ";
            for (char letter : incorrectGuesses) {
                std::cout << letter << " ";
            }
            std::cout << "\nAttempts remaining: " << maxAttempts - attempts << "\n";
            std::cout << "Enter your guess: ";
            char guess;
            std::cin >> guess;

            if (codeword.find(guess) != std::string::npos) {
                std::cout << "Correct guess!\n";
                for (int i = 0; i < codeword.length(); ++i) {
                    if (codeword[i] == guess) {
                        answer[i] = guess;
                    }
                }
            } else {
                std::cout << "Incorrect guess!\n";
                incorrectGuesses.push_back(guess);
                ++attempts;
                display_misses(attempts);
            }
        }

        if (answer == codeword) {
            std::cout << "Congratulations! You guessed the word: " << codeword << "\n";
        } else {
            std::cout << "Sorry, you've run out of attempts. The word was: " << codeword << "\n";
        }
    }
};

class TicTacToe : public Game {
public:
    void play(Player& player) override {
        char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        int currentPlayer = 1;
        int row, col;
        bool win = false;
        bool draw = false;

        std::cout << "Welcome to Tic Tac Toe!\n";
        std::cout << "Player 1: X, Player 2: O\n";

        for (int turn = 0; turn < 9 && !win && !draw; ++turn) {
            std::cout << "Current board:\n";
            displayBoard(board);

            std::cout << "Player " << currentPlayer << ", enter your move (row col): ";
            std::cin >> row >> col;

            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                std::cout << "Invalid move! Try again.\n";
                --turn;
                continue;
            }

            board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
            win = checkWin(board);
            draw = checkDraw(board);
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
        int previousPlayer = 0;

        std::cout << "Final board:\n";
        displayBoard(board);
        if(currentPlayer == 1){
        	previousPlayer = 2;
		}
		if(currentPlayer == 2){
			previousPlayer = 1;
		}
        if (win) {
            std::cout << "Player " << previousPlayer << " wins!\n";
        } else if (draw) {
            std::cout << "It's a draw!\n";
        }
    }

private:
    void displayBoard(char board[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << "|";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "-+-+-" << std::endl;
        }
    }

    bool checkWin(char board[3][3]) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) return true;
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) return true;
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) return true;

        return false;
    }

    bool checkDraw(char board[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false; 
                }
            }
        }
        return true; 
    }
};

class RockPaperScissors : public Game {
public:
    void play(Player& player) override {
        std::cout << "Welcome to Rock Paper Scissors!\n";
        std::cout << "Enter your choice (rock, paper, scissors): ";
        std::string choices[3] = {"rock", "paper", "scissors"};
        std::string playerChoice;
        std::cin >> playerChoice;
        std::cout << "You chose: " << playerChoice << "\n";

        srand(time(0));
        int computerIndex = rand() % 3;
        std::string computerChoice = choices[computerIndex];
        std::cout << "Computer chose: " << computerChoice << "\n";

        if (playerChoice == computerChoice) {
            std::cout << "It's a tie!\n";
        } else if ((playerChoice == "rock" && computerChoice == "scissors") ||
                   (playerChoice == "paper" && computerChoice == "rock") ||
                   (playerChoice == "scissors" && computerChoice == "paper")) {
            std::cout << "Congratulations! You win!\n";
        } else {
            std::cout << "Sorry, you lose!\n";
        }
    }
};

class MemoryGame : public Game {
public:
    void play(Player& player) override {
        std::cout << "Welcome to Memory Game!\n";
        std::cout << "Enter 10 words separated by spaces: ";
        std::string input1, input2;
        for (int i = 0; i < 10; ++i) {
            std::cin >> input1;
        }
        std::cout << "Now enter the same 10 words in the same order: ";
        for (int i = 0; i < 10; ++i) {
            std::cin >> input2;
        }

        if (input1 == input2) {
            std::cout << "Congratulations! You win!\n";
        } else {
            std::cout << "Sorry, you lose!\n";
        }
    }
};

class GameShop {
public:
	void addGame() {
    string name, company, genre;
    float price;
    cout << "Enter game name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter Company: ";
    cin >> company;
    cout << "Enter genre: ";
    cin >> genre;
    cout << "Enter price: ";
    cin >> price;

    ofstream outFile("game.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'game.txt' for writing.\n";
        return;
    }
    outFile << name << ", " << company << ", " << genre << ", " << price << endl;
    cout << "Game added successfully.\n";
}
void addGameDeal() {
    string deal;
    cout << "Enter deal for item: ";
    cin.ignore();
    getline(cin, deal);

    ofstream outFile("gameDeal.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file 'gameDeal.txt' for writing.\n";
        return;
    }
    outFile << deal << endl;
    cout << "Deal added successfully for game.\n";
}

void displayGamesToBuy() {
    ifstream inFile("game.txt");
    if (!inFile) {
        cerr << "Unable to open file 'game.txt' for reading.\n";
        return;
    }

    cout << "Available Games:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}
    void buyGame() {
    displayGamesToBuy();
    string gameName;
    cout << "Enter the name of the game you want to buy: ";
    cin.ignore();
    getline(cin,gameName);

    ifstream inFile("game.txt");
    if (!inFile) {
        cerr << "Unable to open file 'game.txt' for reading.\n";
        return;
    }

    string line;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        stringstream ss(line);
        string productName;
        float productPrice;

        getline(ss, productName, ',');
        ss >> productPrice;

        if (productName == gameName) {
            found = true;
            price = productPrice; 
            break;
        }
    }

    if (found) {
        cout << "You purchased the game: " << gameName << endl;
    }
    else {
        cout << "Error: Game not found.\n";
    }
}
void displayGamesDealsToBuy() {
    ifstream inFile("gameDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'gameDeal.txt' for reading.\n";
        return;
    }

    cout << "Available Game Deals:\n";
    string line;
    int index = 1;
    while (getline(inFile, line)) {
        cout << index++ << ". " << line << endl;
    }
}

void buyGameDeal() {
    displayGamesDealsToBuy();
    int dealNumber;
    cout << "Enter the deal number you want to buy: ";
    cin >> dealNumber;

    ifstream inFile("gameDeal.txt");
    if (!inFile) {
        cerr << "Unable to open file 'gameDeal.txt' for reading.\n";
        return;
    }

    string line;
    int index = 1;
    bool found = false;
    float price = 0.0; 
    while (getline(inFile, line)) {
        if (index == dealNumber) {
            found = true;
            stringstream ss(line);
            ss >> price; 
            break;
        }
        index++;
    }

    if (found) {
        cout << "You purchased deal number: " << dealNumber << endl;
    } else {
        cout << "Error: Deal not found.\n";
    }
}


public:
void playGameMenu() {
	string playerName;
                           cout << "Enter your name: ";
                             cin >> playerName;
                            Player player(playerName);
    std::cout << "Select a game to play:\n";
    std::cout << "1. Hangman\n";
    std::cout << "2. Tic Tac Toe\n";
    std::cout << "3. Rock Paper Scissors\n";
    std::cout << "4. Memory Game\n";
    std::cout << "> ";
    int choice;
    std::cin >> choice;

    Game* game = nullptr;

    switch (choice) {
        case 1:
            game = new Hangman();
            break;
        case 2:
            game = new TicTacToe();
            break;
        case 3:
            game = new RockPaperScissors();
            break;
        case 4:
            game = new MemoryGame();
            break;
        default:
            std::cout << "Invalid choice.\n";
            return;
    }

    if (game) {
        game->play(player);
        delete game;
    }
}
};

int main() {
                           
    GameShop shop;
    int userType;
    string email, password;
    const string adminCode = "admin123";

    setBackgroundColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    std::cout << "\n\n\n\n\n\n\n\t\t\t\t\t- - - - MULTIPURPOSE ONLINE SHOPPING STORE - - - - -\n\n\n\n\n\n\n";
    Sleep(1000);
    system("cls");
    setBackgroundColor(BACKGROUND_GREEN | BACKGROUND_BLUE);
    system("cls");
    std::cout << "\n\n\n\n\t\t\t\tGroup Members:\n\n";
    std::cout << "\t\t\tMuhammad Maaz Nizami (23k-2052)\n";
    std::cout << "\t\t\tMuhammad Tamseel Khanzada (23k-2063)\n";
    Sleep(1000);
    system("cls");

    setBackgroundColor(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

    do {
        cout << "\n\n\n\n\t\t\t\tSelect user type:\n\n";
        cout << "\t\t\t1. Buyer\n";
        cout << "\t\t\t2. Admin\n";
        cout << "\t\t\t3. Exit\n";
        cout << "\t\t\tEnter your choice: ";
        cin >> userType;
        Sleep(1000);
        system("cls");

        if (userType == 1) {
            cout << "\n\n\n\n\t\t\t\tBuyer Options:\n\n";
            cout << "\t\t\t1. Sign Up\n";
            cout << "\t\t\t2. Login\n";
            cout << "\t\t\tEnter your choice: ";
            int choice;
            cin >> choice;
            Sleep(1000);
            system("cls");
            if (choice == 1) {
                cout << "\n\n\n\n\t\t\t\tSign Up\n";
                cout << "\t\t\tEnter your name: ";
                string name;
                cin >> name;
                cout << "\t\t\tEnter your email address: ";
                cin >> email;
                cout << "\t\t\tEnter your password: ";
                cin >> password;
                string confirmPassword;
                cout << "\t\t\tConfirm password: ";
                cin >> confirmPassword;
                if (password == confirmPassword) {
                    saveUserInfo(email, password);
                    cout << "\n\n\n\n\t\t\t\tSignup successful. Please login.\n";
                    Sleep(1000);
                    system("cls");
                } else {
                    cout << "\n\n\n\n\t\t\t\tPassword and Confirm Password do not match.\n";
                    Sleep(1000);
                    system("cls");
                }
            } else if (choice == 2) {
                cout << "\n\n\n\n\t\t\t\tLogin\n";
                do {
                    cout << "\t\t\tEnter your email address: ";
                    cin >> email;
                    cout << "\t\t\tEnter your password: ";
                    cin >> password;
                    if (!checkLogin(email, password)) {
                        cout << "\n\n\n\n\t\t\t\tEmail address or password is incorrect. Please try again.\n";
                        Sleep(1000);
                        system("cls");
                    }
                } while (!checkLogin(email, password));
                cout << "\n\n\n\n\t\t\t\tLogin successful.\n";
                Sleep(1000);
                system("cls");

                int productType;
                do {
                    cout << "\n\n\n\n\t\t\t\tSelect product type to buy:\n\n";
                    cout << "\t\t\t1. Book\n";
                    cout << "\t\t\t2. Music\n";
                    cout << "\t\t\t3. Movie\n";
                    cout << "\t\t\t4. Grocery\n";
                    cout << "\t\t\t5. Item\n";
                    cout << "\t\t\t6. Game store\n";
                    cout << "\t\t\t7. Exit\n";
                    cout << "\t\t\tEnter your choice: ";
                    cin >> productType;
                    Sleep(1000);
                    system("cls");

                    switch (productType) {
                        case 1:
                            cout << "\n\n\n\n\t\t\t\tBook Options:\n\n";
                            cout << "\t\t\t1. Buy a book\n";
                            cout << "\t\t\t2. Buy a book deal\n";
                            cout << "\t\t\tEnter your choice: ";
                            int bookChoice;
                            cin >> bookChoice;
                            Sleep(1000);
                            system("cls");
                            if (bookChoice == 1) {
                                buyBook();
                                Sleep(2000);
                                system("cls");
                            } else if (bookChoice == 2) {
                                buyBookDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 2:
                            cout << "\n\n\n\n\t\t\t\tMusic Options:\n\n";
                            cout << "\t\t\t1. Buy music\n";
                            cout << "\t\t\t2. Buy a music deal\n";
                            cout << "\t\t\tEnter your choice: ";
                            int musicChoice;
                            cin >> musicChoice;
                            Sleep(1000);
                            system("cls");
                            if (musicChoice == 1) {
                                buyMusic();
                                 Sleep(2000);
                                system("cls");
                            } else if (musicChoice == 2) {
                                buyMusicDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 3:
                            cout << "\n\n\n\n\t\t\t\tMovie Options:\n\n";
                            cout << "\t\t\t1. Buy a movie\n";
                            cout << "\t\t\t2. Buy a movie deal\n";
                            cout << "\t\t\tEnter your choice: ";
                            int movieChoice;
                            cin >> movieChoice;
                            Sleep(1000);
                            system("cls");
                            if (movieChoice == 1) {
                                buyMovie();
                                 Sleep(2000);
                                system("cls");
                            } else if (movieChoice == 2) {
                                buyMovieDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 4:
                            cout << "\n\n\n\n\t\t\t\tGrocery Options:\n\n";
                            cout << "\t\t\t1. Buy grocery\n";
                            cout << "\t\t\t2. Buy a grocery deal\n";
                            cout << "\t\t\tEnter your choice: ";
                            int groceryChoice;
                            cin >> groceryChoice;
                            Sleep(1000);
                            system("cls");
                            if (groceryChoice == 1) {
                                buyGrocery();
                                 Sleep(2000);
                                system("cls");
                            } else if (groceryChoice == 2) {
                                buyGroceryDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 5:
                            cout << "\n\n\n\n\t\t\t\tItem Options:\n\n";
                            cout << "\t\t\t1. Buy item\n";
                            cout << "\t\t\t2. Buy an item deal\n";
                            cout << "\t\t\tEnter your choice: ";
                            int itemChoice;
                            cin >> itemChoice;
                            Sleep(1000);
                            system("cls");
                            if (itemChoice == 1) {
                                buyItem();
                                Sleep(2000); 
                                system("cls");
                            } else if (itemChoice == 2) {
                                buyItemDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 6:
                            cout << "\n\n\n\n\t\t\t\tGame Store Options:\n\n";
                            cout << "\t\t\t1. Buy a game\n";
                            cout << "\t\t\t2. Buy Game Deal\n";
                            cout << "\t\t\t3. Play a game\n";
                            cout << "\t\t\tEnter your choice: ";
                            int gameChoice;
                            cin >> gameChoice;
                            Sleep(1000);
                            system("cls");
                            if (gameChoice == 1) {
                                shop.buyGame();
                                 Sleep(2000);
                                system("cls");
                            }  if (gameChoice == 2) {
                                shop.buyGameDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            else if(gameChoice == 3){
                            	shop.playGameMenu();
                            	 Sleep(2000);
                            	system("cls");
							}
                            break;
                        case 7:
                            cout << "\n\n\n\n\t\t\t\tExiting...\n";
                            break;
                        default:
                            cout << "\n\n\n\n\t\t\t\tInvalid choice. Please try again.\n";
                            break;
                    }
                } while (productType != 7);
            } else {
                cout << "\n\n\n\n\t\t\t\tInvalid choice. Please try again.\n";
            }
        } else if (userType == 2) {
            string code;
            cout << "\n\n\n\n\t\t\t\tEnter admin code: ";
            cin >> code;
            if (code == adminCode) {
                cout << "\n\n\n\n\t\t\t\tAdmin Login successful.\n";
                Sleep(1000);
                system("cls");

                int productType;
                do {
                    cout << "\n\n\n\n\t\t\t\tSelect product type to add:\n\n";
                    cout << "\t\t\t1. Book\n";
                    cout << "\t\t\t2. Music\n";
                    cout << "\t\t\t3. Movie\n";
                    cout << "\t\t\t4. Grocery\n";
                    cout << "\t\t\t5. Item\n";
                    cout << "\t\t\t6. Game\n";
                    cout << "\t\t\t7. Exit\n";
                    cout << "\t\t\tEnter your choice: ";
                    cin >> productType;
                    Sleep(1000);
                    system("cls");

                    switch (productType) {
                        case 1:
                            cout << "\n\n\n\n\t\t\t\tAdmin: Add Book Options:\n\n";
                            cout << "\t\t\t1. Add Book\n";
                            cout << "\t\t\t2. Add Book Deal\n";
                            int bookAddChoice;
                            cin >> bookAddChoice;
                            if (bookAddChoice == 1) {
                                addBook();
                                 Sleep(2000);
                                system("cls");
						 } else if (bookAddChoice == 2) {
                                displayBooksToBuy();
                                addBookDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 2:
                             cout << "\n\n\n\n\t\t\t\tAdmin: Add Music Options:\n\n";
                            cout << "\t\t\t1. Add Music\n";
                            cout << "\t\t\t2. Add Music Deal\n";
                            int musicAddChoice;
                            cin >> musicAddChoice;
                            if (musicAddChoice == 1) {
                                addMusic();
                                 Sleep(2000);
                                system("cls");
                            } else if (musicAddChoice == 2) {
                                displayMusicToBuy();
                                addMusicDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 3:
                            cout << "\n\n\n\n\t\t\t\tAdmin: Add Movie Options:\n\n";
                            cout << "\t\t\t1. Add Movie\n";
                            cout << "\t\t\t2. Add Movie Deal\n";
                            int movieAddChoice;
                            cin >> movieAddChoice;
                            if (movieAddChoice == 1) {
                                addMovie();
                                 Sleep(2000);
                                system("cls");
                            } else if (movieAddChoice == 2) {
                                displayMoviesToBuy();
                                addMovieDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 4:
                            cout << "\n\n\n\n\t\t\t\tAdmin: Add Grocery Options:\n\n";
                            cout << "\t\t\t1. Add Grocery\n";
                            cout << "\t\t\t2. Add Grocery Deal\n";
                            int groceryAddChoice;
                            cin >> groceryAddChoice;
                            if (groceryAddChoice == 1) {
                                addGrocery();
                                 Sleep(2000);
                                system("cls");
                            } else if (groceryAddChoice == 2) {
                                displayGroceriesToBuy();
                                addGroceryDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 5:
                            cout << "\n\n\n\n\t\t\t\tAdmin: Add Item Options:\n\n";
                            cout << "\t\t\t1. Add Item\n";
                            cout << "\t\t\t2. Add Item Deal\n";
                            int itemAddChoice;
                            cin >> itemAddChoice;
                            if (itemAddChoice == 1) {
                                addItem();
                                 Sleep(2000);
                                system("cls");
                            } else if (itemAddChoice == 2) {
                                displayItemsToBuy();
                                addItemDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                            case 6:
                            	cout << "\n\n\n\n\t\t\t\tAdmin: Add Game Options:\n\n";
                            cout << "\t\t\t1. Add Game To Buy\n";
                            cout << "\t\t\t2. Add Game Deal to Buy\n";
                            int gameAddChoice;
                            cin >> gameAddChoice;
                            if (gameAddChoice == 1) {
                                shop.addGame();
                                 Sleep(2000);
                                system("cls");
                            } else if (gameAddChoice == 2) {
                                shop.displayGamesToBuy();
                                shop.addGameDeal();
                                 Sleep(2000);
                                system("cls");
                            }
                            break;
                        case 7:
                            cout << "\n\n\n\n\t\t\t\tExiting...\n";
                            break;
                        default:
                            cout << "\n\n\n\n\t\t\t\tInvalid choice. Please try again.\n";
                            break;
                    }
                } while (productType != 7);
            } else {
                cout << "\n\n\n\n\t\t\t\tInvalid admin code. Please try again.\n";
            }
        } else if (userType == 3) {
            cout << "\n\n\n\n\t\t\t\tExiting...\n";
        } else {
            cout << "\n\n\n\n\t\t\t\tInvalid choice. Please try again.\n";
        }
    } while (userType != 3);

    return 0;
}
