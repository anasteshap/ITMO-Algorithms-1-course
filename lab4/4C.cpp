#include <iostream>
#include <fstream>

using namespace std;

struct stack_element  // элемент стека
{
    char value;
    stack_element* next;
};

class StackClass
{
private:
    stack_element* top = nullptr; //верхушка
public:
    bool empty()
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }

    char getTop()
    {
        return top->value;
    }

    void push(char value)
    {
        stack_element* element = new stack_element(); // создание нового элемента типа struct stack_element*
        element->next = top;
        element->value = value;
        top = element;
    }

    char pop() // удаление последнего добавленного элемента, возрат его значения
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
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");

    string s;
    int count_i = 0, temp;
    StackClass str;

    while (fin >> s)
    {
        str.clear();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
                str.push(s[i]);
            else if (!str.empty() && (str.getTop() == '(' && s[i] == ')' || str.getTop() == '[' && s[i] == ']'))
                         str.pop();
            else if (str.empty())
            {
                fout << "NO" << endl;
                break;
            }
            else
            {
                fout << "NO" << endl;
                break;
            }



            if (i == s.length() - 1)
            {
                if (str.empty())
                    fout << "YES" << endl;
                else
                    fout << "NO" << endl;
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
