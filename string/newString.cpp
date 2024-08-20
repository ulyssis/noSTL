// create a sting class, including its construtor and copy constructor
#include <string>
class String
{
public:
    // default constructor
    String(const char *str = nullptr);
    // copy constructor to take parameter with type String
    String(const String &other);
    // New copy constructor to take parameter with type std::string
    String(const std::string &str);
    // TODO: copy constructor to take parameter with type std::string
    // destructor
    ~String(void);
    // assignment operator
    String &operator=(const String &other);
    // access operator
    const char &operator[](int index) const;
    // equality
    bool operator==(const String &other);
    // TODO: Move Constructor : To efficiently transfer ownership of resources.
    // TODO: Move Assignment Operator : To efficiently transfer ownership of resources.
    // TODO: length functiojn: to get the length of the string
    int getLength(void);
    // TODO: concatenation function: to concatenate two strings
    String *concatenation(const String *other);
    // TODO: clear function: to clear the string
    int clearString(void);
    // TODO: enpty functioin: to check if the string is empty
    bool isStringEmpty(void);
    // pring the string
    void printString(void);

private:
    char *m_data;
};

String::String(const char *str)
{
    if (str == nullptr)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
}

String::String(const String &other)
{
    // get the size of string 'other'
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

String::String(const std::string &other)
{
    int length = other.length();
    m_data = new char[length + 1];
    strcpy(m_data, other.c_str());
}

String::~String()
{
    delete[] m_data;
}

String &String::operator=(const String &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] m_data;
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    return *this;
}

const char &String::operator[](int index) const
{
    if (index < 0 || index > strlen(m_data) - 1)
    {
        // TODO: define a custom exception class.
        printf("index excceeds the scope of the sting!\n");
    }
    return m_data[index];
}

bool String::operator==(const String &other)
{
    if (this == &other)
    {
        return true;
    }
    return strcmp(m_data, other.m_data) == 0;
}

int String::getLength()
{
    if (m_data == nullptr)
    {
        return 0;
    }
    return strlen(m_data);
}

String *String::concatenation(const String *other)
{
    if (other == nullptr)
    {
        return this;
    }

    int lengthOther = strlen(other->m_data);
    int lengthThis = strlen(m_data);
    char *m_data_new = new char[lengthOther + lengthThis + 1];
    strcpy(m_data_new, m_data);
    int i = 0;
    while (i < lengthOther)
    {
        m_data_new[lengthThis + i] = other->m_data[i];
        i++;
    }
    m_data_new[lengthOther + lengthThis + 1] = '\0';
    delete[] m_data;
    // the following two lines is due to thinking in this way:
    //
    // char *m_data = new char[lengthOther + lengthThis + 1];
    // strcpy(m_data, m_data_new);
    m_data = m_data_new;
    // delete[] m_data_new;
    return this;
}

bool String::isStringEmpty(void)
{
    int length = getLength();
    return length != 0;
}

void String::printString()
{
    int length = getLength();
    if (length == 0)
    {
        printf("The string is empty\n");
    }

    for (int i = 0; i < length; i++)
    {
        printf("%c", m_data[i]);
    }
    printf("\n");
}

int main()
{

    // C-style string
    char str0[] = "Nihao";
    char str1[] = "Hello";
    // std::string
    std::string str2 = "Gruezi";

    // custom String classes
    String str3(str1); // calls copy constructor
    String str4(str0); // calls copy constructor
    str3.printString();

    str3.concatenation(&str4);
    str3.printString();

    String str5(str2); // calls copy constructor
    str3.concatenation(&str5);
    str3.printString();
    return 0;
}