#ifndef __ARRAY_AND_STRINGS_H__
#define __ARRAY_AND_STRINGS_H__

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

bool isUnique(const std::string& str)
{
    if (str.empty())
        return false;

    std::unordered_map<char, int> freq;
    for (int i = 0; i < str.size(); ++i)
    {
        if (freq[str[i]] >=1)
            return false;

        freq[str[i]]++;
    }

    return true;
}

bool isUniqueSort(const std::string& str)
{
    std::string tmp_str(str);
    std::sort(tmp_str.begin(), tmp_str.end());

    for(int i = 1; i < tmp_str.size(); ++i)
    {
        if (tmp_str[i] == tmp_str[i-1])
            return false;
    }

    return true;
}

bool isUniqueBitVector(const std::string& str)
{
    bool bit_vector[24] = {false};
    for (int i = 0; i < str.size(); ++i)
    {
        if (bit_vector[str[i]-'a'])
            return false;

        bit_vector[str[i]-'a'] = true;
    }

    return true;
}

bool isPermutationSort(const std::string& str1, const std::string& str2)
{
    if (str1.size() not_eq str2.size())
        return false;

    std::string s1(str1);
    std::string s2(str2);
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] != s2[i])
            return false;
    }

    return true;

}

bool isPermutationHash(const std::string& str1, const std::string& str2)
{
    if (str1.size() not_eq str2.size())
        return false;

    // build dictionary
    std::unordered_map<char, int> freq_count1;
    std::unordered_map<char, int> freq_count2;
    for (int i = 0; i < str1.size(); ++i)
    {
        freq_count1[str1[i]]++;
        freq_count2[str2[i]]++;
    }

    return freq_count1 == freq_count2;

}

void testIsPermutation(const std::string& str1, const std::string& str2)
{
    std::cout << "Test strings-> " << str1 << " , " << str2 << std::endl;
    std::cout << "[Sort] ->";
    if (isPermutationSort(str1, str2))
        std::cout << "Permutation!!" << std::endl;
    else
        std::cout << "No permutation!!" << std::endl;

    std::cout << "[Hash] ->";
    if (isPermutationHash(str1, str2))
        std::cout << "Permutation!!" << std::endl;
    else
        std::cout << "No permutation!!" << std::endl;

}

void testIsUnique(const std::string& str)
{
    std::cout << "test string->" << str << std::endl;
    std::cout <<"[Hash]:";
    if (isUnique(str))
    {
        std::cout <<"Unique" << std::endl;
    }
    else
    {
        std::cout <<"Non Unique" << std::endl;
    }

    std::cout << "[Sort]:";
    if (isUniqueSort(str))
    {
        std::cout <<"Unique" << std::endl;
    }
    else
    {
        std::cout <<"Non Unique" << std::endl;
    }        

    std::cout << "[Bit vector]:";
    if (isUniqueBitVector(str))
    {
        std::cout <<"Unique" << std::endl;
    }
    else
    {
        std::cout <<"Non Unique" << std::endl;
    }            
}

std::vector<std::string> splitString(const std::string& input_str, char delimiter, int size)
{
    int start_ind = 0;
    int end_ind = 0;
    std::vector<std::string> results;
    while( start_ind < size && end_ind < size)
    {
        end_ind++;
        if (end_ind == size or input_str[end_ind] == ' ')
        {
            results.push_back(input_str.substr(start_ind, end_ind - start_ind));
            start_ind = end_ind + 1;
            end_ind++;
        }
    }

    return results;
}

std::string combine_results(const std::vector<std::string>& res)
{
    std::string final_res("");
    for (int i = 0; i < res.size(); ++i)
    {
        final_res.append(res[i]);
        if (i < res.size() - 1)
        {
            final_res.append("%20");
        }
    }
    return final_res;
}

void testURLify(const std::string& str, char delim, int size)
{
    auto results = splitString(str, delim, size);
    auto final_results = combine_results(results);
    std::cout << final_results << std::endl;
}

