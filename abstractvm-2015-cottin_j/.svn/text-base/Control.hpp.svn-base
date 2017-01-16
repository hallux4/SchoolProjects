/* 
 * File:   Control.hpp
 * Author: cottin_j
 *
 * Created on February 11, 2012, 5:22 PM
 */

#ifndef CONTROL_HPP
#define	CONTROL_HPP

#include <map>
#include "Input.hpp"
#include "Processor.hpp"

class Control {
public:
    Control(std::string & data);
    ~Control();

    void parsing();
    void new_data(std::string & data);
private:
    
    Processor * process;
    Input * entry;
    
    int e_val;
       
    std::map<std::string, eOperandType> enum_map;    
    std::list<std::string> lexem_list;
    std::list<std::string>::iterator ut;
    std::vector<std::string> to_comp;
    std::vector<std::string> to_type;

    void fill_vector_comp();
    void fill_vector_type();
    void fill_map();
    
    bool scan_type();
    bool scan_value();
    bool dispatch_clean();
    
    bool one_arg_func();
    bool more_arg_func();
    
    void endOfProgram();
    bool test_over_under_flow();
};

#endif	/* CONTROL_HPP */

