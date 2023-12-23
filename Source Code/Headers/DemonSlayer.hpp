#ifndef DemonSlayer_hpp
#define DemonSlayer_hpp

#include "../Headers/Protagonist.hpp"

// Header file for the Demon Slayer class
// publicly inheriting Protagonist
class DemonSlayer : public Protagonist {
protected:
    // Additional data field specific to Demon Slayer
    int demonSlayerMark;

public:
    // Constructor with inherited values from Character and Protagonist
    DemonSlayer(const std::string& name, const std::string& specialAbility, int strength, int constitution,
                int dexterity, int intelligence, int wisdom, int charisma, int holyAura,
                int reputation, int demonSlayerMark);

    // Getter for the data field
    int GetDemonSlayerMark() const;

    // Setter for the data field
    void SetDemonSlayerMark(int demonSlayerMark);

    // Concrete implementations for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;
};

#endif /* DemonSlayer_hpp */
