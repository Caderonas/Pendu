/* 
 * File:   main.cpp
 * Author: loic
 *
 * Created on 21 octobre 2014, 22:00
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
bool verif(bool tab[], int score, int siz)
{
    bool sortie = true;
    for (int i(0);i<siz;i++)
    {
        if (tab[i] == false){sortie = false;}
    }
    if (score < 1)
    {
        sortie = true;
    }
    return sortie;
}
void affichage(string mot, bool tab[])
{
    for (int i(0);i<mot.size();i++)
    {
        if(tab[i] == true)
        {
            cout << mot[i] << " ";
        }
        else
        {
            cout << "_" << " ";
        }
    }
    cout << endl;
}

int main(void)
{
    string mot, faux;
    int lvl(5), score, a(0);
    char in;
    bool lettre, fau = false;
    cout << "Entrez le mot (un vrai sera plus facile à trouver) :" << endl;
    cin >> mot;
    bool tab[mot.size()] = {false};
    while (lvl != 1 && lvl != 2 && lvl != 3)
    {
        cout << "Entrez le niveau (1,2,3) :" << endl;
        cin >> lvl;
    }
    switch (lvl)
    {
        case 1:
            score = 10;
            lettre = true;
            break;
        case 2:
            score = 7;
            lettre = true;
            break;
        case 3:
            score = 7;
            lettre = false;
            break;
    }
    system("clear");
    // Fin initialisation ! 
    
    
    while (verif(tab, score, mot.size()) == false)
    {
        affichage(mot, tab);
        cout << endl;
        if (lettre == true)
        {
                cout << faux << endl;
        }
        cout <<"Score : "<<score <<endl;
        
        fau = false;
        cout << "Ta lettre :" ;
        cin >> in;
        for (int i(0); i<mot.size();i++)
        {
            if(in == mot[i])
            {
                tab[i] = true;
                fau = true;
            }
        }
        if (fau == false)
        {
            score = score-1;
            faux = faux+in;
            a = a+1;
        }
        system("clear");        
    }
    // Fin du jeu
    if (score > 1)
    {
        switch(lvl)
        {
            case 1:
                cout << "Jolie !" << endl;
                break;
            case 2:
                cout << "Belle Performance !" << endl;
                break;
            case 3:
                cout << "T'es une Machine !!!" << endl;
                break;
        }
        affichage(mot, tab);
        cout << "Score : " << score;             
    }
    else 
    {
        cout << "Perdu, le mot etait : "<<mot<<" , n'hesite pas à rejouer !";
    }
}
