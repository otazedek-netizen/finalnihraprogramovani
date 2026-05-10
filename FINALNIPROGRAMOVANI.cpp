#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int playerclasschoice;
    int maxHealth;
    int currentHealth;
    int maxMana;
    int currentMana;
    int gold;
    int level;
    int experience;
    int attack;
    string className;
    srand(time(0));

    cout << "Vyberte si classu:" << endl;
    cout << "1. Paladin" << endl;
    cout << "2. Lovec" << endl;
    cout << "3. Mag" << endl;
    cout << "4. Warlock" << endl;

    bool confirmed = false;
    while (!confirmed) {
        cout << "Zadejte cislo classy: ";
        cin >> playerclasschoice;

        switch (playerclasschoice) {
            case 1:
                maxHealth = 5;
                currentHealth = 5;
                maxMana = 5;
                currentMana = 5;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 3;
                break;
            case 2:
                maxHealth = 4;
                currentHealth = 4;
                maxMana = 4;
                currentMana = 4;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 4;
                break;
            case 3:
                maxHealth = 3;
                currentHealth = 3;
                maxMana = 6;
                currentMana = 6;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 2;
                break;
            case 4:
                maxHealth = 4;
                currentHealth = 4;
                maxMana = 5;
                currentMana = 5;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 3;
                break;
            default:
                cout << "Neplatna volba. Zkuste znovu." << endl;
                continue;
        }

        if (playerclasschoice == 1) className = "Paladin";
        else if (playerclasschoice == 2) className = "Lovec";
        else if (playerclasschoice == 3) className = "Mag";
        else if (playerclasschoice == 4) className = "Warlock";

        cout << "Class: " << className << endl;
        cout << "Statistiky:" << endl;
        cout << "Zivot - " << currentHealth << "/" << maxHealth << endl;
        cout << "Utok - " << attack << endl;
        cout << "Mana - " << currentMana << "/" << maxMana << endl;

        string choice;
        cout << "Chcete potvrdit vyber? (ano/ne): ";
        cin >> choice;
        if (choice == "ano") {
            confirmed = true;
        }
    }
    int hp_nepritel = 10;
int utok_nepritel = 2;

cout << "Narazil jsi na nepritele!" << endl;

while (hp_nepritel > 0 && currentHealth > 0) {
    int akce;
    cout << "Tvoje HP: " << currentHealth << " | HP nepritele: " << hp_nepritel << endl;
    cout << "1 - Utok, 2 - Nic: ";
    cin >> akce;

    if (akce == 1) {
        hp_nepritel = hp_nepritel - attack;
        cout << "Dal jsi ranu za " << attack << endl;
    }

    if (hp_nepritel > 0) {
        currentHealth = currentHealth - utok_nepritel;
        cout << "Nepritel te zasahl za " << utok_nepritel << endl;
    }
}

if (currentHealth <= 0) {
    cout << "Prohra!" << endl;
} else {
    cout << "Vyhra! Nasel jsi 5 penez." << endl;
    gold = gold + 5;
}

    
    return 0;
}