int countSetBits(int input_number)
{
    int counter = 0;
    while (input_number)
    {
        input_number &= (input_number - 1);
        counter++;
    }

    return counter;
}

bool isPalindrome(const std::string& input_str)
{
    bool counter_vector[24] = {false};
    for (int i = 0; i < input_str.size(); ++i)
    {
        counter_vector[input_str[i] - 'a'] = !counter_vector[input_str[i] - 'a'];
    }

    int countBit = 0;
    for (int i = 0; i < 24; ++i)
    {
        if (counter_vector[i])
            countBit++;
    }

    if (input_str.size() % 2 == 0)
        return countBit == 0;
    
    return countBit <= 1;
}

bool oneEdit(const std::string& s1, const std::string& s2)
{
    //find first different character
    int counter = 0;
    while (counter < s1.size() and counter < s2.size())
    {
        if (s1.at(counter) != s2.at(counter))
            break;
        
        counter++;
    }

    if (counter == s1.size())
    {
        if (s2.size() > s1.size() + 1)
            return false;
        else
            return true;
    }

    if (counter == s2.size())
    {
        if (s1.size() > s2.size() + 1)
            return false;
        else
            return true;            
    }

    int ind = counter+1;
    std::string tmp1 = s1.substr(ind, s1.size() - ind);
    std::string tmp2 = s2.substr(counter, s2.size() - counter);
    if (tmp1.compare(tmp2) == 0)
        return true;

    tmp1 = s2.substr(ind, s2.size() - ind);
    tmp2 = s1.substr(counter, s1.size() - counter);
    if (tmp1.compare(tmp2) == 0)
        return true;

    tmp1 = s2.substr(ind, s2.size() - ind);
    tmp2 = s1.substr(ind, s1.size() - ind);
    if (tmp1.compare(tmp2) == 0)
        return true;

    return false;
}

void testOneStringEdit()
{
    std::string s1("george");
    std::string s2("gefdge");

    if (oneEdit(s1, s2))
    {
        std::cout << "one char away" << std::endl;
    }
    else
    {
        std::cout << "more than one char away" << std::endl;
    }
    
}

void testPalindrome()
{
    bool test = isPalindrome("george");
    if (test)
    {
        std::cout << "Palindrome" << std::endl;
    }
    else
    {
        std::cout << "Not a palindrome" << std::endl;
    }
}

std::string compressString(const std::string& str)
{
    int count = 1;
    std::string result{};
    int index = 0;
    while (index < str.length() - 1)
    {
        if (str.at(index) != str.at(index + 1))
        {
            std::string num(std::to_string(count));
            result = result + str.at(index) + num;
            count = 1;
        }
        else
        {
            count++;
        }
        index++;
    }

    std::string num(std::to_string(count));
    result = result + str.at(index) + num;

    return result;
}

void testCompressString()
{
    std::cout << compressString("aabccccaaa");
}

void rotateMatrix(double** matrix, int size)
{
    for (int j = 0; j < size/2; ++j)
    {
        for (int i = j; i < size-j - 1; ++i)
        {
            double tmp = matrix[i][j];
            matrix[i][j] = matrix[j][size - 1 - i];
            matrix[j][size - 1 - i] = matrix[size - 1 - i][size - 1 - j];
            matrix[size - 1 - i][size - 1 - j] = matrix[size - 1 - j][i];
            matrix[size - 1 - j][i] = tmp;
        }
    }
}

void printMatrix(double** matrix, int size)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void testRotateMatrix()
{
    double* matrix[4];
    for (int i = 0; i < 4; ++i)
    {
        matrix[i] = new double[4];
    }

    int counter = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            matrix[i][j] = counter;
            counter++;
        }

    printMatrix(matrix, 4);
    rotateMatrix(matrix, 4);
    std::cout << std::endl;
    printMatrix(matrix, 4);
}

#endif