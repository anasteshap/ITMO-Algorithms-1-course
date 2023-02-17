#include <iostream>
#include <fstream>

using namespace std;

struct queue_element  // элемент очереди
{
    int value;
    queue_element* next;
};

queue_element* list_item(int value, queue_element* next)
{
    queue_element* element = new queue_element();
    element->value = value;
    element->next = next;
    return element;
}

class QueueClass
{
private:
    queue_element* head = nullptr; //верхушка
    queue_element* tail = nullptr; // конец очереди
    int len = 0; // длина очереди
public:
    void push(int value)
    {
        queue_element* new_element = new queue_element(); // создание указателя на элемент типа struct stack_element
        new_element = tail;
        tail = list_item(value, nullptr);
        if (len == 0)
            head = tail;    
        else
            new_element->next = tail;
        len++;
    }

    int pop() // удаление последнего добавленного элемента, возрат его значения
    {
        queue_element* element = new queue_element(); // создание указателя на элемент типа struct stack_element
        int temp = head->value;
        head = head->next;
        len--;
        return temp; // возрат его значения
    }
};

int main()
{
    QueueClass Queue;
    int temp, M;
    char a;

    ifstream fin("queue.in");
    ofstream fout("queue.out");

    fin >> M;

    for (int i = 0; i < M; i++)
    {
        fin >> a;
        if (a == '+')
        {
            fin >> temp;
            Queue.push(temp);
        }
        else
            fout << Queue.pop() << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}