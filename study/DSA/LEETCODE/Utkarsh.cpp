#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

// ─────────────────────────────────────────────
//  CONSTANTS
// ─────────────────────────────────────────────
const int    MAX_SUBJECTS    = 6;
const string DATA_FILE       = "students.dat";
const string SUBJECT_FILE    = "subjects.dat";

const string SUBJECTS_DEFAULT[MAX_SUBJECTS] = {
    "Mathematics", "Physics", "Chemistry",
    "English", "Computer Science", "Biology"
};

// ─────────────────────────────────────────────
//  STRUCTURE: Subject
// ─────────────────────────────────────────────
struct Subject {
    char name[40];
    int  maxMarks;
    int  passMarks;

    Subject() : maxMarks(100), passMarks(35) {//Initializer  list it is like auto assining
        strncpy(name, "Unknown", sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';// places a null terminator '\0' at the very last position of the array (index 39)
    }
};

// ─────────────────────────────────────────────
//  STRUCTURE: MarksRecord
// ─────────────────────────────────────────────
struct MarksRecord {
    int  marks[MAX_SUBJECTS];     // obtained marks
    bool appeared[MAX_SUBJECTS];  // whether student appeared

    MarksRecord()   {
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            marks[i]    = 0;
            appeared[i] = true;
        }
    }
};

// ─────────────────────────────────────────────
//  BASE CLASS: Person
// ─────────────────────────────────────────────
class Person {
    protected:
        char name[60];
        int  age;
        char gender;   // 'M' / 'F' / 'O'
        char contact[10];

    public:
        Person() : age(0), gender('M') {
            strncpy(name,"Unknown", sizeof(name) - 1);
            strncpy(contact, "N/A",     sizeof(contact) - 1);
            name[sizeof(name)-1]    = '\0';
            contact[sizeof(contact)-1] = '\0';
        }

        void setName (const string& n){ 
            strncpy(name,n.c_str(), sizeof(name)-1);//because strncpy uses  const char* as source
            name[sizeof(name)-1] = '\0'; 
        }
        void setContact(const string& c){ 
            strncpy(contact, c.c_str(), sizeof(contact)-1); 
            contact[sizeof(contact)-1] = '\0'; 
        }
        void setAge(int a){ 
            age = a; 
        }
        void setGender (char g){ 
            gender = g; 
        }


        string getName()    const { return string(name);    }  // converts char name[60] → std::string
        string getContact() const { return string(contact); }
        int    getAge()     const { return age;    }
        char   getGender()  const { return gender; }
};

// ─────────────────────────────────────────────
//  DERIVED CLASS: Student  (inherits Person)
// ─────────────────────────────────────────────
class Student : public Person {

    private:
        int rollNo;
        char department[40];
        int semester;
        int year;           // academic year
        MarksRecord result;

    public:
        Student() : rollNo(0), semester(1), year(2024) {
            strncpy(department, "General", sizeof(department) - 1);
            department[sizeof(department)-1] = '\0';
        }

        // ── Setters ──────────────────────────────
        void setRollNo    (int r){ rollNo    = r; }
        void setSemester  (int s){ semester  = s; }
        void setYear      (int y){ year      = y; }
        void setDepartment(const string& d)  { strncpy(department, d.c_str(), sizeof(department)-1); department[sizeof(department)-1]='\0'; }
        void setMarks     (int subIdx, int m){ result.marks[subIdx]    = m;    }
        void setAppeared  (int subIdx, bool a){ result.appeared[subIdx] = a;   }

        // ── Getters ──────────────────────────────
        int getRollNo() const { return rollNo;    }
        //                ↑
        //  means: this function will NOT modify the object
        int         getSemester()           const { return semester;  }
        int         getYear()               const { return year;      }
        string      getDepartment()         const { return string(department); }
        int         getMarks(int i)         const { return result.marks[i];    }
        bool        getAppeared(int i)      const { return result.appeared[i]; }
        MarksRecord getResult()             const { return result; }

