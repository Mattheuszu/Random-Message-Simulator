#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Message
{
private:
    string senderName;
    string timeStamp;
    string message;
    bool sent;

public:
    Message(string senderName, string timeStamp, string message)
    {
        this->senderName = senderName;
        this->timeStamp = timeStamp;
        this->message = message;
        sent = false;
    }

    void setSent()
    {
        sent = true;
    }

    bool isSent()
    {
        return sent;
    }

    void display()
    {
        // Очистити консоль
        system("clear"); 

        // Перевірте відправника та відобразіть повідомлення відповідно
        if (senderName == "Sender 1")
        {
            cout << left << setw(20) << senderName << timeStamp << endl;
            cout << setw(20) << "" << message << endl;
        }
        else
        {
            cout << right << setw(20) << senderName << timeStamp << endl;
            cout << setw(20) << "" << message << endl;
        }
    }
};

int main()
{
    srand(time(0));

    vector<Message> messages;
    int sentMessages = 0;

    string senderNames[2] = { "Sender 1", "Sender 2" };
    string message = "";
    char input;
    int time = 0;

    while (sentMessages < 100 && input != 27)
    {
        // Виберіть випадкового відправника
        int senderIndex = rand() % 2;
        string senderName = senderNames[senderIndex];

        // Згенеруйте випадкову кількість слів для повідомлення
        int wordCount = 3 + rand() % 8;

        // Згенеруйте повідомлення
        message = "";
        for (int i = 0; i < wordCount; i++)
        {
            int wordLength = 1 + rand() % 8;

            for (int j = 0; j < wordLength; j++)
            {
                message += 'a' + rand() % 26;
            }

            message += ' ';
        }

        // Згенеруйте мітку часу
        time += 1 + rand() % 10;
        string timeStamp = " " + to_string(time) + " seconds ago";

        // Додати повідомлення до списку повідомлень
        messages.push_back(Message(senderName, timeStamp, message));

        // Відобразити повідомлення
        messages[sentMessages].display();

        //  Дочекайтеся, поки користувач натисне клавішу
        input = cin.get();

        // Позначте повідомлення як відправлене
        messages[sentMessages].setSent();

        // Збільшити кількість надісланих повідомлень
        sentMessages++;
    }

    return 0;
}