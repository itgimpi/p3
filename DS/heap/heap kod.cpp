#include<bits/stdc++.h>
using namespace std;

struct Cvor {
    int vrednost;
    Cvor* levi;
    Cvor* desni;
    Cvor* roditelj;
};

Cvor* koren = nullptr;

Cvor* napraviCvor(int vrednost) {
    Cvor* noviCvor = new Cvor();
    noviCvor->vrednost = vrednost;
    noviCvor->levi = noviCvor->desni = noviCvor->roditelj = nullptr;
    return noviCvor;
}

void heapifyUp(Cvor* cvor) {
    while (cvor->roditelj && cvor->vrednost > cvor->roditelj->vrednost) {
        swap(cvor->vrednost, cvor->roditelj->vrednost);
        cvor = cvor->roditelj; } 
}

void heapifyDown(Cvor* cvor) {
    while (cvor) {
        Cvor* maks = cvor;
        if (cvor->levi && cvor->levi->vrednost > maks->vrednost) {
            maks = cvor->levi;
        }

        if (cvor->desni && cvor->desni->vrednost > maks->vrednost) {
            maks = cvor->desni;
        }

        if (maks == cvor) break;

        swap(cvor->vrednost, maks->vrednost);

        cvor = maks;
    }
}

//trazimo poslednji cvor
Cvor* najDoleDesni() {
    	//ako nema koren...
        if (!koren) return nullptr;

        queue<Cvor*> queue;
        queue.push(koren);
        Cvor* trenutni = nullptr;

        //izbacujemo svi leviji i na kraj ostane samo najdesniji
        while (!queue.empty()) {
            trenutni = queue.front();
            queue.pop();

            if (trenutni->levi) queue.push(trenutni->levi);
            if (trenutni->desni) queue.push(trenutni->desni);
        }

        return trenutni;
}

//u sustini krecemo od korena i trazimo prvi cvor koji nema oba deteta
Cvor* slobodan(Cvor* cvor) {
    if (!cvor) return nullptr;
    queue<Cvor*> queue;
    queue.push(cvor);

    while (!queue.empty()) {
        Cvor* trenutni = queue.front();
        queue.pop();
        //ako cvor nema oba deteta
        if (!trenutni->levi || !trenutni->desni) {
            return trenutni;
        }
        queue.push(trenutni->levi);
        queue.push(trenutni->desni);
    }

    return nullptr;
}

void ispisiHeap() {
    if (koren == nullptr) {
        return; 
    }
    queue<Cvor*> q;
    q.push(koren);

    while (!q.empty()) {
        Cvor* trenutni = q.front();
        q.pop();

        cout << trenutni->vrednost << " ";

        if (trenutni->levi != nullptr) {
            q.push(trenutni->levi);}
            
        if (trenutni->desni != nullptr) {
            q.push(trenutni->desni);}
    }

    cout << endl;
}

void ubaciCvor(int vrednost) {
    Cvor* novi = napraviCvor(vrednost);
    //ako nema koren...
    if (koren == nullptr){
        koren = novi;
    }
    else{
    //prvi cvor koji nema oba deteta
    Cvor* poz = slobodan(koren);
    novi->roditelj = poz;
    if(poz->levi == nullptr){
        poz->levi = novi;
    }
    else{
        poz->desni = novi;
    }
    //nakon sto ubacimo novi cvor trazimo mu mesto
    heapifyUp(novi);
    }
}

//funkcija koja trazi cvor koji treba da izbacimo preko vrednosti
Cvor* najdiCvor(Cvor* cvor, int vr){
    if(cvor == nullptr){
        return nullptr;
    }
    if(cvor->vrednost == vr){
        return cvor;
    }
    Cvor* lev = najdiCvor(cvor->levi, vr);
    Cvor* des = najdiCvor(cvor->desni, vr);
    if(lev == nullptr){
        return des;
    }
    return lev;
}

void izbaciCvor(int vrednost) {
    Cvor* najdeni = najdiCvor(koren,vrednost);
    Cvor* najdonjidesni = najDoleDesni();
    swap(najdeni->vrednost, najdonjidesni->vrednost);

    Cvor* rod = najdonjidesni->roditelj;
    //izbacujemo nepozeljni cvor
    if(najdonjidesni == rod->desni){
        rod->desni = nullptr;
    }
    else{
        rod -> levi = nullptr;
    }
    //da budemo sigurni da je prethodno swapovani pronasao svoje mesto
    heapifyDown(najdeni);
    heapifyUp(najdeni);

}

int main() {
    ubaciCvor(10);
    ubaciCvor(20);
    ubaciCvor(30);
    ubaciCvor(40);
    ubaciCvor(50);
    ubaciCvor(60);
    ubaciCvor(70);
    ubaciCvor(80);
    ubaciCvor(90);
    ubaciCvor(100);

    cout << "Max Heap:" << endl;
    ispisiHeap();

    izbaciCvor(70);
    ispisiHeap();

    ubaciCvor(99);
    ispisiHeap();
    
    Cvor * najdeni = najdiCvor(koren,40);
    cout << najdeni -> vrednost << endl;

    while(koren != nullptr){
        cout << koren->vrednost << " ";
        izbaciCvor(koren->vrednost);
    }

    return 0;
}