        // ── Grade Calculation ─────────────────────
        /*
        *  Grade Scale:
        *   90–100 → A+   (10 points)
        *   80–89  → A    (9  points)
        *   70–79  → B+   (8  points)
        *   60–69  → B    (7  points)
        *   50–59  → C    (6  points)
        *   40–49  → D    (5  points)
        *   35–39  → E    (4  points)
        *   <  35  → F    (0  points / FAIL)
        */
        static string gradeFromPercent(double pct) {
            if (pct >= 90) return "A+";
            if (pct >= 80) return "A";
            if (pct >= 70) return "B+";
            if (pct >= 60) return "B";
            if (pct >= 50) return "C";
            if (pct >= 40) return "D";
            if (pct >= 35) return "E";
            return "F";
        }

        static double gradePoints(const string& grade) {
            if (grade == "A+") return 10.0;
            if (grade == "A")  return 9.0;
            if (grade == "B+") return 8.0;
            if (grade == "B")  return 7.0;
            if (grade == "C")  return 6.0;
            if (grade == "D")  return 5.0;
            if (grade == "E")  return 4.0;
            return 0.0;
        }

        // Returns total marks obtained (only in appeared subjects)
        int getTotalMarks(const Subject subjects[], int numSubjects) const {
            int total = 0;
            for (int i = 0; i < numSubjects; i++)
                if (result.appeared[i]) total += result.marks[i];
            return total;
        }

        // Returns maximum possible marks
        int getMaxPossible(const Subject subjects[], int numSubjects) const {
            int total = 0;
            for (int i = 0; i < numSubjects; i++)
                if (result.appeared[i]) total += subjects[i].maxMarks;
            return total;
        }

        // Returns overall percentage
        double getPercentage(const Subject subjects[], int numSubjects) const {
            int maxP = getMaxPossible(subjects, numSubjects);
            if (maxP == 0) return 0.0; 
            return (double)getTotalMarks(subjects, numSubjects) / maxP * 100.0;
        }

        // Returns CGPA (average grade points across subjects)
        double getCGPA(const Subject subjects[], int numSubjects) const {
            double totalGP  = 0.0;
            int    count    = 0;
            for (int i = 0; i < numSubjects; i++) {
                if (!result.appeared[i]) continue;
                double pct = (subjects[i].maxMarks > 0)
                            ? (double)result.marks[i] / subjects[i].maxMarks * 100.0
                            : 0.0;
                totalGP += gradePoints(gradeFromPercent(pct));
                count++;
            }
            return (count > 0) ? totalGP / count : 0.0;
        }

        // Returns PASS / FAIL
        string getStatus(const Subject subjects[], int numSubjects) const {
            for (int i = 0; i < numSubjects; i++) {
                if (!result.appeared[i]) continue;
                if (result.marks[i] < subjects[i].passMarks) return "FAIL";
            }
            return "PASS";
        }

        // Returns overall letter grade
        string getOverallGrade(const Subject subjects[], int numSubjects) const {
            if (getStatus(subjects, numSubjects) == "FAIL") return "F";
            return gradeFromPercent(getPercentage(subjects, numSubjects));
        }
};

// ─────────────────────────────────────────────
//  CLASS: SubjectManager
// ─────────────────────────────────────────────
class SubjectManager {
public:
    Subject subjects[MAX_SUBJECTS];
    int     numSubjects;

