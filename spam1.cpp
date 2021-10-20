#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int countFreq(string text, string subtext)
{
    int subtextLength = subtext.length();
    int textLength = text.length();
    int counter = 0;

    for (int i = 0; i <= textLength - subtextLength; i++)
    {
        int j;
        for (j = 0; j < subtextLength; j++)
        {
            if (text[i+j] != subtext[j])
            {
                break;
            }
        }

        if (j == subtextLength)
        {
           counter++;
        }
    }
    return counter;
}

int calculateSpamGrade(string inputText)
{
    int grade = 0;
    grade+= countFreq(inputText, "$") * 10;
    grade+= countFreq(inputText, "earn per week") * 20;
    grade+= countFreq(inputText, "double your") * 20;
    grade+= countFreq(inputText, "income in one week") * 15;
    grade+= countFreq(inputText, "trial that lasts forever") * 30;
    grade+= countFreq(inputText, "opportunity") * 10;
    grade+= countFreq(inputText, "income") * 10;
    grade+= countFreq(inputText, "cash") * 20;
    grade+= countFreq(inputText, "month free trial") * 15;
    grade+= countFreq(inputText, "your love life") * 25;
    return grade;
}

int number_of_spam_words(string inputText)
{
    int word = 0;
    word+= countFreq(inputText, "$") * 1;
    word+= countFreq(inputText, "earn per week") * 3;
    word+= countFreq(inputText, "double your") * 2;
    word+= countFreq(inputText, "income in one week") * 4;
    word+= countFreq(inputText, "trial that lasts forever") * 4;
    word+= countFreq(inputText, "opportunity") * 1;
    word+= countFreq(inputText, "income") * 1;
    word+= countFreq(inputText, "cash") * 1;
    word+= countFreq(inputText, "month free trial") * 3;
    word+= countFreq(inputText, "your love life") * 3;
    return word;
}

int main()
{
    std::ifstream mail;
    mail.open("mail.txt");
    std::string buffer;
    std::string line;

    while(mail)
        {
        std::getline(mail, line);
        }
    mail.close();

    line.erase(std::remove(line.begin(), line.end(), '.'), line.end());
    line.erase(std::remove(line.begin(), line.end(), ','), line.end());
    line.erase(std::remove(line.begin(), line.end(), '!'), line.end());

    transform(line.begin(), line.end(), line.begin(), ::tolower);
    cout << line << endl;

    int spamGrade = calculateSpamGrade(line);
    int spamWord = number_of_spam_words(line);

    int number_of_words;
    number_of_words = std::count(line.begin(), line.end(), ' ') + 1;

    float spamPercentage;
    spamPercentage = ((spamWord)/(number_of_words * 1.00) * 100);

    ofstream result;
    result.open("result.txt");
    result << "Number of spam words in the string: " << spamWord << endl;
    result << "There are " << number_of_words << " words in the string." << endl;
    result << "The score is: " << spamGrade << " points, " << " ";

    if(spamGrade < 10)
        result << "Not Spam!" << endl;
    else if((spamGrade >= 10 && spamGrade < 50))
        result << "Maybe Spam!" << endl;
    else
        result << "Definitely Spam!" << endl;

    result << "The percentage is: " << spamPercentage << "%, " << " ";

    if(spamPercentage < 15)
        result << "Not Spam!" << endl;
    else if(spamPercentage >= 15 && spamPercentage < 50)
        result << "Maybe Spam!" << endl;
    else
        result << "Definitely Spam!" << endl;

    result.close();
    return 0;
}
