#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl "\n"
// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
    {
        return true;
    }
    return false;
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
    {
        return true;
    }
    return false;
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(string str2)
{
    if (str2[0] == '0' || str2[0] == '1' || str2[0] == '2' ||
        str2[0] == '3' || str2[0] == '4' || str2[0] == '5' ||
        str2[0] == '6' || str2[0] == '7' || str2[0] == '8' ||
        str2[0] == '9' || isDelimiter(str2[0]) == true)
    {
        return false;
    }
    return true;
}
// Returns 'true' if the string is a KEYWORD.
bool isKeyword(string str2)
{
    if (str2 == "if" or str2 == "else" or
        str2 == "while" or str2 == "do" or str2 == "break" or
        str2 == "continue" or str2 == "int" or str2 == "double" or
        str2 == "float" or str2 == "return" or str2 == "if" or
        str2 == "char" or str2 == "case" or str2 == "sizeof" or str2 == "long" or
        str2 == "short" or str2 == "typdef" or str2 == "switch" or str2 == "unsigned" or
        str2 == "void" or str2 == "static" or str2 == "struct" or str2 == "goto")
    {
        return true;
    }
    return false;

}

// Returns 'true' if the string is an INTEGER.
bool isInteger(string str2)
{
    int i, len = str2.size();

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str2[i] != '0' && str2[i] != '1' && str2[i] != '2'
            && str2[i] != '3' && str2[i] != '4' && str2[i] != '5'
            && str2[i] != '6' && str2[i] != '7' && str2[i] != '8'
            && str2[i] != '9' || (str2[i] == '-' && i > 0))
        {
            return false;
        }
    }
    return true;
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(string str2)
{
    int i, len = str2.size();
    bool hasDecimal = false;

    if (len == 0)
    {
        return false;
    }
    for (i = 0; i < len; i++)
    {
        if (str2[i] != '0' && str2[i] != '1' && str2[i] != '2'
            && str2[i] != '3' && str2[i] != '4' && str2[i] != '5'
            && str2[i] != '6' && str2[i] != '7' && str2[i] != '8'
            && str2[i] != '9' && str2[i] != '.' ||
            (str2[i] == '-' && i > 0))
        {
            return false;
        }

        if (str2[i] == '.')
        {
            hasDecimal = true;
        }
    }
    return hasDecimal;
}

// Extracts the SUBSTRING.
string subString(string str2, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
        sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str2[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Parsing the input STRING.
void parse(string str2)
{
    int left = 0, right = 0;
    // int len = strlen(str2);
    int len = str2.size();

    while (right <= len && left <= right)
    {
        if (isDelimiter(str2[right]) == false)
            right++;

        if (isDelimiter(str2[right]) == true && left == right)
        {
            if (isOperator(str2[right]) == true)
            {
                printf("'%c' IS AN OPERATOR\n", str2[right]);
                cout << str2[right] << " " << "IS AN OPEARATOR" << nl;
            }
            right++;
            left = right;
        }
        else if (isDelimiter(str2[right]) == true && left != right
            || (right == len && left != right))
        {
            string subStr = subString(str2, left, right - 1);

            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);

            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);

            else if (isRealNumber(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);

            else if (validIdentifier(subStr) == true
                && isDelimiter(str2[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);

            else if (validIdentifier(subStr) == false
                && isDelimiter(str2[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}

// DRIVER FUNCTION
signed main()
{
    // maximum length of string is 100 here 
    // char str2[100] = "int a = b + 1c; ";
    string str2 = "int a - b + 1c;";

    parse(str2); // calling the parse function

    return (0);
}
