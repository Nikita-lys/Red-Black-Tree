// main.cpp
// Red-Black Tree
// Лысенко Никита 2 курс 8 группа

/* Лог работы программы:
 
 1 2 5 7 8 10 11 12 13 14 16 19 20 21 22 27 28 29 30 32 33 35 37 38 39 40 42 43 44 45 46 48 49 52 53 54 57 58 61 63 65 67 68 69 70 72 73 74 75 78 79 80 81 82 84 85 86 90 91 92 93 95 96 97 99
 find(12): 12
 Удалили 12.
 1 2 5 7 8 10 11 13 14 16 19 20 21 22 27 28 29 30 32 33 35 37 38 39 40 42 43 44 45 46 48 49 52 53 54 57 58 61 63 65 67 68 69 70 72 73 74 75 78 79 80 81 82 84 85 86 90 91 92 93 95 96 97 99
 find(12): 99
 
 lower_bound(-1000): 1
 lower_bound(1000): 2147483647
 upper_bound(-1000): -2147483648
 upper_bound(1000): 99
 
 --------------—Сравнение RBTree c set.-----------------
 
 RBTree insert: 0.002255 seconds
 set insert: 0.003643 seconds
 
 RBTree find: 0.001633 seconds
 set find: 0.001839 seconds
*/

#include <iostream>
#include <ctime>
#include <set>
#include "RBT.h"

using namespace std;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    RBT<int> tree;
    int n = 100;
    for (size_t i = 0; i < n; i++)
        tree.insert(rand() % n);
    tree.input_file("RBTree.txt");
    tree.output_file("RBTree.txt");
    
    tree.print_infix();
    cout << endl;
    
    cout << "find(12): " << *tree.find(12) << endl;
    
    tree.remove(12);
    cout << "Удалили 12." << endl;
    
    tree.print_infix();
    cout << endl;
    
    cout << "find(12): " << *tree.find(12) << endl << endl;
    
    cout << "lower_bound(-1000): " << *tree.lower_bound(-1000) << endl;
    cout << "lower_bound(1000): " << *tree.lower_bound(1000) << endl;
    
    cout << "upper_bound(-1000): " << *tree.upper_bound(-1000) << endl;
    cout << "upper_bound(1000): " << *tree.upper_bound(1000) << endl;
    
    
    cout << endl << "--------------—Сравнение RBTree c set.-----------------" << endl << endl;
    
    
    RBT<int> myt;
    set<int> s;
    
    int len = 10000;
    // Вставка
    unsigned int start_time = clock();
    for (size_t i = 0; i < len; ++i)
        myt.insert(rand() % len);
    cout << "RBTree insert: " << (double)(clock() - start_time) / CLOCKS_PER_SEC << " seconds\n";
    
    start_time = clock();
    for (size_t i = 0; i < len; ++i)
        s.insert(rand() % len);
    cout << "set insert: " << (double)(clock() - start_time) / CLOCKS_PER_SEC << " seconds\n\n";
    
    // Поиск
    start_time = clock();
    for (size_t i = 1; i < len; i++)
        myt.find(rand() % len);
    cout << "RBTree find: " << (double)(clock() - start_time) / CLOCKS_PER_SEC << " seconds\n";
    
    start_time = clock();
    for (size_t i = 1; i < len; i++)
        s.find(rand() % len);
    cout << "set find: " << (double)(clock() - start_time) / CLOCKS_PER_SEC << " seconds\n\n";
    
    system("pause");
}

