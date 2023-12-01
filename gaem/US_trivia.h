//
// Created by me on 11/25/2023.
//

#ifndef CLIONPROJECTS_US_TRIVIA_H
#define CLIONPROJECTS_US_TRIVIA_H
#include<iostream>
#include<map>
#include <set>
#include<algorithm>
using namespace std;
int playTrivia() {
    map<string, string> capital;
    capital.insert(make_pair("Alabama", "Montgomery"));
    capital.insert(make_pair("Alaska", "Juneau"));
    capital.insert(make_pair("Arizona", "Phoenix"));
    capital.insert(make_pair("Arkansas", "Little Rock"));
    capital.insert(make_pair("California", "Sacramento"));
    capital.insert(make_pair("Colorado", "Denver"));
    capital.insert(make_pair("Connecticut", "Hartford"));
    capital.insert(make_pair("Delaware", "Dover"));
    capital.insert(make_pair("Florida", "Tallahassee"));
    capital.insert(make_pair("Georgia", "Atlanta"));
    capital.insert(make_pair("Hawaii", "Honolulu"));
    capital.insert(make_pair("Idaho", "Boise"));
    capital.insert(make_pair("Illinois", "Springfield"));
    capital.insert(make_pair("Indiana", "Indianapolis"));
    capital.insert(make_pair("Iowa", "Des Moines"));
    capital.insert(make_pair("Kansas", "Topeka"));
    capital.insert(make_pair("Kentucky", "Frankfort"));
    capital.insert(make_pair("Louisiana", "Baton Rouge"));
    capital.insert(make_pair("Maine", "Augusta"));
    capital.insert(make_pair("Maryland", "Annapolis"));
    capital.insert(make_pair("Massachusetts", "Boston"));
    capital.insert(make_pair("Michigan", "Lansing"));
    capital.insert(make_pair("Minnesota", "Saint Paul"));
    capital.insert(make_pair("Mississippi", "Jackson"));
    capital.insert(make_pair("Missouri", "Jefferson City"));
    capital.insert(make_pair("Montana", "Helena"));
    capital.insert(make_pair("Nebraska", "Lincoln"));
    capital.insert(make_pair("Nevada", "Carson City"));
    capital.insert(make_pair("New Hampshire", "Concord"));
    capital.insert(make_pair("New Jersey", "Trenton"));
    capital.insert(make_pair("New Mexico", "Santa Fe"));
    capital.insert(make_pair("New York", "Albany"));
    capital.insert(make_pair("North Carolina", "Raleigh"));
    capital.insert(make_pair("North Dakota", "Bismarck"));
    capital.insert(make_pair("Ohio", "Columbus"));
    capital.insert(make_pair("Oklahoma", "Oklahoma City"));
    capital.insert(make_pair("Oregon", "Salem"));
    capital.insert(make_pair("Pennsylvania", "Harrisburg"));
    capital.insert(make_pair("Rhode Island", "Providence"));
    capital.insert(make_pair("South Carolina", "Columbia"));
    capital.insert(make_pair("South Dakota", "Pierre"));
    capital.insert(make_pair("Tennessee", "Nashville"));
    capital.insert(make_pair("Texas", "Austin"));
    capital.insert(make_pair("Utah", "Salt Lake City"));
    capital.insert(make_pair("Vermont", "Montpelier"));
    capital.insert(make_pair("Virginia", "Richmond"));
    capital.insert(make_pair("Washington", "Olympia"));
    capital.insert(make_pair("West Virginia", "Charleston"));
    capital.insert(make_pair("Wisconsin", "Madison"));
    capital.insert(make_pair("Wyoming", "Cheyenne"));

    map<string, string>::iterator quiz;
    int right = 0, wrong = 0;
    string check, compare;
    cout << "Guess the capital of all 50 US states, each correct answer is worth 1 point" << endl;
    cout << "type end to finish early" << endl;

    for (quiz = capital.begin(); quiz != capital.end(); quiz++) {
        cout << "what is the capital of: " << quiz->first << endl;
        cin >> check;
        compare = quiz->second;

        //put to lowercase for compare
        transform(check.begin(), check.end(), check.begin(), ::tolower );
        transform(compare.begin(), compare.end(), compare.begin(), ::tolower );

        //remove whitespace for compare
        std::string::iterator end_pos = std::remove(check.begin(), check.end(), ' ');
        check.erase(end_pos, check.end());
        end_pos = std::remove(compare.begin(), compare.end(), ' ');
        compare.erase(end_pos, compare.end());

        //compare
        if (check == compare) {
            cout << "correct" << endl;
            right++;
        } else if (check == "end") {
            break;
        } else {
            cout << "incorrect" << endl;
            wrong++;
        }
    }
    cout << "right ans: " << right << endl;
    cout << "wrong ans: " << wrong << endl;
    return right;
}
#endif //CLIONPROJECTS_US_TRIVIA_H
