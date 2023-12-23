#include <iostream>
#include "../Source Code/Headers/Character.hpp"
#include "../Source Code/Headers/Antagonist.hpp"
#include "../Source Code/Headers/Protagonist.hpp"
#include "../Source Code/Headers/DemonSlayer.hpp"
#include "../Source Code/Headers/Sorcerer.hpp"
#include "../Source Code/Headers/SoulRipper.hpp"
#include "../Source Code/Headers/CursedSpirit.hpp"
#include "../Source Code/Headers/Hollow.hpp"
#include "../Source Code/Headers/Demon.hpp"

// Defining functions to test each class
void testCharacter() {
    std::cout << "Character, this an abstract class - cannot be instantiated" << std::endl;
}

void testProtagonist() {
    Protagonist protagonist("Protagonist", "Shield Wall", 10, 10, 10, 10, 10, 10, 5, 100);
    std::cout << "Protagonist DPS: " << protagonist.DPS() << std::endl;
    std::cout << "Protagonist Special Ability: " << protagonist.SpecialAbility() << std::endl;
    std::cout << "Protagonist Special Ability Name: " << protagonist.SpecialAbilityName() << std::endl;
}

void testAntagonist() {
    Antagonist antagonist("Antagonist", "Dark Wave", 13, 11, 12, 145, 102, 30, 50, 10);
    std::cout << "Antagonist DPS: " << antagonist.DPS() << std::endl;
    std::cout << "Antagonist Special Ability: " << antagonist.SpecialAbility() << std::endl;
    std::cout << "Antagonist Special Ability Name: " << antagonist.SpecialAbilityName() << std::endl;
}

void testSorcerer() {
    Sorcerer sorcerer("Sorcerer", "Sorcerer attack", 13, 11, 12, 145, 102, 30, 50, 10, 25);
    std::cout << "Sorcerer DPS: " << sorcerer.DPS() << std::endl;
    std::cout << "Sorcerer Special Ability: " << sorcerer.SpecialAbility() << std::endl;
    std::cout << "Sorcerer Special Ability Name: " << sorcerer.SpecialAbilityName() << std::endl;
}

void testSoulRipper() {
    SoulRipper soulRipper("Soul Ripper", "Soul Ripper attack", 13, 11, 12, 145, 102, 30, 50, 10, 25);
    std::cout << "Soul Ripper DPS: " << soulRipper.DPS() << std::endl;
    std::cout << "Soul Ripper Special Ability: " << soulRipper.SpecialAbility() << std::endl;
    std::cout << "Soul Ripper Special Ability Name: " << soulRipper.SpecialAbilityName() << std::endl;
}

void testDemonSlayer() {
    DemonSlayer demonSlayer("Demon Slayer", "Demon Slayer attack", 13, 11, 12, 145, 102, 30, 50, 10, 25);
    std::cout << "Demon Slayer DPS: " << demonSlayer.DPS() << std::endl;
    std::cout << "Demon Slayer Special Ability: " << demonSlayer.SpecialAbility() << std::endl;
    std::cout << "Demon Slayer Special Ability Name: " << demonSlayer.SpecialAbilityName() << std::endl;
}

void testHollow() {
    Hollow hollow("Hollow", "Hollow attack", 13, 11, 12, 145, 102, 30, 50, 10, 25);
    std::cout << "Hollow DPS: " << hollow.DPS() << std::endl;
    std::cout << "Hollow Special Ability: " << hollow.SpecialAbility() << std::endl;
    std::cout << "Hollow Special Ability Name: " << hollow.SpecialAbilityName() << std::endl;
}

void testCursedSpirit() {
    CursedSpirit cursedSpirit("Cursed Spirit", "Cursed Spirit Attack", 13, 11, 12, 145, 102, 30, 50, 10, 25);
    std::cout << "Cursed Spirit DPS: " << cursedSpirit.DPS() << std::endl;
    std::cout << "Cursed Spirit Special Ability: " << cursedSpirit.SpecialAbility() << std::endl;
    std::cout << "Cursed Spirit Special Ability Name: " << cursedSpirit.SpecialAbilityName() << std::endl;
}

void testDemon() {
    Demon demon("Demon", "Demon Attack", 13, 11, 12, 145, 102, 30, 50, 10, 25);
    std::cout << "Demon DPS: " << demon.DPS() << std::endl;
    std::cout << "Demon Special Ability: " << demon.SpecialAbility() << std::endl;
    std::cout << "Demon Special Ability Name: " << demon.SpecialAbilityName() << std::endl;
}

int main() {
    testCharacter();
    std::cout << std::endl;
    testProtagonist();
    std::cout << std::endl;
    testAntagonist();
    std::cout << std::endl;
    testSorcerer();
    std::cout << std::endl;
    testDemonSlayer();
    std::cout << std::endl;
    testSoulRipper();
    std::cout << std::endl;
    testHollow();
    std::cout << std::endl;
    testDemon();
    std::cout << std::endl;
    testCursedSpirit();
    std::cout << std::endl;
    std::cout << "All tests working." << std::endl;
    return 0;
}
