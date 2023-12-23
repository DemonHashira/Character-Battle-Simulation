#ifndef Character_h
#define Character_h

// Header file for the main class Character
class Character {
protected:
    // Default data fields for all characters
    std::string Name;
    double strength;
    double constitution;
    double dexterity;
    double intelligence;
    double wisdom;
    double charisma;
    
public:
    // Seven parameter constructor
    Character(const std::string& name, double constitution, double dexterity,
              double intelligence, double wisdom, double charisma);
    
    // Getters for the data fields
    std::string GetName() const;
    double GetStrength() const;
    double GetConstitution() const;
    double GetDexterity() const;
    double GetIntelligence() const;
    double GetWisdom() const;
    double GetCharisma() const;
    
    // Setters for the data fields
    void SetName(const std::string& name);
    void SetStrength(double strength);
    void SetConstitution(double constitution);
    void SetWisdom(double wisdom);
    void SetCharisma(double charisma);
    
    // Pure virtual function DPS that will be used to determine the winner
    virtual double DPS() = 0;
    // Pure virtual function for special ability that will add dps depending on the character
    virtual double SpecialAbility() = 0;
    // Pure virtual function for displaying the special ability
    virtual std::string SpecialAbilityName() = 0;
};

#endif /* Character_h */
