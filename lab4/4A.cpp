#include <iostream>
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
    void push(int value)
    {
        stack_element* element = new stack_element(); // создание указателя, указывающего на тип struct stack_element
        element->next = top;
        element->value = value;
        top = element;
    }

    int pop() // удаление последнего добавленного элемента, возврат его значения
    {
        int temp = top->value;
        top = top->next;
        return temp; // возврат его значения
    }
};

int main()
{
    StackClass stack;
    int temp, M;
    char a;

    ifstream fin("stack.in");
    ofstream fout("stack.out");

    fin >> M;

    for (int i = 0; i < M; i++)
    {
        fin >> a;
        if (a == '+')
        {
            fin >> temp;
            stack.push(temp);
        }
        else
            fout << stack.pop() << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}