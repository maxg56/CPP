/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:39:06 by max               #+#    #+#             */
/*   Updated: 2025/02/10 21:39:37 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replaceOccurrences(const std::string &content, const std::string &s1, const std::string &s2) {
    if (s1.empty())
        return content;
    
    std::string result;
    size_t pos = 0;
    size_t found;
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result.append(content.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content.substr(pos)); // Ajout du reste du texte
    
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1;
    }
    
    std::string content;
    std::string line;
    while (std::getline(inputFile, line)) {
        content += line + "\n";
    }
    inputFile.close();
    
    std::string modifiedContent = replaceOccurrences(content, s1, s2);
    
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: could not create output file" << std::endl;
        return 1;
    }
    outputFile << modifiedContent;
    outputFile.close();
    
    std::cout << "File " << filename << ".replace created successfully." << std::endl;
    return 0;
}