    SubjectManager() : numSubjects(MAX_SUBJECTS) {
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            strncpy(subjects[i].name, SUBJECTS_DEFAULT[i].c_str(), 39);
            subjects[i].name[39]  = '\0';
            subjects[i].maxMarks  = 100;
            subjects[i].passMarks = 35;
        }
        loadFromFile();
    }

    void saveToFile() {
        ofstream f(SUBJECT_FILE, ios::binary);
        if (!f) return;
        f.write(reinterpret_cast<char*>(&numSubjects), sizeof(numSubjects));
        f.write(reinterpret_cast<char*>(subjects),     sizeof(Subject) * MAX_SUBJECTS);
    }

    void loadFromFile() {
        ifstream f(SUBJECT_FILE, ios::binary);
        if (!f) return;
        f.read(reinterpret_cast<char*>(&numSubjects), sizeof(numSubjects));
        f.read(reinterpret_cast<char*>(subjects),     sizeof(Subject) * MAX_SUBJECTS);
    }

    void display() const {
        cout << "\n  +--------------------------------------------------+\n";
        cout <<   "  | #  | Subject            | Max Marks| Pass Marks  |\n";
        cout <<   "  +--------------------------------------------------+\n";
        for (int i = 0; i < numSubjects; i++) {
            cout << "  | " << setw(2) << (i+1) << " | "
                 << left  << setw(18) << subjects[i].name   << " | "
                 << right << setw(8)  << subjects[i].maxMarks  << " | "
                 << setw(10) << subjects[i].passMarks << " |\n";
        }
        cout << "  +---------------------------------------------------+\n";
    }

    void edit(int idx) {
        if (idx < 0 || idx >= numSubjects) return;
        cout << "\n  Current Name: " << subjects[idx].name << "\n";
        cout << "  New Name (Enter to keep): ";
        cin.ignore();
        string inp; getline(cin, inp);
        if (!inp.empty()) strncpy(subjects[idx].name, inp.c_str(), 39);

        cout << "  Max Marks [" << subjects[idx].maxMarks << "]: ";
        string tmp; getline(cin, tmp);
        if (!tmp.empty()) subjects[idx].maxMarks = stoi(tmp);

        cout << "  Pass Marks [" << subjects[idx].passMarks << "]: ";
        getline(cin, tmp);
        if (!tmp.empty()) subjects[idx].passMarks = stoi(tmp);

        saveToFile();
        cout << "  ✔  Subject updated.\n";
    }
};

// ─────────────────────────────────────────────
//  CLASS: StudentManager
// ─────────────────────────────────────────────
class StudentManager {
private:
    vector<Student> students;
    SubjectManager& sm;

    // ── File Persistence ──────────────────────
    void saveToFile() {
        ofstream f(DATA_FILE, ios::binary);
        if (!f) { cerr << "  ✘  Cannot open data file!\n"; return; }
        int count = (int)students.size();
        f.write(reinterpret_cast<char*>(&count), sizeof(count));
        for (auto& s : students)
            f.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }

    void loadFromFile() {
        ifstream f(DATA_FILE, ios::binary);
        if (!f) return;
        int count = 0;
        if (!f.read(reinterpret_cast<char*>(&count), sizeof(count))) {
            cout << "File corrupted!\n";
            return;
        }        
        students.resize(count);
        for (auto& s : students)
            f.read(reinterpret_cast<char*>(&s), sizeof(Student));
    }

    // ── Find by roll number ───────────────────
    int findByRoll(int roll) const {
        for (int i = 0; i < (int)students.size(); i++)
            if (students[i].getRollNo() == roll) return i;
        return -1;
    }

    // ── Roll number uniqueness check ──────────
    bool rollExists(int roll) const { return findByRoll(roll) != -1; }

