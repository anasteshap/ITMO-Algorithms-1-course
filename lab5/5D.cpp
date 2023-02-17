#include <iostream>
#include <vector>

using namespace std;

vector <string> commands;
vector <int> registers(26, 0);
vector <pair<string, int>> labels;

int newIndex(string label) {
    for (int j = 0; j < labels.size(); j++) {
        if (labels[j].first == label) {
            return labels[j].second;
        }
    }
}

struct Node {
    int data;
    Node* next;
};

void put(Node** head, int value) {
    Node *temp = new Node();
    Node *last = *head;

    temp->data = value;
    temp->next = nullptr;

    if (*head == nullptr) {
        *head = temp;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = temp;
}

int get(Node** head) {
    Node *temp = *head;
    *head = temp->next;

    return temp->data;
}

int main() {
    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);

    string command, label;
    char reg;
    unsigned int x, y;
    bool run = true;

    Node *head = nullptr;

    int n = 0;
    while (cin >> command) {
        commands.emplace_back(command);
        n++;
    }

    for (int i = 0; i < n; ++i) {
        if (commands[i][0] == ':') {
            labels.emplace_back(make_pair(commands[i].substr(1), i));
        }
    }

    int i = 0;
    while (i < n) {
        command = commands[i];

        switch (command[0]) {
            case '+': {
                x = get(&head);
                y = get(&head);
                unsigned int sum = (x + y) % 65536;
                put(&head, sum);
                break;
            }

            case '-': {
                x = get(&head);
                y = get(&head);
                unsigned int diff = (x - y) % 65536;
                put(&head, diff);
                break;
            }

            case '*': {
                x = get(&head);
                y = get(&head);
                unsigned int multiplication = (x * y) % 65536;
                put(&head, multiplication);
                break;
            }

            case '/': {
                x = get(&head);
                y = get(&head);
                uint16_t division;
                if (!y) {
                    division = 0;
                } else {
                    division = (x / y) % 65536;
                }
                put(&head, division);
                break;
            }

            case '%': {
                x = get(&head);
                y = get(&head);
                unsigned int remainder;
                if (!y) {
                    remainder = 0;
                } else {
                    remainder = (x % y) % 65536;
                }
                put(&head, remainder);
                break;
            }

            case '>': {
                reg = command[1];
                x = get(&head);
                registers[reg % 97] = x;
                break;
            }

            case '<': {
                reg = command[1];
                x = registers[reg % 97];
                put(&head, x);
                break;
            }

            case 'P': {
                if (command.length() == 1) {
                    x = get(&head);
                } else {
                    reg = command[1];
                    x = registers[reg % 97];
                }
                cout << x << '\n';
                break;
            }

            case 'C': {
                if (command.length() == 1) {
                    x = get(&head);
                } else {
                    reg = command[1];
                    x = registers[reg % 97];
                }
                cout << char(x % 256);
                break;
            }

            case ':': {
                break;
            }

            case 'J': {
                label = commands[i].substr(1);
                i = newIndex(label);
                break;
            }

            case 'Z': {
                label = commands[i].substr(2);
                if (registers[command[1] % 97] == 0) {
                    i = newIndex(label);
                }
                break;
            }

            case 'E': {
                label = commands[i].substr(3);
                if (registers[command[1] % 97] == registers[command[2] % 97]) {
                    i = newIndex(label);
                }
                break;
            }

            case 'G': {
                label = commands[i].substr(3);
                if (registers[command[1] % 97] > registers[command[2] % 97]) {
                    i = newIndex(label);
                }
                break;
            }

            case 'Q': {
                run = false;
                break;
            }

            default: {
                uint16_t num = atoi(command.c_str());
                put(&head, num);
                break;
            }
        }

        i++;

        if (!run) {
            break;
        }
    }

    return 0;
}


