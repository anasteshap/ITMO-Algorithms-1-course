#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct stack_element  // элемент стека
{
    int value;
    stack_element* next;
};

class StackClass
{
private:
    stack_element* top = nullptr; //верхушка
public:
    bool isEmpty()
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }

    int getTop()
    {
        return top->value;
    }

    void push(int value)
    {
        stack_element* element = new stack_element(); // создание нового элемента типа struct stack_element*
        element->next = top;
        element->value = value;
        top = element;
    }

    int pop() // удаление последнего добавленного элемента, возрат его значения
    {
        int temp = top->value;
        top = top->next;
        return temp; // возрат его значения
    }

    void clear()
    {
        while (top != nullptr)
            pop();
    }
};

int main()
{
    ifstream fin("postfix.in");
    ofstream fout("postfix.out");

    char a;
    StackClass stack;

    while (fin >> a)
    {
        if (isdigit(a)) {
            stack.push(stoi(&a)); // строку (если число допустим 876) по адресу &a преобразует в int
        }
        else {
            int num_1 = stack.pop();
            int num_2 = stack.pop();

            switch (a) {
                case '+':
                    stack.push(num_1 + num_2);
                    break;
                case '-':
                    stack.push(num_2 - num_1);
                    break;
                case '*':
                    stack.push(num_1 * num_2);
                    break;
                default:
                    break;
            }
        }
    }

    fout << stack.pop();

    fin.close();
    fout.close();

    return 0;
}


