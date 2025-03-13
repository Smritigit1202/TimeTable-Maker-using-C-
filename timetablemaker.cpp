#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
using namespace std;

struct Lecture {
    string timeSlot, subject, batch;
};

class TimeTableGenerator {
private:
    vector<string> subjects, batches, professors;
    map<string, vector<string>> professor_subjects;
    map<string, int> lecture_count;
    map<string, map<string, vector<Lecture>>> schedule;
    map<string, map<string, int>> professor_slots, batch_slots;
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    vector<string> time_slots = {"9AM-10AM", "10AM-11AM", "11AM-12PM", "1PM-2PM", "2PM-3PM", "3PM-4PM", "4PM-5PM"};

public:
    void inputData() {
        int numSubjects, numBatches, numProfessors;
        cout << "Enter number of subjects: ";
        cin >> numSubjects;
        subjects.resize(numSubjects);
        cout << "Enter subjects: ";
        for (string &s : subjects) cin >> s;
        
        cout << "Enter number of professors: ";
        cin >> numProfessors;
        professors.resize(numProfessors);
        cout << "Enter professor names: ";
        for (string &p : professors) cin >> p;
        
        for (const string &p : professors) {
            int numSubj;
            cout << "Enter number of subjects for Professor " << p << ": ";
            cin >> numSubj;
            professor_subjects[p].resize(numSubj);
            cout << "Enter subjects: ";
            for (string &s : professor_subjects[p]) cin >> s;
        }
        
        cout << "Enter number of batches: ";
        cin >> numBatches;
        batches.resize(numBatches);
        cout << "Enter batch names: ";
        for (string &b : batches) cin >> b;
        
        for (const string &s : subjects) {
            cout << "Enter number of lectures per week for " << s << ": ";
            cin >> lecture_count[s];
        }
    }
    
    bool isValidAssignment(const string &professor, const string &day) {
        return professor_slots[professor][day] < 3;
    }

    void assignLectures() {
        random_device rd;
        mt19937 gen(rd());
        vector<string> professor_list(professors.begin(), professors.end());
        shuffle(professor_list.begin(), professor_list.end(), gen);
        
        for (const string &professor : professor_list) {
            shuffle(days.begin(), days.end(), gen);
            for (const string &day : days) {
                shuffle(time_slots.begin(), time_slots.end(), gen);
                shuffle(professor_subjects[professor].begin(), professor_subjects[professor].end(), gen);
                for (const string &subject : professor_subjects[professor]) {
                    if (lecture_count[subject] == 0) continue;
                    shuffle(batches.begin(), batches.end(), gen);
                    for (const string &batch : batches) {
                        if (lecture_count[subject] == 0) break;
                        for (const string &slot : time_slots) {
                            if (lecture_count[subject] == 0) break;
                            if (isValidAssignment(professor, day)) {
                                schedule[professor][day].push_back({slot, subject, batch});
                                professor_slots[professor][day]++;
                                batch_slots[batch][day]++;
                                lecture_count[subject]--;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    void printSchedule() {
        for (const auto &profEntry : schedule) {
            cout << "\nTimetable for Professor " << profEntry.first << ":\n";
            for (const auto &dayEntry : profEntry.second) {
                cout << "  " << dayEntry.first << ":\n";
                for (const auto &lecture : dayEntry.second) {
                    cout << "    " << lecture.timeSlot << " - " << lecture.subject << " (Batch: " << lecture.batch << ")\n";
                }
            }
        }
    }
};

int main() {
    TimeTableGenerator timetable;
    timetable.inputData();
    timetable.assignLectures();
    timetable.printSchedule();
    return 0;
}
