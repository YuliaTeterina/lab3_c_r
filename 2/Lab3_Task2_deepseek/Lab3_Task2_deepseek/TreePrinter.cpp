#include "TreePrinter.h"
#include "Node.h"

//FIX_ME: фигурные скобки стоят в неправильных местах
//Изменено: все скобки перенесены

void printTreeIndented(Node* node, int depth) {
    if (!node) return;

    // Отступ из depth*2 пробелов
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }

    if (node->getType() == Node::Type::Operand) {
        std::cout << node->getValue() << std::endl;
    }
    else {
        int op = node->getValue();
        char opChar;
        switch (op) {
        case -1: opChar = '+'; break;
        case -2: opChar = '-'; break;
        case -3: opChar = '*'; break;
        case -4: opChar = '/'; break;
        case -5: opChar = '%'; break;
        case -6: opChar = '^'; break;
        default: opChar = '?';
        }
        std::cout << opChar << std::endl;
        printTreeIndented(node->getLeft(), depth + 1);
        printTreeIndented(node->getRight(), depth + 1);
    }
}