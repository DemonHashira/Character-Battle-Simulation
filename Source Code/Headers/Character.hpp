#ifndef Character_hpp
#define Character_hpp

#include <string>

// Header file for the main abstract class Character
class Character {
protected:
    // Default data fields for all characters
    std::string name;
    std::string specialAbility;
    int strength;
    int constitution;
    int dexterity;
    int intelligence;
    int wisdom;
    int charisma;

public:
    // Seven parameter constructor
    Character(const std::string& name, const std::string& specialAbility, int strength, int constitution, int dexterity,
              int intelligence, int wisdom, int charisma);
    
    // Pure virtual destructor
    virtual ~Character() = 0;

    // Getters for the data fields
    std::string GetName() const;
    std::string GetSpecialAbility() const;
    int GetStrength() const;
    int GetConstitution() const;
    int GetDexterity() const;
    int GetIntelligence() const;
    int GetWisdom() const;
    int GetCharisma() const;

    // Setters for the data fields
    void SetName(const std::string& name);
    void SetSpecialAbility(const std::string& specialAbility);
    void SetStrength(int strength);
    void SetDexterity(int dexterity);
    void SetConstitution(int constitution);
    void SetIntelligence(int intelligence);
    void SetWisdom(int wisdom);
    void SetCharisma(int charisma);

    // Pure virtual function DPS that will be used to determine the winner
    virtual int DPS() = 0;
    // Pure virtual function for special ability that will add DPS depending on the character
    virtual double SpecialAbility() = 0;
    // Pure virtual function for displaying the special ability
    virtual std::string SpecialAbilityName() = 0;
};

#endif /* Character_hpp */
