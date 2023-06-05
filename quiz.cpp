// asks the user 5 questions and checks the answers
#include <iostream>
#include <stdlib.h>
#include <algorithm> // transform
#include <string>   //transform
#include <fstream> // fstrean

using namespace std;

string subject, nick;
string content[5];
string answerA[5], answerB[5], answerC[5], answerD[5];
string correct_answer[5];
string user_answer;
int points=0;

int main()
{
    int line_no=1;
    string line;
    int question_no=0;

    fstream file;
    file.open("quiz.txt", ios::in);

    if (file.good()== false)
    {
        cout<<"I couldn't read the file!";
        exit(0);
    }

    while(getline(file, line))
    {
        switch (line_no)
        {
            case 1: subject=line;               break;
            case 2: nick=line;                  break;
            case 3: content[question_no]=line;            break;
            case 4: answerA[question_no]=line;            break;
            case 5: answerB[question_no]=line;            break;
            case 6: answerC[question_no]=line;            break;
            case 7: answerD[question_no]=line;            break;
            case 8: correct_answer[question_no]=line;     break;


        }
        if (line_no==8) {line_no=2; question_no++;}
        line_no++;
    }

    file.close();

    for (int i = 0; i <=4; ++i)
    {
        cout<<endl<<content[i]<<endl;
        cout<<"A. "<<answerA[i]<<endl;
        cout<<"B. "<<answerB[i]<<endl;
        cout<<"C. "<<answerC[i]<<endl;
        cout<<"D. "<<answerD[i]<<endl;

        cout<<"Your answer is: ";
        cin>>user_answer;

        transform(user_answer.begin(),user_answer.end(),user_answer.begin(), ::tolower); // converts to lowercase

        if (user_answer==correct_answer[i])
        {
            cout<<"Well done! That's 1 point for you."<<endl;
            points++;
        } else cout<<"Wrong answer! No points for this question. Correct answer is: "<<correct_answer[i]<<endl;


    }

    cout<<"End of our Quiz. total points: "<<points;
    return 0;
}
