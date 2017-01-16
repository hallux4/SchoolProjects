/* 
 * File:   Processor2.hpp
 * Author: cottin_j
 *
 * Created on February 8, 2012, 6:27 PM
 */

#ifndef PROCESSOR_2_HPP
#define	PROCESSOR_2_HPP

#include <iostream>
#include  "IStack.hpp"
#include  "IOperand.hpp"

class Processor2 {
public:

    Processor2() {
        std::cout << "Construction PROCESSOR" << std::endl;
    }

    ~Processor2() {
        std::cout << "Destruction PROCESSOR" << std::endl;
    }

    void push(eOperandType test_enum, std::string value) {
        std::cout << "________ enum : " << test_enum << " value : " << value << std::endl;
    }

    void pop() {
        std::cout << "________ pop" << std::endl;
    }

    void dump() {
        std::cout << "________ dump" << std::endl;
    }

    void assert(eOperandType test_enum, std::string value) {
        std::cout << "________ enum : " << test_enum << " value : " << value << std::endl;
    }

    void add() {
        std::cout << "________ add" << std::endl;
    }

    void sub() {
        std::cout << "________ sub" << std::endl;
    }

    void mul() {
        std::cout << "________ mul" << std::endl;
    }

    void div() {
        std::cout << "________ div" << std::endl;
    }

    void mod() {
        std::cout << "________ mod" << std::endl;
    }

    void print() {
        std::cout << "________ print" << std::endl;
    }

    void endOfProgram() {
        std::cout << "________ exit" << std::endl;
    }
    
private:
   
};

#endif	/* PROCESSOR_2_HPP */