    // ── Input helpers ─────────────────────────
    int    readInt   (const string& prompt, int lo = INT_MIN, int hi = INT_MAX) {
        int v;
        while (true) {
            cout << prompt;
            if (cin >> v && v >= lo && v <= hi) return v;
            cout << "    Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    string readStr(const string& prompt) {
        string s;
        cout << prompt;
        cin.ignore();
        getline(cin, s);
        return s;
    }
    string readStrNoIgnore(const string& prompt) {
        string s;
        cout << prompt;
        getline(cin, s);
        return s;
    }

public:
    StudentManager(SubjectManager& subMgr) : sm(subMgr) { loadFromFile(); }

    // ════════════════════════════════════════
    //  1. ADD STUDENT
    // ════════════════════════════════════════
    void addStudent() {
        cout << "\n  +--------------------------------------------------+\n";
        cout <<   "  |     ADD NEW STUDENT                              |\n";
        cout <<   "  +--------------------------------------------------+\n";

        Student s;

        int roll = readInt("  Roll No          : ");
        if (rollExists(roll)) {
            cout << "  ✘  Roll No already exists!\n"; return;
        }
        s.setRollNo(roll);

        string name = readStr("  Full Name         : ");
        s.setName(name);

        int age = readInt("  Age               : ", 10, 100);
        s.setAge(age);

        cout << "  Gender (M/F/O)     : ";
        char g; cin >> g;
        s.setGender(toupper(g));

        string dept = readStrNoIgnore("  Department        : ");
        cin >> dept;          
        s.setDepartment(dept);

        int sem = readInt("  Semester (1-8)    : ", 1, 8);
        s.setSemester(sem);

        int yr = readInt("  Academic Year     : ", 2000, 2100);
        s.setYear(yr);

        string contact = readStr("  Contact No        : ");
        s.setContact(contact);

        students.push_back(s);
        saveToFile();
        cout << "    Student added successfully (Roll No: " << roll << ").\n";
    }

    // ════════════════════════════════════════
    //  2. UPDATE STUDENT DETAILS
    // ════════════════════════════════════════
    void updateStudent() {
        cout << "\n  +--------------------------------------------------+\n";
        cout <<   "  |   UPDATE STUDENT DETAILS                         | \n";
        cout <<   "  +--------------------------------------------------+\n";

        int roll = readInt("  Enter Roll No to update: ");
        int idx  = findByRoll(roll);
        if (idx == -1) { cout << "   Student not found!\n"; return; }

        Student& s = students[idx];
        cout << "\n  Updating: " << s.getName() << " (Leave blank to keep current)\n\n";

        cin.ignore();
        auto keepOrUpdate = [](const string& cur) -> string {
            string inp; getline(cin, inp);
            return inp.empty() ? cur : inp;
        };

        cout << "  Full Name  [" << s.getName()      << "]: "; s.setName(keepOrUpdate(s.getName()));
        cout << "  Department [" << s.getDepartment() << "]: "; s.setDepartment(keepOrUpdate(s.getDepartment()));
        cout << "  Contact    [" << s.getContact()    << "]: "; s.setContact(keepOrUpdate(s.getContact()));

        cout << "  Age        [" << s.getAge() << "]: ";
        string tmp; getline(cin, tmp);
        if (!tmp.empty()) s.setAge(stoi(tmp));

        cout << "  Semester   [" << s.getSemester() << "]: ";
        getline(cin, tmp);
        if (!tmp.empty()) s.setSemester(stoi(tmp));

        cout << "  Year       [" << s.getYear() << "]: ";
        getline(cin, tmp);
        if (!tmp.empty()) s.setYear(stoi(tmp));

        saveToFile();
        cout << "    Student updated.\n";
    }

    // ════════════════════════════════════════
    //  3. DELETE STUDENT
    // ════════════════════════════════════════
    void deleteStudent() {
        int roll = readInt("  Enter Roll No to delete: ");
        int idx  = findByRoll(roll);
        if (idx == -1) { cout << "  ✘  Student not found!\n"; return; }

        cout << "  Deleting: " << students[idx].getName() << "  — Confirm? (y/n): ";
        char c; cin >> c;
        if (tolower(c) == 'y') {
            students.erase(students.begin() + idx);
            saveToFile();
            cout << "    Student deleted.\n";
        } else {
            cout << "  Cancelled.\n";
        }
    }

    // ════════════════════════════════════════
    //  4. ENTER / UPDATE MARKS
    // ════════════════════════════════════════
    void enterMarks() {
        cout << "\n  +--------------------------------------------------+\n";
        cout <<   "  |      ENTER MARKS                                 |\n";
        cout <<   "  +--------------------------------------------------+\n";

        int roll = readInt("  Enter Roll No: ");
        int idx  = findByRoll(roll);
        if (idx == -1) { cout << "    Student not found!\n"; return; }

        Student& s = students[idx];
        cout << "\n  Student: " << s.getName() << "\n";
        sm.display();
        cout << "\n  Enter marks for each subject (enter -1 if absent):\n\n";

        for (int i = 0; i < sm.numSubjects; i++) {
            int m = readInt("  " + string(sm.subjects[i].name) +
                            " (0-" + to_string(sm.subjects[i].maxMarks) + ", -1=absent): ",
                            -1, sm.subjects[i].maxMarks);
            if (m == -1) {
                s.setAppeared (i, false);
                s.setMarks    (i, 0);
            } else {
                s.setAppeared (i, true);
                s.setMarks    (i, m);
            }
        }

        saveToFile();
        cout << "  ✔  Marks saved.\n";
    }

    // ════════════════════════════════════════
    //  5. DISPLAY SINGLE STUDENT RESULT
    // ════════════════════════════════════════
    void displayResult(int idx) const {
        const Student& s = students[idx];
        string status = s.getStatus(sm.subjects, sm.numSubjects);

        cout << "\n";
        cout << "  +-------------------------------------------------------------+\n";
        cout << "  |              STUDENT RESULT CARD                           |\n";
        cout << "  +------------------------------------------------------------+\n";
        cout << "  |  Roll No  : " << left << setw(49) << s.getRollNo()     << "|\n";
        cout << "  |  Name     : " << setw(49) << s.getName()               << "|\n";
        cout << "  |  Dept     : " << setw(49) << s.getDepartment()         << "|\n";
        cout << "  |  Semester : " << setw(49) << s.getSemester()           << "|\n";
        cout << "  |  Year     : " << setw(49) << s.getYear()               << "|\n";
        cout << "  +------------------------------------------------------------+\n";
        cout << "  |  Subject             |Marks| Max | %age  |Grade| Points |   |\n";
        cout << "  +----------------------+-----+-----+-------+-----+--------+---+\n";

        for (int i = 0; i < sm.numSubjects; i++) {
            string subName = string(sm.subjects[i].name);
            if (!s.getAppeared(i)) {
                cout << "  |  " << left << setw(20) << subName
                     << "|  AB |     |       |  -  |   -    |   |\n";
                continue;
            }
            int    m   = s.getMarks(i);
            int    mx  = sm.subjects[i].maxMarks;
            double pct = (mx > 0) ? (double)m / mx * 100.0 : 0.0;
            string gr  = Student::gradeFromPercent(pct);
            double gp  = Student::gradePoints(gr);

            cout << "  | " << left << setw(20) << subName
                 << "|" << right << setw(5) << m
                 << "|" << setw(5)   << mx
                 << "|" << setw(6)   << fixed << setprecision(1) << pct << " "
                 << "|" << setw(5)   << gr
                 << "|" << setw(6)   << fixed << setprecision(1) << gp << "  |   |\n";
        }

        cout << "  +----------------------+-----+-----+-------+-----+--------+---+\n";

        double pct  = s.getPercentage(sm.subjects, sm.numSubjects);
        double cgpa = s.getCGPA      (sm.subjects, sm.numSubjects);
        string ovGr = s.getOverallGrade(sm.subjects, sm.numSubjects);

        cout << "  | Total  : " << setw(4) << s.getTotalMarks(sm.subjects, sm.numSubjects)
             << " / " << setw(4) << s.getMaxPossible(sm.subjects, sm.numSubjects)
             << "   Percentage : " << setw(6) << fixed << setprecision(2) << pct << "%"
             << setw(16) << "|\n";
        cout << "  |  CGPA   : " << fixed << setprecision(2) << cgpa
             << "   Overall Grade : " << setw(3) << ovGr
             << "   Result : " << setw(4) << status
             << setw(12) << "|\n";
        cout << "  |\n";
    }

    void showStudentResult() {
        int roll = readInt("  Enter Roll No: ");
        int idx  = findByRoll(roll);
        if (idx == -1) { cout << "    Student not found!\n"; return; }
        displayResult(idx);
    }

    // ════════════════════════════════════════
    //  6. DISPLAY ALL STUDENTS (table)
    // ════════════════════════════════════════
    void displayAll() const {
        if (students.empty()) { cout << "  No students found.\n"; return; }

        cout << "\n";
        cout << "    +---------------------------+------+--------------------+--------+--------+--------+-------+\n";
        cout <<   "  | #  | Name                 | Roll | Department         |  Sem   | %age   |  CGPA  |Status |\n";
        cout <<   "  +---------------------------+------+--------------------+--------+--------+--------+-------+\n";

        for (int i = 0; i < (int)students.size(); i++) {
            const Student& s = students[i];
            cout << "  | " << right << setw(2) << (i+1) << " | "
                 << left  << setw(20) << s.getName().substr(0,20)  << " | "
                 << right << setw(4)  << s.getRollNo()             << " | "
                 << left  << setw(18) << s.getDepartment().substr(0,18) << " | "
                 << right << setw(6)  << s.getSemester()           << " | "
                 << setw(5) << fixed << setprecision(1) << s.getPercentage(sm.subjects, sm.numSubjects) << "% | "
                 << setw(6) << fixed << setprecision(2) << s.getCGPA(sm.subjects, sm.numSubjects) << " | "
                 << setw(4) << s.getStatus(sm.subjects, sm.numSubjects) << "  |\n";
        }
        cout << "  +--------------------------------------------------+\n";
        cout << "  Total students: " << students.size() << "\n";
    }

    // ════════════════════════════════════════
    //  7. RANK LIST GENERATION
    // ════════════════════════════════════════
    void generateRankList() {
        if (students.empty()) { cout << "  No students.\n"; return; }

        // Create index vector and sort by percentage descending
        vector<int> order(students.size());
        for (int i = 0; i < (int)order.size(); i++) order[i] = i;

        sort(order.begin(), order.end(), [&](int a, int b){
            return students[a].getPercentage(sm.subjects, sm.numSubjects) >
                   students[b].getPercentage(sm.subjects, sm.numSubjects);
        });

        cout << "\n";
        cout << "  +------------------------------------------------------+\n";
        cout << "  |                    RANK LIST                         |\n";
        cout << "  +------------------------------------------------------+\n";
        cout << "  +------+-----------------------+-------+---------+-----+\n";
        cout << "  | Rank | Name                 | Roll | %age   |  CGPA  |Status|\n";
        cout << "  +------+----------------------+------+--------+--------+\n";

        int rank = 1;
        for (int idx : order) {
            const Student& s = students[idx];
            double pct  = s.getPercentage(sm.subjects, sm.numSubjects);
            double cgpa = s.getCGPA(sm.subjects, sm.numSubjects);
            string st   = s.getStatus(sm.subjects, sm.numSubjects);
            cout << "  | " << right << setw(4) << rank++ << " | "
                 << left  << setw(20) << s.getName().substr(0,20) << " | "
                 << right << setw(4)  << s.getRollNo()           << " | "
                 << setw(5) << fixed << setprecision(1) << pct   << "% | "
                 << setw(6) << fixed << setprecision(2) << cgpa  << " | "
                 << setw(4) << st << "  |\n";
        }
        cout << "  +------+----------------------+------+--------+--------+\n";
        cout << "\n  🏆  Topper : " << students[order[0]].getName()
             << "  (" << fixed << setprecision(2)
             << students[order[0]].getPercentage(sm.subjects, sm.numSubjects) << "%)\n";
    }

    // ════════════════════════════════════════
    //  8. SEARCH
    // ════════════════════════════════════════
    void search() {
        cout << "\n  Search by:\n";
        cout << "  1. Roll Number\n";
        cout << "  2. Name\n";
        cout << "  3. Department\n";
        int ch = readInt("  Choice: ", 1, 3);

        if (ch == 1) {
            int roll = readInt("  Roll No: ");
            int idx  = findByRoll(roll);
            if (idx == -1) { cout << "  ✘  Not found!\n"; return; }
            displayResult(idx);
            return;
        }

        string key = readStr("  Enter search term: ");
        transform(key.begin(), key.end(), key.begin(), ::tolower);

        vector<int> found;
        for (int i = 0; i < (int)students.size(); i++) {
            string field = (ch == 2) ? students[i].getName() : students[i].getDepartment();
            transform(field.begin(), field.end(), field.begin(), ::tolower);
            if (field.find(key) != string::npos) found.push_back(i);
        }

        if (found.empty()) { cout << "  ✘  No matches found.\n"; return; }
        cout << "  Found " << found.size() << " result(s):\n";
        for (int i : found) displayResult(i);
    }

    // ════════════════════════════════════════
    //  9. STATISTICS
    // ════════════════════════════════════════
    void showStats() {
        if (students.empty()) { cout << "  No data.\n"; return; }

        int    total    = (int)students.size();
        int    passed   = 0, failed = 0;
        double sumPct   = 0.0;
        double highest  = -1, lowest = 101;
        int    topIdx   = 0, botIdx = 0;

        // Grade distribution using STL set for tracking unique grades
        set<string> gradeSet = {"A+", "A", "B+", "B", "C", "D", "E", "F"};
        vector<pair<string,int>> gradeDist;
        for (auto& g : gradeSet) gradeDist.push_back({g, 0});

        for (int i = 0; i < total; i++) {
            double pct = students[i].getPercentage(sm.subjects, sm.numSubjects);
            sumPct += pct;
            if (pct > highest) { highest = pct; topIdx = i; }
            if (pct < lowest)  { lowest  = pct; botIdx = i; }
            if (students[i].getStatus(sm.subjects, sm.numSubjects) == "PASS") passed++;
            else failed++;

            string gr = students[i].getOverallGrade(sm.subjects, sm.numSubjects);
            for (auto& p : gradeDist)
                if (p.first == gr) { p.second++; break; }
        }

        cout << "\n  +--------------------------------------------------+\n";
        cout <<   "  |          CLASS STATISTICS                        |\n";
        cout <<   "  +--------------------------------------------------+\n";
        cout <<   "  Total Students  : " << total          << "\n";
        cout <<   "  Passed          : " << passed         << "\n";
        cout <<   "  Failed          : " << failed         << "\n";
        cout <<   "  Pass %          : " << fixed << setprecision(1) << (double)passed/total*100.0 << "%\n";
        cout <<   "  Class Average   : " << fixed << setprecision(2) << sumPct/total << "%\n";
        cout <<   "  Highest Score   : " << fixed << setprecision(2) << highest
             << "% (" << students[topIdx].getName() << ")\n";
        cout <<   "  Lowest Score    : " << fixed << setprecision(2) << lowest
             << "% (" << students[botIdx].getName() << ")\n";

        cout << "\n  Grade Distribution:\n";
        cout << "  +--------------------------------------------------+\n";
        cout << "  | Grade | Count | Bar                              |\n";
        cout << "  +--------------------------------------------------+\n";
        for (auto& p : gradeDist) {
            int bars = (total > 0) ? (p.second * 24 / total) : 0;
            cout << "  |  " << setw(3) << p.first << "  | " << setw(5) << p.second << " | "
                 << string(bars, '#') << string(24-bars, ' ') << "|\n";
        }
        cout << "  +------+----------------------+------+--------+--------+\\n";
    }

    // ════════════════════════════════════════
    //  10. EXPORT RESULTS TO TEXT FILE
    // ════════════════════════════════════════
    void exportToText() {
        string filename = "results_export.txt";
        ofstream f(filename);
        if (!f) { cout << "  ✘  Cannot create file!\n"; return; }

        f << "+--------------------------------------------------+\n";
        f << "|   Student Result Management System               |\n";
        f << "+--------------------------------------------------+\n\n";

        // Sort by roll number for export
        vector<int> order(students.size());
        for (int i = 0; i < (int)order.size(); i++) order[i] = i;
        sort(order.begin(), order.end(), [&](int a, int b){
            return students[a].getRollNo() < students[b].getRollNo();
        });

        for (int idx : order) {
            const Student& s = students[idx];
            f << "Roll No: " << s.getRollNo() << "  |  Name: " << s.getName() << "\n";
            f << "Department: " << s.getDepartment() << "  Semester: " << s.getSemester() << "\n";
            f << string(60, '-') << "\n";
            for (int i = 0; i < sm.numSubjects; i++) {
                if (!s.getAppeared(i)) {
                    f << "  " << setw(22) << sm.subjects[i].name << ": Absent\n";
                    continue;
                }
                double pct = (sm.subjects[i].maxMarks > 0)
                             ? (double)s.getMarks(i) / sm.subjects[i].maxMarks * 100.0 : 0.0;
                f << "  " << left << setw(22) << sm.subjects[i].name
                  << ": " << right << setw(3) << s.getMarks(i)
                  << "/" << sm.subjects[i].maxMarks
                  << "  " << setw(5) << fixed << setprecision(1) << pct << "%"
                  << "  [" << Student::gradeFromPercent(pct) << "]\n";
            }
            f << "  Total: " << s.getTotalMarks(sm.subjects, sm.numSubjects)
              << "/" << s.getMaxPossible(sm.subjects, sm.numSubjects)
              << "  CGPA: " << fixed << setprecision(2) << s.getCGPA(sm.subjects, sm.numSubjects)
              << "  Result: " << s.getStatus(sm.subjects, sm.numSubjects) << "\n";
            f << string(60, '=') << "\n\n";
        }

        f.close();
        cout << "  ✔  Exported to '" << filename << "'\n";
    }

    int count() const { return (int)students.size(); }
};
// ─────────────────────────────────────────────
//  MENU HELPERS
// ─────────────────────────────────────────────
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void banner() {
    cout << "\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  |                                                  |\n";
    cout << "  |     Student Record & Result Management System    |\n";
    cout << "  |                                                  |\n";
    cout << "  +--------------------------------------------------+\n";
}

void mainMenu(int count) {
    cout << "\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  |            MAIN MENU                             |\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  |  STUDENT RECORDS                                 |\n";
    cout << "  |   1.  Add New Student                            |\n";
    cout << "  |   2.  Update Student Details                     |\n";
    cout << "  |   3.  Delete Student                             |\n";
    cout << "  |   4.  Search Student                             |\n";
    cout << "  |   5.  Display All Students                       |\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  |  MARKS & RESULTS                                 |\n";
    cout << "  |   6.  Enter / Update Marks                       |\n";
    cout << "  |   7.  View Student Result Card                   |\n";
    cout << "  |   8.  Generate Rank List                         |\n";
    cout << "  |   9.  Class Statistics                           |\n";
    cout << "  |  10.  Export Results to Text File                |\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  |  SUBJECTS                                        |\n";
    cout << "  |  11.  View Subjects                              |\n";
    cout << "  |  12.  Edit Subject                               |\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  |   0.  Exit                                       |\n";
    cout << "  +--------------------------------------------------+\n";
    cout << "  Total students in database: " << count << "\n";
    cout << "  Enter choice: ";
}

// ─────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────
int main() {
    SubjectManager sm;
    StudentManager mgr(sm);

    banner();

    int choice = -1;
    while (choice != 0) {
        mainMenu(mgr.count());

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }

        cout << "\n";
        switch (choice) {
            case 1:  mgr.addStudent();       break;
            case 2:  mgr.updateStudent();    break;
            case 3:  mgr.deleteStudent();    break;
            case 4:  mgr.search();           break;
            case 5:  mgr.displayAll();       break;
            case 6:  mgr.enterMarks();       break;
            case 7:  mgr.showStudentResult();break;
            case 8:  mgr.generateRankList(); break;
            case 9:  mgr.showStats();        break;
            case 10: mgr.exportToText();     break;
            case 11: sm.display();           break;
            case 12: {
                sm.display();
                cout << "  Enter subject number to edit (1-" << sm.numSubjects << "): ";
                int n; cin >> n;
                sm.edit(n-1);
                break;
            }
            case 0:
                cout << "  Goodbye! Data saved. \n\n";
                break;
            default:
                cout << "    Invalid choice. Please try again.\n";
        }

        if (choice != 0) {
            cout << "\n  Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }

    return 0;
}