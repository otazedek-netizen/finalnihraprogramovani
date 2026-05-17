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
    int classBonusDamage;
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
                classBonusDamage = 2;
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
                classBonusDamage = 2;
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
                classBonusDamage = 3;
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
                classBonusDamage = 2;
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
        cout << "Bonus utok - " << classBonusDamage << endl;
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

    cout << "\nNarazil jsi na nepritele!" << endl;

    while (hp_nepritel > 0 && currentHealth > 0) {
        int akce;
        cout << "Tvoje HP: " << currentHealth << " | HP nepritele: " << hp_nepritel << endl;
        cout << "1 - Utok, 2 - Nic: ";
        cin >> akce;

        if (akce == 1) {
            int totalDamage = attack + classBonusDamage;
            hp_nepritel = hp_nepritel - totalDamage;
            cout << "Utok: " << attack << " + bonus " << classBonusDamage << " = " << totalDamage << " poskozeni." << endl;
        }

        if (hp_nepritel > 0) {
            currentHealth = currentHealth - utok_nepritel;
            cout << "Nepritel te zasahl za " << utok_nepritel << endl;
        }
    }

    if (currentHealth <= 0) {
        cout << "Prohra!" << endl;
        return 0;
    } else {
        cout << "Vyhra! Porazil jsi prvni monstrum." << endl;
        if (rand() % 2 == 0) {
            cout << "Nasel jsi u nej 5 penez." << endl;
            gold = gold + 5;
        } else {
            cout << "Monstrum u sebe nemelo zadne penize." << endl;
        }
    }

    cout << "Pokracujes do male vesnice." << endl;
    cout << "Mas " << gold << " zlatek." << endl;
    cout << "1 - Vylepsit zivot o 1 za 5 zlata" << endl;
    cout << "2 - Vylepsit utok o 1 za 5 zlata" << endl;
    cout << "3 - Nic" << endl;
    int volbaVesnice;
    cin >> volbaVesnice;
    if (volbaVesnice == 1) {
        if (gold >= 5) {
            maxHealth = maxHealth + 1;
            currentHealth = maxHealth;
            gold = gold - 5;
            cout << "Maximalni zivot vylepsen na " << maxHealth << "." << endl;
        } else {
            cout << "Nemas dostatek zlata! Pokracujes bez vylepseni." << endl;
        }
    } else if (volbaVesnice == 2) {
        if (gold >= 5) {
            attack = attack + 1;
            gold = gold - 5;
            cout << "Utok vylepsen na " << attack << "." << endl;
        } else {
            cout << "Nemas dostatek zlata! Pokracujes bez vylepseni." << endl;
        }
    } else {
        cout << "Pokracujes bez vylepseni." << endl;
    }

    cout << "Prichazis do dalsiho souboje s orkem." << endl;
    int hp_ork = 12;
    int utok_ork = 3;

    while (hp_ork > 0 && currentHealth > 0) {
        int akce2;
        cout << "Tvoje HP: " << currentHealth << " | HP orka: " << hp_ork << endl;
        cout << "1 - Utok, 2 - Specialni utok (vyuzije 2 many): ";
        cin >> akce2;

        if (akce2 == 1) {
            int totalDamage = attack + classBonusDamage;
            hp_ork = hp_ork - totalDamage;
            cout << "Utok: " << attack << " + bonus " << classBonusDamage << " = " << totalDamage << " poskozeni." << endl;
        } else if (akce2 == 2) {
            if (currentMana >= 2) {
                int totalDamage = attack + classBonusDamage + 2;
                hp_ork = hp_ork - totalDamage;
                currentMana = currentMana - 2;
                cout << "Specialni utok: " << attack << " + bonus " << classBonusDamage << " + 2 = " << totalDamage << " poskozeni." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else {
            cout << "Nic jsi neudelal." << endl;
        }

        if (hp_ork > 0) {
            currentHealth = currentHealth - utok_ork;
            cout << "Ork te uderil za " << utok_ork << "." << endl;
        }
    }

    if (currentHealth <= 0) {
        cout << "Prohral jsi proti orku." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi proti orku!" << endl;
        if (rand() % 2 == 0) {
            gold = gold + 10;
            cout << "Ziskal jsi 10 zlata." << endl;
        } else {
            cout << "Ork u sebe nemel zadne penize." << endl;
        }
        experience = experience + 10;
        cout << "Ziskal jsi 10 zkusenosti." << endl;
        if (experience >= level * 10) {
            level = level + 1;
            maxHealth = maxHealth + 1;
            attack = attack + 1;
            currentHealth = maxHealth;
            cout << "Novy level! Mas level " << level << "." << endl;
            cout << "Max zivot +1, utok +1." << endl;
        }
    }

    cout << "Pokracujes do jeskyne, kde se skryva mini boss - divoky troll." << endl;
    int hp_troll = 15;
    int utok_troll = 4;

    while (hp_troll > 0 && currentHealth > 0) {
        currentHealth = currentHealth - utok_troll;
        cout << "Troll te uderil za " << utok_troll << "." << endl;

        if (currentHealth <= 0) {
            break;
        }

        int akce3;
        cout << "Tvoje HP: " << currentHealth << " | HP trolla: " << hp_troll << " | Mana: " << currentMana << "/" << maxMana << endl;
        cout << "1 - Utok, 2 - Specialni utok (vyuzije 2 many), 3 - Obnovit trochu many" << endl;
        cin >> akce3;

        if (akce3 == 1) {
            int totalDamage = attack + classBonusDamage;
            hp_troll = hp_troll - totalDamage;
            cout << "Utok: " << attack << " + bonus " << classBonusDamage << " = " << totalDamage << " poskozeni." << endl;
        } else if (akce3 == 2) {
            if (currentMana >= 2) {
                int totalDamage = attack + classBonusDamage + 3;
                hp_troll = hp_troll - totalDamage;
                currentMana = currentMana - 2;
                cout << "Specialni utok: " << attack << " + bonus " << classBonusDamage << " + 3 = " << totalDamage << " poskozeni." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else if (akce3 == 3) {
            currentMana = currentMana + 2;
            if (currentMana > maxMana) currentMana = maxMana;
            cout << "Obnovil jsi 2 many. Mana: " << currentMana << "/" << maxMana << endl;
        } else {
            cout << "Nic jsi neudelal." << endl;
        }
    }

    if (currentHealth <= 0) {
        cout << "Troll te porazil. Hra konci." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi proti trollovi!" << endl;
        gold = gold + 15;
        experience = experience + 15;
        cout << "Ziskal jsi 15 zlata a 15 zkusenosti." << endl;
        if (experience >= level * 10) {
            level = level + 1;
            maxHealth = maxHealth + 1;
            attack = attack + 1;
            currentHealth = maxHealth;
            cout << "Novy level! Mas level " << level << "." << endl;
            cout << "Max zivot +1, utok +1." << endl;
        }
    }

    return 0;
}