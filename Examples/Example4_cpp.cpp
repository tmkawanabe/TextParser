/*
 * TextParser - Text Parsing Library
 *
 * Copyright (C) 2012-2014 Institute of Industrial Science, The University of Tokyo.
 * All rights reserved.
 *
 */

/** @file Example4_cpp.cpp
 * サンプルプログラム
 */

#include <iostream>
#include <string>
#include <vector>
#include "TextParser.h"

int get_node_parameters(std::string filename, std::string label)
{
    int ierror;
    //    TextParser* tp=TextParser::get_instance();
     TextParser* tp=TextParser::get_instance_singleton();

    ierror=tp->changeNode(label);
    if (ierror != 0) {
        std::cout <<  "ERROR in TextParser::changeDirector: " << filename 
	        << " ERROR CODE "<< ierror << std::endl;
        return ierror;
    }

    ierror = tp->currentNode(label);
    if (ierror != 0) {
        std::cout <<  "ERROR in TextParser::currentNode: " << filename 
	        << " ERROR CODE "<< ierror << std::endl;
        return ierror;
    }
    std::cout << "Current node: "<< label << std::endl;

    std::vector<std::string> dir_labels;
    //    dir_labels = MGPPGetDirectories(&ierror);
    //        ierror = tp->getNodes(dir_labels);
    ierror = tp->getNodes(dir_labels,1);
    //        ierror = tp->getNodes(dir_labels,2);
    if (ierror != 0) {
        std::cout <<  "ERROR in TextParser::getNodes: " << filename 
	        << " ERROR CODE "<< ierror << std::endl;
        return ierror;
    }

    for (int i = 0; i < dir_labels.size(); i++) {
        ierror = get_node_parameters(filename, dir_labels[i]);
    }

    std::vector<std::string> parm_labels;
    int oswitch=2;
    ierror = tp->getLabels(parm_labels,oswitch);
    if (ierror != 0) {
        std::cout <<  "ERROR in TextParser::getLabels: " << filename 
	        << " ERROR CODE "<< ierror << std::endl;
        return ierror;
    }

    for (int i = 0; i < parm_labels.size(); i++) {
        std::cout << i << " " << parm_labels[i] << std::endl;
        std::string value;
	ierror = tp->getValue(parm_labels[i],value);
        if (ierror!=0){
        std::cout <<  "ERROR in TextParser::getValue file: " << filename 
		    << " ERROR CODE "<< ierror << std::endl;
            return ierror;
        }
        std::cout << i << " " << value << std::endl;

        TextParserValueType type = tp->getType(parm_labels[i], &ierror);
        if (ierror != 0){
            std::cout <<  "ERROR in TextParser::getType file: " << filename 
		        << " ERROR CODE "<< ierror << std::endl;
            return ierror;
        }
        std::cout << i << " value type: " << type << std::endl;
    }

    //    label = MGPPCurrentNode(&ierror);
    ierror=tp->currentNode(label);
    if (label.compare("/")) {
        ierror=tp->changeNode("..");
        if (ierror != 0) {
            std::cout <<  "ERROR in TextParser::changeNode: " << filename 
	            << " ERROR CODE "<< ierror << std::endl;
            return ierror;
        }

        ierror = tp->currentNode(label);
	std::cout << "Current node: "<< label << std::endl;
    }
}

int move_and_get_parameters(std::string filename)
{
    int ierror;
    //    TextParser* tp=TextParser::get_instance();
    TextParser* tp=TextParser::get_instance_singleton();
    
    // ファイルの読み込み
    std::cout << "filename: " << filename << std::endl;
    ierror=tp->read(filename);
    if (ierror != 0) {
        std::cout <<  "ERROR in MgppReadParameters file: " << filename 
	        << " ERROR CODE "<< ierror << std::endl;
        return ierror;
    }
  
    std::string label = "/";

    get_node_parameters(filename, label);

    // パラメータの削除
    ierror=tp->remove();
    if (ierror != 0) {
        std::cout <<  "ERROR in TextParser::Remove file: " << filename 
	        << " ERROR CODE "<< ierror << std::endl;
    }
    std::cout << std::endl;

    return ierror;
}

int main(int argc, char* argv[])
{
    std::string filename;
    // filename = "Input0-1.txt";
    // move_and_get_parameters(filename);
    // filename = "Input4-1.txt";
    // move_and_get_parameters(filename);
    // filename = "Input0-9.txt";
    // move_and_get_parameters(filename);

    filename = "./tpp_examples/correct_basic_1.txt";
    move_and_get_parameters(filename);
    filename = "./tpp_examples/correct_string_1.txt";
    move_and_get_parameters(filename);
    filename = "./tpp_examples/correct_label_2.txt";
    move_and_get_parameters(filename);
    filename = "./tpp_examples/correct_cond_10.txt";
    move_and_get_parameters(filename);
    filename = "./tpp_examples/correct_cond_9.txt";
    move_and_get_parameters(filename);

    return 0;
}

