// Started at 9:34 6-1-2022

// Section 13
// Copy Constructor - Deep Copy
#include <iostream>

using namespace std;

class Deep {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::Deep(const Deep &source) 
    : Deep {*source.data} {
        cout << "Copy Constructor - deep copy" << endl;
}
    
Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(Deep s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Deep obj1 {100};
    display_deep(obj1);
    
    Deep obj2 {obj1};
    
    obj2.set_data_value(1000);
    
    return 0;
}

// Section 13
// Move Constructor 
#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    Move(Move &&source) noexcept;
    // Destructor
    ~Move();
};

 Move::Move(int d)  {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy ctor
Move::Move(const Move &source)
    : Move {*source.data} {
        cout << "Copy constructor  - deep copy for: " << *data << endl;
}

//Move ctor
Move::Move(Move &&source) noexcept 
    : data {source.data} {
        source.data = nullptr;
        cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main() {
    vector<Move> vec;

    vec.push_back(Move{10});

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});


    return 0;
}


// Section 13
// Using const in classes
#include <iostream>
#include <string>

using namespace std; 

class Player 
{
private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() const {
        return name;
    }
    void set_name(std::string name_val) {
        name = name_val;
    }
    // Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player {"None", 0,0} {        
}

Player::Player(std::string name_val) 
    : Player {name_val,0,0} {
}

Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {        
}

void display_player_name(const Player &p) {
    cout << p.get_name() << endl;
}

int main() {
    
    const Player villain {"Villain", 100, 55};
    Player hero {"Hero", 100, 15};

//    villain.set_name("Super villain");
    cout << villain.get_name() << endl;
    cout << hero.get_name() << endl;
    
    display_player_name(villain);
    display_player_name(hero);
    
    return 0;
}


// Ended at 12:38 6-1-2022
