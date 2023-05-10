#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Card {
public:
    int value;

    Card(int v) {
        value = v;
    }
};

class Deck {
private:
    stack<Card> cards;

public:
    Deck() {}

    void add_card(Card card) {
        cards.push(card);
    }

    void shuffle() {
        vector<Card> temp;
        while (!cards.empty()) {
            temp.push_back(cards.top());
            cards.pop();
        }

        srand(time(NULL));
        while (!temp.empty()) {
            int index = rand() % temp.size();
            cards.push(temp[index]);
            temp.erase(temp.begin() + index);
        }
    }

    int size() {
        return cards.size();
    }

    Card draw() {
        if (cards.size() != 0) {
            Card card = cards.top();
            cards.pop();
            return card;
        }
        else {
            return 6;
        }
    }
};

class Player {
private:
    string name;
    Deck deck;

public:
    Player(string n) {
        name = n;
    }

    string get_name() {
        return name;
    }

    int get_deck_size() {
        return deck.size();
    }

    Card draw_card() {
        return deck.draw();
    }

    void add_cards(Card card1, Card card2) {
        deck.add_card(card1);
        deck.add_card(card2);
    }
};

int main() {
    Deck deck;

    cout << "rules:" << endl;
    cout << "6,7, 8,9 10 is standart cards" << endl;
    cout << "11 is wallet, 12 is dam, 13 is king, 14 is tuz" << endl;
    int value;
    int n;
    cout << "Enter amount of cards" << endl;
    cin >> n;
    if (n % 2 != -0) {
        n++;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter value for card " << i + 1 << ": ";
        cin >> value;
        while (value > 14 || value < 6) {
            cout << "Enter value for card " << i + 1 << ": ";
            cin >> value;
        }
        deck.add_card(Card(value));
    }

    deck.shuffle();

    Player player1("Player 1");
    Player player2("Player 2");

    while (deck.size() > 0) {
        player1.add_cards(deck.draw(), deck.draw());
        player2.add_cards(deck.draw(), deck.draw());
    }

    while (player1.get_deck_size() > 0 && player2.get_deck_size() > 0) {
        Card card1 = player1.draw_card();
        Card card2 = player2.draw_card();

        if (card1.value > card2.value) {
            player1.add_cards(card1, card2);
        }
        else if (card2.value > card1.value) {
            player2.add_cards(card1, card2);
        }

    }

    if (player1.get_deck_size() > 0) {
        cout << player1.get_name() << " wins!" << endl;
    }
    else {
        cout << player2.get_name() << " wins!" << endl;
    }

    return 1;
}
